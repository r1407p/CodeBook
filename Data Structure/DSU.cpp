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