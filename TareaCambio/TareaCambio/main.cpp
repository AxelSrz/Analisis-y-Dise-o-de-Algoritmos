//
//  main.cpp
//  TareaCambio
//
//  Created by Axel Suarez on 19/03/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int num, cambio, resto, aux, cuantasMonedas, monedasActuales;
    cout<<"Ingrese el numero de tipos diferentes de monedas: ";
    cin>>num;
    int monedas[num], cambioOptimo[num], cambioActual[num];
    for (int i=0; i<num; i++) {
        cambioOptimo[i]=0;
        cambioActual[i]=0;
    }
    for (int i=0; i<num; i++) {
        cout<<"Ingrese la denominacion de la moneda numero "<<i+1<<": ";
        cin>>monedas[i];
    }
    sort(monedas+0, monedas+num);
    cout<<"Ingrese la cantidad de cambio: ";
    cin>>cambio;
    cuantasMonedas= cambio+1;
    for (int i=0; i<num; i++) { // del subconjunto de monedas mas pequeño al mas grande
        resto=cambio;
        monedasActuales= 0;
        for (int j=i; j>=0; j--) { // Saca el cambio optimo empezando por la denominacion más grande del conjunto actual
            if (resto!=0) { // si todavia no queda exacto el cambio
                aux= resto/monedas[j];
                if (aux!=0) {
                    cambioActual[j]=aux;
                    monedasActuales+= aux;
                    resto%= monedas[j];
                }
            }
        }
        if (resto==0) { // Valida que si se completara el cambio con este conjunto de monedas
            if (monedasActuales<cuantasMonedas) { // checa que la respuesta sea mejor que con el conjunto anterior
                cuantasMonedas= monedasActuales; // modifica la respuesta y limpia el arreglo auxiliar
                for (int i=0; i<num; i++) {
                    cambioOptimo[i]=cambioActual[i];
                    cambioActual[i]=0;
                }
            }
            else{
                for (int i=0; i<num; i++) //limpia el aux
                    cambioActual[i]=0;
            }
        }
        else{
            for (int i=0; i<num; i++) //limpia el aux
                cambioActual[i]=0;
        }
    }
    if (cuantasMonedas<cambio+1) { // Valida que si quedara el cambio exacto
        cout<<"Su cambio es: "<<endl;
        for (int i=0; i<num; i++) {
            if (cambioOptimo[i]!=0) {
                cout<<cambioOptimo[i]<<" moneda(s) de "<<monedas[i]<<endl;
            }
        }
    }
    else
        cout<<"No se puede dar cambio exacto con esas denominaciones de moneda"<<endl;
    return 0;
}
