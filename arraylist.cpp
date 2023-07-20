#include<iostream>

using namespace std;

template <typename E> class AList{

private:
    int maxSize;
    int listSize;
    int curr;
    E *list;

public:

    AList(int size = 0){
        maxSize = size;
        listSize = curr = 0;
        list = new E[maxSize];
    }

    ~AList(){
        delete [] list;
    }

    void insert(const E& it){
        if(listSize < maxSize){
            for(int i = listSize; i>curr; i--){
                list[i] = list[i-1];
            }
            list[curr] = it;
            listSize++;
        }
    }

    void append(const E& it){
        if(listSize < maxSize){
            list[listSize] = it;
            listSize++;
        }
    }

    E remove(){
       
        E value = list[curr];
        if(curr>=0){
            for(int i = curr; i<listSize-1; i++){
                list[i] = list[i+1];
            }
            listSize--;
        }
        return value;
        
    }

    void prev(){
        if(curr>0) curr--;
    }

    void next(){
        if(curr<listSize) curr++;
    }

    void moveToPos(int pos){
        if(pos>= 0 && pos<=listSize) curr = pos;
    }

    void moveToStart(){
        curr = 0;
    }

    void moveToEnd(){
        curr = listSize;
    }

    int lenght(){
        return listSize;
    }

    int getPos(){
        return curr;
    }

    const E& getValue(){    
        return list[curr];
    }


};


int main(){

    /*AList<int> lista(10);
    lista.insert(7);
    lista.insert(1);
    lista.next();
    lista.remove();
    lista.moveToStart();
    lista.append(3);
    lista.insert(7);
    cout << lista.getValue() << " " << lista.getPos() << "\n";
    lista.next();
    cout << lista.getValue() << " " << lista.getPos() << "\n";
    lista.next();
    cout << lista.getValue() << " " << lista.getPos() << "\n";*/
}