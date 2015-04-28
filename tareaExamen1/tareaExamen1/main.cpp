//Nombre: Axel Suarez
//MatrÌcula: A01195895

#include <cstdlib>
#include <iostream>

using namespace std;

int ventas[365] = { 485, 487, 494, 495, 501, 504, 512, 519, 522, 523, 530, 533, 534, 535, 538, 546, 547, 555, 559, 562, 565, 566, 572, 580, 586, 591, 595, 602, 607, 610, 617, 625, 632, 638, 646, 652, 657, 661, 665, 671, 673, 677, 681, 685, 689, 690, 697, 698, 704, 710, 712, 719, 722, 730, 734, 742, 750, 751, 752, 756, 764, 771, 778, 783, 788, 796, 800, 805, 811, 814, 819, 826, 827, 828, 832, 833, 839, 844, 848, 852, 857, 862, 870, 878, 882, 890, 894, 901, 902, 903, 905, 908, 916, 921, 928, 936, 944, 952, 955, 962, 963, 971, 978, 984, 988, 989, 993, 997, 1001, 1006, 1007, 1010, 1016, 1018, 1024, 1026, 1029, 1031, 1034, 1036, 1044, 1045, 1052, 1058, 1066, 1067, 1068, 1076, 1077, 1083, 1090, 1094, 1099, 1104, 1109, 1117, 1121, 1124, 1125, 1131, 1134, 1137, 1139, 1142, 1144, 1146, 1149, 1152, 1151, 1148, 1145, 1144, 1143, 1140, 1139, 1137, 1135, 1132, 1130, 1129, 1128, 1127, 1126, 1125, 1122, 1120, 1117, 1115, 1112, 1110, 1107, 1104, 1101, 1098, 1095, 1092, 1090, 1089, 1088, 1087, 1085, 1083, 1082, 1080, 1079, 1078, 1077, 1074, 1071, 1069, 1067, 1066, 1065, 1064, 1063, 1062, 1059, 1056, 1054, 1051, 1048, 1047, 1044, 1041, 1039, 1038, 1037, 1035, 1033, 1031, 1029, 1027, 1024, 1021, 1019, 1016, 1015, 1013, 1011, 1010, 1008, 1007, 1005, 1002, 1001, 998, 996, 993, 990, 988, 985, 983, 980, 978, 977, 976, 973, 971, 968, 966, 964, 961, 958, 955, 953, 950, 949, 948, 945, 943, 941, 938, 936, 934, 932, 929, 928, 926, 924, 923, 921, 919, 917, 916, 914, 912, 909, 908, 906, 904, 903, 902, 900, 899, 898, 897, 895, 892, 890, 888, 887, 884, 882, 879, 878, 876, 874, 873, 870, 868, 865, 862, 860, 858, 855, 853, 851, 850, 847, 846, 843, 842, 840, 837, 835, 834, 831, 830, 829, 828, 826, 825, 822, 820, 818, 815, 813, 811, 808, 805, 803, 802, 801, 800, 798, 797, 794, 793, 790, 789, 786, 784, 781, 780, 777, 774, 773, 772, 769, 766, 764, 763, 762, 759, 757, 754, 752, 751, 749, 746, 743, 742, 740, 737, 735, 733, 731, 728, 725, 722, 721, 720, 719, 717, 714};
int ventas1[365] = { 485, 487, 494, 495, 504, 512, 519, 522, 523, 530, 533, 534, 535, 538, 546, 547, 559, 562, 565, 566, 572, 580, 586, 591, 595, 602, 607, 610, 617, 625, 632, 638, 646, 652, 657, 661, 665, 671, 673, 677, 681, 685, 689, 690, 697, 698, 704, 710, 712, 719, 722, 730, 734, 742, 750, 751, 752, 756, 764, 771, 778, 783, 788, 800, 805, 811, 819, 826, 827, 828, 832, 833, 839, 844, 848, 852, 857, 862, 870, 878, 882, 890, 894, 901, 902, 903, 905, 908, 916, 921, 928, 936, 944, 952, 955, 962, 963, 971, 978, 988, 989, 993, 997, 1001, 1007, 1010, 1016, 1018, 1024, 1026, 1029, 1031, 1034, 1036, 1044, 1045, 1052, 1058, 1066, 1067, 1068, 1076, 1077, 1083, 1090, 1094, 1099, 1104, 1109, 1117, 1121, 1124, 1125, 1131, 1134, 1139,  1148, 1145, 1144, 1143, 1140, 1139, 1137, 1135, 1132, 1130, 1129, 1128, 1127, 1126, 1125, 1122, 1120, 1117, 1115, 1112, 1110, 1107, 1104, 1101, 1098, 1095, 1092, 1090, 1089, 1088, 1087, 1085, 1083, 1082, 1080, 1079, 1078, 1077, 1074, 1071, 1069, 1067, 1066, 1065, 1064, 1063, 1062, 1059, 1056, 1054, 1051, 1048, 1047, 1044, 1041, 1039, 1038, 1037, 1035, 1033, 1031, 1029, 1027, 1024, 1021, 1019, 1016, 1015, 1013, 1011, 1010, 1008, 1007, 1005, 1002, 1001, 998, 996, 993, 990, 988, 985, 983, 980, 978, 977, 976, 973, 971, 968, 966, 964, 961, 958, 955, 953, 950, 949, 948, 945, 943, 941, 938, 936, 934, 932, 929, 928, 926, 924, 923, 921, 919, 917, 916, 914, 912, 909, 908, 906, 904, 903, 902, 900, 899, 898, 897, 895, 892, 890, 888, 887, 884, 882, 879, 878, 876, 874, 873, 870, 868, 865, 862, 860, 858, 855, 853, 851, 850, 847, 846, 843, 842, 840, 837, 835, 834, 831, 830, 829, 828, 826, 825, 822, 820, 818, 815, 813, 811, 808, 805, 803, 802, 801, 800, 798, 797, 794, 793, 790, 789, 786, 784, 781, 780, 777, 774, 773, 772, 769, 766, 764, 763, 762, 759, 757, 754, 752, 751, 749, 746, 743, 742, 740, 737, 735, 733, 731, 728, 725, 722, 721, 720, 719, 717, 714, 700, 698, 650, 503, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
int costos[7][7] = { {0, 100, 9999, 500, 9999, 9999, 9999}, { 9999, 0, 9999, 9999, 9999, 9999, 480}, { 340, 9999, 0, 9999, 9999, 9999, 9999}, { 9999, 9999, 9999, 0, 9999, 1075, 9999}, { 9999, 900, 9999, 9999, 0, 9999, 9999}, { 9999, 9999, 760, 9999, 9999, 0, 120}, { 9999, 9999, 9999, 9999, 230, 9999, 0} };

// Problema 1
int prob1dinamico(int n){
    int a=1, b=1, c=1, ans=1; //nuestros valores base de los que se va a partir son 1, donde a b c representan los primeros tres numeros de la secuencia
    if (n==1||n==2||n==3) {
        return 1;
    }
    else{
        for (int i=4; i<=n; i++) {// se hace un ciclo empesando del primer calculo que no es base y de ahí hasta el valor deseado usando los valores ya calculados hasta el momento
            ans= a+b+c;// se calcula la respuesta de la iteracion actual
            a= b; // se mueven todos los valores para preparar la proxima iteracion
            b= c;
            c= ans;
        }
        return ans;
    }
    return 0;
}

int prob1divide(int n){
    if (n==1||n==2||n==3)
        return 1; //caso base
    else
        return (prob1divide(n-1)+prob1divide(n-2)+prob1divide(n-3)); //llamada recursiva para dividir en 3 casos de tamaño n-1, n-2 y n-3 (no es eficiente la division)
}

// Problema 2
int problema2()// este problema es una busqueda binaria que en lugar de buscar un numero especifico busca al amyor en un arreglo semi ordenado
{
    int centro,inf=0,sup=364;
    while(inf<=sup){
        centro=(sup+inf)/2;
        if((ventas1[centro]>ventas1[centro+1])&&(ventas1[centro]>ventas1[centro-1]))//el numero que se busca siempre tendra un numero menor a el a su izq y a su derecha
            return centro;
        else if((ventas1[centro]>ventas1[centro+1])&&(ventas1[centro]<ventas1[centro-1]))//si el numero actual es menor que el de la izquierda, hay que descartar la mitad derecha
            sup=centro-1;
        else//si el numero es menor que el de la derecha hay que descartar la mitad izquierda
            inf=centro+1;
    }
    return -1;
}

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
            for(int j=0;j<n;j++)
                p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}


