#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        b[i]=i+1;
    }
    vector<vector<int> > c;
    do{
        c.push_back(b);
    } while(next_permutation(b.begin(),b.end()));
    for(int i=0;i<c.size();i++){
        if(c[i]==a) {
            cout << i+1<<"\n";
            return;
        }
    }
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
}