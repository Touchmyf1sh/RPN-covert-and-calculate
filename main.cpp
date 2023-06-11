#include "Nporan.h"

using namespace std;
/*
 * 中缀表达式转化为后缀表达式（逆波兰式）并计算数值
 * 仅支持基本四则运算
 */


int main(){
    auto temp = Split::split();
    cout<<"the splited string vector is： ";
    for (auto& p:temp) {
        cout<<p<<" ";
    }
    cout<<endl;
    auto tp = Converting::convert(temp);
    cout<<"the PRN expression is： ";
    for (auto& p:tp) {
        cout<<p<<" ";
    }
    cout<<endl;
    auto ans = Calculation::evalRPN(tp);
    cout<<"the final ans is： ";
    auto prec = cout.setf(ios_base::fixed,ios_base::floatfield);
    auto pre = cout.precision(5);//保留五位小数
    cout<<ans<<endl;
    cout.setf(prec,ios_base::floatfield);
    cout.precision(pre);//返回原来输出方式
}
