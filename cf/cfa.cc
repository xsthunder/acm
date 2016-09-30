#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
#include<cassert>
const int inf=0x7fffffff;
#define IF if(test)
const bool test=0;
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
void pA(int *begin,int n){
	for(int i=0;i<n;i++){
		printf("%d " ,*(begin+i));
	}
	printf("\n");
}
char s[500];
int ans[500];
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	fgets(s,sizeof(s),stdin);
	IF cout<<s;
	memset (ans,0,sizeof(ans));
	int flag=0;
	int tcnt=0;
	int cnt=0;
int i=0;
	for(;s[i]!='\n';i++){
		if(flag){
			if(s[i]=='B'){//b b
				tcnt++;
				flag=1;
		//		continue;
			}
			else { //b w
				ans[cnt++]=tcnt;
				tcnt=0;;
				flag=0;
			}
		}
		else {
			if(s[i]=='B'){// w b
				flag=1;
				tcnt=1;
			}
			else { //w w
		//		continue;
				flag=0;
				tcnt=0;
			}
		}
		IF cout<<s[i]<<' '<<cnt<<' '<<tcnt<<endl;
	}
	if(s[i-1]=='B'){
		ans[cnt++]=tcnt;
	}
	printf("%d\n",cnt);
	if(cnt!=0)pA(ans,cnt);

	return 0;
}
//cfa.cc
//generated automatically at Fri Sep 30 22:24:16 2016
//by xsthunder

