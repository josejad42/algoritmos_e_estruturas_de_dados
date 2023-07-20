#include<iostream>

using namespace std;

class Node{
    public:
    int key;
    Node * left;
    Node * right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

class BST{
    private:
        int cnt;

        bool findhelp(Node * rt, int k){
            if (rt == NULL) return false;
            if (rt->key > k) return findhelp(rt->left, k);
            else if(rt->key == k) return rt->key;
            else return findhelp(rt->right, k);
        };

        Node * inserthelp(Node * rt, int k){
            if(rt==NULL) return new Node(k);
            if(rt->key > k) rt->left = inserthelp(rt->left, k);
            else rt->right = inserthelp(rt->right, k);
            return rt;
        }

    public:

    Node * root;

    BST(){
        root = NULL;
        int cnt = 0;
    }

    bool find(int key){
        return findhelp(root, key);
    }

    void insert(int key){
        root = inserthelp(root, key);
        cnt++;
    }

    void inorder(Node * rt){
        if(rt != NULL){
            inorder(rt->left);
            printf(" %d", rt->key);
            inorder(rt->right);
        }
    }

};

int main(){
    BST tree;
    tree.insert(99);
    tree.insert(63);
    tree.insert(49);
    tree.insert(479);
    tree.insert(479);
    tree.insert(40);
    tree.insert(100);
    tree.insert(0);
    tree.insert(14);
    tree.inorder(tree.root);
}