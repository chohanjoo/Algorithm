# 문자열 내 p와 y의 개수

## 내 풀이

~~~c++
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pc=0,yc=0;

    for(int i=0;i<s.length();++i){
        if(tolower(s[i])=='p')
            ++pc;
        else if (tolower(s[i])=='y')
            ++yc;
    }

    if(pc==yc)
        answer = true;
    else
        answer = false;

    if(pc==0 && yc==0)
        answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
~~~



---

### string 인덱스 접근

~~~c++
string s = "hello world";

s[0] == 'h'
~~~



### to lower()

~~~c++
string s = "Hello world";

s[0] == 'H'

tolower(s[0]) == 'h'
toupper(s[1]) == 'E'
~~~

