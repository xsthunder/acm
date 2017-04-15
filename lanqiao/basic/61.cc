const bool TEST=0;
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
#include<sstream>
#include<stack>
const int inf=0x7fffffff;
#define IF if(TEST)
#define FI if(!TEST)
#define gts(s) fgets((s),sizeof(s),stdin)
#define ALL(s) (s).begin(),(s).end()
#define MK(a,b) make_pair((a),(b))
typedef long long int LL;
typedef unsigned int U;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> Point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin++); } printf("\n"); }
char num[][10]={
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
char keta[][10]={
	"",
	"shi",
	"bai",
	"qian",
	"wan",
	"shi",
	"bai",
	"qian",
	"yi",
	"shi",
};
struct info{
	int pos=0;
	//int pre=1;
	int zero=0;
}pre;
char * ans[30]={0};
void sol(){
	string s ;
	cin>>s;
	int N = s.size()-1;
	IF{
		printf("pre: pos:%d , zero:%d, i:%d\n",pre.pos,pre.zero,-1);
	}
	for( U i = 0 ; i  <s.size();i++){
		int cur=s[i]-'0';
		IF{
//			printf("size:%d i:%d, s[i]:%c\n",(int)s.size(),i,s[i]);
			printf("cur : %d ,pre: pos:%d , zero:%d, i:%d\n",cur,pre.pos,pre.zero,i);
		}
		if(cur){
			IF if(i==0)cout<<keta[N-i]<<endl;
			ans[pre.pos++]=num[cur];
			pre.zero=0;
			ans[pre.pos++]=keta[N-i];
		}
		else {
			if(pre.zero)continue;
			else {
				pre.zero=1;
				ans[pre.pos++]=num[cur];
			}
		}
	}
	for(int i = 0 ; i < pre.pos;i++){
		if(i!=0)cout<<" ";
		if(!strcmp(ans[i],"yi")&&!strcmp(ans[i+1],"shi"))i++;
		if(i==pre.pos-1&&!strcmp(ans[i],"ling"))break;
		cout<<ans[i];
	}
}
int main()
{
	sol();
	return 0;
}
//61.cc
//generated automatically at Sat Feb  4 13:03:16 2017
//by xsthunder

