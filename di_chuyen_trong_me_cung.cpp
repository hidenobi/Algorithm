#include<iostream>
#include<vector>   
#include<algorithm>
using namespace std;
int n;
int a[20][20];
vector<string> v;
void Try(string s, int i,int j){
    if(a[i][j]==0) return;
    if(i==n-1&&j==n-1){
       v.push_back(s);
       return;
    }
    if(a[i+1][j]==1) Try(s+"D",i+1,j);
    if(a[i][j+1]==1) Try(s+"R",i,j+1);
    if(a[i+1][j]==0&&a[i][j+1]==0) return;

}
void slove(){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            a[i][j]=0;
        }
    }
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    Try("",0,0);
    if(v.size()==0) {
        cout << "-1\n";
        return;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n";
    v.clear();
}
int main(){
    int test=1;
    cin >> test;
    while(test--) slove();
    return 0;
}
