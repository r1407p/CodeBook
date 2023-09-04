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