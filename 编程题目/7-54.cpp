#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> match_stack;  // 使用vector作为符号栈

// 检查当前右符号和栈顶符号是否匹配
void IfMatch(char left, char right) {
    if (match_stack.empty()) {  // 栈为空，缺少左符配对
        if (right == '>') {
            cout << "NO\n?-*/";
        } else {
            cout << "NO\n?-" << right;
        }
        exit(0);
    } else if (match_stack.back() == left) {  // 配对成功
        match_stack.pop_back();
    } else {  // 配对失败
        if (match_stack.back() == '<') {
            cout << "NO\n/*-?";
        } else {
            cout << "NO\n" << match_stack.back() << "-?";
        }
        exit(0);
    }
}

int main() {
    string str;
    
    while (cin >> str && str != ".") {
        for (size_t i = 0; i < str.length(); ++i) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                match_stack.push_back(str[i]);  // 左符号入栈
            } else if (str[i] == '/' && i + 1 < str.length() && str[i + 1] == '*') {
                match_stack.push_back('<');  // 注释符换成 < 入栈
                ++i;
            } else if (str[i] == ')') {
                IfMatch('(', str[i]);
            } else if (str[i] == ']') {
                IfMatch('[', str[i]);
            } else if (str[i] == '}') {
                IfMatch('{', str[i]);
            } else if (str[i] == '*' && i + 1 < str.length() && str[i + 1] == '/') {
                IfMatch('<', '>');
                ++i;
            }
        }
    }

    if (match_stack.empty()) {
        cout << "YES";
    } else {
        if (match_stack.back() == '<') {
            cout << "NO\n/*-?";
        } else {
            cout << "NO\n" << match_stack.back() << "-?";
        }
    }

    return 0;
}