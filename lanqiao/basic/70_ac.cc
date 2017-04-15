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
const int N = 200;
int a[3][N+1];
char s [N];
void sol(){
	for(int i = 0 ; i< 2 ;i++){
		scanf("%s", s);
		U len  = strlen (s  );
		int cnt = N ;
		for(int  j = len -1 ; j>=0  ;j--){
			IF cout<<j<<' '<<cnt<<endl;
			if(j==-1){
				//break;
			}
			a[i][cnt--]=s[j]-'0';
		}
	}
	IF {
		pA(a[0],30);
		pA(a[1],30);
	}
	for(int i = N ; i > 0 ; i--){
		int ans= 0 ;
		ans = (a[0][i]+a[1][i]);
		a[2][i]=ans%10;
		a[1][i-1]+=ans/10;
	}
	int b= 0; 
	while(!a[2][b]){
		b++;
	}
	for(; b <  N +1;b++){
		printf("%d",a[2][b]);
	}
	cout<<endl;
}
int main()
{
	sol();
	return 0;
}
//70.cc
//generated automatically at Wed Feb  8 10:17:09 2017
//by xsthunder

//AC at Wed Feb  8 10:36:20 2017
 
