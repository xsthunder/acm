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
	int a[256]={0};
	char s[80];
	for(int i=0;i<4;i++){
		fgets(s,80,stdin);
		for(int j=0;s[j]!='\0';j++){
			if(isalpha(s[j])){
				a[s[j]]++;
			}
		}
	}
	int best=0;
	for(int i='A';i<='Z';i++){
		best=max(a[i],best);
	}
	for(int i=best;i>=1;i--)
	{
		for(int j='A';j<='Z';j++)
		{
			if(a[j]==i){
				if(j=='A')printf("*");
				else printf(" *");
				a[j]--;
			}
			else
			{
				if(j=='A')printf(" ");
				else printf("  ");
			}
		}
		printf("\n");
		printf("\n");
	}
	printf("A");
	for(int i='B';i<='Z';i++)printf(" %c",i);
	printf("\n");

	
	//insert code
	return 0;
}
