#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int TK,kcase=0;
	scanf("%d",&TK);
	while(TK--)
	{
		int a[3];
		scanf("%d%d%d",a,a+1,a+2);
		sort(a,a+3);
		printf("Case %d: %d\n",++kcase, a[1]);
	}

	




	
	//insert code
	return 0;
}
