const bool test=1;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
char ans[10][100]={
	"zero",
	"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
};
void print(int x){
	//cout<<x;
	bool fflag =0;
	vector<string> vs;
	if(x==0)vs.push_back(string("zero"));
	while(x!=0){
		int r=x%10;
		x/=10;
		vs.push_back(string(ans[r]));
	}
	for(auto it =vs.rbegin();it!=vs.rend();it++){
		if(fflag)printf(" ");
		fflag=1;
		cout<<*it;
	}
	printf("\n");
}
void sol(){
	string s;
	cin>>s;
	int sum=0;
	for(char x:s){
		if(isdigit(x)){
			sum+=x-'0';
		}
	}
	print(sum);
}
int main()
{
	sol();
	return 0;
}
//a1005.cc
//generated automatically at Sun Nov 27 21:56:10 2016
//by xsthunder

//AC at Sun Nov 27 22:11:27 2016
 
