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
	int a,b,c;
	int kcase=0;
	while(scanf("%d%d%d", &a,&b,&c)!=EOF)
	{
		bool flag=0;
		for(int i=10;i<=100;i++)
		{
			if(i%3==a&&i%5==b&&i%7==c)
			{
				flag=1;
				printf("Case %d: %d\n",++kcase, i);
			}
		}
			if(flag==0)
				printf("Case %d: No answer\n",++kcase);
	}

	




	
	//insert code
	return 0;
}
