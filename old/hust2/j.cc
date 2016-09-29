#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<cassert>
using namespace std;

int main()
{
	//freopen("c:\\cygwin64\\home\\xs\\mygit\\acm\\in", "r", stdin);
	//insert code
	int n;
	while(cin>>n)
	{
		vector<int> vA;
		map<int,int> mA;
		int x;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			vA.push_back(x);
		}
		sort(vA.begin(),vA.end());
		for(int i=0;i<vA.size()-1;i++)
		{
			assert(!(i+1==vA.size());
			x=vA[i]-vA[i+1];
			if(mA.count(x)==0)
			{
			mA[x]=1;
			}
			else 
			{
			mA[x]=mA[x]+1;
			}
		}
		int max=-1;
		assert(!mA.empty());
		for(auto i=mA.begin();i<=mA.end();i++)
		{
			if(max<i->second)
			{
			max=i->second;
			}
		}

		
	}
	//insert code
	return 0;
}
