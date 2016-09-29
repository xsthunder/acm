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
int Next[N];
char s[N];

int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	while(scanf("%s",s+1)!=EOF)
	{
		cout<<s+1;
		int len=strlen(s+1);
		cout<<"len:"<<len<<endl;
		int cur,last;
		char ch;
		cur=last=0;
		for(int i=1;i<=len;i++)
		{
			ch=s[i];
			if(ch=='[')cur=0;
			else if(ch==']')cur=last;
			else {
			Next[i]=Next[cur];
			Next[cur]=i;
			if (cur==last)last=i;
			cur=i;
			}
		}
		//for(int i=0;i<50;i++)
		//	printf("%d ", Next[i]);
		for(int i=Next[0];i!=0;i=Next[i])
			printf("%c",s[i]);
		printf("\n");
	}


	
	//insert code
	return 0;
}
