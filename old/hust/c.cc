#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;
int main()
{
	//freopen("c:\\cygwin64\\home\\xs\\mygit\\acm\\in", "r", stdin);
	//insert code
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int ar[12][12]={0};
		char re[12][12]={0};
		int x,y;
		//initializing
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				re[i][j]='.';
			}
		}
		//in
		for(int i=1;i<=k;i++)
		{
			cin>>x>>y;
			x;
			y;
			ar[x][y]=1;
			re[x][y]='M';
		}
		//sovle
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ar[i][j]==1)continue;
				re[i][j]='0'+ar[i-1][j-1]+ar[i][j-1]+ar[i+1][j-1]
					+ar[i-1][j]+		ar[i+1][j]
					+ar[i-1][j+1]+ar[i][j+1]+ar[i+1][j+1];
				if(re[i][j]=='0')re[i][j]='.';
				if(ar[i][j]==1)re[i][j]='M';
			}
		}
		//display
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<re[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	




	
	//insert code
	return 0;
}
