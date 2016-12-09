//Ac
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
typedef pair<int,int> point;
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	int n;
	scanf("%d", &T);
	set<point> data;
	while(T--)
	{
		data.clear();
		scanf("%d",&n);
		point p;
		int x,y;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			data.insert(make_pair(x*n,y));
			sum+=x;
		}
		bool flag=true;
		for(auto i=data.begin();i!=data.end();i++)
		{
			point p=*i;
			if(data.find(make_pair(2*sum-p.first,p.second))==data.end())flag=false;
		}
		printf("%s\n",flag?"YES":"NO");


	}


	
	//insert code
	return 0;
}
