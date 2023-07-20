#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

class Dict{
    private:
        int m;
        int cnt;
        int h(char * key){
            int tam = strlen(key);
            int acu = 0;
            for(int i = 0; i<tam; i++){
                acu += key[i];
            }
            return abs(acu) % m;
        }
    public:
        char **H;
        Dict(int size){
            m = size;
            cnt = 0;
            H = new char* [m];
            for(int i = 0; i<m; i++){
                H[i] = new char [100];
            }
        }

        bool find(char * key){
            int pos = h(key);
            if(strlen(H[pos]) == 0) return false;
            else{
                if(!strcmp(H[pos], key)) return true;
                while( strlen(H[pos]) != 0){
                    pos++;
                    if(pos==m) pos = 0;
                    if(!strcmp(H[pos], key)) return true;
                }
            }
            return false;
        }

        void insert(char * key){
            if(cnt == m) return;
            if(!find(key)){
                int pos = h(key);
                if(strlen(H[pos]) == 0) {strcpy(H[pos], key); cnt++;}
                else{
                    while(strlen(H[pos]) != 0){
                        pos++;
                        if(pos==m) pos = 0;
                    }
                    strcpy(H[pos], key);
                    cnt++;
                }
            }
        }

        void remove(char * key){
            if(find(key)){
                int pos = h(key);
                if(!strcmp(H[pos], key)) {strcpy(H[pos], ""); cnt--;}
                else {
                    while(strlen(H[pos]) != 0){
                        pos++;
                        if(pos==m) pos = 0;
                        if(!strcmp(H[pos], key)) {strcpy(H[pos], ""); cnt--;}
                    }
                }
            }
        }
}; 

int main(){
    int m = 4;
    Dict dicionario(m);
    char s[10] = "jose";
    char s1[10] = "jseo";
    char s2[10] = "ojse";
    dicionario.insert(s);
    dicionario.insert(s1);
    dicionario.insert(s2);
    dicionario.remove(s2);

    for(int i = 0; i<m; i++){
        printf("%d:%s\n", i, dicionario.H[i]);
    }
}