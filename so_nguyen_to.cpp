#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int s,p,n,c[500],dem=0;
vector<int> v,res;
vector< vector<int> > b;
void Try(int sum,int n,int s,int i){
    if(sum==s&&res.size()==n){
        dem++;
        b.push_back(res);
        return;
    }
    if(sum>s||i==v.size()) return;
    for(int j=i;j<v.size();j++){
        if(sum+v[j]<=s){
            res.push_back(v[j]);
            Try(sum+v[j],n,s,j+1);
            res.pop_back();
        }
        else return;
    }
}
void slove(){
    dem=0;
    b.clear();
    v.clear();
    cin >> n >> p >> s;
    for(int i=p+1;i<=s;i++){
        if(!c[i]) v.push_back(i);
    }
    Try(0,n,s,0);
    cout << dem << '\n';
    sort(b.begin(),b.end());
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].size();j++) cout << b[i][j] <<" ";
        cout << "\n";
    }
}
int main(){
    c[0]=c[1]=1;
    for(int i=2;i*i<=300;i++){
        if(!c[i]){
            for(int j=i*i;j<=300;j+=i) c[j]=1;
        }
    }
    int test;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}