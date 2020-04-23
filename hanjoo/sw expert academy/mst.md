# 백준

## 1197. 최소 신장 트리

~~~c++
#include<iostream>
#include<vector>
#include<algorithm>
 
#define endl "\n"
#define MAX 10000 + 1
using namespace std;
 
int Vertex, E, Answer;
int Parent[MAX];
vector<pair<int, pair<int, int> > > V;
 
void Input()
{
    cin >> Vertex >> E;
    for(int i = 0; i < E; i++)
    {
        int From, To, Cost;
        cin >> From >> To >> Cost;
 
        V.push_back(make_pair(Cost, make_pair(From, To)));
    }
 
    sort(V.begin(), V.end());
}
 
int Find(int x)
{
    if (Parent[x] == x) return x;
    else return Parent[x] = Find(Parent[x]);
}
 
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
 
    if (x != y) Parent[y] = x;
}
 
bool SameParent(int x, int y)
{
    x = Find(x);
    y = Find(y);
 
    if (x == y) return true;
    else return false;
}
 
void Solution()
{
    for (int i = 1; i <= Vertex; i++)
    {
        Parent[i] = i;
    }
 
    for (int i = 0; i < E; i++)
    {
        if (SameParent(V[i].second.first, V[i].second.second) == false)
        {
            Union(V[i].second.first, V[i].second.second);
            Answer = Answer + V[i].first;
        }
    }
}
 
void Solve()
{
    Input();
    Solution();
 
    cout << Answer << endl;
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
~~~



참고 [블로그](https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html)

크루스칼 알고리즘으로 구현



# SW Expert Academy

## 1251. 하나로

MST 로 구현

~~~c++
#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

struct Edge
{
    ll start, end, cost;
    bool operator<(const Edge &other) const { return cost < other.cost; }
};

ll t, n, m, ans, p[1001], x[1001], y[1001];
double E;

ll Find(ll x) { return x == p[x] ? x : p[x] = Find(p[x]); }

void Union(ll x, ll y) { p[Find(x)] = Find(y); }

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    ll a = abs(x1 - x2), b = abs(y1 - y2);
    return a * a + b * b;
}

int main()
{
    scanf("%lld", &t);
    for (ll k = 1; k <= t; k++)
    {
        scanf("%lld", &n);
        for (ll i = 1; i <= n; i++)
            scanf("%lld", &x[i]);
        for (ll i = 1; i <= n; i++)
            scanf("%lld", &y[i]);
        scanf("%lf", &E);
        for (ll i = 1; i <= n; i++)
            p[i] = i;
        vector<Edge> a;
        for (ll i = 1; i <= n; i++)
            for (ll j = i + 1; j <= n; j++)
                a.push_back({i, j, dist(x[i], y[i], x[j], y[j])});
        sort(a.begin(), a.end());
        m = a.size(), ans = 0;
        for (ll i = 0; i < m; i++)
        {
            Edge e = a[i];
            ll x = Find(e.start), y = Find(e.end);
            if (x != y)
                Union(e.start, e.end), ans += e.cost;
        }
        printf("#%lld %.0f\n", k, ans * E);
    }
    return 0;
}
~~~



