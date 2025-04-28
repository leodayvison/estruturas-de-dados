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

    void inverte(){
        if (inicio == fim) return; // nulo ou só tem 1 elemento
        
        node* p = inicio;
        node* q = p->prox;
        node* r = q->prox;

        inicio->prox = nullptr;
        while (q != nullptr){
            q->prox = p;
            p = q;
            q = r;
            if (r != nullptr) r=r->prox;
        }
        fim = inicio;
        inicio = p;
    }
};


int main(){
    Lista lista = Lista();
    lista.insere_no_inicio(1);
    lista.insere_no_inicio(2);
    lista.insere_no_inicio(3);

    lista.imprime();


    return 0;
}