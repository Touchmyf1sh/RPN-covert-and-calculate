#include "Nporan.h"
using namespace std;

static string priori{"*/"};
static string inferior{"+-"};

 double Calculation::evalRPN(vector<string>& tokens) {
        stack<double> stk;
        int n = (int)tokens.size();
        for (int i = 0; i < n; i++) {
            string& token = tokens[i];
            if (is_a_realnumber(token)) {
                stk.push(stod(token));
            } else {
                double num2 = stk.top();
                stk.pop();
                double num1 = stk.top();
                stk.pop();
                switch (token[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }
        return stk.top();
    }

    bool Calculation::is_a_realnumber(const string & c) {
     bool flag = false;
     for(auto& p: c){
         if(p == '.') flag = true;
     }
        return isNumber(c) || flag;
 }

    bool Calculation::isNumber(const string& token) {//改进之后使用isdigit（）函数来挨个判断是否为一个数字
        if (token.empty()) {
            return false;
        }
        auto it = token.begin();
        if (*it == '-' || *it == '+') {
            ++it; // 跳过可选的负号或正号
        }
        return (it != token.end()) && all_of(it, token.end(), ::isdigit);
    }

bool Converting::smaller(char &a,char &b){
    if(b == '(') return false;//如果top为左括号就直接停止
    if(priori.find(a) != string::npos && inferior.find(b) != string::npos) return false;//a优先于b
    return true;//ab同级或者a小于b
}

vector<string> Converting::convert(vector<string>& target){
    int len = (int)target.size();
    vector<string> ans;
    stack<char> mystack;
    for (int i = 0; i < len; ++i) {
        auto temp = target[i];
        if(Calculation::is_a_realnumber(temp)) {
            ans.push_back(temp);
            continue;
        }
        if(mystack.empty()) {
            mystack.push(temp[0]);
            continue;
        }
        char a = temp[0];
        char top = mystack.top();
        switch (a) {
            case '(': {
                mystack.push(a);
            };
                break;
            case ')':{
                while(top != '('){
                    string s;
                    s = top;
                    ans.push_back(s);
                    mystack.pop();
                    top = mystack.top();
                }
                mystack.pop();//pop掉'（'
                break;
            }
            default:{
                while(smaller(a,top)){//当a优先级小于top时候，即这个时候top优先级大于等于a，我们的目的是弹出所有优先级大于等于a的
                    // ans.push_back(to_string(top));//这里应该是把char当作数字来转换为string了
                    string s;
                    s = top;
                    ans.push_back(s);
                    mystack.pop();
                    if(mystack.empty()) {
                        break;
                    }
                    top = mystack.top();
                }
                mystack.push(a);
            }
        }
    }
    while(!mystack.empty()){
        char temp = mystack.top();
        string s;
        s = temp;
        ans.push_back(s);
        mystack.pop();
    }
    return ans;
}

    vector<string> Split::split() {
        cout<<"Please enter your expression. Do not separate each number and character "
              "with spaces. Floating-point calculations are supported,\n and the result is "
              "rounded to 5 decimal places. If entering a negative number, please **make sure** enclose it "
              "in parentheses.\n Only basic arithmetic operations are supported."<<endl;
        string s;
        vector<string> ans;
        getline(cin,s);
        string temp;
        for (int i = 0;i<s.size();){
            temp.push_back(s[i]);
            if((isdigit(s[i]) || s[i] == '.') && (isdigit(s[i+1]) || s[i+1] == '.')){
                ++i;
            }else if(s[i] == '(' && s[i+1] == '-'){//出现负数
                temp.pop_back();
                int right = -1;
                for (int j = i+2; j < s.size(); ++j) {//寻找相匹配的"）"
                    if(s[j] == ')') {
                        right = j;
                        break;
                    }
                }
                if(right == -1) {
                    cout<<"wrong expression!"<<endl;
                    exit(1);
                }
                int num = right - i-1;
                temp=s.substr(i+1,num);
                ans.push_back(temp);
                temp.clear();
                i = right+1;
            }
            else{
                ans.push_back(temp);
                temp.clear();
                ++i;
            }
        }
        return ans;
 }