int main()
{
    //problema 1 divide
    cout<<"el valor del "<<31<<" numero de la secuencia loca por divide y venceras es "<<prob1divide(31)<<endl;
    //problema 1 divide
    cout<<"el valor del "<<31<<" numero de la secuencia loca por programacion dinamica es "<<prob1dinamico(31)<<endl;
    //problema 2
    int n=problema2();
    cout<<"en el dia "<<n<<" y la venta maxima fue de "<<ventas1[n]<<endl;
    
    //Problema 3
    //En este problema se busca de manera secuencial el mayor valor de la matriz depues de ejecutar floyd sin contar los 9999
    bool encontrado=false;
    int may=0,a, b, x=-1, y=-1;
    floyd(costos, 7);
    for(int i=0; i<7; i++){
        for (int j=0; j<7; j++) {
            if ((costos[i][j]<9999)&&(costos[i][j]>may)) {
                a= i+1;//se guardan las coordenadas de la casilla con mayor valor hasta el momento
                b= j+1;
                may= costos[i][j];
            }
            if (!encontrado) {
                if (costos[i][j]==9999) { //para encontrar los primeros nodos que no tengan conexion
                    x= i+1;
                    y= j+1;
                    encontrado=true;
                }
            }
        }
    }
    cout<<"el par de nodos con el camino optimo mas costoso es "<<a<<" y "<<b<<", y el primer par de nodos sin camino entre ellos son: "<<x<<" y "<<y<<endl;
}