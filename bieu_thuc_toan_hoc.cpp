#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
using namespace std;
bool ok;
vector<int> num(5);
int kq(int a,int b, char s){
    if(s=='+') return a+b;
    if(s=='-') return a-b;
    return a*b;
}
bool cmp(vector<int> a,string s){
    int m1=kq(a[0],a[1],s[0]);
    int m2=kq(m1,a[2],s[1]);
    int m3=kq(m2,a[3],s[2]);
    int m4=kq(m3,a[4],s[3]);
    return (m4==23);
}
void Try(string s,int i){
    if(i==4){
        if(cmp(num,s)){
            ok =true;
        }
        return;
    }
    Try(s+"+",i+1);
    Try(s+"-",i+1);
    Try(s+"*",i+1);
}
vector<int> Init(vector<int> pos, vector<int> a){
    vector<int>res;
    for(int i=0;i<5;i++){
        res.push_back(a[pos[i]-1]);
    }
    return res;    
}
void slove(){
    ok = false;
    vector<int> a(5);
    for(auto &i:a) cin >> i;
    vector<int> pos(5);
    for(int i=0;i<5;i++) pos[i]=i+1;
    do{
        num=Init(pos,a);
        Try("",0);
    } while(next_permutation(pos.begin(),pos.end()));
    if(ok==true) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}