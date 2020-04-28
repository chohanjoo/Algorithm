# DFS

## 백준

### 11403. 경로찾기

#### 실패 코드

~~~c++
#include <iostream>
#include <map>
using namespace std;

int graph[101][101] = {
    0,
};

multimap<int, int> m;
int _count = 0;

void dfs(int init, int start)
{
    pair<map<int, int>::iterator, map<int, int>::iterator> iter_pair;
    multimap<int, int>::iterator iter;

    if (_count != 0 && init == start)
        return;

    iter_pair = m.equal_range(start);

    for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
    {
        graph[init][iter->second] = 1;
        ++_count;
        dfs(init, iter->second);
    }
}
int main()
{

    int n;
    char arr[101] = {
        0,
    };

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
            {
                m.insert(make_pair(i, j));
                arr[i] = 1;
            }
        }
    }

    for (int i = 0; i < 101; ++i)
    {
        if (arr[i] == 1)
        {
            _count = 0;
            dfs(i, i);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << graph[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
~~~



#### 다른사람 코드

~~~c++
#include <iostream>
#include <string.h>
using namespace std;
 
int arr[100][100]={0};
int visited[100]={0};
int n;
 
void dfs(int j){
    for(int k=0;k<n;k++){
        if(arr[j][k] && !visited[k]){
            visited[k]++;
            dfs(k);
        }
    }
}
int main(){
    
    cin>>n;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    
    for(int i=0;i<n;i++){
        memset(visited,0,sizeof(visited));
        dfs(i);
        
        for(int j=0;j<n;j++){
            if(visited[j])
                arr[i][j]=1;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        
        cout<<endl;
    }
    return 0;
}

~~~





### 9466. 텀 프로젝트

~~~c++
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
vector<int> s;
vector<int> v;
vector<int> f;
int dfs(int start, int current, int cnt)
{

    if(v[current]){
        if(f[current] != start)
            return 0;
        
        return cnt - v[current];
    }

    f[current] = start;
    v[current] = cnt;
    return dfs(start, s[current],cnt+1);
}
int main()
{

    int T;

    cin >> T;
    int n;
    for (int i = 0; i < T; ++i)
    {
        cin >> n;
        f = vector<int>(n + 1, 0);
        s = vector<int>(n + 1, 0);
        v = vector<int>(n+1, 0);
        // memset(visited,0,sizeof(visited));
        int result = 0;
        for (int j = 1; j <= n; ++j)
        {
            cin >> s[j];
        }

        for (int j = 1; j <= n; ++j)
        {
            if(!v[j]){
                result += dfs(j, j, 1);
            }
        }

        cout << n - result << "\n";
    }
    return 0;
}
~~~



### 1325. 효율적인 해킹

~~~c++
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
 
#define endl "\n"
#define MAX 10000 + 1
using namespace std;
 
int N, M, Num, Tmp_Answer;
bool Visit[MAX];
 
vector<int> Computer[MAX];
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Computer[b].push_back(a);
        // a가 b를 신뢰한다.
        // 즉, b를 해킹하면 a도 해킹할 수 있다.
    }
}
 
void DFS(int x)
{
    Visit[x] = true;
 
    for (int i = 0; i < Computer[x].size(); i++)
    {
        int nx =  Computer[x][i];
        
        if (Visit[nx] == false)
        {
            Num++;
            DFS(nx);
        }
    }
    
}
 
void Solution()
{
    vector<int> Answer;
    for (int i = 1; i <= N; i++)
    {
        memset(Visit, false, sizeof(Visit));
        Num = 0;
        DFS(i);
 
        if (Tmp_Answer == Num)
        {
            Answer.push_back(i);
        }
        else if (Tmp_Answer < Num)
        {
            Tmp_Answer = Num;
            Answer.clear();
            Answer.push_back(i);
        }
    }
 
    sort(Answer.begin(), Answer.end());
    for (int i = 0; i < Answer.size(); i++)
    {
        cout << Answer[i] << " ";
    }
    cout << endl;
}
 
void Solve()
{
    Input();
    Solution();
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



### 2468. 안전 영역

~~~c++
#include <iostream>
#include <string.h>

using namespace std;
int graph[100][100] = {
    0,
};
int visited[100][100] = {
    0,
};
int mx = 0;
int Num = 0;
int n;
typedef struct dir
{
    int x;
    int y;
} DIR;

DIR d[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y, int rain)
{
    if (graph[y][x] <= rain)
        return;
    visited[y][x] = 1;

    for (int i = 0; i < 4; ++i)
    {
        int nx = d[i].x + x;
        int ny = d[i].y + y;

        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            if (graph[ny][nx] > rain && visited[ny][nx] == 0)
            {
                dfs(nx, ny, rain);
            }
        }
    }
}
int main()
{
    int result = 0;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
            if (mx < graph[i][j])
                mx = graph[i][j];
        }
    }

    for (int i = 0; i <= mx; ++i)
    {
        memset(visited, 0, sizeof(visited));
        Num = 0;
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                if (graph[y][x] > i && visited[y][x] == 0)
                {
                    dfs(x, y, i);
                    ++Num;
                }
            }
        }
        if (result < Num)
            result = Num;
    }
    cout << result << "\n";

    return 0;
}
~~~



### 2842 . 집배원 한상덕

투포인터 알고리즘과 dfs의 합

set은 insert만 해도 자동 정렬된다.

~~~c++
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

int n, lo, hi, a[51][51], v[51][51];
int di[] = {0, 0, 1, -1, 1, 1, -1, -1}, dj[] = {1, -1, 0, 0, 1, -1, 1, -1};
struct pos
{
    int i, j;
};
vector<pos> K;

void dfs(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= n || v[i][j] || a[i][j] < lo || a[i][j] > hi)
        return;
    v[i][j] = 1;
    for (int d = 0; d < 8; ++d)
        dfs(i + di[d], j + dj[d]);
}

bool possible()
{
    int cnt = 0;
    for (int k = 0; k < K.size(); ++k)
        if (v[K[k].i][K[k].j])
            ++cnt;
    return cnt == K.size();
}

int main()
{
    pos P;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char t[51];
        cin >> t;
        for (int j = 0; j < n; ++j)
        {

            if (t[j] == 'P')
            {
                P.i = i;
                P.j = j;
            }
            else if (t[j] == 'K')
            {
                pos tmp = {i, j};
                K.push_back(tmp);
            }
        }
    }
    set<int> s;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
            s.insert(a[i][j]);
        }
    
    for(set<int>::iterator ll = s.begin() ;ll != s.end();++ll)
        cout << *ll << " ";
    cout << "\n";

    int result = 1e6;
    set<int>::iterator l = s.begin(), r = s.begin();
    while (r != s.end())
    {
        while (l != s.end())
        {
            memset(v, 0, sizeof(v));
            lo = *l;
            hi = *r;
            dfs(P.i, P.j);
            if (!possible())
                break;

            result = min(result, *r - *l);
            ++l;
        }
        ++r;
    }
    cout << result;
}
~~~

