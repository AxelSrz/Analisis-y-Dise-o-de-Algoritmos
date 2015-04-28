//
//  main.cpp
//  cuentaLogaritmica
//
//  Created by Axel Suarez on 09/02/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int first(int arr[], int low, int high, int x, int n)
{
    if(high >= low)
    {
        int mid = (low + high)/2;
        if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x)
            return mid;
        else if(x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid -1), x, n);
    }
    return -1;
}
int last(int arr[], int low, int high, int x, int n)
{
    if(high >= low)
    {
        int mid = (low + high)/2;
        if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x )
            return mid;
        else if(x < arr[mid])
            return last(arr, low, (mid -1), x, n);
        else
            return last(arr, (mid + 1), high, x, n);
    }
    return -1;
}
int count(int arr[], int x, int n)
{
    int i;
    int j;
    
    i = first(arr, 0, n-1, x, n);
    
    if(i == -1)
        return i;
    
    j = last(arr, i, n-1, x, n);
    
    return j-i+1;
}


int main()
{
    int x;
    cout<<"Que numero quieres bucar? "<<endl;
    cin>>x;
    ifstream archE;
    int dato, arr[13530], i = 0;
    archE.open("datos.txt");
    while(archE >> dato)
    {
        arr[i] = dato;
        i++;
    }
    archE.close();
    int n = sizeof(arr)/sizeof(arr[0]);
    int c = count(arr, x, n);
    ofstream archS;
    archS.open("resultado.txt");
    archS << x<< "esta "<< c<< "veces";
    archS.close();
    return 0;
}
