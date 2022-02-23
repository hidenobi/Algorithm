#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void slove(){
    string s;
    cin >> s;
    do{
        cout << s << " ";
    } while (next_permutation(s.begin(),s.end()));
   cout << "\n";
    
}
int main(int argc, char const *argv[])
{
    int test=1;
    cin >> test;
    cin.ignore();
    while(test--){
        slove();
    }
    return 0;
}
