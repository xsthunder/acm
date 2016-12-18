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
const int N=1e5+1000;
int nxt[N];
void sol(){
	memset (nxt,-1,sizeof(nxt));
	int n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	if(a>b)swap(a,b);
	a--;b--;
	int ans=0;
	//int index=a;
	int cur0=-1;
	int cur1=-1;
	for(unsigned int i=0;i<s.size();i++){
		if(s[i]=='0'){
			if(cur0!=-1){
				nxt[cur0]=i;
			}
			cur0=i;
		}
		if(s[i]=='1'){
			if(cur1!=-1){
				nxt[cur1]=i;
			}
			cur1=i;
		}
		IF cout<<cur0<<cur1<<i<<endl;
	}
	IF pA(nxt,n);
	//return ;
	while(a!=b){
		if(nxt[a]!=-1&&nxt[a]<=b){
			a=nxt[a];
		}
		else {
			a++;
			ans++;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	sol();
	return 0;
}
//A.cc
//generated automatically at Wed Dec 14 22:39:15 2016
//by xsthunder

