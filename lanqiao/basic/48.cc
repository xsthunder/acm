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
void sol(){

	int n;
	scanf("%d",&n);
	string s;
	char tmp[100];
	for(int i=1;i<10;i++){
		for(int j=0;j<10;j++){
			int z=n-2*i-2*j;
			IF cout<<i<<j<<z<<endl;
			if(z>=0&&z<10){
				printf("%d%d%d%d%d\n",i,j,z,j,i);
			}
			if(z>=0&&z<=18&&z%2==0){
				sprintf(tmp,"%d%d%d%d%d%d\n",i,j,z/2,z/2,j,i);
//				cout<<tmp;
				s+=tmp;
			}
		}
	}
	cout<<s;
}
int main()
{
	sol();
	return 0;
}
//48.cc
//generated automatically at Tue Jan 17 14:32:17 2017
//by xsthunder

