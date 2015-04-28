//
//  main.cpp
//  DijkstraPrim
//
//  Created by Axel Suarez on 26/03/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int costos[15][15], longitudArcos[15], auxArcos[15], c=0;
bool encontrado[15];
string ciudades[15];
class tupla
{
private:
    int desde;
    int hasta;
public:
    tupla();
    tupla(int des, int has);
    int getDesde();
    void setDesde(int des);
    int getHasta();
    void setHasta(int has);
};

tupla::tupla()
{
    desde=-1;
    hasta=-1;
}

tupla::tupla(int des, int has)
{
    desde = des;
    hasta = has;
}

int tupla::getDesde()
{
    return desde;
}

void tupla::setDesde(int des)
{
    desde = des;
}

int tupla::getHasta()
{
    return hasta;
}

void tupla::setHasta(int has)
{
    hasta = has;
}

vector<tupla> arcos;
vector<int> peso;

void dijkstra(int nodo){
    tupla arco;
    int min, vmin=0;
    for (int i = 0; i<15; i++){
        if (i!=nodo) {
            longitudArcos[i] = costos[nodo][i];
            auxArcos[i] = nodo;
            encontrado[i]= false;
        }
        else
            auxArcos[i]= -1;
    }
    for (int j=1; j<15; j++) {
        min= 9999;
        for(int i=0; i<15; i++){
            if (i!=nodo) {
                if((0<=longitudArcos[i])&&(longitudArcos[i]<=min)){
                    min= longitudArcos[i];
                    vmin= i;
                }
            }
        }
        arco.setDesde(auxArcos[vmin]);
        arco.setHasta(vmin);
        arcos.push_back(arco);
        peso.push_back(costos[auxArcos[vmin]][vmin]);
        encontrado[vmin]= true;
        for (int i=0; i<15; i++) {
            if(i!=nodo){
                if (longitudArcos[vmin]+costos[vmin][i] < longitudArcos[i]) {
                    longitudArcos[i]= longitudArcos[vmin]+costos[vmin][i];
                    auxArcos[i]= vmin;
                }
            }
        }
        longitudArcos[vmin]= -1;
    }
    
}
void recorrido(int des, int has)
{
    int sum=0;
    bool ya= false;
    for (int j=0; j<15 && !ya; j++) {
        if(j!=des){
            if (has==arcos[j].getHasta()) {
                if (des==arcos[j].getDesde()) {
                    cout<<ciudades[arcos[j].getHasta()]<<" ";
                    ya=true;
                    c+= peso[j];
                }
                else{
                    recorrido(des, arcos[j].getDesde());
                    cout<<ciudades[arcos[j].getHasta()]<<" ";
                    c+= peso[j];
                }
            }
        }
    }
}

int separaNumero(string cadena){
    int ultimo= (int)cadena.length()-1;
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


int main(int argc, const char * argv[]) {
    ifstream doc;
    string linea, c1, c2;
    int  ultimoespacio, ciudad=0, costo;
    bool hashtag=false;
    char archivo[30];
    for (int i=0; i<15; i++) {
        for (int j=0; j<15; j++) {
            if (i==j) {
                costos[i][j]= 0;
            }
            else
                costos[i][j]= 9999;
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
            costos[regresaSub(c1)][regresaSub(c2)]= costo;
            costos[regresaSub(c2)][regresaSub(c1)]= costo;
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
    char siguiente='s';
    while (siguiente=='s') {
        string res;
        cout<<"Ingrese el nombre de la ciudad: ";
        cin.ignore();
        getline(cin, res);
        int pos= regresaSub(res);
        arcos.clear();
        peso.clear();
        dijkstra(pos);
        for (int j=0; j<15; j++) {
            if(j!=pos&&encontrado[j]){
                c=0;
                cout<<ciudades[pos]<<" ";
                recorrido(pos, j);
                cout<<endl<<"Con un costo de: "<<c<<endl<<endl;
            }
        }
        cout<<"¿Desea buscar rutas para otra ciudad? (s/n)"<<endl;
        cin>>siguiente;
    }
    //Se implementa prim
    int vmin=0;
    arcos.clear();
    peso.clear();
    for(int i = 0; i <15; i++)
    {
        longitudArcos[i] = costos[0][i];
        auxArcos[i] = 0;
    }
    int n=0;
    int suma=0;
    tupla arco;
    while(n< 15)
    {
        int min = 9999;
        for(int i=1; i<15; i++)
        {
            if(0 <= longitudArcos[i] && longitudArcos[i]<= min)
            {
                if(auxArcos[i]!=-1)
                {
                    min = longitudArcos[i];
                    vmin = i;
                }
            }
        }
        suma+= min;
        arco.setDesde(auxArcos[vmin]);
        arco.setHasta(vmin);
        arcos.push_back(arco);
        for(int j=0; j<15; j++)
        {
            longitudArcos[j] = costos[vmin][j];
            if(auxArcos[j]!=-1)
                auxArcos[j] = vmin;
        }
        auxArcos[vmin]=-1;
        n++;
    }
    cout << "El costo minimo es de: " << suma << endl;
    for(int i = 0; i < arcos.size()-1; i++)
        cout << "(" << ciudades[arcos[i].getDesde()] << "," << ciudades[arcos[i].getHasta()] << ")" << " ";
    
}