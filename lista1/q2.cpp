#include <iostream>
#include <vector>
using namespace std;

int buscaBinariaImpares(vector<int> v, int x){
    int r, p = 1;
    if(v.size()%2 != 0) r = v.size();
    else r = v.size() - 1;

    while(p <= r){
        int q = (p+r)/2;
        if(v[q] == x) return v[q];
        if(v[q] < x) p = q + 2;
        if(v[q] > x) r = q - 2;
    }
    return -1;
}

int buscaBinariaPares(vector<int> v, int x){
    int r, p=0;
    if(v.size()%2 == 0) r = v.size();
    else r = v.size() + 1; //TERMINAR A PARTIR DAQUI

    while (p <= r){
        int q = (p+r)/2;
        if(v[q] == x) return v[q];
        if(v[q] < x) p = q + 2;
        if(v[q] > x) r = q - 2;
    }
    return -1;
}



int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(50);
    v.push_back(2);
    v.push_back(40);
    v.push_back(3);
    v.push_back(30);
    v.push_back(4);
    v.push_back(20);
    v.push_back(5);
    v.push_back(10);

    
    // 3, 8, 6

    cout <<buscaBinariaPares(v, 2) << " " << buscaBinariaImpares(v, 2);
}