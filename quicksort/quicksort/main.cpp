//
//  main.cpp
//  quicksort
//
//  Created by Axel Suarez on 09/02/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& A, int p,int q)
{
    int x= A[p];
    int i=p;
    int j;
    
    for(j=p+1; j<q; j++)
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
    vector<int> A = {6,10,13,5,8,3,2,25,4,11};
    int p=0;
    int q=10;
    
    cout<<"======Original======="<<endl;
    for(auto e: A)
        cout<< e <<" ";
    cout<< endl;
    
    quickSort(A,p,q);
    
    cout<<"======Sorted======="<<endl;
    for(auto e: A)
        cout<< e <<" ";
    cout<< endl;
}





