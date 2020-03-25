# 프로그래머스
## 구명보트
풀이 : 
1. people 을 오름차순으로 정렬
2. people 수만큼 순회한다
3. 가장 몸무게 큰 사람과 가장 몸무게 작은 사람을 더해 리미트를 넘는지 검사한다.
4. 리미트를 넘으면 가장 몸무게 큰 사람만 구출돼 answer 에 1을 더한다. 
5. 넘지 않으면 두사람이 구출되기 때문에 마지막 사람을 뜻하는 end에서 1을 빼준다.
6. 이를 i가 end보다 커질때까지 반복한다.
```
def solution(people, limit):
    answer = 0
    end =len(people) -1

    people = sorted(people,reverse=True)

    for i in range(len(people)):
        if i > end:
            break
        if people[i] + people[end] <= limit:
            answer += 1
            end -= 1
        else:
            answer+= 1

    return answer
```


## 숫자야구
1. 1~9 로 3자리 숫자를 만들 수 있는 순열을 구한다.
2. 순열과 주어지는 [숫자, s, b]  를 비교하며 제거한다.
3. 모든 case과 비교가 끝난 후 남은 리스트 개수를 리턴한다.
```
def st_B(given, chosen):
    st = 0
    B = 0
    chosen_dif = []
    given_dif = []
    for i in range(3):
        if given[i] == chosen[i]:
            st += 1
        else:
            given_dif.append(given[i])
            chosen_dif.append(chosen[i])
    for num in chosen_dif:
        if num in given_dif:
            B += 1
    return st, B

import itertools

def solution(baseball):
    first = list(itertools.permutations([1,2,3,4,5,6,7,8,9], 3))
    second = []
    for each in baseball:
        given = [int(i) for i in str(each[0])]
        stb = (each[1], each[2])
        for chosen in first:
            if st_B(given, chosen) == stb:
                second.append(chosen)
        first = second
        second = []
    return len(first)

```

## 타겟 넘버
DFS 문제
1. 경우의 수를 2가지로 나눔 (더하는 경우, 빼는 경우)
2. 모든 숫자를 순회했을 때 재귀를 멈춤 (이 때, evaluation이 target가 같으면 answer 증가)
3. 각 숫자를 더하거나 빼는 재귀를 작성

```
answer = 0
def solution(numbers, target):
    global answer
    
    dfs(numbers,0,0,target)
    return answer

def dfs(numbers, index, evaluation, target):
    global answer
    
    if index == len(numbers):
        if evaluation == target:
            answer += 1
        return;
    
    dfs(numbers, index+1, evaluation-numbers[index], target)
    dfs(numbers, index+1, evaluation+numbers[index],target)

    
```




```
def solution(name):
    answer = 0
    lists = []
    start = 0
    indexs = []
    
    for i,s in enumerate(name):
        if s != 'A':
            indexs.append(i)
    
    for i in range(len(indexs)-1):
        dist = indexs[i+1] - indexs[i]
        others = len(name)-1 - indexs[i+1] + indexs[i] +1
        answer += min([dist,others])
        
    for s in name:
        cal = ord(s) - ord('A')
        if cal >13:
            answer += 26 - cal
        else:
            answer += cal    
    
    
    return answer
```