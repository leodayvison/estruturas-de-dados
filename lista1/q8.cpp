#include <iostream>
#include <vector>
using namespace std;

class Deque{
    

    public:
    vector<int> data;
    int front, back, capacity;
    Deque(int n);
    void insert_front(int val);
    void insert_back(int val);
    void pop_front();
    void pop_back();
};

Deque::Deque(int n): data(n), front(0), back(n-1), capacity(n){}

void Deque::insert_front(int val){
    if (front > back) return;
    data[front] = val;
    front++;
}

void Deque::insert_back(int val){
    if (back < front) return;
    data[back] = val;
    back--;
}

void Deque::pop_front(){
    if (front == 0) return;
    front--;
}

void Deque::pop_back(){
    if (back == capacity-1) return;
    back++;
}

int main(){
    Deque d(10);
    d.insert_front(1);
    d.insert_back(10);
    d.insert_front(2);
    d.insert_back(9);
    d.pop_back();
    d.insert_back(3);

    cout << d.data[0] << ", " << d.data[1] << ", " << d.data[9] << ", " << d.data[8];

    return 0;
}