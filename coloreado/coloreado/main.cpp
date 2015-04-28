//
//  main.cpp
//  coloreado
//
//  Created by Axel Suarez on 17/04/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

const int n = 9;  // cantidad de nodos
int m = 5;  // cantidad de colores
int a;


int grafo[n][n] = {{0,1,1,0,0,0,0,0,0}, {1,0,1,1,1,0,0,0,0}, {1,1,0,0,1,1,0,0,0}, {0,1,0,0,1,0,1,0,0}, {0,1,1,1,0,1,1,1,0},{0,0,1,0,1,0,0,1,1},{0,0,0,1,1,0,0,1,1},{0,0,0,0,1,1,1,0,1},{0,0,0,0,0,0,1,1,0}};

int vcolor[n+1], cont=0;

bool valido(int i)
{
    int j = 1;
    bool sw = true;
    
    while (j < i && sw)
    {  if (grafo[i-1][j-1] && vcolor[i] == vcolor[j]) // 1 es true, 0 es false
        sw = false;
        j++;
    }
    return sw;
}

void coloreado (int i)
{
    if (valido(i)){
        if (i == n)
        {
            if(vcolor[1]==a){
                cont++;
                cout << "-------------------------------------- \n";
                for (int x = 1; x <= n; x++)
                    cout << "Nodo " << x << " se pinta del color #" << vcolor[x] << "\n";
            }
        }
        else
            for (int color=1; color <= m; color++)
            {  vcolor[i+1] = color;
                coloreado(i+1);
            }
    }
}

int main()
{
    cout<<"¿Cuantos colores queires usar?"<<endl;
    cin>>m;
    cout<<"¿Con que numero de color quieres empezar?"<<endl;
    cin>>a;
    coloreado(0);
    cout<<endl<<"El numero de combinaciones diferentes es: "<<cont<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
