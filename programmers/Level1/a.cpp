#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool compare(string a, string b);
int N;
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
   
	sort(strings.begin(),strings.end());
    sort(strings.begin(), strings.end(),compare);
    answer = strings;
    return answer;
}

bool compare(string a, string b){
    string temp = "";
    string temp2 = "";
    //for(int i=N;i<a.length();++i)
        temp += a.at(N);
    //for(int i=N;i<b.length();++i)
        temp2 += b.at(N);
    

		cout<< temp << "  "<<temp2 << endl;
    if(temp.compare(temp2)){
		printf("hello\n");
		
		if(temp < temp2)
			return true;
		else 
			return false;

			}

        //return temp.compare(temp2);
    else 
        return !a.compare(b);
}

int main(){
	vector<string> strings;
	vector<string> answer;
	strings.push_back("abcd");
	strings.push_back("abce");
	strings.push_back("cdx");
//	strings.push_back("sun");
//	strings.push_back("bed");
//	strings.push_back("car");
	answer = solution(strings,2);
//	answer = solution(strings,1);
	for(int i=0;i<answer.size();++i)
		cout<< answer[i] <<endl;
	return 0;
}
