#include <stdio.h>

int BS(int a[], int l, int r, int k){
    if(l<=r){
        int m = (l+r)/2;
        if(k==a[m]) return m;
        else if(k<a[m]) return BS(a, l, m-1, k);
        else return BS(a, m+1, r, k);
    } else return -1;
}

int main(){
    int a[] = {1,3,5,6,6,7,8,8,9, 12, 23, 43};
    int k = 9;
    
    printf("%d", BS(a, 0, 11, k));

    return 0;
}