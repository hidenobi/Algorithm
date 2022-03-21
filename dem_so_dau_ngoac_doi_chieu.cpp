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
    stack<char> st;
    for(auto i:s){
        if(i==')'&&!st.empty()){
            if(st.top()=='(') st.pop();
            else st.push(i);
        }
        else st.push(i);
    }
    int sz=st.size();
    int n=0;
    while(!st.empty()&&st.top()=='('){
        st.pop();
        n++;
    }
    cout << sz/2+n%2 << "\n";
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