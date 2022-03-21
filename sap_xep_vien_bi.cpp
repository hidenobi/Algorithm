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
void slove(){
    int n;
    cin >> n;
    cin.ignore();
    string s;
    cin >> s;
    map<char,int> m;
    for(auto i:s) m[i]++;
    int a=m['X'],b=m['T'],c=m['D'];
    int ans=0;
    // string s = XX...X[0->a),TT...T[a->a+b),DD...D[a+b,n)
    // duyet XX...X
    for(int i=0;i<a;i++){
        if(s[i]=='T'){
            bool ok=false;
            for(int j=a;j<a+b;j++){
                if(s[j]=='X'){
                    ok=true;
                    swap(s[i],s[j]);
                    ans++;
                    break;
                }
            }
            if(!ok){
                for(int j=a+b;j<n;j++){
                    if(s[j]=='X'){
                        // ok=true;
                        swap(s[i],s[j]);
                        ans++;
                        break;
                    }
                }
            }
        }
        else if(s[i]=='D'){
            bool ok=false;
            for(int j=a+b;j<n;j++){
                if(s[j]=='X'){
                    ok=true;
                    swap(s[i],s[j]);
                    ans++;
                    break;
                }
            }
            if(!ok){
                for(int j=a;j<a+b;j++){
                    if(s[j]=='X'){
                        // ok=true;
                        swap(s[i],s[j]);
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    for(int i=a;i<a+b;i++){
        if(s[i]=='D'){
            for(int j=a+b;j<n;j++){
                if(s[j]=='T'){
                    // ok=true;
                    swap(s[i],s[j]);
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans ;
}
int main(){
    int t=1;
    // cin >> t;
    while(t--){
        slove();
    }
    return 0;
}