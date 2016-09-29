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
	int TK;
	while(scanf("%d",&TK),TK)
	{
		int dx,dy;
		scanf("%d%d",&dx,&dy);
		while(TK--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int disx=x-dx,disy=y-dy;
			if(disx==0||disy==0)
			{
				printf("divisa\n");
				continue;

			}
			if(disy>0)
			{
				printf("N");
			}
			else
			{
				printf("S");
			}
			if(disx>0)
			{
				printf("E\n");
			}
			else printf("O\n");
		}

	}

	




	
	//insert code
	return 0;
}
