#include <iostream>
using namespace std;

void maxHeapify(int* vector, int n, int i){ 
    int m = i; // maximo
    int esq = 2*i + 1;
    int dir = (i+1)*2;
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

void heapSort(int* vector, int n){
    buildMaxHeap(vector, n);
    for(int k=n; k>=2; k--){
        swap(vector[1], vector[k]);
        maxHeapify(vector, k-1, 1);
    }
}

void swap(int &x, int &y){
    int z = x;
    x=y;
    y=z;
}