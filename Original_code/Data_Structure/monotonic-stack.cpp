/*
input: array A
ouput: array B
bi is the value aj such that j>i and aj>bi   (j)
ex:
A = [2,1,2,4,3]
B = [4,3,4,-1,-1
*/
#include<bits/stdc++.h>

using namespace std;

vector<int> monotonic_stack(vector<int> nums){
    int n = nums.size();
    vector<int> res(n);
    stack<int>  st;
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i]){
            st.pop();
            // we want the value greater than nums[i], so we pop the value smaller and equal nums[i]
        }
        if(st.empty())res[i] = -1;
        else res[i] = st.top();
        st.push(nums[i]);
    }
    return res;
}

int main(){
    vector<int> res = monotonic_stack({2,1,2,4,3});
    for(auto r:res){
        cout << r<<" ";
    }
}