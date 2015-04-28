//
//  main.cpp
//  puntosCercanos
//
//  Created by Axel Suarez on 20/02/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;

struct punto // Estructura de un punto.
{
    double x;
    double y;
    string id;
};

void busca(struct punto *,int);
int ordenax(const void *,const void *);
double dist(struct punto,struct punto);
void merge(struct punto *p,int, int , int );
void mergesort(struct punto *p, int low, int high);

struct punto c1,c2; // Puntos más cercanos.
double mindist=1e10; // Mínima distancia.

int main()
{
    bool resp=true;
    while (resp) {
        int num=0;
        string re;
        struct punto p[10000];
        ifstream arch;
        char nombre[30];
        cout<<"Ingrese el nombre del archivo: ";
        cin>>nombre;
        arch.open(nombre);
        while(arch >> p[num].id >> p[num].x >> p[num].y)
        {
            num++;
        }
        arch.close();
        
        mergesort(p, 0, num-1);
        
        busca(p,num); // Hacer la primera búsqueda.
        
        cout<<"Vuelos mas cercanos: "<<c1.id<<" ("<<c1.x<<","<<c1.y<<") "<<" y "<<c2.id<<" ("<<c2.x<<","<<c2.y<<") "<<endl;
        cout<<"Distancia minima: "<<mindist<<endl;
        cout<<"Desea procesar otro archivo? (si/no)"<<endl;
        cin>>re;
        if (re!="si") {
            resp=false;
        }
    }
    
    return(0);
}

void busca(struct punto *p,int num)
{
    double d;
    int desde,hasta,a,b;
    
    if(num<=1) // Si no hay pares de puntos:
        return; // salir.
    // Mirar en el subconjunto de la izquierda.
    busca(p,num/2);
    // Mirar en el subconjunto de la derecha.
    busca(p+num/2,(num+1)/2);
    
    // Hallar los límites del conjunto central.
    for(desde=num/2; desde>0 && p[num/2].x-p[desde].x<mindist; desde--);
    for(hasta=num/2; hasta<num-1 && p[hasta].x-p[num/2].x<mindist; hasta++);
    
    // Búsqueda exhaustiva en el conjunto central.
    for(a=desde;a<=hasta;a++)
        for(b=a+1;b<=hasta;b++)
            if((d=dist(p[a],p[b]))<mindist)
            {
                mindist=d;
                c1.id=p[a].id;
                c1.x=p[a].x;
                c1.y=p[a].y;
                c2.id=p[b].id;
                c2.x=p[b].x;
                c2.y=p[b].y;
            }
}

// Función que calcula la distancia entre dos puntos.
double dist(struct punto a,struct punto b)
{
    return(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

void mergesort(struct punto *p, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(p,low,mid);
        mergesort(p,mid+1,high);
        merge(p,low,high,mid);
    }
    return;
}
void merge(struct punto *p, int low, int high, int mid)
{
    int i, j, k;
    struct punto c[10000];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (p[i].x < p[j].x)
        {
            c[k].x = p[i].x;
            c[k].y = p[i].y;
            c[k].id = p[i].id;
            k++;
            i++;
        }
        else
        {
            c[k].x = p[j].x;
            c[k].y = p[j].y;
            c[k].id = p[j].id;
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k].x = p[i].x;
        c[k].y = p[i].y;
        c[k].id = p[i].id;
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k].x = p[j].x;
        c[k].y = p[j].y;
        c[k].id = p[j].id;
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        p[i].x = c[i].x;
        p[i].y = c[i].y;
        p[i].id = c[i].id;
    }
}

