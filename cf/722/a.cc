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
const bool test=1;
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
void pA(int *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
void sol(){
	int n;
	scanf("%d", &n);
	int a,b;
	scanf("%d%*c%d",&a,&b);
	//minutes
	if(b/10>=6)b=0+b%10;
	//hours
	if(n==12){
		if(a==0){
			a=1;
		}
		else if(a>12){
			a=a%10;
		}
	}
	else {
		if(a>23)a=a%10;
	}
	printf("%02d:%02d\n",a,b);
}
int main()
{
	sol();
	return 0;
}
//a.cc
//generated automatically at Sat Oct  1 22:34:34 2016
//by xsthunder

