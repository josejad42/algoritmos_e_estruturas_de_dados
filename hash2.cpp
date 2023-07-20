#include <iostream>
using namespace std;

class Node{
    public:
    int element;
    Node * next;
    Node(int key, Node * pt){
        element = key;
        next = pt;
    }
    Node(Node * pt = NULL){
        next = pt;
    }
};

class List{
    public:
        Node * head;
        Node * curr;
        Node * tail;
        int cnt;
    
        List(){
            head = curr = tail = new Node();
            cnt = 0;
        }
        void append(int key){
            tail = tail->next = new Node(key, NULL);
            cnt++;
        }
        int size(){
            return cnt;
        }
};

class Dict{
    private:
        int m;
        int cnt;
        int h(int key){
            return key%m;
        }
    public:
        List * H;
        Dict(int size){
            m = size;
            cnt = 0;
            H = new List[m];
            for(int i = 0; i<m; i++){
                H[i] = List();
            }
        }

        bool find(int key){
            int pos = h(key);
            if(H[pos].size() == 0) return false;
            else {
                Node * temp = H[pos].head;
                while(temp->next != NULL){
                    temp = temp->next;
                    if(temp->element == key) return true;
                }
                return false;
            }
        }

        void insert(int key){
            if(!find(key)){
                int pos = h(key);
                H[pos].append(key);
            }
        }

        // void remove(int key){
        //     if(find(key)){
        //         int pos = h(key);
        //         H[pos].curr = H[pos].head;
        //         while(H[pos].curr != NULL){
        //             if(H[pos].curr->element == key){
        //                 Node * temp = H[pos].curr->next;
        //                 if(H[pos].tail == H[pos].curr->next) H[pos].tail = H[pos].curr;
        //                 H[pos].curr->next = H[pos].curr->next->next;
        //                 delete temp;
        //                 H[pos].cnt--;
        //             } 
        //               H[pos].curr = H[pos].curr->next;
        //         }
        //     }
        // } 
        
};

int main() {
    Dict dicionario(5);
    dicionario.insert(199);
    dicionario.insert(13);
    dicionario.insert(13);
    dicionario.insert(23);
    dicionario.insert(23);

     for(int i = 0; i<5; i++){
        printf("%d: ", i);
        Node * temp = dicionario.H[i].head;
        while(temp->next!=NULL){
            printf("%d ", temp->next->element);
            temp = temp->next;
        }
        printf("\n");
         
    }
    

    return 0;
}