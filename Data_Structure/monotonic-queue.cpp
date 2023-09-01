#include<bits/stdc++.h>
using namespace std;

class Monotonic_queue{
private:
    deque<int> qu;
public:
    void push(int n){
        while(!qu.empty()&&qu.back()<n){
            qu.pop_back();
        }
        qu.push_back(n);
    }
    int max(){
        return qu.front();
    }
    int min(){
        return qu.back();
    }
    int  size(){
        return qu.size();
    }
    void pop(){
        qu.pop_front();
    }
};