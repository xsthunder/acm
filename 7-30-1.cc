#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
using namespace std;
const int inf=0x7fffffff;
const int N=1e5+10;
int s[N];
int n,m;
bool solve(){
	int sum;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j>=i)break;
			sum=s[i]-s[j];
			if(sum>=m){
				if(sum%m==0)return 1;
			}
		}
	}
	return 0;
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n,&m);
		int x;
		s[0]=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d" ,&x);
			s[i]=s[i-1]+x;
		}
//		cout<<s[n];
		printf("%s\n", solve()?"YES":"NO");
	}

	
	//insert code
	return 0;
}
//7-30-1.cc

