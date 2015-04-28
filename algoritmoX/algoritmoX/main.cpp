//
//  main.cpp
//  algoritmoX
//
//  Created by Axel Suarez on 23/01/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//


#include <cctype>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <ctime>

using namespace std;

void buscaMayor(int iArrCont[], int &iMayor){
    iMayor = 0;
    int iMayorCont = iArrCont[0];
    for (int iIndex = 1; iIndex < 26; iIndex++) {
        if (iArrCont[iIndex] > iMayorCont) {
            iMayorCont = iArrCont[iIndex];
            iMayor = iIndex;
        }
    }
}

bool esLetra(char cLetra, int &iLetra){
    iLetra = tolower(cLetra);
    if (iLetra >= 97 && iLetra <= 122) {
        iLetra -= 97;
        return true;
    }
    else
        return false;
}

void inicializaArr(int iArrCont[], int iNum){
    for (int iAux = 0; iAux < iNum; iAux++) {
        iArrCont[iAux] = 0;
    }
}

int main() {
    clock_t Tiempo;
    double duracion;
    ifstream doc;
    doc.open("quijote.txt");
    char cLetra;
    int iLetra, iArrCont[26], iMayor;
    //Tiempo = clock();
    clock_t startTime = clock();
    inicializaArr(iArrCont, 26);
    while (doc >> cLetra) {
        if (esLetra(cLetra, iLetra)) {
            iArrCont[iLetra]++;
        }
    }
    
    buscaMayor(iArrCont, iMayor);
    
    cLetra = iMayor + 97;
    
    cout << cLetra << endl;
    
    //Tiempo = clock() - Tiempo;
    //printf("%lu clicks %f seconds .\n", Tiempo, ((float)Tiempo)/CLOCKS_PER_SEC);
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    cout << timeInSeconds;
    
    return 0;
}
