#include<stdio.h>

void merge(int a[], int l, int m, int r){
    int temp[r+1];
    int curr = l, i1 = l, i2 = m+1;
    for(int i =l; i<= r; i++){
        temp[i] = a[i];
    }   
    while (i1 <= m && i2 <= r) {
        if (temp[i1] <= temp[i2]) a[curr++] = temp[i1++];
        else a[curr++] = temp[i2++];
    }
    while (i1 <= m) a[curr++] = temp[i1++];
    while (i2 <= r) a[curr++] = temp[i2++];
}

void mergesort(int a[], int l, int r){
    if(l<r){
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main(){
    int a[] = {-4,4,5,-6,-4,0,45,1000};
    mergesort(a, 0, 7);
    for (int i = 0; i < 8; i++) printf("%d ", a[i]);
    return 0;
}

