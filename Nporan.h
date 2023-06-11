//
// Created by 谢川峰 on 2023/6/11.
//

#ifndef PRACTICE_NPORAN_H
#define PRACTICE_NPORAN_H
#include "iostream"
#include "vector"
#include "string"
using namespace std;

class Solution{//用于将中缀转后缀
public:
    static bool smaller(char&,char&);
    static vector<string> convert(vector<string>&);
};


class Polution{//用于后缀计算
public:
    static double evalRPN(vector<string>&);
    static bool isNumber(const string&);
    static bool is_a_realnumber(const string &c);
};

class Split{
public:
    static vector<string> split();//读取输入并转化为string数组，注意不支持负数
};

#endif //PRACTICE_NPORAN_H
