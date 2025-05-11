#include <vector>
using namespace std;

class StackSimulator{
    vector<int> v;
    int countStack1, countStack2;
    int capacity;


    public:
    StackSimulator(int n);
    void push_back(int stack, int val);
    void pop(int stack);
};

StackSimulator::StackSimulator(int n): v(n), countStack1(0), countStack2(n-1), capacity(n){}


void StackSimulator::push_back(int stack, int val){
    if (stack != 1 && stack != 2) return;
    if (countStack1 > countStack2) return;

    if (stack == 1) {v[countStack1] = val; countStack1++;}
    if (stack == 2) {v[countStack2] = val; countStack2--;}
}

void StackSimulator::pop(int stack){
    if (stack == 1) {
        if (countStack1 > 0) countStack1--;
    } 
    else if (stack == 2) {
        if (countStack2 < capacity-1) countStack2++;  // Correção: incrementar para voltar
    }
}