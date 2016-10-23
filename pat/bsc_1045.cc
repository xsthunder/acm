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
int min(int x,int y){
	if(x>y)return y;
	else return x;
}
int max(int x,int y){
	if(x>y)return x;
	else return y;
}
int (* fuc[2])(int x,int y);
int (*now)(int x,int y);
const int N=2e5+10;
int _n=0;
int f[2][16][N];
void cal(int x){
	long long sum=1;
	while(sum<x){
		_n++;
		sum<<=1;
	}
}
void pre(int fc){
	now=fuc[fc];
	
}
bool good(int x){

}
void sol(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		for(int j=0;j<2;j++)f[j][0][i]=x;
	}
	for(int j=0;j<2;j++)pre(j);
	set<int >s;
	for(int i=0;i<n;i++){
		if(good(i))s.insert(i);
	}
	auto flag=s.rend();flag--;
	for(auto it =s.rbegin();it!=s.rend();it++){
		printf("%d",*it);
		if(it!=flag)printf("\n");
	}
}
int main()
{
	fuc[0]=min;
	fuc[1]=max;
	sol();
	return 0;
}
//bsc_1045.cc
//generated automatically at Sat Oct 22 11:40:01 2016
//by xsthunder

