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
const int N=1e5;
int a[N+10];
typedef long long ll;
ll ans;
void sum(int x){
	ans =0;
	for(int i=0;i<x;i++){
		ans+=a[i];
	}
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
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n-1;i++){
			scanf("%d", &a[i]);
		}
		sort(a,a+n-1);
		if(k>=n){printf("%d\n", n);
			continue;
		}
		else {
			sum(n-k);
			cout<<ans+n<<endl;

		}
	}

	
	//insert code
	return 0;
}
//hdu5777.cc

//AC

