#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> v;
string s;
int n;
void Try(string a){
    if(a.size()==n){
        string b="";
        for(int j=0;j<a.size();j++){
            if(a[j]=='1') b+=s[j];
        }
        v.push_back(b);
    } 
    else{
        Try(a+"0");
        Try(a+"1");
    }
}
void slove(){
    cin >> n;
    cin.ignore();
    cin >> s;
    v.clear();
    Try("");
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) cout << v[i] << " ";
    cout << "\n";
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}