#include<cstdio>
#include<set>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	inp();
	return 0;
}
const int N = 10, D = 6;;
int a[N],b[N];
int mo[N];
void inp(){
	int p;scanf("%d",&p);
	for(int i =0;i<D;i++){ scanf("%d",&a[i]); }
	for(int i =0;i<D;i++){ scanf("%d",&b[i]); }
	for(int i =0;i<D;i++){
		for(int j = 0;j<D;j++){
			mo[(a[i]+b[j])%p] ++;
		}
	}
	set<int > s;
	for(int i =0;i<p;i++){
		s.insert(mo[i]);
	}
	puts(s.size()==1?"YES":"NO");
}
//A.cc by xsthunder at Fri Dec  8 18:37:32 2017

