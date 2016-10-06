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
#define gts(s) fgets((s),sizeof(s),stdin)
const bool test=0;
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
void pA(int *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
const int AN=1000;
int A[AN];
char s[AN+2000];
bool che(char c){
	switch(c){
		case'a':
		case'e':
		case'i':
		case'o':
		case'u':
		case'y':
			return 1;
		default:
			return 0;
	}
}
void sol(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",A+i);
	}
	getchar();
	IF pA(A,n);
	int flag=1;
	for(int i=0;i<n;i++){
		gts(s);
		if(flag){
			int cnt=0;
			for(int j=0;s[j]!='\n';j++){
				IF cout<<s[j];
				cnt+=che(s[j]);
			}
			IF cout<<i<<' '<<cnt<<endl;
			if(A[i]!=cnt)flag=0;
		}
	}
	printf("%s\n",flag?"YES":"NO");


}
int main()
{
	sol();
	return 0;
}
//b.cc
//generated automatically at Sat Oct  1 22:48:30 2016
//by xsthunder

