## 1861. 정사각형 방

~~~c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct dir
{
    int x;
    int y;
} Dir;

Dir d[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

int number;
int s;
int n;
int arr[1000][1000] = {
    0,
};

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second)
        return a.first < b.second;
    return a.second > b.second;
}
void dfs(int x, int y, int count, int start)
{

    for (int i = 0; i < 4; ++i)
    {
        int nx = d[i].x + x;
        int ny = d[i].y + y;

        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            if (arr[ny][nx] == arr[y][x] + 1)
            {
                dfs(nx, ny, count + 1, start);
            }
        }
    }
    if(number < count){
        number = count;
        s = start;
    }
    else if(number == count){
        if(s > start)
            s = start;
    }
    return;
}

int main()
{

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;

        s = number = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dfs(j, i, 1, arr[i][j]);
            }
        }

        cout << "#" << test_case << " " <<  s << " " << number << "\n";
    }
    return 0;
}
~~~



## 1258. 행렬찾기

~~~c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[100][100] = {
    0,
};
bool visited[100][100] = {
    false,
};
int col = 1;
int row = 1;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second * a.first == b.second * b.first)
        return a.first < b.first;
    return a.second * a.first < b.second * b.first;
}
void dfs(int x, int y)
{
    if (arr[y + 1][x] != 0)
    {
        visited[y + 1][x] = true;
        ++col;
        dfs(x, y + 1);
    }
    else if (arr[y][x + 1] != 0)
    {
        visited[y][x + 1] = true;
        ++row;
        dfs(x + 1, y);
    }
}
int main()
{
    int n;
    int T;
    vector<pair<int, int>> v;

    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        v.clear();

        for (int i = 0; i < 100; ++i)
        {
            for (int j = 0; j < 100; ++j)
            {
                visited[i][j] = false;
                arr[i][j] = 0;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j] && arr[i][j] != 0)
                {
                    visited[i][j] = true;
                    col = row = 1;
                    dfs(j, i);
                    v.push_back(make_pair(col, row));
                    for (int k = i; k < i + col; ++k)
                        for (int l = j; l < j + row; ++l)
                            visited[k][l] = true;
                }
            }
        }

        sort(v.begin(), v.end(), cmp);
        cout << "#" << test_case << " " << v.size() << " ";
        for (int z = 0; z < v.size(); ++z)
        {
            cout << v[z].first << " " << v[z].second << " ";
        }
        cout << "\n";
    }
    return 0;
}
~~~

