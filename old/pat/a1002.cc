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
void sol(){
	int K;
	K=2;
	map<int , float> mif;
	while(K--){
		int n;
		scanf("%d",&n);
		while(n--){
			int ex;float co;
			scanf("%d%f",&ex,&co);
			if(mif.count(ex)){
				mif[ex]+=co;
			}
			else {
				mif[ex]=co;
			}
		}
	}
	//bool fflag=0;
	int cnt=0;
	for(auto it=mif.rbegin();it!=mif.rend();it++)if((int)it->second!=0)cnt++;
	printf("%d",cnt);
	//if(cnt!=0)printf(" ");//valid
	for(auto it=mif.rbegin();it!=mif.rend();it++){
	//	if(fflag)cout<<' ';
		if((int)it->second==0)continue;
		printf(" %d %.1f",(*it).first,(*it).second);
	//	fflag=1;
	}
	cout<<endl;
}
int main()
{
	sol();
	return 0;
}
//a1002.cc
//generated automatically at Sun Nov  6 22:58:07 2016
//by xsthunder
//保持代码量少有意外收获。。。。。
