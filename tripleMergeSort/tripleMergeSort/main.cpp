//
//  main.cpp
//  tripleMergeSort
//
//  Created by Axel Suarez on 05/02/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void merge(int *, int, int, int, int);
void mergesort(int *a, int low, int high)
{
    int p1, p2;
    if(low < high)
    {
        int p1 = (high - low) / 3;
        int p2 = p1 * 2;
        
        mergesort(a, low, low+p1);
        mergesort(a, low+p1+1, low+p2);
        mergesort(a, low+p2+1, high);
        merge(a, low, high, low+p1, low+p2);
    }
    return;
}
void merge(int *a, int low, int high, int p1, int p2)
{
    int i = low, j = p1+1, k = p2 + 1, l = low;
    int aux[13530];
    while((i <= p1) && (j <= p2) && (k <= high))
    {
        if((a[i] <= a[j]) && (a[i] <= a[k]))
        {
            aux[l] = a[i];
            i++;
        }
        else if((a[j] <= a[i]) && (a[j] <= a[k]))
        {
            aux[l] = a[j];
            j++;
        }
        else if((a[k] <= a[i]) && (a[k] <= a[j]))
        {
            aux[l] = a[k];
            k++;
        }
        l++;
    }
    while((i <= p1) && (j <= p2))
    {
        if(a[i] <= a[j])
        {
            aux[l] = aux[i];
            i++;
        }
        else
        {
            aux[l] = a[j];
            j++;
        }
        l++;
    }
    while((i <= p1) && (k <= high))
    {
        if(a[i] <= a[k])
        {
            aux[l] = a[i];
            i++;
        }
        else
        {
            aux[l] = a[k];
            k++;
        }
        l++;
    }
    while((j <= p2) && (k <= high))
    {
        if(a[j] <= a[k])
        {
            aux[l] = a[j];
            j++;
        }
        else
        {
            aux[l] = a[k];
            k++;
        }
        l++;
    }
    while(i <= p1)
    {
        aux[l] = a[i];
        i++;
        l++;
    }
    while(j <= p2)
    {
        aux[l] = a[j];
        j++;
        l++;
    }
    while(k <= high)
    {
        aux[l] = a[k];
        k++;
        l++;
    }
    for(int m = low; m <= high; m++)
        a[m] = aux[m];
}
int main()
{
    ifstream archE;
    int dato, a[13530], i = 0;
    archE.open("datos.txt");
    while(archE >> dato)
    {
        a[i] = dato;
        i++;
    }
    archE.close();
    cout<<"enter  the elements\n";
    for (i = 0; i < 9; i++)
    {
        cin>>a[i];
    }
    mergesort(a, 0, 13529);
    ofstream archS;
    archS.open("resultado.txt");
    for(int i = 0; i <= 13530; i++)
    {
        archS << a[i];
    }
    archS.close();
}