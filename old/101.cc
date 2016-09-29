#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;
vector<vector<int> > piles;

void find_bl(int a, int &p, int &h)
{}
void return_bl(int p, int h)//execept the p,h
{
}
void move_bl(int pa, int ha, int pb, int hb)
{
}
void display()
{
	for(int i=0;i<piles.size();i++)
	{
		cout<<i;
	}

}
int main()
{
	//freopen("c:\\cygwin64\\home\\xs\\mygit\\acm\\in", "r", stdin);
	//insert code
	
	int n;
	piles.resize(n);
	for(int i=0;i<n;i++)
	{
		piles[i][0]=i;
	}
	string s1, s2;
	int a,b;
	while(cin>>s1&&s1!="quit")
	{
		cin>>a>>s2>>b;
		int ha,hb,pa,pb;
		if(a==b)continue;
		find_bl(a,pa,ha);
		find_bl(b,pb,hb);
		if(s1=="move")return_bl(pa,ha);
		if(s2=="onto")return_bl(pb,hb);
		move_bl(pa,ha,pb,hb);
	}
	display();
	//insert code
	return 0;
}
