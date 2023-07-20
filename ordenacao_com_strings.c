#include <stdio.h>
#include <string.h>

void swap(char a[][30], int i, int j){
    char temp[30];
    strcpy(temp, a[i]);
    strcpy(a[i], a[j]);
    strcpy(a[j], temp);
}

int partition(char a[][30], int l, int r){
    char p[30];
    strcpy(p, a[l]);
    int i = l, j = r+1;
    do{
        do{
            i++;
        } while(strcmp(a[i], p) < 0);
        do{
            j--;
        } while(strcmp(a[j], p) > 0);
        swap(a, i, j);
        
    }while(i<j);
    
    swap(a, i, j);
    swap(a, l, j);
    return j;
}

void quicksort(char a[][30], int l, int r){
    if(l<r){
        int s = partition(a, l, r);
        quicksort(a, l, s-1);
        quicksort(a, s+1, r);
    }
}

int BS(char a[][30], char k[30], int tam){
    int l = 0, r = tam-1;
    
    while(l<=r){
        int m = (l+r)/2;
        if(!strcmp(a[m], k)) return m;
        else if(strcmp(k, a[m]) < 0) r = m-1;
        else l = m+1;
    }
    
    return -1;
}

int main()
{   
    int num;
    printf("Digite o número de strings: ");
    scanf("%d", &num);
    char sts[num][30];
    char k[30];
    for(int i = 0; i<num; i++){
        scanf(" %s", sts[i]);
    }
    
    printf("PASSANDO PELO ALGORITMO DE ORDENACAO\n\n");
    
    quicksort(sts, 0, num-1);
    
    for(int i = 0; i<num; i++){
        printf("%d: %s\n",i+1,  sts[i]);
    }
    
    printf("\nDigite qual o nome do meliante: ");
    scanf("%s", k);
    
    printf(".....................................");
    printf("\nESSE MELIANTE TEM A POSICAO NUM. %d", BS(sts, k, num)+1);

    return 0;
}
