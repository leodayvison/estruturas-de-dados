#include <iostream>
#include <queue>
using namespace std;

struct node {
    char value;
    node* pai;
    node* fEsq;
    node* iDir;
};

class tree{
    node* root;
    void erase(node* p);
    void pre_order(node* p);
    void post_order(node* p);
    node* subtree(string& s, int& i);

    public:
    tree(string s);
    ~tree();
    void apaga_tudo();
    void pre_order();
    void post_order();
    void level_order();
};

void tree::pre_order(node* p){
    if (p==nullptr) return;
    cout << p -> value << " ";
    node* q = p ->fEsq;
    while (q != nullptr){
        pre_order(q);
        q = q ->iDir;
    }
}

void tree::post_order(node* p){
    if (p==nullptr) return;
    node* q = p -> fEsq;
    while (q != nullptr){
        post_order(q);
        q = q->iDir;
    }
    cout <<  p->value << " ";
}

void tree::level_order(){
    if (root==nullptr) return;
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()){
        node* p = Q.front();
        Q.pop();
        if (p==nullptr) continue;
        cout << p -> value << " ";
        p = p -> fEsq;
        while (p != nullptr){
            Q.push(p);
            p = p -> iDir;
        } 
    }
}

void tree::erase(node* p){
    if (p==nullptr) return;
    erase(p->iDir);
    p -> iDir = nullptr; // talvez não seja necessário, só pira do professor
    erase(p->fEsq);
    p -> fEsq = nullptr; //                     ""
    delete(p);
}

node* tree::subtree(string& s, int& i){
    while (i < s.size() && ((s[i] == '(') || (s[i] == ' '))) i++;
    if ((i >= s.size()) || (s[i] == ')')) {
        i++;
        return nullptr;
    }
    node* p = new node;
    p -> value = s[i++];
    node* q = subtree(s, i);
    p -> fEsq = q;
    while (q != nullptr){
        q -> pai = p;
        node* r = subtree(s, i);
        q -> iDir = r;
        q = r;
    }
    return p;
}