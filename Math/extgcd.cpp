#include<bits/stdc++.h>
using namespace std;

int extgcd(int a,int b,int &x,int &y){//a*x +b*y = 1
    if(b==0){
        x = 1;
        y = 0;
        return a;  //到達遞歸邊界開始向上一層返回
    }
    int r = extgcd(b,a%b,x,y);
    int temp=y;    //把x y變成上一層的
    y = x - (a / b) * y;
    x = temp;
    return r;     //得到a b的最大公因數
}
int main(){
    int a = 55,b = 80;
    int x,y;//a*x+b*y = 1;
    int GCD = extgcd(a,b,x,y);
}