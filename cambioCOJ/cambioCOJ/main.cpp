/*

 El diseño de este algoritmo consistio en la siguiente formula recursiva; C[i,j] = min( C[i − 1,j], 1 + C[i,j − di])
 dicha conclusión fue sacada en base a la practica y error y apoyo del siguiente documento en linea: http://ace.cs.ohiou.edu/~razvan/courses/cs4040/lecture19.pdf
 
 
*/
#include <iostream>
#include <algorithm>

using namespace std;



int main() {
    char resp='f';
    while (resp!='n') {
        int cambio, num;
        cout<<"Ingrese el numero de tipos diferentes de monedas: ";
        cin>>num;
        int monedas[num+1];
        monedas[0]=0;
        for (int i=1; i<=num; i++) {
            cout<<"Ingrese la denominacion de la moneda numero "<<i<<": ";
            cin>>monedas[i];
        }
        sort(monedas+0, monedas+(num+1));
        cout<<"Ingrese la cantidad de cambio: ";
        cin>>cambio;
        int monedasOptimas[num+1][cambio+1];
        bool camino[num+1][cambio+1];
        for (int i=1; i<=num; i++) {
            monedasOptimas[i][0]=0;
        }
        for (int j=1; j<=cambio; j++) {
            monedasOptimas[1][j]=j;
            camino[1][j]= true;
        }
        for (int i=2; i<=num; i++) {
            for (int j=0; j<=cambio; j++) {
                if (j<monedas[i]){
                    monedasOptimas[i][j]= monedasOptimas[i-1][j];
                    camino[i][j]=false;
                }
                else{
                    int a= monedasOptimas[i-1][j], b=1+monedasOptimas[i][j-monedas[i]];
                    if (a<b) {
                        monedasOptimas[i][j]= a;
                        camino[i][j]=false;
                    }
                    else{
                        monedasOptimas[i][j]= b;
                        camino[i][j]= true;
                    }
                }
            }
        }
        cout<<"Su cambio es ("<<monedasOptimas[num][cambio]<<" monedas): "<<endl;
        for (int i=num; i>0; i--) {
            if (camino[i][cambio]) {
                int veces=1, iterador=cambio-monedas[i];
                while (camino[i][iterador]) {
                    veces++;
                    iterador-=monedas[i];
                }
                cout<<veces<<" moneda(s) de "<<monedas[i]<<endl;
                cambio-= (veces*monedas[i]);
            }
            if (cambio==0)
                break;
        }
        cout<<endl<<endl<<"¿Desea introducir nuevos datos? (s/n)"<<endl;
        cin>>resp;
        cout<<endl;
    }
    return 0;
}

