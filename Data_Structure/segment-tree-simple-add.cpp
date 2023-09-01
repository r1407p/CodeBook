#include <bits/stdc++.h>
using namespace std;

struct node{
    int left;
    int right;
    int value;
};
vector<node> segment_tree;
void build(int left,int right,int x ,vector<int> & nums){
    segment_tree[x].left = left;
    segment_tree[x].right = right;
    // cout <<left <<" "<<right<<" "<<x<<endl;
    if(left == right){ // here is leaf
        segment_tree[x].value = nums[left];
        return;
    }
    int mid = (left+right)/2;
    build(left,mid,x<<1,nums);
    build(mid+1,right,x<<1|1,nums);
    segment_tree[x].value = segment_tree[x<<1].value+segment_tree[x<<1|1].value;
}
void modify(int position ,int x,int value){
    if(segment_tree[x].left == position && segment_tree[x].right ==position){ // here is leaf
        segment_tree[x].value = value;
        return;
    }
    int mid = (segment_tree[x].left+segment_tree[x].right)/2;
    
    if(position<=mid){
        modify(position,x<<1,value);
    }else{
        modify(position,x<<1|1,value);
    }
    segment_tree[x].value = segment_tree[x<<1].value+segment_tree[x<<1|1].value;
}
int query(int i,int j,int x){
    int res = 0;
    int left = segment_tree[x].left;
    int right = segment_tree[x].right;
    int mid = (left+right)/2;
    if(segment_tree[x].left==i && segment_tree[x].right ==j){
        return segment_tree[x].value;
    }
    if(i>mid)return query(i,j,x*2+1);
    if(mid>=j)return query(i,j,x*2);
    return query(i,mid,x*2)+ query(mid+1,j,x*2+1);
}