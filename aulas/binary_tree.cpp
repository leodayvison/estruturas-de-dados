#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node { 
    int value;
    node* pai;
    node* esq = nullptr;
    node* dir = nullptr;
};

class BinaryTree {
    

    public:
    node* root;


    void rebuild(int n);
    void delete_all();
    void delete_from(node* p);
    void level_order();
    void pre_order();
    void post_order(); // TODO
    void in_order(); // TODO
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

void BinaryTree::level_order(){
    if (root == nullptr) return;
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* p = q.front();
        q.pop();
        cout << p->value << " ";
        if(p->esq != nullptr) q.push(p->esq);
        if(p->dir != nullptr) q.push(p->dir);
    }
}

void BinaryTree::pre_order(){
    if (root == nullptr) return;
    stack<node*> s;
    s.push(root);

    while (!s.empty()){
        node* p = s.top();
        s.pop();
        cout << p->value << " ";
        if (p->dir != nullptr) s.push(p->dir);
        if (p->esq != nullptr) s.push(p->esq);
    }
}

int main(){

    // Cornojob abaixo (sim, eu fiz uma arvore binaria na mão.)    
    BinaryTree arvore;
    node* raiz = new node;;
    raiz->value = 10;
    raiz->esq = new node;
    raiz->dir = new node;
    raiz->esq->value=9;
    raiz->dir->value=2;
    raiz->esq->esq = new node;
    raiz->esq->esq->value = 8;
    raiz->esq->dir = new node;
    raiz->esq->dir->value = 7;
    raiz->dir->esq = new node;
    raiz->dir->esq->value = 1;
    raiz->dir->dir = new node;
    raiz->dir->dir->value = 0;
    arvore.root = raiz;
    arvore.pre_order();

    return 0;
}