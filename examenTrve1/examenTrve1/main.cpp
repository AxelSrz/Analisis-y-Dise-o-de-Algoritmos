//Nombre: Raul Axel Suarez
//MatrÌcula: A01195895

#include <cstdlib>
#include <iostream>

using namespace std;
int datos[500] = { 150, 807, 963, 323, 331, 618, 329, 952, 311, 294, 379, 746, 995, 803, 871, 839, 168, 472, 950, 249, 173, 650, 681, 501, 266, 165, 703, 398, 441, 920, 755, 898, 900, 132, 581, 432, 475, 792, 905, 892, 438, 274, 586, 417, 163, 953, 375, 325, 802, 382, 764, 333, 491, 741, 586, 788, 293, 730, 807, 790, 606, 222, 290, 618, 334, 415, 856, 740, 235, 800, 824, 251, 128, 826, 876, 548, 230, 331, 902, 555, 565, 960, 848, 902, 157, 704, 627, 447, 726, 523, 424, 485, 763, 321, 253, 846, 315, 835, 786, 463, 677, 394, 863, 245, 391, 637, 672, 478, 902, 414, 703, 574, 362, 624, 537, 981, 283, 499, 159, 471, 589, 796, 157, 795, 361, 882, 880, 319, 540, 396, 746, 552, 468, 525, 701, 654, 398, 771, 606, 944, 388, 709, 189, 400, 997, 546, 378, 162, 973, 798, 338, 986, 484, 966, 167, 910, 825, 971, 939, 161, 644, 561, 778, 987, 859, 321, 126, 913, 498, 207, 263, 201, 608, 410, 855, 130, 555, 668, 415, 377, 331, 656, 723, 416, 265, 356, 304, 709, 759, 719, 480, 394, 325, 785, 233, 838, 754, 563, 686, 634, 619, 904, 142, 999, 189, 923, 416, 898, 314, 446, 721, 909, 624, 361, 996, 250, 172, 499, 370, 874, 506, 416, 120, 701, 965, 311, 928, 165, 100, 553, 492, 127, 482, 554, 739, 174, 743, 385, 274, 962, 204, 900, 604, 466, 558, 555, 196, 558, 639, 962, 195, 589, 187, 355, 763, 347, 182, 792, 878, 413, 452, 226, 497, 201, 831, 722, 500, 785, 141, 245, 877, 774, 645, 223, 692, 963, 667, 960, 571, 615, 666, 362, 615, 939, 290, 217, 627, 752, 267, 764, 558, 919, 802, 895, 398, 856, 122, 570, 868, 702, 474, 741, 466, 131, 560, 676, 761, 494, 920, 127, 150, 841, 334, 788, 492, 659, 123, 756, 894, 630, 854, 628, 180, 552, 909, 586, 693, 897, 839, 519, 848, 510, 272, 522, 948, 436, 270, 655, 788, 518, 103, 545, 915, 207, 525, 659, 690, 203, 959, 912, 340, 771, 302, 447, 296, 313, 717, 246, 843, 747, 207, 214, 663, 692, 217, 266, 449, 247, 269, 844, 916, 558, 987, 478, 779, 325, 244, 209, 388, 240, 840, 776, 619, 948, 804, 499, 457, 514, 505, 231, 137, 624, 903, 865, 347, 102, 411, 833, 100, 421, 950, 501, 592, 966, 575, 758, 996, 404, 630, 560, 404, 698, 243, 723, 923, 308, 951, 140, 221, 217, 166, 356, 958, 994, 570, 264, 670, 175, 466, 555, 586, 923, 293, 347, 561, 273, 383, 984, 170, 476, 439, 747, 557, 441, 677, 817, 875, 545, 841, 416, 430, 904, 557, 901, 250, 358, 965, 799, 372, 788, 627, 137, 159, 503, 153, 583, 509, 386, 624, 581, 702, 735, 949, 950, 880, 345, 521, 410, 529, 944, 491, 353, 528, 622, 514, 355, 639, 368, 591, 768, 640, 203, 865, 115, 246, 465, 491, 362, 894, 664};
int costos[7][7] = { {0, 9999, 9999, 500, 9999, 9999, 9999}, { 9999, 0, 9999, 9999, 9999, 9999, 480}, { 340, 9999, 0, 9999, 9999, 9999, 9999}, { 9999, 9999, 9999, 0, 9999, 1075,  9999}, { 9999, 900, 9999, 9999, 0, 9999, 9999}, { 9999, 9999, 760, 9999, 9999, 0, 120}, { 9999, 9999, 9999, 9999, 230, 9999, 0} };
int escalas[7][7] = {{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}};
// Problema 1
int mayorDivide(int inf, int sup){
    int a, b;
    if ((sup-inf)>1) {
        int mid= (sup+inf)/2;
        a=mayorDivide(inf, mid);
        b=mayorDivide(mid+1, sup);
        if(a>b)
            return a;
        else
            return b;
    }
    else if ((sup-inf)==1){
        if (datos[sup]>datos[inf])
            return datos[sup];
        else
            return datos[inf];
    }
    else
        return datos[inf];
}



// Problema 2

