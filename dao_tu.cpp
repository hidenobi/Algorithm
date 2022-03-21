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
     string s, x = "";
        stack<string> st;
        getline(cin, s);
        s += ' ';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (x != "")
                {
                    st.push(x);
                    x = "";
                }
            }
            else
                x += s[i];
        }
        while (st.size())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
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