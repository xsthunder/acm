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
char s[100+10];
int len;
char ans[10][5]={
	"ling",
	"yi",
	"er",
	"san",
	"si",
	"wu",
	"liu",
	"qi",
	"ba",
	"jiu"
};
void pri(int sum){
	int t;
	vector<int > v;
	while(sum>0){
		t=sum%10;
		sum/=10;
		v.push_back(t);
	}
	auto flag=v.rend();flag--;
	for(auto it=v.rbegin();it!=v.rend();it++){
		printf("%s",ans[*it]);
		if(it!=flag){
			printf(" ");
		}
	}
	printf("\n");
}
void sol(){
	scanf("%s",s);
	len=strlen(s);
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=s[i]-'0';
	}
	pri(sum);
}
int main()
{
	sol();
	return 0;
}
//bsc_1002.cc
//generated automatically at Sat Oct 22 11:27:03 2016
//by xsthunder

