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
const bool test=1;
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
void pA(int *begin,int n){
	for(int i=0;i<n;i++){
		printf("%d" ,*(begin+i));
	}
	printf("\n");
}
char s[500];
int cnt;
int ans[500];
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	fgets(s,sizeof(s),stdin);
	int flag=0;
	int tcnt=0;
	for(int i=0;s[i]!='\0';i++){
		if(flag){
			if(s[i]=='B'){
				tcnt++;
				continue;
			}
			else {
				ans[cnt++]=tcnt;
				tcnt++;
			}
		}
		else {
			if(s[i]=='B'){
				flag=1;
				tcnt++;
			}
			else {
				continue;
			}
		}
	}
	printf("%d\n",cnt);
	pA(ans,cnt);

	return 0;
}
//cfa.cc
//generated automatically at Fri Sep 30 22:24:16 2016
//by xsthunder

