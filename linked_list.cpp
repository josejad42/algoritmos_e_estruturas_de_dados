#include<iostream>
#include<assert.h>

using namespace std;

template <typename E> class Link{
    public:
        E element;
        Link *next;

        Link(E it, Link *pointer = NULL){
            element = it;
            next = pointer;
        }

        Link(Link *pointer = NULL){
            next = pointer;
        }

};

template <typename E> class LList{

    private:
        Link<E> *tail;
        Link<E> *curr;
        Link<E> *head;
        int count;

        void init(){
            tail = curr = head = new Link<E>;
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

    LList(){
        init();
    }
    ~LList(){
        removeall();
    }

    void insert(const E& it){
        curr->next = new Link<E>(it, curr->next);
        if(tail==curr) tail = curr->next;
        count++;
    }

    E remove(){
        assert(curr->next!=NULL);
        E it = curr->next->element;
        Link<E> *temp = curr->next;
        if(tail == curr->next) tail = curr;
        curr->next = curr->next->next;
        delete temp;
        count--;
        return it;
    }

    void append(const E& it){
        tail = tail->next = new Link<E>(it, NULL);
        count++;
    }

    void next(){
        if(curr!=tail) curr = curr->next;
    }

    void prev(){
        if(curr != head){
            Link<E>* temp = head;
            while(temp->next != curr){
                temp = temp->next;
            }
            curr = temp;
        }
    }

    int lenght(){
        return count;
    }

    void moveToStart(){
        curr = head;
    }

    void moveToEnd(){
        curr = tail;
    }

    const E& getValue(){
        assert(curr->next != NULL);
        return curr->next->element;
    }

    int getPos(){
        Link<E> *temp = head;
        int i = 0;
        while(temp != curr){
            temp = temp->next;
        }
        return i;
    }

    void moveToPos(int pos){
        curr = head;
        for(int i = 0; i<pos; i++){
            curr = curr->next;
        }
    }


};

int main(){
    LList<int> lista;
    lista.insert(1);
    lista.remove();
}