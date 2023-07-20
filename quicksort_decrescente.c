#include <stdio.h>

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int HoarePartition(int a[], int l, int r){
    int p = a[l], i = l, j = r+1;
    do{
        do{
            i++;
        }while(a[i] >p && i<r);
        do{
            j--;
        }while(a[j] < p);
        swap(a, i, j);
    }while(i<j);
    
    swap(a, i, j);
    swap(a, l, j);
    return j;
}

void Quicksort(int a[], int l, int r){
    if(l<r){
        int s = HoarePartition(a, l, r);
        Quicksort(a, l, s-1);
        Quicksort(a, s+1, r);
    }
}

int main()
{
    int a[] = {1,4,8,3,8,6,5,3,2,9,0,5,3,6};
    
    int tam = sizeof(a) / sizeof(int);
    
    Quicksort(a, 0, tam-1);
    
    for(int i =0; i<tam; i++){
        printf("%d ", a[i]);
    }

    return 0;
}

