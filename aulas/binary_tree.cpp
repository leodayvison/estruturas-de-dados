#include <iostream>
#include <queue>

using namespace std;

struct node { 
    int value;
    node* pai;
    node* esq;
    node* dir;
};

class BinaryTree {
    node* root;

    public:
    void rebuild(int n);
    void delete_all();
    void delete_from(node* p);
};

void BinaryTree::rebuild(int n){
    delete_all();

    if (n <=0) {root = nullptr; return;}
    root = new node;
    root -> pai = nullptr;
    queue<node*> Q;
    Q.push(root);

    int count = 1; // conta os elementos na fila pra não criar objetos que serão vazios
    for (int i = 1; i <= n; i++){
        node* p = Q.front(); 
        Q.pop(); 
        p -> value = i;
        if (n > count){
            p -> esq = new node;
            p -> esq -> pai = p;
            Q.push(p->esq);
            count++;
        } else p->esq = nullptr;
        if (n > count){
            p -> dir = new node;
            p -> dir -> pai = p;
            Q.push(p->dir);
            count++;
        } else p -> dir = nullptr;
    }
}

void BinaryTree::delete_from(node* p){
    if (p == nullptr) return;
    delete_from(p->esq); 
    p->esq = nullptr;
    delete_from(p->dir);
    p->dir = nullptr;
    delete p;
}

void BinaryTree::delete_all(){
    delete_from(root);
    root = nullptr;
}

