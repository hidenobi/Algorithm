#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    string s;
    cin >> s;
    vector<int> open;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
            open.push_back(i);
    }
    int cur = 0, ans = 0, pos = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
        {
            cur++;
            pos++;
        }
        else if (s[i] == ']')
            cur--;
        if (cur < 0)
        {
            ans += open[pos] - i;
            swap(s[i], s[open[pos]]);
            cur = 1;
            pos++;
        }
    }
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}