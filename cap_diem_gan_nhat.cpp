#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Point
{
    int x, y;
};
bool cmp(Point a, Point b)
{
    return (a.x < b.x);
}
double Distance(Point a, Point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}
double Brute_Force(Point x[], int n)
{
    double res = DBL_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            res = min(res, Distance(x[i], x[j]));
    }
    return res;
}
double ClosestTemp(Point temp[], int len, double d)
{
    double res = d;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len && (temp[j].y - temp[i].y) < res; j++)
            res = min(res, Distance(temp[i], temp[j]));
    }
    return res;
}
double Closest(Point Px[], int n)
{
    if (n <= 3)
        return Brute_Force(Px, n);
    int mid = n / 2;
    Point midPoint = Px[mid];
    double dl = Closest(Px, mid);
    double dr = Closest(Px + mid, n - mid);
    double d = min(dl, dr);
    Point temp[n];
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(Px[i].x - midPoint.x) < d)
            temp[len++] = Px[i];
    }
    return ClosestTemp(temp, len, d);
}
void Solve()
{
    int n;
    cin >> n;
    Point a[n], Px[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        Px[i] = a[i];
    }
    sort(Px, Px + n, cmp);
    cout << fixed << setprecision(6) << Closest(Px, n) << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}