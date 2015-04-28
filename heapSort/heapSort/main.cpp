//
//  main.cpp
//  heapSort
//
//  Created by Axel Suarez on 16/04/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

int n;

void heapsort(int arr[]){
    priority_queue<int, vector<int>, greater<int>> q1;
    for (int i=0; i<n; i++) {
        q1.push(arr[i]);
    }
    for (int i=0; i<n; i++) {
        arr[i]= q1.top();
        q1.pop();
    }
    cout<<" ";
}


int main(int argc, const char * argv[]) {
    n=10;
    int arr[10]={5,7,1000,20,34,54,66,98,137,101};
    heapsort(arr);
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
