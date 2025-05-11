#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    char value;
    node* father;
    vector<node*> son;
};

class tree{
    node* root;
    void pre_order(node* p);
    void post_order(node* p);
    void erase(node* p);
    node* subtree(string& s, int& i);

    public:
    tree(string s);
    ~tree();
    void erase_all();
    void pre_order();
    void post_order();
    void level_order();
    void pre_order_nonrec(); // nao recursiva 
};

void tree::pre_order(node* p){
    if (p == nullptr) return;
    cout << p -> value << " ";
    for (int i = 0; i < p->son.size(); i++){
        pre_order(p->son[i]);
    }
}

void tree::post_order(node* p){
    if (p == nullptr) return;
    for (int i = 0; p -> son.size(); i++){
        post_order(p->son[i]);
    }
    cout << p -> value << " ";
}

void tree::level_order() {
    if(root == nullptr) return;
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()){
        node* p = Q.front();
        Q.pop();
        if (p == nullptr) continue;
        cout << p->value << " ";
        for(int i = 0; i<p->son.size(); i++){
            Q.push(p->son[i]);
        }
    }
}