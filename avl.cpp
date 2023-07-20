#include <iostream>

using namespace std;

class Node{
    public:
    int key;
    int height;
    Node * left;
    Node * right;

    Node(int k){
        key = k;
        left = right = NULL;
        height = 0;
    }

    Node(){
        left = right = NULL;
        height = 0;
    }
};

class AVL{
    private:
    Node *root;
    int cnt;

    int max(int a, int b){
        if(a>b) return a;
        else if(a<b) return b;
        else return a;
    }

    int h(Node * rt){
        if(rt == NULL) return -1;
        return rt->height;
    }

    int getBalance(Node * rt){  
        if(rt == NULL) return 0;
        return h(rt->left) - h(rt->right);
    }

    Node * inserthelp(Node *rt, int k){
        if (rt == NULL) return new Node(k);
        if (rt->key > k){
            rt->left = inserthelp(rt->left, k);
        } else {
            rt->right = inserthelp(rt->right, k);
        }
        rt->height = 1 + max(h(rt->left), h(rt->right));
        int balance = getBalance(rt);



        return rt;
    }

    public:

    AVL(){
        root = NULL;
        cnt = 0;
    }

    void insert(int key){
        root = inserthelp(root, key);
        cnt++;
    }

    void inorder(Node * rt){
        if(rt !=  NULL){
            inorder(rt->left);
            printf("ITEM:%d H:%d ", rt->key, rt->height);
            inorder(rt->right);
        }
    }

    Node * getRoot(){
        return root;
    }


};

int main(){

    AVL arvore;
    arvore.insert(42);
    arvore.insert(666);
    arvore.insert(13);
    arvore.insert(4002);
    arvore.inorder(arvore.getRoot());

}