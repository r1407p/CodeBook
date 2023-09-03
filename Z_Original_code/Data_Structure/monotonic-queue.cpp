//ref:leetcode 
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

vector<int> maxSlidingWindow(vector<int> nums, int k) {
    Monotonic_queue window;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) {
            window.push(nums[i]);
        } else {
            window.push(nums[i]);
            res.push_back(window.max());
            if(window.max() == nums[i-k+1]){
                window.pop();
            }
            
        }
    }
    return res;

}
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums,k);
    for (auto r:res)cout <<r <<" ";
}