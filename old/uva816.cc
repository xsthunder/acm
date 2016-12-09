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
const int row=0;
const int col=1;
struct Node{
	int x,y,dir;
};
const int N=9*9+10;
int has_edge[N][N][N];
const char* dirs="NESW";
const char* turns="FLR";
const int nxt[4][2]={-1,0,1,0,0,1,0,-1};
int r1,c1,r2,c2;
char dir;
int dir_id(char c){return strchr(dirs,c)-dirs;}
int turn_id(char c){return strchr(turns,c)-turns;}
void read_input()
{
	int r0,c0,temdir;
	scanf("%d%d%c%d%d",&r0,&c0,&temdir,&r2,&c2);
	dir=dir_id(temdir);




}
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	char s[20+5];
	while(scanf("%s",s)!=EOF)
	{
		if(!strcmp(s,"END"))break;
		printf("%s\n",s);
		memset(has_edge,0,sizeof(has_edge));

	}


	
	//insert code
	return 0;
}
