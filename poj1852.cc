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
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int KT;
	scanf("%d",&KT);
	while(KT--)
	{
		int n,num;
		scanf("%d%d",&n,&num);
		int best=0;
		int worst=0;
		int x;
		while(num--)
		{
			scanf("%d",&x);
			best=max(best,min(n-x,x));
			worst=max(worst,max(n-x,x));
		}
		printf("%d %d\n",best
				,worst);
	}

	
	//insert code
	return 0;
}
