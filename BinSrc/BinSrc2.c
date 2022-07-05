#include <stdio.h>
#include <math.h>
/*
Escribir una función de búsqueda binaria 
aplicado a un array ordenado en modo descendente
*/

#define SIZE 8



int sophie (int arr[], int target, int start, int end){

    int middle;

    middle = floor((start+end)/2);

    if (start >end)
        return -1;

    if (arr[middle] == target)
        return middle;
    else if (target >arr[middle])
        return sophie(arr,target,start,middle-1);
    else
        return sophie(arr,target,middle +1,end);

}



int main (){
    int arr[] = {100,72,30,26,18,13,3,2};

    int target;


    printf("Ingrese el elemento a buscar: "); scanf("%d",&target);


    int index=sophie(arr,target,0,SIZE);

    printf("El elemento se encuetra en la posx: %d",index);



    return 0;
} 
