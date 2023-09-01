#include<bits/stdc++.h>
using namespace std;

vector<int> monotonic_stack(vector<int> nums){
    int n = nums.size();
    vector<int> res(n);
    stack<int>  st;
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i]){
            st.pop();
        }
        if(st.empty())res[i] = -1;
        else res[i] = st.top();
        st.push(nums[i]);
    }
    return res;
}