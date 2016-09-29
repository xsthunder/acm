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
#include<list>
using namespace std;
const int inf=0x7fffffff;
const int N=1e5+10;
set<int > si;
list<int> orig;
struct Node{
	vector<int> vi;
};
Node aN[N];
int oe(int num)
{
	if(num%2)return num+1;
	else return num-1;
}
bool build()
{
	for(int i=1;i<=N;i++)
	{

	}

}
bool solve()
{
	if(!build)return false;
	return true;
}
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int x,y;
	while(scanf("%d%d", &x,&y)!=EOF&&(x!=-1&&y!=-1))
	{
		for(int i=0;i<N;i++)
		{
			aN[i].vi.clear();
		}
		orig.clear();
		orig.push_back(0);
		orig.push_back(x);
		orig.push_back(y);
		for(int i=3;scanf("%d%d",&x,&y)==2&&(x!=0&&y!=0);i+=2)
		{
			orig.push_back(x);
			orig.push_back(y);
		}
		printf("%s\n",solve()?"Yes":"No");
	}

	
	//insert code
	return 0;
}
