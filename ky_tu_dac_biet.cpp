#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
long long len[100];
char Try(long long n, long long res, string s){
    if(res==1) return s[--n];
    long long mid=len[res]/2;
    if(n<=mid) return Try(n,res-1,s);
    if(n==mid+1) return Try(len[res-1],res-1,s);
    return Try(n-(mid+1),res-1,s);
}
void slove(){
    string s;
    long long n;
    cin >> s;
    cin >> n;
    if(s.size()==1){
        cout << s << "\n";
        return;
    }
    long long res;
    len[1]=(long long) s.size();
    for(int i=2;;i++){
        len[i]=len[i-1]*2;
        if(len[i]>=n){
            res=i;
            break;
        }
    }
    cout << Try(n,res,s) << "\n";
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        cin.ignore();
        slove();
    }
    return 0;
}