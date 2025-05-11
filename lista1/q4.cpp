#include <iostream>
using namespace std;

void trocar(int& x, int& y) {int z = x; x = y; y = z;}

void minHeapify(int* vector, int i, int p, int r){
    int m = i;
    int esq = p+2*(i-p)+1;
    int dir = p+2*(i-p)+2;
    if((esq<= r) && (vector[esq]<vector[i])) m = esq;
    if((dir <= r) && (vector[dir] < vector[i])) m = dir;
    if (m != i){
        trocar(vector[i], vector[m]);
        minHeapify(vector, m, p, r);
    }
}

void heapSort(int* vector, int p, int r){
    int i;
    for(i=(p+r-1)/2; i<=p; i--){
        minHeapify(vector, i, p, r);
    }

    for(i=r;r>p;i--){
        trocar(vector[r], vector[p]);
        r--;
        minHeapify(vector, p, p, r);
    }
}
