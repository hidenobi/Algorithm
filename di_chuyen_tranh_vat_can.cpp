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
long long mod = 1e9 + 7;
struct Node
{
    int row, col;
    int count;
};
void slove(){
    int n;
    cin >> n;
    char mat[n + 1][n + 1];
    bool vis[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a++, b++, c++, d++;
    memset(vis, false, sizeof(vis));
    Node mid;
    mid.row = a, mid.col = b, mid.count = 0;
    queue<Node> q;
    q.push(mid);
    vis[a][b] = true;
    while (!q.empty())
    {
        Node temp = q.front();
        q.pop();
        if (temp.row == c && temp.col == d)
        {
            cout << temp.count << "\n";
            return;
        }
        // Down
        for (int i = temp.row; i <= n; i++)
        {
            if (mat[i][temp.col] == 'X')
                break;
            if (!vis[i][temp.col])
            {
                Node m;
                m.row = i, m.col = temp.col, m.count = temp.count + 1;
                q.push(m);
                vis[i][temp.col] = true;
            }
        }
        // Up
        for (int i = temp.row; i > 0; i--)
        {
            if (mat[i][temp.col] == 'X')
                break;
            if (!vis[i][temp.col])
            {
                Node m;
                m.row = i, m.col = temp.col, m.count = temp.count + 1;
                q.push(m);
                vis[i][temp.col] = true;
            }
        }
        // Right
        for (int i = temp.col; i <= n; i++)
        {
            if (mat[temp.row][i] == 'X')
                break;
            if (!vis[temp.row][i])
            {
                Node m;
                m.row = temp.row, m.col = i, m.count = temp.count + 1;
                q.push(m);
                vis[temp.row][i] = true;
            }
        }
        // Left
        for (int i = temp.col; i > 0; i--)
        {
            if (mat[temp.row][i] == 'X')
                break;
            if (!vis[temp.row][i])
            {
                Node m;
                m.row = temp.row, m.col = i, m.count = temp.count + 1;
                q.push(m);
                vis[temp.row][i] = true;
            }
        }
    }
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}