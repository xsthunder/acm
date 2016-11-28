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
int (*A)[N];
int n;
int cnst[2]={
	0,
	inf
};
long long sum;
int cal(int x){
	sum=1;
	int tmp=0;
	while(sum<x){
		tmp++;
		sum<<=1;
	}
	return tmp;
}
void pre(int fc){
	now=fuc[fc];
	_n=cal(n);
	cout<<sum<<endl;;
	for(int i=1;i<=_n;i++){
		for(int j=0;j+(1>>i)<=sum;j++){
			f[fc][i][j]=now(f[fc][i-1][j],f[fc][i-1][j+(1<<(i-1))]);
			cout<<f[fc][i-1][j]<<' '<<f[fc][i-1][j+(1<<i)]<<' '<<(1<<i)<<endl;;
		}
	}
}
bool qry(int i,int fc){
	now=fuc[fc];
	if(fc==1){
		if(i==n-1)return true;
		int p=cal(n-i);p--;
		return now(f[fc][p][i],f[fc][p][n-1-(1>>p)+1]);
	}
	else if(fc==0){
		if(i==0)return false;
		int p=cal(i+1);p--;
		return now(f[fc][p][0],f[fc][p][i-(1>>p)+1]);
	}
	printf("expection in qry\n");
	exit(1);
}
bool good(int x){
	for(int c=0;c<2;c++){
		if(fuc[c](*A[x],qry(x,c))!=x)return false;
	}
	return true;
}
void sol(){
	scanf("%d",&n);_n=cal(n);
	for(int i=0;i<2;i++)fill(&f[i][0][0],&f[i][0][0]+N,cnst[i]);
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x);
		//cout<<i;
		for(int j=0;j<2;j++)f[j][0][i]=x;
	}
	for(int j=0;j<2;j++)pre(j);
	set<int >s;
	pA(f[0][1],n);
	pA(f[1][1],n);
	for(int i=0;i<n;i++){
		if(good(i))s.insert(i);
	}
	auto flag=s.begin();
	if(s.size()!=0){auto flag=s.end();flag--;}
	printf("%d\n",(int )s.size());
	for(auto it =s.begin();it!=s.end();it++){
		printf("%d",*it);
		if(it!=flag)printf("\n");
	}
}
int main()
{
	fuc[0]=min;
	fuc[1]=max;
	A=&f[0][0];
	sol();
	return 0;
}
//bsc_1045.cc
//generated automatically at Sat Oct 22 11:40:01 2016
//by xsthunder

