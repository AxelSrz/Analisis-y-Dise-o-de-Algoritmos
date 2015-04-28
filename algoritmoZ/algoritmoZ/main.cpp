//
//  main.cpp
//  algoritmoZ
//
//  Created by Axel Suarez on 22/01/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

int main(int argc, const char * argv[]) {
    int mayor=0, contactual=0;
    ifstream quijote;
    char c, archivo[30], actual, ganador;
    cin>>archivo;
    double dur;
    clock_t startTime= clock();
    vector<char> a;
    quijote.open(archivo);
    while(quijote>>c){
        a.push_back(tolower(c));
    }
    quijote.close();
    sort(a.begin(),a.end());
    actual= a[0];
    ganador= a[0];
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i]==actual) {
            contactual++;
        }
        else{
            if (contactual>=mayor) {
                mayor= contactual;
                ganador= a[i-1];
            }
            contactual=1;
            actual= a[i];
        }
    }
    cout<<ganador<<" "<<mayor<<endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    dur = clockTicksTaken / (double) CLOCKS_PER_SEC;
    cout<<dur<<endl;
    return 0;
}
