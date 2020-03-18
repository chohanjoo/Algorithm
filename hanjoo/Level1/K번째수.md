

# K번째수



## 내 풀이

~~~c++
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
    vector<int> answer;
    vector<int> temp(3);
    int a,b,c;
    
    for(int i=0;i<commands.size();++i){
        a = commands[i][0];
        b = commands[i][1];
        c = commands[i][2];
        temp.resize(b-a+1);


        copy(array.begin()+a-1,array.begin()+b,temp.begin());
				printf("\n------temp -------- \n");
				for(int i=0;i<temp.size();++i)
					printf("%d ",temp[i]);
		
        sort(temp.begin(),temp.end());
				printf("\n------sort -------- \n");
				for(int i=0;i<temp.size();++i)
					printf("%d ",temp[i]);
				printf("\n--------\n");
        answer.push_back(temp[c-1]);
    }
    return answer;
}

int main(){
	int v[]={1,5,2,6,3,7,4};
	int v1[]={2,5,3};
	int v2[]={4,4,1};
	int v3[]={1,7,3};
	vector <int> array(begin(v),end(v));
	vector <vector<int> > commands;
	vector <int> a1(begin(v1),end(v1));
	commands.push_back(a1);
	vector <int> a2(begin(v2),end(v2));
	commands.push_back(a2);
	vector <int> a3(begin(v3),end(v3));
	commands.push_back(a3);

	vector <int> answer;


answer = 	solution(array,commands);

for(int i=0;i<answer.size();++i)
	printf("%d ",answer[i]);
	return 0;
}

~~~



## 베스트 풀이

~~~~c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2]-2]);
    }

    return answer;
}

~~~~

----

### vector 초기화

#### vector는 초기화를 할 수가 없어 배열을 만들어 vector 초기화를 진행하였다.

~~~c++
	int v[]={1,5,2,6,3,7,4};
	vector <int> array(begin(v),end(v));
~~~



### vector copy

~~~c++
// copy() 를 이용한 복사
 
destVector.resize((int)(sourceVector.size()));
std::copy( sourceVector.begin(), sourceVector.end(), destVector.begin() );
std::copy( sourceVector.begin() + 2, sourceVector.begin() + 5, destVector.begin() );

// assign() 을 이용한 복사
 
destVector.clear();
destVector.assign( sourceVector.begin(), sourceVector.end() ); // 전체 복사
destVector.assign( sourceVector.begin() + 1, sourceVector.begin() + 4 );


출처: https://ogoons.tistory.com/75 [오군의 기술 블로그]
~~~

<출처>

https://ogoons.tistory.com/75

