#include<iostream>

using namespace std;

template <typename E> class Link{
    public:
        E element;
        Link *next;
        Link(const E& it = 0, Link *pointer = NULL){
            element = it;
            next = pointer;
        }
};

template <typename E> class LList{
    private:
        Link<E>* curr;
        Link<E>* tail;
        Link<E>* head;
        int count;

        void init(){
            curr = head = tail = new Link<E>;
            count = 0;
        }

        void removeall(){
            while(head != NULL){
                curr = head;
                head = head->next;
                delete curr;
            }
        }
        

    public:
        LList(){init();}
        ~LList(){removeall();}

        void insert(const E& it){
            curr->next = new Link<E>(it, curr->next);
            if(tail == curr) tail = curr->next;
            count++;
        }

        E getValue(){
            return curr->next->element;
        }

        E remove(){
            
        }

};

int main(){

   LList<char> lista;
   lista.insert('a');
   lista.insert('b');
   cout << lista.getValue();


}