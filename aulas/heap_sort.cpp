#include <iostream>
using namespace std;

void maxHeapify(int* vector, int n, int i){ // TODO adaptar considerando primeiro indice 0
    int m = i; // maximo
    int esq = 2*i;
    int dir = 2*i + 1;
    if (esq <= n && vector[esq] > vector[i]){
        m = esq;
    }
    if (dir <= n && vector[dir] > vector[m]){
        m = dir;
    }
    if (m != i){
        int aux = vector[i];
        vector[i] = vector[m];
        vector[m] = aux;
    }
    maxHeapify(vector, n, m);
}

void buildMaxHeap (int* vector, int n){
    for (int i = n/2; i>=1; i--){
        maxHeapify(vector, n, i);
    }
}