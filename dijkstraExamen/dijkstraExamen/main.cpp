//
//  main.cpp
//  dijkstraExamen
//
//  Created by Axel Suarez on 16/04/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
using namespace std;


#define tam 15
int datos[tam][tam] = {{0,5,3,999,999,4,5,4,999,999,7,8,999,5,6}, {2,0,999,999,999,6,999,4,6,999,999,9,3,4,1}, {5,2,0,1,999,6,999,999,8,1,999,4,2,999,999}, {2,8,999,0,1,6,999,3,3,999,999,999,7,999,999}, {999,999,6,999,0,999,1,7,1,999,3,1,999,1,999}, {999,5,3,999,999,0,999,8,999,999,999,999,2,7,4}, {6,999,999,1,999,999,0,4,999,4,9,9,999,1,999}, {2,999,5,8,4,7,999,0,999,999,999,999,1,4,1}, {9,999,6,9,4,1,1,2,0,9,999,999,3,999,4}, {999,999,6,3,999,7,6,999,9,0,999,999,999,999,2}, {3,8,999,999,999,6,7,4,1,4,0,5,999,999,999}, {2,2,9,8,1,999,4,999,2,999,4,0,999,2,999}, {999,7,999,1,999,7,999,1,6,999,2,7,0,8,999}, {8,7,7,4,4,9,999,6,6,6,999,999,7,0,999}, {999,999,999,999,999,4,5,999,5,4,4,999,4,8,0}};


void camino (int T[], int v)
{  if (T[v] != 1)
{  camino(T, T[v]);
    cout << "-" << T[v];  }
}

void dijkstra (int W[tam][tam])
{
    int L[tam+1], T[tam+1], R[tam+1], min, vmin;
    
    for (int i = 2; i<=tam; i++)
    {
        if(W[0][i-1]!=999&&W[0][i-1]!=0)
            W[0][i-1]=1;
        L[i] = W[0][i-1];
        T[i] = 1;
    }
    for (int x = 1; x < tam; x++)
    {
        min = 999;
       	for (int i = 2; i<= tam; i++){
            if ( 0 <= L[i] && L[i] <= min)
            {
                min = L[i];
                vmin = i;
            }
        }
       	for (int i=2; i<= tam; i++){
            if (W[vmin-1][i-1]!=999&&W[vmin-1][i-1]!=0) {
                W[vmin-1][i-1]=1;
            }
            if (L[vmin]+W[vmin-1][i-1] < L[i])
            {
                L[i] = L[vmin]+W[vmin-1][i-1];
                T[i] = vmin;
            }
        }
        R[vmin] = L[vmin];
        L[vmin] = -1;
    }
    cout << "\nCAMINOS MAS CORTOS\n";
    for (int i = 2; i <= tam; i++)
    {
        cout << "de 1 a " << i << ": 1";
        camino(T, i);
        cout << "-" << i << " tiene " << R[i]-1 << " escalas\n";
    }
}

int main()
{
    dijkstra(datos);
    system("PAUSE");
    return EXIT_SUCCESS;
}

