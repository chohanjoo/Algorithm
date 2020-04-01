## 다음 큰 숫자

### 내 풀이

~~~python
def solution(n):
    answer = 0
    n_2 = []
    while n:
        n_2.append(n%2)
        n //= 2

    # n_2 = n_2[::-1]
    print(n_2.count(1))
    count = n_2.count(1)

    while True:
        for i in range(len(n_2)):
            if n_2[i] == 1:
                n_2[i] = 0
            else:
                n_2[i] = 1
                break

            if i == len(n_2)-1:
                n_2.append(1)

        if n_2.count(1) == count:
            break

    for i in range(len(n_2)):
        answer += n_2[i] * (2**i)

    return answer
~~~



### 다른 사람 풀이

~~~python
def nextBigNumber(n):
    num1 = bin(n).count('1')
    while True:
        n = n + 1
        if num1 == bin(n).count('1'):
            break
    return n
~~~

bin() 함수를 사용하여 2진수를 구했다면 더 편했다