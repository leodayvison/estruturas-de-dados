/*
PRÉ-ORDEM
PÓS-ORDEM
EM-ORDEM
*/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int valor;
    node* pai;
    node* esq;
    node* dir;
};
/*
void pre_order(node* p){
    if (p == nullptr) return;
    cout << p->valor << " ";
    pre_order(p->esq);
    pre_order(p->dir);
}
*/
// TODO reescrever o algoritmo por pilha
void pre_order(node* p){
    if (p == nullptr) return;
}

void post_order(node* p){
    if (p == nullptr) return;
    post_order(p->esq);
    post_order(p->dir);
    cout << p->valor << " ";
}

void in_order(node* p){
    if (p == nullptr) return;
    in_order(p->esq);
    cout << p->valor << " ";
    in_order(p->dir);
}

void nivel_ordem(node* raiz){ //ajeitar a classe da arvore dps pra esse raiz ser um atributo
    if (raiz == nullptr) return;
    queue<node*> q;
    q.push(raiz);
    while(!q.empty()){
        node* p = q.front();
        q.pop();
        cout << p->valor << " ";
        if(p->esq != nullptr) q.push(p->esq);
        if(p->dir != nullptr) q.push(p->dir);
    }
}