#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>

using namespace std;
struct dog
{
	int p;
	int v;
};
int main()
{
	//freopen("c:\\cygwin64\\home\\xs\\mygit\\acm\\in", "r", stdin);
	//insert code
	int n,v;
	while(cin>>n>>v)
	{
		vector<dog> vD(n);
		for(int i=0;i<n;i++)
		{
			cin>>vD[i].p>>vD[i].v;	
		}
		/*for(int i=0;i<n;i++)
		{
			cout<<vD[i].p<<vD[i].v<<endl;
		}*/
		double t=0,p=0;
		double td,pd;
		double vh;
		int i;
		for(i=0;i<n;i++)
		{
			pd=vD[i].p+vD[i].v*t;
			double xd,xh;
			if(pd-p>0)vh=v;
			else if(pd-p<0)vh=-v;
			else continue;
			if(vh==vD[i].v)
			{

				cout<<"Bad Dog\n";
				break;
			}
			td=(pd-p)/(vh-vD[i].v);
			if(td<0)
			{
				cout<<endl<<endl<<i<<'t'<<t<<'p'<<p;
			}
			t+=td;
		}
		if(vh==vD[i].v)continue;
		printf("%.2f\n",t);
		
	}
	




	
	//insert code
	return 0;
}
