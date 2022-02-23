#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n;
int check(string s){
    if(s.back()!='6') return 0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='8'&&s[i+1]=='8') return 0;
    }
    for(int i=0;i<s.size()-3;i++){
        if(s[i]=='6'&&s[i+1]=='6'&&s[i+2]=='6'&&s[i+3]=='6') return 0;
    }
    return 1;
}
void in(string s){
    cout << s << "\n";
}
void Try(string s){
    if(s.size()==n){
        if(check(s)==1) in(s);
    }
    else {
        Try(s+"6");
        Try(s+"8");
    }
}
void slove(){
    cin >> n;
    Try("8");
}
int main(){
    slove();
    return 0;
}