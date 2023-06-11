#include "iostream"
#include "vector"
#include "cmath"
#include "queue"
#include "cstring"
#include "unordered_set"
#include "stack"
#include "bitset"
#include "../head files/Nporan.h"

using namespace std;
/*
 * 中缀表达式转化为后缀表达式（逆波兰式）并计算数值
 * 仅支持基本四则运算
 */


int main(){
    auto temp = Split::split();
    cout<<"转化出的vector数组为： ";
    for (auto& p:temp) {
        cout<<p<<" ";
    }
    cout<<endl;
    auto tp = Solution::convert(temp);
    cout<<"转化出来的逆波兰数为： ";
    for (auto& p:tp) {
        cout<<p<<" ";
    }
    cout<<endl;
    auto ans = Polution::evalRPN(tp);
    cout<<"最终结果为： ";
    auto prec = cout.setf(ios_base::fixed,ios_base::floatfield);
    auto pre = cout.precision(5);//保留五位小数
    cout<<ans<<endl;
    cout.setf(prec,ios_base::floatfield);
    cout.precision(pre);//返回原来输出方式
}
