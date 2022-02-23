#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n,k;
    cin >> n >> k;
    cin.ignore();
    vector<string> a(n);
    for(auto &i:a){
        cin >> i;
    }
    sort(a.begin(),a.end());
    a.resize(distance(a.begin(),unique(a.begin(),a.end())));
    string s(a.size(),'0');
    for(int i=0;i<k;i++){
        s[i]='1';
    }
    do{
        for(int i=0;i<a.size();i++){
            if(s[i]=='1') cout << a[i] << " ";
        }
        cout << "\n";
    }while(prev_permutation(s.begin(),s.end()));
}
int main(){
    slove();
}