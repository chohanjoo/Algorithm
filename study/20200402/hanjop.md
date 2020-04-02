## 피보나치 수

### 내 풀이

~~~python
def solution(n):
    pre_v = 0
    v = 1

    if n < 3:
        return n

    for i in range(n-1):
        temp = v
        v += pre_v
        pre_v =temp

    return v%1234567
~~~



### 다른 사람 풀이

~~~python
def fibonacci(num):
    a,b = 0,1
    for i in range(num):
        a,b = b,a+b
    return a
~~~



## 폰켓몬

~~~python
def solution(nums):
    answer = 0
    dicts = {}
    for n in nums:
        if n in dicts:
            dicts[n] += 1
        else :
            dicts[n] = 1

    if len(dicts) > len(nums) / 2:
        answer = len(nums) / 2
    else :
        answer = len(dicts)
    return answer
~~~



---

### 다른 사람 풀이

```python
def solution(ls):
    return min(len(ls)/2, len(set(ls)))
```

set() 자료형을 알았으면 더 간단하다



## 행렬의 곱셈

~~~python
def solution(arr1, arr2):
    answer = []

    for i in range(len(arr1)):
        line = []
        for j in range(len(arr2[0])):
            result = 0
            for k in range(len(arr1[i])):
                result += arr1[i][k] * arr2[k][j]
            line.append(result)
            result = 0
        answer.append(line)

    return answer

~~~

### 다른 사람 풀이

~~~python
def productMatrix(A, B):
    return [[sum(a*b for a, b in zip(A_row,B_col)) for B_col in zip(*B)] for A_row in A]

# 아래는 테스트로 출력해 보기 위한 코드입니다.
a = [ [ 1, 2 ], [ 2, 3 ]];
b = [[ 3, 4], [5, 6]];
print("결과 : {}".format(productMatrix(a,b)));

~~~



## [3차] 파일명 정렬

### 내 풀이

~~~python
def solution(files):
    answer = []
    for file in files:
        flag = False
        split = {'HEAD' : "", 'NUMBER' :'', "TAIL" : ''}

        for i,c in enumerate(file):

            if c >= '0' and c<='9' and flag == False:
                flag = True
                split['HEAD'] = file[:i]
                split['NUMBER'] = c                
            elif flag == True and (c < '0' or c > '9'):
                split['TAIL'] = file[i:]
                break
            elif c >= '0' and c<='9' and flag == True:
                split['NUMBER'] += c

        answer.append(split)

    answer = sorted(answer, key=lambda x: (x['HEAD'].lower(),int(x['NUMBER'])))
    answer = [x['HEAD']+x['NUMBER']+x['TAIL'] for x in answer]


    return answer
~~~



### 다른 사람 풀이

~~~python
import re

def solution(files):
    a = sorted(files, key=lambda file : int(re.findall('\d+', file)[0]))
    b = sorted(a, key=lambda file : re.split('\d+', file.lower())[0])
    return b
~~~

