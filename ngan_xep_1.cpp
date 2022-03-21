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
    int n;
    string s;
    stack<int> st;
    while (cin >> s)
    {
        if (s == "push")
        {
            cin >> n;
            st.push(n);
        }
        else if (s == "pop")
            st.pop();
        else if (s == "show")
        {
            if (st.size())
            {
                stack<int> q;
                while (st.size())
                {
                    q.push(st.top());
                    st.pop();
                }
                while (q.size())
                {
                    cout << q.top() << " ";
                    st.push(q.top());
                    q.pop();
                }
                cout << endl;
            }
            else
                cout << "empty" << endl;
        }
    }
}
int main(){
    int t=1;
    // cin >> t;
    while(t--){
        slove();
    }
    return 0;
}