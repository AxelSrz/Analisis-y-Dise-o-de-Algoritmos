//
//  main.cpp
//  Boruvka
//
//  Created by Axel Suarez A01195895 on 19/04/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

// ********** SI FUNCIONA ************
// el video que me ayudo a visualizar el algoritmo https://www.youtube.com/watch?v=MFsyfvtQskw&spfreload=10

#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#define N 15 // Numero de nodos

using namespace std;

int grafo[N][N] = {{0,2,3,2,999,4,5,4,999,999,7,8,999,5,6},
    {2,0,2,8,999,5,999,4,6,999,8,2,3,4,1},
    {3,2,0,1,6,3,999,5,6,1,999,4,2,7,999},
    {2,8,1,0,1,6,1,3,3,3,999,8,1,4,999},
    {999,999,6,1,0,999,1,4,1,999,3,1,999,1,999},
    {4,5,3,6,999,0,999,7,1,7,6,999,2,7,4},
    {6,999,999,1,1,999,0,4,1,4,7,4,999,1,5},
    {2,4,5,3,4,7,4,0,2,999,4,999,1,4,1},
    {9,6,6,3,1,1,1,2,0,9,1,2,3,6,4},
    {999,999,1,3,999,7,4,999,9,0,4,999,999,6,2},
    {3,8,999,999,3,6,7,4,1,4,0,4,2,999,4},
    {2,2,4,8,1,999,4,999,2,999,4,0,7,2,999},
    {999,3,2,1,999,2,999,1,3,999,2,7,0,7,4},
    {8,4,7,4,1,7,1,4,6,6,999,2,7,0,8},
    {999,1,999,999,999,4,5,1,4,2,4,999,4,8,0}};

vector<bool> baseParaAgregados (N, false);

struct Conexion{
    int peso;
    int inicio;
    int destino;
};

bool operator <(const Conexion x, const Conexion y) { //la funcion de comparacion para el heap
    if(x.peso < y.peso) {
        return false;
    }
    else {
        return true;
    }
}

struct Componente {
    vector<bool> agregados;
    vector <int> nodos;
    priority_queue<Conexion> vertices; // un heap que contenga los arcos que salen del componente ordenados de manera ascendente
};

vector<Componente> componentes;

void Boruvka(){
    int nodoAgregar, count=0;
    bool encontrado=false;
    Componente aux;
    while (componentes.size()>1) { //aqui se itera cada conjunto hasta que todo el grafo este conectado y sea un solo conjunto
        aux= componentes[0];
        nodoAgregar= aux.vertices.top().destino; //el nodo destino del arco con el menor peso
        count+= aux.vertices.top().peso;
        cout<<aux.vertices.top().inicio<<" - "<<aux.vertices.top().destino<<" con un costo de "<<aux.vertices.top().peso<<endl;
        aux.vertices.pop();
        componentes.erase(componentes.begin());
        for (int i=0; i<componentes.size() && !encontrado; i++) {
            for (int j=0; j<componentes[i].nodos.size() && !encontrado; j++) {
                if(componentes[i].nodos[j]==nodoAgregar){ // iterar todos los componentes para buscar en cual está el siguiente nodo a agregar
                    for (int k=0; k<componentes[i].vertices.size(); k++) {
                        if (!aux.agregados[componentes[i].vertices.top().destino]) { //CON ESTO SE ASEGURA NO FORMAR CICLOS. checa si no hay conexiones que salgan de este componente hacia el componente actual.
                            aux.vertices.push(componentes[i].vertices.top()); //Agrega la conexion al heap de vertices del componente
                            componentes[i].vertices.pop();
                        }
                        else
                            componentes[i].vertices.pop();
                    }
                    for (int k=0; k< componentes[i].nodos.size(); k++) {
                        aux.nodos.push_back(componentes[i].nodos[k]); //agrega los nodos del componente recien conectado
                        aux.agregados[componentes[i].nodos[k]]= true;
                    }
                    encontrado=true;
                    componentes.erase(componentes.begin()+i); //elimina al componente que se acaba de juntar
                }
            }
        }
        encontrado=false;
        componentes.push_back(aux);
    }
    cout<<"El costo total seria de "<<count<<endl;
}

int main(int argc, const char * argv[]) {
    for (int i=0; i<N; i++) {
        Componente nodoActual;
        Conexion auxiliar;
        nodoActual.agregados= baseParaAgregados;
        nodoActual.nodos.push_back(i);
        nodoActual.agregados[i]= true;
        for (int j=0; j<N; j++) {
            if (grafo[i][j]!=999&&(i!=j)) {
                auxiliar.inicio=i;
                auxiliar.destino=j;
                auxiliar.peso= grafo[i][j];
                nodoActual.vertices.push(auxiliar);
            }
        }
        componentes.push_back(nodoActual);
    }
    Boruvka();
    return 0;
}
