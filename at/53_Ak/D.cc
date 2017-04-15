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
const int N =1e5+1e5;
int dat[N];
void sol(){
	int n;
	cin>>n;
	int x;
	bool flag2=0;
	while(n--){
		scanf("%d", &x);
		dat[x]++;
		if(dat[x]==3)dat[x]-=2;
	}
	IF pA(dat,9);
	for(int i =0 ;i < N ;i++){
		if(dat[i]==2){
			if(flag2){
				dat[x]--;
				flag2=0;
				dat[i]--;
			}
			else {
				x=i;
				flag2=1;
			}
		}
	}
	IF pA(dat,9);
	if(flag2){
		dat[x]-=2;
	}
	IF pA(dat,9);
	int cnt=0;
	for(int i = 0;i<N;i++){
		if(dat[i])cnt++;
	}
	cout<<cnt<<endl;
}
int main()
{
	sol();
	return 0;
}
//D.cc
//generated automatically at Sat Jan 28 20:34:39 2017
//by xsthunder

