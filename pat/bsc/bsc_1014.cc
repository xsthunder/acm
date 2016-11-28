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
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<' '<<*(begin+i); } printf("\n"); }
const int N=100;
char s[4][N];
char W[][5]{
	"MON",
		"TUE",
		"WED",
		"THU",
		"FRI",
		"SAT",
		"SUN"
};
void sol(){
	gts(s[0]);
	gts(s[1]);
	gts(s[2]);
	gts(s[3]);
	int lena=min(strlen(s[0]),strlen(s[1]))-1;
	int lenb=min(strlen(s[2]),strlen(s[3]))-1;
	bool w=0;
	for(int i=0;i<lena;i++){
		char a1=s[0][i];
		char a2=s[1][i];
		if(a1==a2&&isupper(a1)&&!w){
			printf("%s ",W[a1-'A']);
			w=1;
			continue;
		}
		if(w){
			if(a1==a2&&(isdigit(a1)||(a1>='A'&&a1<='N'))){
				printf("%02d:",isdigit(a1)?a1-'0':a1-'A'+10);
			}
		}
	}
	for(int i=0;i<lenb;i++){
		char a1=s[2][i];
		char a2=s[3][i];
		if(a1==a2&&a1=='s'){
//			cout<<a1<<i;
			printf("%02d\n",i);
		}
	}
}
int main()
{
	sol();
	return 0;
}
//bsc_1014.cc
//generated automatically at Fri Nov  4 09:41:48 2016
//by xsthunder

