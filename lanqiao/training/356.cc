const bool TEST=1;
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
int mov0[3];
int thow[3];
struct status{
	int used[3][3];
	int len[1000];
	int cur[3];
	int lock[3];
	status(int a,int b,int c){
		memset(used ,0 ,sizeof(used));
		memset(len,-1,sizeof(len));
		memset(lock,0,sizeof(lock));
		len[a]=0;len[b]=1;len[c]=2;
		cur[0]=a,cur[1]=b,cur[2]=c;
	}
	bool mov(int j){//0
		if(lock[j])return 0;
		if(used[0][j])return 0;
		if(len[cur[j]+mov0[j]]!=-1)return 0;
		used[0][j]=1;
		len[cur[j]]=-1;
		cur[j]=cur[j]+mov0[j];
		len[cur[j]]=j;
	}
	bool lif(int j ){//1
		if(used[1][j])return 0;
	}
	bool thr(int j ){//2
		if(used[2][j])return 0;
	}
	bool (status::*fun[3])(int )={
		mov,lif,thr
	};
	bool work(int i ,int j ){
		return (this->*fun[i])(j);
	}
};
void dfs(int curi,int curj,status s){
	if(s.work(curi,curj)){
		for(int i =0 ; i <  3;i++){
			for(int j =0 ; j< 3;j++){
				dfs(i,j,s);
			}
		}
	}
	else return;
}
void sol(){
	for(int i =0 ; i <3;i++){
		cin>>pos0[i]>>mov0[i]>>thow[i];
		len[pos0[i]]=i;
		cur0[i]=pos0[i];
	}
}
int main()
{
	sol();
	return 0;
}
//356.cc
//generated automatically at Fri Feb 10 21:33:45 2017
//by xsthunder

