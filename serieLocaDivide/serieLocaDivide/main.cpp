//
//  main.cpp
//  serieLocaDivide
//
//  Created by Axel Suarez on 03/03/15.
//  Copyright (c) 2015 Axel Suarez. All rights reserved.
//

#include <cstdlib>
#include <iostream>

using namespace std;
int serieloca(int n){
    if (n==1||n==2||n==3)
        return 1; //caso base
    else
        return (serieloca(n-1)+serieloca(n-2)+serieloca(n-3)); //llamada recursiva para dividir en 3 casos de tamaño n-1, n-2 y n-3 (no es eficiente la division)
}
int main(int argc, const char * argv[]) {
    int n;
    cout<<"Ingrese numero a buscar de la secuencia loca: ";
    cin>>n;
    cout<<"el valor del "<<n<<" numero de la secuencia loca es "<<serieloca(n)<<endl;
    cout<<endl;
    return 0;
}
