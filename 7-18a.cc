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
const int N=1e5+10;
char s[N];
char Map[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
char MAP(char ch)
{
	int p;
	if(ch==' ')return ch;
	for(p=0;Map[p]!=ch;p++);
	return Map[p-1];
}
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	while(fgets(s,N,stdin)!=NULL)
	{
		for(int i=0;s[i]!='\n';i++)
			s[i]=MAP(s[i]);
		printf("%s",s);
	}
	


	
	//insert code
	return 0;
}
