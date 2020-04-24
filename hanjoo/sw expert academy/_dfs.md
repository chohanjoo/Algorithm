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

