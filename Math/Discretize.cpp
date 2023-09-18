void __solve(vector<int> u){
    sort(ALL(u));
    u.resize(unique(ALL(u))-u.begin());
    vi nums(u.size()+50,0);
    vi discrete(u.size()+50);
    
    for(int i =0;i<u.size();i++){
        discrete[i] = upper_bound(ALL(u),u[i])-u.begin();
        cout << u[i]<<" "<<discrete[i]<<endl;
    }
}
signed main(){
    vector<int> u = {4,13,14,152312,12314,31234,123,3};
    __solve(u);
}