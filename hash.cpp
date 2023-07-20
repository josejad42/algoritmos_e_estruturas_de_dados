#include<iostream>
using namespace std;

class Node{
    public:
        int element;
        Node *next;
        Node(int it, Node *pt){
            element = it;
            next = pt;
        } 
        Node(Node *pt = NULL){
            next = pt;
        }
};

class List{
    public: 
        Node* head;
        Node* curr;
        Node* tail;
        int cnt;
    
        List(){
            head = curr = tail = new Node();
            cnt = 0;
        }
        void append(int key){
            tail = tail->next = new Node(key, NULL);
            cnt ++;
        }
};

class Dict{
     public:
        int m = 10;
        int cnt;
        List *H;
        int h(int key){
            return key%m;
        }
   
        Dict(){
            int cnt = 0;
            H = new List[m];
            for(int i = 0; i<m; i++){
                H[i] = List();
            }
        }
        void insert(int key){
            if(!find(key)){
                int pos = h(key);
                H[pos].append(key);
            }
        }
        bool find(int key){
            int pos = h(key);
            if(H[pos].cnt == 0) return false;
            Node *temp = H[pos].head;
            while(temp->next != NULL){
                temp = temp->next;
                if (temp->element == key) return true;
            }
            return false;
        }

};

int main(){

    Dict dicionario;
    int num = 0;
    scanf("%d", &num);
    for(int i = 0; i<num; i++){
        int it;
        scanf("%d", &it);
        dicionario.insert(it);
    }

    for (int i = 0; i<10; i++){
        cout << i << ": ";
        Node *temp;
        temp = dicionario.H[i].head;
        while(temp->next != NULL){
            temp = temp->next;
            cout << temp->element << " ";
        } 
        cout << "\n";
    }

}