#include<bits/stdc++.h>
using namespace std;

int priority (char ch) {
    if(ch == '-' || ch == '+')return 1;
    else if(ch == '*' || ch == '/') return 2; 
    else if (ch == '^')return 3;
    else return 0;
}

string convert(string& s){
    string ans;
    stack<char> st;

    for(char ch: s){
        if((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9')){
            ans = ans + ch;
        } else if (ch == '('){
            st.push(ch);
        } else if (ch == ')'){
            while(!st.empty() && st.top() != '('){
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }  else { // Operator
            while (!st.empty() && 
                   (priority(ch) < priority(st.top()) || 
                   (priority(ch) == priority(st.top()) && ch != '^'))) { 
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()) {
        ans = ans + st.top();
        st.pop();
    }

    return ans;
}

string infix2Prefix(string s){
    //reverse
    reverse(s.begin(), s.end());

    // changing the brackets
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    s = convert(s);

    //reverse
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string s;
    getline(cin, s);
    cout << infix2Prefix(s);
    return 0;
}