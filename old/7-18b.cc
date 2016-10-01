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
const int N=16+5;
int na[N];
bool yes;
int n;
set<int>od[2];
void solve(int num,bool flag)
{
	for(int i=0;i<num;i++)
	{
		na[n/2-num]=od[flag][i];
		od[flag].erase(od[flag][i]);
		for(int j=0;j<od[flag].size();j++)
		{
			na[n/2-num+n/2]=od[flag][i];
			od[flag].erase(od[flag][i]);
			slove(num-1,flag);
			if(num==0)
			{
				for(i=0;i<n;i++)printf(" %d",na[i]);
				printf("\n")
			}
		}
	}


}
int cir(int i)
{
	return n%i;
}
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int Ks=0;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case %d:\n",Ks);
		bool flag=0;
		for(int i=1;i<=n;i+=2)od[1].insert(i);
		for(int i=2;i<=n;i+=2)od[0].insert(i);
		na[0]=1;od[1][i].erase(i);
		for(int i=0;i<=od[0].size();i++){na[0+n/2]=od[0][i];od[0].erase(od[0].[i]);}
		flag=0;
		solve(n/2-1,flag);

exitdoor:
		printf("%d",na[0]);
		for(int i=1;i<n;i++)printf(" %d",na[i]);
		printf("\n");
		printf("%d",na[0]);
		for(int i=n-1;i>0;i--)printf(" %d",na[i]);
		printf("\n");

			

	}

	
	//insert code
	return 0;
}
