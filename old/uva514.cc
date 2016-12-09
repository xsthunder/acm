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


using namespace std;
const int maxn=1000+1;
int a[maxn];
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n;
	while(scanf("%d",&n)==1)
	{
		for(;;)
		{
		if(n==0)break;
		stack<int> s;
		int ok=1;
		scanf("%d",a+1);
		if(a[1]==0)break;
		for(int i=2;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		int A=1,B=1;
		while(B<=n)
		{
			if(A==a[B]){A++;B++;}
			else if (!s.empty()&&s.top()==a[B]){s.pop();B++;}
			else if(A<=n){s.push(A);A++;}
			else {ok=0;break;}
		}
		printf(ok?"Yes\n":"No\n");
		}
		printf("\n");

	}

	
	//insert code
	return 0;
}
