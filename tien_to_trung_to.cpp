#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;
long long mod = 1e9 + 7;
bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
            return true;
    }
    return false;
}
void slove(){
    string s;
    cin >> s;
    stack<string> st;
    int sz = s.size();
    for(int i=sz-1;i>=0;i--){
        if(isOperator(s[i])){
            string s1=st.top();st.pop();
            string s2=st.top();st.pop();
            // string tmp="("+s1+s[i]+s2+")"; // tiền tố-trung tố
            string tmp = s1+s2+s[i];    // tiền tố hậu tố
            st.push(tmp);
        }
        else {
            st.push(string(1,s[i]));
        }
    }
    cout << st.top() << "\n";
}
int main(){
    int t=1;
    cin >> t;
    cin.ignore();
    while(t--){
        slove();
    }
    return 0;
}