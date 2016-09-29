#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
//	freopen("in", "r", stdin);
	//insert code
	vector<int>marble;
	int kase=0;
	int n,q;
	cin>>n>>q;
	int x;
	while(n!=0&&q!=0)
	{
		for(int i=0;i<n;i++)
		{
			cin>>x;
			marble.push_back(x);
		}
		cout<<"CASE# "<<++kase<<":"<<endl;
		sort(marble.begin(),marble.end());
		for(int i=0;i<q;i++)
		{
			cin>>x;
			cout<<x<<" found at "<<lower_bound(marble.begin(),marble.end(),x)-marble.begin()+1<<endl;
		}

	}
	




	
	//insert code
	return 0;
}
