#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

void in(int n, set<int> &s)
{
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		s.insert(x);
	}
}
int main()
{
	//freopen("c:\\cygwin64\\home\\xs\\mygit\\acm\\in", "r", stdin);
	//insert code
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		set<int>s1;
		set<int>s2;
		int x;
		cin>>n;
		in(n,s1);
		in(n-1,s2);
		set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),&x);
		cout<<x<<endl;



	}

	




	
	//insert code
	return 0;
}
