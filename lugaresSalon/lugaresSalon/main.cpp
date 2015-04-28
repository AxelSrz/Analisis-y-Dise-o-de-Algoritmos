//
//  main.cpp
//  lugaresSalon
//
//  Created by Axel Suarez A01195895 on 18/04/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

const int estudiantes = 12;  // cantidad de estudiantes
int tipos;  // cantidad de tipos diferentes
bool encontrado= false; // variable para checar cuando ya encuentre la primera solucion
char examenTipo; //variable para imprimir el tipo de examen

int lugares[estudiantes][estudiantes] = {{0,1,0,0,1,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,0,0,0},{0,1,0,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,1,0,0,0,0,0,0},{0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,1},{0,0,0,0,0,0,1,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,0,1,0},{0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,0,1,0,0,1,0}};

int vtipos[estudiantes+1];

bool valido(int i)
{
    int j = 1;
    bool sw = true;
    
    while (j < i && sw)
    {
        if (lugares[i-1][j-1] && vtipos[i] == vtipos[j]) // 1 es true, 0 es false
        sw = false;
        j++;
    }
    return sw;
}

void examenes (int i)
{
    if (valido(i)){
        if (i == estudiantes)
        {
            encontrado=true;
            for (int x = 1; x <= estudiantes; x++){
                examenTipo= 64+vtipos[x];
                cout << "El estudiante " << x << " debe tener el examen tipo " << examenTipo << "\n";
            }
        }
        else{
            for (int tipo=1; tipo <= tipos; tipo++)
            {
                vtipos[i+1] = tipo;
                if (encontrado)
                    break; //para detener el desarrollo del arbol
                examenes(i+1);
            }
        }
    }
}

int main()
{
    cout<<"¿Cuantos tipos examenes diferentes esta dispuesto a hacer"<<endl;
    cin>>tipos;
    examenes(0);
    if (!encontrado) {
        cout<<"No se puede cumplir la regla de distribución con es cantidad de examenes"<<endl;
    }
    return 0;
}
