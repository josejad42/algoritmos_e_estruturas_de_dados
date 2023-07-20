#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class Dict{
    private:
        int m;
        int cnt;

        int h(char *key){  //fold
            int tam = strlen(key);
            int sum = 0;
            for(int i = 0; i<tam; i++){
                sum += key[i];
            }
        return abs(sum)%m;
        }

    public:

    char **H;
    Dict(int size){
        m = size;
        cnt = 0;
        H = new char*[m];
        for(int i = 0; i<m; i++){
            H[i] = new char[100];
        }
    }

    int find(char * key){
        int pos = h(key);
        if(strlen(H[pos]) == 0) return -1;
        else if (!strcmp(H[pos], key)) return pos;
        else {
            pos++;
            while(strlen(H[pos]) != 0){
                if(!strcmp(H[pos], key)) return pos;
                pos++;
                if(pos == m) pos = 0;
            }
        }
        return -1;
    }

    void insert(char * key){
        if(find(key)<0){
            int pos = h(key);
            if(strlen(H[pos]) == 0){
                strcpy(H[pos], key);
            } else {
                while(strlen(H[pos]) != 0){
                    pos++;
                    if(pos == m) pos = 0;
                }
                strcpy(H[pos], key);
            }
        }
    }

    void remove(char * key){
        if(find(key) > 0){
            int pos = h(key);
            if(!strcmp(H[pos], key)) strcpy(H[pos], "");
            else {
                pos++;
                while(strlen(H[pos]) != 0){
                    if(!strcmp(H[pos], key)) strcpy(H[pos], "");
                    pos++;
                    if(pos == m) pos = 0;
                }
            }
        }
    }


};

int main(){
    
    int num;
    scanf("%d", &num);
    Dict dicionario(num);
    char func[4], key[100];
    scanf("%s", func);
    while(strcmp(func, "fim")){
        scanf(" %s", key);
        if(!strcmp(func, "add")) dicionario.insert(key);
        else if(!strcmp(func, "rmv")) dicionario.remove(key);
        else {
            int index = dicionario.find(key);
            printf("%s %d\n", key, index);
        }
        scanf(" %s", func);
    }
    
}