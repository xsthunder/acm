const bool test=0;
#include<iostream>
#include<stack>
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
struct v{
	int i;
	int v;
};
const int N=1e6;
int a[N];
int b[N];
void sol(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		a[n++]=0;
		stack<v> s;
		for(int i=0;i<n;i++){
			for(;;){
				if(s.empty()||a[i]>s.top().v){
					s.push(v{i,a[i]});
					break;
				}
				b[s.top().i]=i;
				s.pop();
			}
		}
		IF pA(b,n);
		IF pA(a,n);
		int q;
		scanf("%d",&q);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			l--;r--;
			int ans=a[l];
			int tmp=b[l];
			while(tmp<=r){
				ans%=a[tmp];
				tmp=b[tmp];
			}
			printf("%d\n",ans);
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		
	}
}
int main()
{
	sol();
	return 0;
}
//02_1.cc
//generated automatically at Tue Oct 11 20:53:42 2016
//by xsthunder

