#include <bits/stdc++.h>
using namespace std;

class BIT{
public:
    vector<int> bit;
    int N;
    BIT(int n){
        this->N = n;
        this->bit.resize(n);
    }
    void update(int x,int d){
        while(x<=N){
            bit[x] +=d;
            x +=x&(-x);// lowest bit in x;
        }
    }
    int query(int x){
        int res = 0;
        while(x){
            res+= bit[x];
            x -= x& -x;
        }
        return res;
    }
};  
// Driver program to test above functions
int main()
{
    vector<int> freq =  {0, 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = freq.size();
    BIT bit(n);
    for(int i = 1;i<n;i++){
        bit.update(i,freq[i]);
    }
    for(int i = 1;i<n;i++){
        cout << bit.query(i)<<" ";
    }cout << endl;
    for(int i = 1;i<n;i++){
        bit.update(i,-1);
    }
    for(int i = 1;i<n;i++){
        cout << bit.query(i)<<" ";
    }cout << endl;
}