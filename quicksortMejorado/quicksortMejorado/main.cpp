//
//  main.cpp
//  quicksortMejorado
//
//  Created by Axel Suarez on 09/02/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int partition(vector<int>& A, int p,int q)
{
    
    int x, i=p, y=p+((q-p)/2);
    if((A[p]<=A[y]&&A[y]<=A[q-1])||(A[q-1]<=A[y]&&A[y]<=A[p]))
        swap(A[y],A[p]);
    else if((A[y]<=A[q-1]&&A[q-1]<=A[p])||(A[p]<=A[q-1]&&A[q-1]<=A[y]))
        swap(A[q-1],A[p]);
    x= A[p];
    
    for(int j=p+1; j<q; j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            swap(A[i],A[j]);
        }
        
    }
    
    swap(A[i],A[p]);
    return i;
}
void quickSort(vector<int>& A, int p,int q)
{
    int r;
    if(p<q)
    {
        r=partition(A, p,q);
        quickSort(A,p,r);
        quickSort(A,r+1,q);
    }
}
int main()
{
    vector<int> a;
    
    ifstream archE; // A01280106 Pepinillos7#
    int dato, j = 0;
    archE.open("datos.txt");
    while(archE >> dato)
    {
        a.push_back(dato);
        j++;
    }
    archE.close();
    quickSort(a,0,j);
    ofstream archS;
    archS.open("resultado.txt");#include <iostream>
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
    for(int i = 0; i <= j; i++)
    {
        archS << a[i];
    }
    archS.close();
}