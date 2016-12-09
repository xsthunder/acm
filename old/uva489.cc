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
const int N=100;
char s[N];
char s2[N];
int chance,lose,left;
int bad;
int win;
void guess(char ch)
{
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]==ch)
		{
			s[i]=' ';
			bad=0;
			left--;
		}
	}
	if(bad)chance--;
}
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n;
	while(scanf("%d",&n)!=EOF&&n!=-1)
	{
	chance=7;;lose=0;win=0;
	scanf("%s%s",s,s2);
	left=strlen(s);
	for(int i=0;i<strlen(s2);i++)
	{
		bad=1;
		guess(s2[i]);
		if(chance==0)
		{
			lose=1;
			break;
		}
		if(!left)
		{
			win=1;
			break;
		}
	}
	printf("Round %d\n",n);
	if(win)printf("You win.");
	else if(lose)printf("You lose");
	else printf("You chickened out."); 
	printf("\n");
	}
	
	//insert code
	return 0;
}
