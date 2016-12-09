#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;
#define maxn  80+10
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int TK;
	scanf("%d",&TK);
	while(TK--)
	{
		char s[maxn];
		scanf("%s",s);
		int score=0;
		int cnt=0;
//		printf("%s",s);
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='O')
			{
				cnt++;
				score+=cnt;
//				printf("cnt:%d\n",cnt);
			}
			else cnt=0;
		}
		printf("%d\n",score);
	}


	




	
	//insert code
	return 0;
}
