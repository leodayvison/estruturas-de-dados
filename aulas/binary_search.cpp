#include <iostream>
using namespace std;

int binarySearch(int* v, int n, int x){
    int p = 1; 
    int r = n;
    while(p<=r){
        int q = (p+r)/2;
        if(v[q] == x) return q;
        if(v[q] < x) p = q + 1;
        if(v[q] > x) r = q - 1;
    }
    return -1;
}

int recursiveBinarySearch(int* v, int p, int r, int x){ // p = posicao inciial, r = posicao final
    if(p>r) return -1;
    
    int q = (p + r)/2;
    if (v[q] == x) return q;
    if(v[q] < x) return recursiveBinarySearch(v, q+1, r, x);
    if(v[q] > x) return recursiveBinarySearch(v, p, q-1, x);
}
