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
void slove(){
    string s;
    cin >> s;
    stack<double> st;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])) st.push(s[i]-'0');
        else{
            double s1=st.top();st.pop();
            double s2=st.top();st.pop();
            switch (s[i]){
                case '+':
                    st.push(s1+s2);
                    break;
                case '-':
                    st.push(s2-s1);
                    break;
                case '*':
                    st.push(s1*s2);
                    break;
                case '/':
                    st.push(s2/s1);
                    break;
            }
           
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