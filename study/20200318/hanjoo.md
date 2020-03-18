# 라인 코딩테스트 

## 1번


```python
def solution():
    m_s,q_s = map(int,input().split(' '))
    lists = []
    for i in range(q_s):
        lists.append(0)
        
    for i in range(m_s):
        message = int(input())
        index = lists.index(min(lists))
        lists[index] += message
    
    print(max(lists))

def find(lists):
    min_v = min(lists)
    
    for index,value in enumerate(lists):
        if min_v == value:
            return index

```

    5 2
    4
    3
    5
    2
    8
    14


### Test Case
5 2   
4   
3   
5   
2   
8   

## 3번


```python
lists = []
def solution():
    global lists
    count = int(input())
    array = [list(map(int, input().strip().split(' '))) for i in range(count)]
    array = sorted(array)
    
    for index,data in enumerate(array):
        res(array[index:], data[1], 0,1)

    if len(lists) == 0:
        print(1)
    else:
        print(max(lists))


def res(array, end, count, k):
    global lists
    if count == len(array) -1:
        lists.append(k)
        return 0
    

    if end > array[count+1][0]:
        res(array,array[count][1],count+1, k+1)
    else:
        lists.append(k)
```

    4
    0 10
    5 20
    11 15
    13 16
    3


### Test case
4   
0 10  
5 20  
11 15  
13 16  

## 4번


```python
def solution():
    lens = int(input())
    string = input().replace(" ","",lens-1)
    start = 0
    lists = []
    
    for index,s in enumerate(string):
        if s == '1':
            if start != 0:
                lists.append((index+1-start)//2)
                start = index+1
            else:
                lists.append(index)
                start = index+1
    if start != lens:
        lists.append(lens-start)
        
    print(max(lists))
    
```


```python
solution()
```

    9
    1 0 0 0 0 0 0 0 1
    4


### Test case
9   
0 0 0 1 0 0 0 0 0   
0 0 0 1 0 0 0 0 1   
1 0 0 1 0 0 0 0 0   
1 0 0 1 0 0 0 0 1   
