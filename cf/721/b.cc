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

char s[200];
int ans[105];
int n,k;
int m=0;
int cnt;
int Con(int o){
	int sum=0;
	sum=o/k*5;
	return sum+o;
}
int Bes(){
	int sum=0;
	for(int i=0;i<cnt;i++){
		sum+=ans[i];
	}
	return Con(sum)+1;
}
int Wor(){
	int sum=0;
	for(int i=0;i<=cnt;i++){
		sum+=ans[i];
	}
	return Con(sum-1)+1;
}
int main(){
	scanf("%d%d",&n,&k);
	IF cout<<n<<' '<<k<<endl;
	while(n--){
		scanf("%s", s);
		cnt=strlen(s);
		IF cout<<cnt<<endl;
		ans[cnt]++;
		m=max(cnt,m);
	}
	scanf("%s", s);
	cnt=strlen(s);
	IF pA(ans,105);
	printf("%d %d",Bes(), Wor());
}
//b.cc
//generated automatically at Fri Sep 30 23:42:03 2016
//by xsthunder

//AC at Sat Oct  1 11:01:07 2016
 
