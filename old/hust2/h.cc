#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int main()
{
	//freopen("c:\\cygwin64\\home\\xs\\mygit\\acm\\in", "r", stdin);
	//insert code
	int n,k;
	while(cin>>n>>k)
	{
		int x=0;
		int cnt=pow(10,9)+7;
		for(int i=0;i<cnt;i<i++)
		{

			n=n/2+k;
			if(x==n)break;
			x=n;
		}
		cout<<n<<endl;
	}
	//insert code
	return 0;
}
