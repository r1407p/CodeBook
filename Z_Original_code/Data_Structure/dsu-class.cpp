#include <bits/stdc++.h>

using namespace std;
 
class DSU{
    public:
    DSU(int n ){
        this->n = n;
        reset();
    }
    int n;
    vector<int> boss;
    vector<int> rank;
    vector<int> size;

    void reset(){
        this->boss.resize(n);
        this->rank.resize(n,0);
        this->size.resize(n,0);
        for(int i =0;i<n;i++){
            boss[i] = i;
        }
    }
    int find(int x){
        if(boss[x]!= x){
            boss[x] = find(boss[x]);
        }
        return boss[x];
    }
    int get_size(int x){
        return size[find(x)];
    }
    void merge(int x, int y){
        int a = find(x);
        int b = find(y);
        // if(a!=b){
        //     boss[a] = b;
        //     size[b] += size[a]; 
        // }
        if(a!=b){
            if(rank[a]<rank[b]){
                boss[a] = b;
                size[b] += size[a];
            }else if (rank[a]<rank[b]){
                boss[b] = a;
                size[a] += size[b];
            }else{
                boss[a] = b;
                size[b] += size[a];
                rank[b]++;
            }
        }
    }
    bool aresame(int a,int b){
        return find(a)==find(b);
    }
};
int main(){
    DSU dsu(10);

    dsu.merge(0, 1);
    dsu.merge(2, 3);
    dsu.merge(4, 5);
    dsu.merge(6, 7);

    cout << "Are 0 and 1 connected? " << (dsu.aresame(0, 1) ? "Yes" : "No") << endl;
    cout << "Are 2 and 3 connected? " << (dsu.aresame(2, 3) ? "Yes" : "No") << endl;
    cout << "Are 4 and 5 connected? " << (dsu.aresame(4, 5) ? "Yes" : "No") << endl;
    cout << "Are 6 and 7 connected? " << (dsu.aresame(6, 7) ? "Yes" : "No") << endl;
    cout << "Are 1 and 2 connected? " << (dsu.aresame(1, 2) ? "Yes" : "No") << endl;

    dsu.merge(1, 2);

    cout << "Are 0 and 2 connected? " << (dsu.aresame(0, 2) ? "Yes" : "No") << endl;
    cout << "Are 1 and 3 connected? " << (dsu.aresame(1, 3) ? "Yes" : "No") << endl;

    return 0;
}