//
//  main.cpp
//  tareaFloyd
//
//  Created by Axel Suarez on 11/03/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int menorCosto[15][15], camino[15][15], escalas[15][15];
string ciudades[15];

int separaNumero(string cadena){
    int ultimo= cadena.length()-1;
    while (ultimo>0) {
        if ((cadena[ultimo]!=' '))
            ultimo--;
        else
            return ultimo;
    }
    return 0;
}

void separaCiudades(string &a, string &b, string cadena){
    for (int i=0; i<cadena.length(); i++) {
        if (cadena[i]=='-') {
            a= cadena.substr(0, i);
            b= cadena.substr(i+1);
            break;
        }
    }
}

int regresaSub(string s){
    int i=0;
    while (i<15) {
        if (ciudades[i]==s) {
            return i;
        }
        i++;
    }
    return -1;
}

void recorrido(int inicio, int fin){
    if(camino[inicio][fin]!=0){
        recorrido(inicio, camino[inicio][fin]);
        cout<<ciudades[camino[inicio][fin]]<<"-";
        recorrido(camino[inicio][fin], fin);
    }
}

void floyd()
{
    for(int k=0;k<15;k++)
        for(int i=0;i<15;i++)
            for(int j=0;j<15;j++){
                if(menorCosto[i][j]>menorCosto[i][k]+menorCosto[k][j]){
                    camino[i][j]= k;
                    menorCosto[i][j]= menorCosto[i][k]+menorCosto[k][j];
                    escalas[i][j]= escalas[i][k]+escalas[k][j]+1;
                }
            }
}

int main(int argc, const char * argv[]) {
    ifstream doc;
    string linea, c1, c2;
    int  ultimoespacio, ciudad=0, costo;
    bool hashtag=false;
    char archivo[30], resp='f';
    for (int i=0; i<15; i++) {
        for (int j=0; j<15; j++) {
            if (i==j) {
                menorCosto[i][j]= 0;
            }
            else
                menorCosto[i][j]= 9999;
            escalas[i][j]= 0;
        }
    }
    cout<<"Ingrese el nombre del archivo :"<<endl;
    cin>>archivo;
    doc.open(archivo);
    while (getline(doc, linea)) {
        if (hashtag) {
            ultimoespacio= separaNumero(linea);
            costo= stoi(linea.substr(ultimoespacio+1));
            separaCiudades(c1, c2, linea.substr(0, ultimoespacio));
            menorCosto[regresaSub(c1)][regresaSub(c2)]= costo;
            menorCosto[regresaSub(c2)][regresaSub(c1)]= costo;
        }
        else{
            if(linea=="#")
                hashtag=true;
            else{
                ciudades[ciudad]= linea;
                ciudad++;
            }
        }
    }
    doc.close();
    floyd();
    while (resp!='e') {
        cout<<"Seleccione una opcion(a/b/c/d):"<<endl;
        cout<<" a) Desplegar la ruta más económica que se puede tomar para ir de una ciudad a otra y su costo."<<endl;
        cout<<" b) Indicar para una ciudad, a cuáles ciudades no se puede llegar de ninguna manera con los vuelos programados."<<endl;
        cout<<" c) Indicar a qué ciudades se puede volar desde una ciudad, sin importar escalas, y mostrando el costo del viaje."<<endl;
        cout<<" d) Listar todas las rutas óptimas en costo que tienen cierto número de escalas."<<endl;
        cout<<" e) Salir"<<endl<<endl;
        cin>>resp;
        if (resp=='a') {
            string res1, res2;
            cout<<"Ingrese el nombre de la primera ciudad: ";
            cin.ignore();
            getline(cin, res1);
            cout<<"Ingrese el nombre de la segunda ciudad: ";
            getline(cin, res2);
            int ini=regresaSub(res1), fin=regresaSub(res2);
            if (menorCosto[ini][fin]!=9999) {
                cout<<endl<<"El camino mas corto de "<<res1<<" a "<<res2<<" tiene un costo de "<<menorCosto[ini][fin]<<endl;
                if (escalas[ini][fin]!=0) {
                    cout<<"Y la ruta de dicho camino es: "<<endl<<ciudades[ini]<<"-";
                    recorrido(ini, fin);
                    cout<<ciudades[fin]<<endl;
                }
                else
                    cout<<"Es ruta directa"<<endl;
            }
            else
                cout<<"No hay ruta posible entre esos destinos"<<endl;
            cout<<endl;
        }
        else if (resp=='b'){
            bool conectada=true;
            string res1;
            cout<<"Ingrese el nombre de la ciudad: ";
            cin.ignore();
            getline(cin, res1);
            int pos=regresaSub(res1);
            for (int j=0; j<15; j++) {
                if (menorCosto[pos][j]==9999) {
                    if (conectada==true){
                        cout<<"Desde esta ciudad no se puede llegar a los siguientes destinos: ";
                        conectada=false;
                    }
                    cout<<ciudades[j]<<"/ ";
                }
            }
            if (conectada)
                cout<<"Esta ciudad puede llegar a todas las demas ciudades a traves de 0 o mas escalas";
            cout<<endl<<endl;
        }
        else if (resp=='c'){
            bool conectada=false;
            string res1;
            cout<<"Ingrese el nombre de la ciudad: ";
            cin.ignore();
            getline(cin, res1);
            int pos=regresaSub(res1);
            for (int j=0; j<15; j++) {
                if (menorCosto[pos][j]!=9999&&(j!=pos)) {
                    if (conectada==false){
                        cout<<"Desde esta ciudad se puede llegar a los siguientes destinos con los siguientes costos: "<<endl;
                        conectada=true;
                    }
                    cout<<ciudades[j]<<": "<<menorCosto[pos][j]<<endl;
                }
            }
            if (!conectada)
                cout<<"Desde esta ciudad no sale ningun vuelo."<<endl;
            cout<<endl;
        }
        else if (resp=='d'){
            int num;
            bool encontrado=false;
            cout<<"Ingrese el numero de escalas: ";
            cin>>num;
            for (int i=0; i<15; i++) {
                for (int j=0; j<15; j++) {
                    if ((escalas[i][j]==num)&&(i!=j)) {
                        if(!encontrado){
                            cout<<"Las rutas optimas con este numero de escalas son: "<<endl;
                            encontrado=true;
                        }
                        cout<<ciudades[i]<<" - "<<ciudades[j]<<endl;
                    }
                }
            }
            if(!encontrado){
                cout<<"No hay rutas optimas con ese numero de escalas"<<endl;
            }
            cout<<endl;
        }
    }
    return 0;
};
