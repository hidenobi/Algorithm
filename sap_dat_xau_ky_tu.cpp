#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
void slove(){
    string s;
    cin >> s;
    map<char,int> m;
    int maxx=-1e8;
    for(auto i:s) {
        m[i]++;
        maxx=max(maxx,m[i]);
    }
    if(maxx>(s.size()+1)/2){
        cout << "-1\n";
        return;
    }
    cout << "1\n";
}
int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        slove();
    }
    return 0;
}