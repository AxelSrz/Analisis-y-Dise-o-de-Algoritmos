//
//  main.cpp
//  algoritmoY
//
//  Created by Axel Suarez on 23/01/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    char cLetraAct = 'a';
    char cNombreArchivo[100], cActual, cLetra;
    ifstream archivoEntrada;
    int iContGeneral = 0, iActual = 0, iI = 0;
    
    cout << "Ingresa el nombre del archivo" << endl;
    cin.getline(cNombreArchivo, 100);
    
    clock_t startTime = clock();
    while(iI < 26)
    {
        archivoEntrada.open(cNombreArchivo);
        while(archivoEntrada >> cActual)
        {
            if(tolower(cActual) == cLetraAct)
                iActual++;
        }
        
        if(iActual > iContGeneral)
        {
            iContGeneral = iActual;
            cLetra = cLetraAct;
        }
        
        iActual = 0;
        cLetraAct++;
        iI++;
        archivoEntrada.close();
    }
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    
    cout << "La letra que mas se repite es la letra: " << cLetra << endl;
    cout << timeInSeconds << endl;
    
    return 0;
}