#include <stdio.h>


int BS(int a[], int k, int tam){
    int l = 0, r = tam -1;
    while(l<=r){
        int m = (l+r)/2;
        if(k == a[m]) return m;
        else if (k<m) r = m-1;
        else l = m+1;
    }
    return -1;
}

int main(){   
    
    int a[] = {1,2,2,3,4,5,5,6,6,7,8,9,9};
    int k = 5, tam = sizeof(a)/sizeof(int);
    printf("%d ", BS(a, k, tam));
    return 0;
}
