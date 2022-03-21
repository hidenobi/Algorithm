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
    getline(cin,s);
    stack<char> st;
    for(auto i:s){
        if(i==')'){
            char top=st.top();
            st.pop();
            bool ok=true;
            while(!st.empty()&&top!='('){
                if(top=='+'||top=='-'||top=='*'||top=='/') ok=false;
                top=st.top();
                st.pop();
            }
            if(ok==true) {
                cout << "Yes\n";
                return;
            }
            
        }
        else st.push(i);
    }
    cout << "No\n";
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