#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;
int solve()
{
	double curcar,curloan;
	for(int i=0;i<=100;i++)
	{

	}
}
int maxn=100+5;
set<int>s;
map<int,double>m;
double down,loan,carv;
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int mon;
	while(scanf("%d",&mon)&&mon>=0)
	{
		s.clear();
		m.clear();
		int rec;
		scanf("%lf%lf%d",&down ,&loan,&rec);
		carv=down+loan;
		while(rec--)
		{
			int x;
			double y;
			scanf("%d%lf",&x,y);
			s.insert(x);
			m[x]=y;
		}
		int months=solve();
		if(months==1)printf("1 month\n)");
		else printf("%d months\n",months);
	}

	//insert code
	return 0;
}
