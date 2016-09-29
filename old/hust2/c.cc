#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
	//freopen("c:\\cygwin64\\home\\xs\\mygit\\acm\\in", "r", stdin);
	//insert code
	int t;
	cin>>t;
	string x="a",x2="b";
	int b1=0,b2=0,current=1;
	while(t--)
	{
		for(;;)
		{
			cin>>x;
			if(x[0]=='E');break;
			if(x==x2)
			{
				current=(current)%2+1;
			}
			x2=x;
			switch(current)
			{
				case 1:b1++;break;
				case 2:b2++;break;
				default: exit(1);
			}
		}
		cout<<b1*b2<<endl;
	}
	//insert code
	return 0;
}
