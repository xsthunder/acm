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
bool ck(string s){
	unsigned int a,b,c;
	a=s.find_first_not_of('A');
	if(a==string::npos&&s[a]!='P')return 0;
	a=a-0;
	b=s.find_first_of('T',a);
	if(b==string::npos)return 0;
	c=s.length()-b;
	b=c-a;
	if(c==a*b)return 1;
	else return 0;
}
void sol(){
	int t;scanf("%d",&t);getchar();
	string s;
	while(t--){
		cin>>s;
		printf(ck(s)?"YES\n":"NO\n");
	}
}
int main()
{
	sol();
	return 0;
}
//bsc_1003.cc
//generated automatically at Sat Oct 22 17:56:43 2016
//by xsthunder