// Funcion para dividir el arreglo y hacer los intercambios
int particion(int datos[], int inicio, int fin) {
    int izq, izq2;
    int der, der2;
    int pivote;
    int temp;
    int tam= (fin-inicio)+1, tercio=tam/3;
    int n=0;
    bool balance= false;
    int arraux[tam];
    for(int i=inicio, x=0; x<tam; i++, x++){//se obtiene un arreglo auxiliar por si la particion queda desbalanceada
        arraux[x]=datos[i];
    }
    
    while(!balance&&n<tam){ //mientras no este balanceado y no se hayan tratado todos como pivotes
        izq = inicio;
        der = fin;
        der2= 0;
        izq2= 0;
        pivote = datos[inicio];
        // Mientras no se cruzen los Ìndices
        while (izq < der) {
            while (datos[der] > pivote) {
                der--;
                der2++;
            }
            
            while ((izq < der) && (datos[izq] <= pivote)) {
                izq++;
                izq2++;
            }
            
            // Si todavÌa no se cruzan los indices seguimos intercambiando
            if (izq < der) {
                temp = datos[izq];
                datos[izq] = datos[der];
                datos[der] = temp;
            }
        }
        if ((der2<tercio||izq2<tercio)&&n<(tam-1)) {
            for(int i=inicio, x=0; x<tam; i++, x++){//se regresa el arreglo a su forma original
                datos[i]=arraux[x];
            }
            n++;
            temp = datos[inicio];
            datos[inicio] = datos[inicio+n];
            datos[inicio+n] = temp;
        }
        else
            balance=true;
    }
    
    // Los Ìndices ya se han cruzado, ponemos el pivote en el lugar que le corresponde
    temp = datos[der];
    datos[der] = datos[inicio];
    datos[inicio] = temp;
    
    // La nueva posiciÛn del pivote
    return der;
}

// FunciÛn recursiva para hacer el ordenamiento
void quicksort(int datos[], int inicio, int fin)
{
    int pivote;
    
    if (inicio < fin) {
        pivote = particion(datos, inicio, fin);
        
        // Ordeno la lista de los menores
        quicksort(datos, inicio, pivote - 1);
        
        // Ordeno la lista de los mayores
        quicksort(datos, pivote + 1, fin);
    }
}

/*int particion(int datos[], int inicio, int fin) {
    int izq, izq2;
    int der, der2;
    int pivote;
    int temp;
    
    pivote = datos[inicio];
    izq = inicio;
    der = fin;
    
    izq2=0;
    der2=0;
    
    // Mientras no se cruzen los Ìndices
    while (izq < der) {
        while (datos[der] > pivote) {
            der--;
            der2++;
        }
        
        while ((izq < der) && (datos[izq] <= pivote)) {
            izq++;
            izq2++;
        }
        
        // Si todavÌa no se cruzan los indices seguimos intercambiando
        if (izq < der) {
            temp = datos[izq];
            datos[izq] = datos[der];
            datos[der] = temp;
        }
    }
    
    // Los Ìndices ya se han cruzado, ponemos el pivote en el lugar que le corresponde
    temp = datos[der];
    datos[der] = datos[inicio];
    datos[inicio] = temp;
    
    cout<<izq2<<" "<<der2<<"--"<<endl;
    // La nueva posiciÛn del pivote
    return der;
}

// FunciÛn recursiva para hacer el ordenamiento
void quicksort(int datos[], int inicio, int fin)
{
    int pivote;
    
    if (inicio < fin) {
        pivote = particion(datos, inicio, fin);
        
        // Ordeno la lista de los menores
        quicksort(datos, inicio, pivote - 1);
        
        // Ordeno la lista de los mayores
        quicksort(datos, pivote + 1, fin);
    }
}*/


//Problema 3
// Algoritmo de Floyd

int min(int a,int b)
{
    if(a<b)
        return(a);
    return(b);
}

void floyd(int p[7][7],int n)
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                int x=min(p[i][j],p[i][k]+p[k][j]);
                if (x!=p[i][j]) {
                    escalas[i][j]= escalas[i][k]+escalas[k][j]+1;
                    p[i][j]=x;
                }
            }
}


int main()
{
    int n= mayorDivide(0, 499);
    cout<<"Problema 1"<<endl<<n<<endl<<"Problema 2"<<endl;
    
    quicksort(datos, 0, 499);
    for (int i=0; i<500; i++) {
        cout<<datos[i]<<endl;
    }
    
    int noescala=0, maxescala=0;
    floyd(costos, 7);
    for (int i=0; i<7; i++) {
        for (int j=0; j<7; j++) {
            if (escalas[i][j]==0)
                noescala++;
            if (escalas[i][j]>maxescala)
                maxescala=escalas[i][j];
        }
    }
    cout<<"Problema 3"<<endl<<"Hay "<<noescala<<" que no implican ninguna escala."<<endl;
    cout<<"La cantidad maxima de escalas en una trayectoria optima es de "<<maxescala<<" escalas"<<endl;
    cout<<"El numero de escalas en la ruta optima de 3 a 5 es de "<<escalas[3][5]<<endl;
}