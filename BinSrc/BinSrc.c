#include <stdio.h>
#include <math.h>

/*
Un array contiene los elementos indicados más abajo. 
Utilizando el algoritmo de búsqueda binaria, trazar las
etapas necesarias para encontrar el número 88.
[8,13,17,26,44,56,88,97]
Igual búsqueda pero aplicada al caso del número 20.
*/

int sophie (int arr[], int target, int start, int end){

    int middle;

    middle = floor((start+end)/2);

    if (start >end)
        return -1;

    if (arr[middle] == target)
        return middle;
    else if (arr[middle] >target)
        return sophie(arr,target,start,middle-1);
    else
        return sophie(arr,target,middle +1,end);

}

int sophie2 (int arr[],int target,int start, int end){

    int middle;

    while (start <=end){
        middle = (start + end)/2;

        if (arr[middle]==target)
            return middle;
        else if (target < arr[middle])
            end = middle -1;
        else 
            start = middle +1;
    }

    return -1;

}


int main (){

    int MyArr[] = {8,13,17,26,44,56,88,97};

    int target =88;

    printf("El elemento se encuetra en la posx: %d",sophie2(MyArr,target,0,8));
    return 0;
} 
