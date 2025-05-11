#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

struct node{
    int valor;
    node* prox;
};

class Lista{
    node* inicio;
    node* fim;

    public:
    Lista(){
        inicio = nullptr;
        fim = nullptr;
    }
    
    ~Lista(){
        apaga_tudo();
    }

    void insere_no_inicio(int k){
        node* q = new node;
        q -> valor = k;
        q -> prox = inicio;
        inicio = q;
        if(fim==nullptr) fim=q;
    }

    void insere_na_frente(node* p, int k){
        if(p == nullptr) return;
        node* q = new node;
        q -> valor = k;
        q -> prox = p -> prox;
        p -> prox = q;
        if(p == fim) fim = q;
    }

    void insere_no_fim(int k){

        if(inicio == nullptr){
            insere_no_inicio(k);
        } else {
            insere_na_frente(fim, k);
        }

    }

    void apaga_da_frente(node* p){
        if (p == nullptr) return;
        if (p->prox == nullptr) return;
        node* q = p->prox;
        p->prox = q->prox;
        delete q;
        if (fim == q) fim = p;
    }

    void apaga_primeiro(){
        if (inicio == nullptr) return;
        node* q = inicio->prox;
        delete inicio;
        inicio = q;
        if(inicio == nullptr) fim = nullptr;
    }

    void apaga_tudo(){
        while (inicio != nullptr) {
            apaga_primeiro();
        }
    }

    node* busca(int k){
        node* p = inicio;
        while (p != nullptr){
            if (p->valor == k) return p;
            p = p->prox;
        }
        return nullptr;
    }

    void imprime(){
        node* p = inicio;
        while (p != nullptr){
            cout << p->valor << " ";
            p = p->prox;
        }
    }

    bool vazia(){
        if (inicio==nullptr) return true;
        return false;
    }
    void invertList(Lista list){
        if (inicio == fim) return;

        node* p = inicio;
        node* q = inicio->prox;
        node* r = inicio->prox->prox;

        while(r != nullptr){
            q->prox = p;
            p = q;
            q = r;
            r = r->prox;
        }
        fim = inicio;
        inicio = q;
        
    }
};

