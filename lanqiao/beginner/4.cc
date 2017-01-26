const bool test=0;
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
const int N = 1e6+100;
const int mod = 10007;
void sol(){
	int n ; 
	cin >> n;
	int cur[2]={1, 1};
	IF cout<< cur [ 1] <<cur [ 0];
	if(n<=2){
		cout<<cur[n-1]<<endl;
	}
	else{ 
		for(int i = 3 ; i <= n ;i++){
			int tmp  = cur[0]+cur[1];
			swap ( cur[0],cur[1]);
			cur [ 1] = tmp%mod;
		}
		cout<<cur[1]<<endl;
	}
}
int main()
{
	sol();
	return 0;
}
//4.cc
//generated automatically at Sun Jan 15 22:26:46 2017
//by xsthunder

