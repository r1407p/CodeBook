class SegmentTree{
private:
    const int n;
    const vl arr;
    // vl st;
    vl summ;
    vl minn;
    vl maxx;
    vl tag;
    void pull(int l,int r,int v){
        if(r-l==1)
            return;
        // st[v]=st[2*v+1]+st[2*v+2];
        int mid=(l+r)/2;
        push(l,mid,2*v+1);
        push(mid,r,2*v+2);
        summ[v]=summ[2*v+1]+summ[2*v+2];
        // minn[v]=min(minn[2*v+1],minn[2*v+2]);
        // maxx[v]=max(maxx[2*v+1],minn[2*v+2]);
    }
    void push(int l,int r,int v){
        summ[v]+=tag[v]*(r-l);
        if(r-l==1)
            return tag[v]=0,void();
        tag[2*v+1]+=tag[v];
        tag[2*v+2]+=tag[v];
        tag[v]=0;
    }
    void build(int l,int r,int v=0){
        if(r-l==1){
            summ[v]=arr[l];
            // summ[v]=minn[v]=maxx[v]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*v+1);
        build(mid,r,2*v+2);
        pull(l,r,v);
    }

public:
    SegmentTree(vl&_arr,int _n):arr(_arr),n(_n){
        assert(arr.size()==n);
        summ.assign(4*n,0);
        // minn.assign(4*n,1e9);
        // maxx.assign(4*n,-1e9);
        tag.assign(4*n,0);
        build(0,arr.size());
    }
    void modify(int x,int val,int l,int r,int v=0){

    }
    // query sum
    loli query(int L,int R,int l,int r,int v=0){
        // dbn(L,R,l,r,v)
        push(l,r,v);
        if(l==L && R==r){
            return summ[v];
            return minn[v];
            return maxx[v];
        }
        int mid=(l+r)/2;
        if(R<=mid)
            return query(L,R,l,mid,2*v+1);
        else if(mid<=L)
            return query(L,R,mid,r,2*v+2);
        else
            return query(L,mid,l,mid,2*v+1)+query(mid,R,mid,r,2*v+2);
    }
    // plus `val` to every element in [L,R)
    void update(int L,int R,loli val,int l,int r,int v=0){
        // dbn(L,R,l,r,v)
        push(l,r,v);
        if(l==L && R==r){
            tag[v]+=val;
            push(l,r,v);
            return;
        }
        int mid=(l+r)/2;
        if(R<=mid)
            update(L,R,val,l,mid,2*v+1);
        else if(mid<=L)
            update(L,R,val,mid,r,2*v+2);
        else
            update(L,mid,val,l,mid,2*v+1),update(mid,R,val,mid,r,2*v+2);
        pull(l,r,v);
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    vl arr(n);
    for(auto&x:arr)
        cin>>x;
    SegmentTree st(arr,n);
    while(q--){
        int op=0;
        // str op;
        cin>>op;
        if(op&1){
            loli l,r,val;
            cin>>l>>r>>val;
            assert(r>=l);
            st.update(l-1,r,val,0,n);
            // loli k,u;
            // cin>>k>>u;
            // st.update(k-1,k,u-arr[k-1],0,n);
            // arr[k-1]=u;
        }else{
            int x,y;
            cin>>x>>y;
            assert(y>=x);
            cout<<st.query(x-1,y,0,n)<<endl;
        }
    }
}