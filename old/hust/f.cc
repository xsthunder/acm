#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main()
{
	//freopen("c:\\cygwin64\\home\\xs\\mygit\\acm\\in", "r", stdin);
	//insert code
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		vector<int> vg;
		map<int,int>mg;
		set<int>sg;
		set<int>sd;
		int g;
		for(int i=0;i<n;i++)
		{
			cin>>g;
			vg.push_back(g);
			sg.insert(g);
		}
		for(int i=0;i<vg.size();i++)
		{
			g=vg[i];
			if(0==sg.count(g))continue;
			vector<int> distance;
			for(int j=++i;j<vg.size();j++)//find all the position 0f g
			{

				if(vg[j]==g)distance.push_back(j);
			}
			for(int k=0;k<distance.size()-1;k++)
			{
				int min=1000;
				int dis=-(distance[k]-distance[k+1]);
				if(min>dis)min=dis;
				if(sg.count(min))continue;
				mg[dis]=g;
				if(dis==1)goto display;
				sd.insert(dis);
			}
			sg.erase(g);
		}
display:
		cout<<mg[*sd.begin()]<<endl;
	}


	




	
	//insert code
	return 0;
}
