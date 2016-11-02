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
struct stu{
	string name;
	string num;
};
void sol(){
	char name[20];
	char num[20];
	int ma=-1;int mi=101;
	int mark;
	stu sma,smi;
	int t;scanf("%d",&t);
//	cout<<t;
	while(t--){
		cin>>name>>num>>mark;
		if(ma<mark){
			sma=stu{name,num};
			ma=mark;
		}
		if(mi>mark){
			smi=stu{name,num};
			mi=mark;
		}
	}
	cout<<sma.name<<' '<<sma.num<<endl;
	cout<<smi.name<<' '<<smi.num<<endl;
}
int main()
{
	sol();
	return 0;
}
//bsc_1004.cc
//generated automatically at Tue Nov  1 20:11:50 2016
//by xsthunder

