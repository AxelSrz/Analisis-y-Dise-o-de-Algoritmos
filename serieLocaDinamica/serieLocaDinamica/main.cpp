//
//  main.cpp
//  serieLocaDinamica
//
//  Created by Axel Suarez on 03/03/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <cstdlib>
#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    int a=1, b=1, c=1, n, ans; //nuestros valores base de los que se va a partir son 1, donde a b c representan los primeros tres numeros de la secuencia
    cout<<"Ingrese numero a buscar de la secuencia loca: ";
    cin>>n;
    cout<<endl;
    if (n==1||n==2||n==3) {
        cout<<"el valor del "<<n<<" numero de la secuencia loca es 1"<<endl;
    }
    else{
        for (int i=4; i<=n; i++) {// se hace un ciclo empesando del primer calculo que no es base y de ahí hasta el valor deseado usando los valores ya calculados hasta el momento
            ans= a+b+c;// se calcula la respuesta de la iteracion actual
            a= b; // se mueven todos los valores para preparar la proxima iteracion
            b= c;
            c= ans;
        }
        cout<<"el valor del "<<n<<" numero de la secuencia loca es "<<ans<<endl;
    }
    return 0;
}
