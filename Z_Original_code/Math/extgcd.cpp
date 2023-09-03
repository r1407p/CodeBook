
#include<bits/stdc++.h>

using namespace std;

int extgcd(int a,int b,int &x,int &y)//擴展歐幾里得算法
{
    if(b==0)
    {
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
    int x,y;
    int GCD = extgcd(a,b,x,y);
    cout << "GCD: "<<GCD<<endl;;
    cout <<x<<" "<<y<<endl;
    cout <<a*x+b*y<<endl;
}