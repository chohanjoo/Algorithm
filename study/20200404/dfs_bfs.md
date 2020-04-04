# baekjoon

## DFS와 BFS [1260]

### 내 풀이 - 런타임 에러 발생

~~~python
import queue
def input_f():
    n,m,start = map(int,input().split(' '))
    graph = []
    for i in range(m):
        x,y = map(int,input().split(' '))
        graph.append([x,y])
        
    return [graph,start]

def dfs(start,dicts):
    visit = []
    stack = []
    stack.append(start)
    
    while stack:
        v = stack.pop()
        if v not in visit:
            visit.append(v)
        for n in dicts[v]:
            if n not in visit:
                stack.append(n)
    
    return visit

def bfs(start,dicts):
    visit = []
    q = queue.Queue()
    
    q.put(start)
    
    while q.qsize() != 0:
        v = q.get()
        if v not in visit:
            visit.append(v)
        for n in dicts[v]:
            if n not in visit:
                q.put(n)
                
    return visit

if __name__ == "__main__":
    graph, start = input_f()
    dicts = {}
    for v in graph:
        if v[0] in dicts:
            dicts[v[0]].append(v[1])
        else :
            dicts[v[0]] = [v[1]]
            
        if v[1] in dicts:
            dicts[v[1]].append(v[0])
        else :
            dicts[v[1]] = [v[0]]
            
    for key in dicts:
        dicts[key] = sorted(dicts[key],reverse=True)
    
    _dfs = dfs(start,dicts)
    for key in dicts:
        dicts[key] = sorted(dicts[key])
    _bfs = bfs(start,dicts)
    
    d_s = ' '.join(str(s) for s in _dfs)
    b_s = ' '.join(str(s) for s in _bfs)
    print(d_s)
    print(b_s)
            
~~~

### 다른 사람 풀이

~~~python
from collections import deque

def DFS(graph, root):
    visited = []
    stack = [root]

    while stack:
        n = stack.pop()
        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort(reverse=True)
                stack += temp
    return " ".join(str(i) for i in visited)

def BFS(graph, root):
    visited = []
    queue = deque([root])

    while queue:
        n = queue.popleft()
        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort()
                queue += temp
    return " ".join(str(i) for i in visited)

  
graph = {}
n = input().split(' ')
node, edge, start = [int(i) for i in n]
for i in range(edge):
    edge_info = input().split(' ')
    n1, n2 = [int(j) for j in edge_info]
    if n1 not in graph:
        graph[n1] = [n2]
    elif n2 not in graph[n1]:
        graph[n1].append(n2)

    if n2 not in graph:
        graph[n2] = [n1]
    elif n1 not in graph[n2]:
        graph[n2].append(n1)

print(DFS(graph, start))
print(BFS(graph, start))
~~~



## 바이러스

~~~python
def input_f():
    com = int(input())
    n = int(input())
    graph = {i:[] for i in range(1,com+1)}
 
    for v in range(n):
        x, y = map(int,input().split(' '))
        graph[x].append(y)
        graph[y].append(x)

    return graph

def dfs(start,gragh):
    stack = [start]
    visit = []
    
    while stack:
        v = stack.pop()
        if v not in visit:
            visit.append(v)
            stack += list(set(graph[v]) - set(visit))
    return visit

if __name__ == "__main__":
    graph = input_f()
    _dfs = dfs(1,graph)
    print(len(_dfs)-1)
~~~



## 단지번호붙이기

~~~python
n = int(input())
visited = [[0]*(n) for i in range(n)]
graph = []
for _ in range(n):
    col = [int(i) for i in input()]
    graph.append(col)
direction = [[1,0],[0,1],[-1,0],[0,-1]]
result = []
def dfs(i,j):
    global count
    
    count += 1
    visited[i][j] = 1
    
    for d in direction:
        new_x = d[1] + j
        new_y = d[0] + i
        if new_x >=0 and new_x<n and new_y>=0 and new_y<n:
            if graph[new_y][new_x] == 1:
                if visited[new_y][new_x] == 0:
                    dfs(new_y,new_x)


for i in range(0,n):
    for j in range(0,n):
        if visited[i][j] == 0 and graph[i][j] ==1 :
            count = 0
            dfs(i,j)
            result.append(count)

print(len(result))
for i in sorted(result):
    print(i)
~~~



## 숨바꼭질

### 다른 사람 풀이 [블로그](https://velog.io/@devjuun_s/숨바꼭질-백준-1697번python)

BFS

~~~python
from collections import deque

def bfs(v):
    count = 0
    q = deque()
    q.append([5,0])
    while q:
        v = q.popleft()
        e = v[0]
        count = v[1]
        if not visited[e]:
            visited[e] = True
            if e == K:
                return count
            count += 1
            if (e * 2) <= 100000:
                q.append([e * 2, count])
            if (e + 1) <= 100000:
                q.append([e + 1, count])
            if (e - 1) >= 0:
                q.append([e - 1, count])
    return count
                
N, K = map(int, input().split())
visited = [False] * 100001
print(bfs(N))
~~~



BFS의 특징은 각 정점을 최단경로로 방문한다는 것이다. 이 점을 이용해 최단거리를 구해 보자

## 미로탐색

~~~python
from collections import deque
n,m = map(int,input().split(' '))
# graph = [['1', '0', '1', '1', '1', '1'], ['1', '0', '1', '0', '1', '0'], ['1', '0', '1', '0', '1', '1'], ['1', '1', '1', '0', '1', '1']]
graph = []
for _ in range(n):
    col = [ s for s in input()]
    graph.append(col)
visited = [[0]*m for _ in range(n)]
direction = [[0,1],[1,0],[0,-1],[-1,0]]
# print(visited)
# print(graph)
count = 0
def bfs():
    global count
    q = deque()
    q.append([0,0])
    visited[0][0] = 1
    
    while q:
        v = q.popleft()
        count +=1
        if v == [n,m]:
            return;
        for d in direction:
            nx = d[1] + v[1]
            ny = d[0] + v[0]

            if nx>=0 and nx<m and ny>=0 and ny<n:
                if visited[ny][nx] == 0 and graph[ny][nx] == '1':
                    q.append([ny,nx])
                    visited[ny][nx] = visited[v[0]][v[1]] +1
                
bfs()
print(visited[-1][-1])
~~~

