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

//		printf("%d %d %d\n",a,b,c);
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

	
//	for(int i=0;i<commands.size();++i){
//		for(int j=0;j<commands[i].size();++j)
//			printf("%d ",commands[i][j]);
//		printf("\n");
//	}
answer = 	solution(array,commands);

for(int i=0;i<answer.size();++i)
	printf("%d ",answer[i]);
	return 0;
}
