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
#include<utility>
using namespace std;
const int inf=0x7fffffff;
const int N=1e3+5;
int d[N];
typedef pair<int,int> point;
set<point> ss;
deque<point>s;
int solve(int i){
	//for(int j=0;j<=11;j++)printf("%3d", j);
	//cout<<endl;
	//for(int j=0;j<=11;j++)printf("%3d", d[j]);
	//cout<<endl;
	if(d[i])return d[i];
	else if(i==s.size())return 0;
	else {
		int best=0;
		for(int j=i+1;j<=s.size();j++){
			if(s[i].first>s[j].first&&s[i].second>s[j].second) best=max(best,solve(j));
		}
		return d[i]=best+1;
	}
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while(T--){
		memset (d,0,sizeof(d));
		s.clear();ss.clear();
		int a,b;
		int x,y;
		int n;
		scanf("%d" ,&n);
		//cout<<"nnnnnnnnnnnnnn"<<n<<endl;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d", &a,&b);
			x=max(a,b);
			y=min(a,b);
			ss.insert(make_pair(x,y));
			//cout<<x<<','<<y<<endl;
			//cout<<ss.size()<<":";
		}
		for(std::_Rb_tree_const_iterator<std::pair<int, int> >it =ss.begin();it!=ss.end();it++){
			s.push_front(*it);
			//cout<<p.first<<','<<p.second<<endl;
		}
		int best=0;
		//cout<<"size:"<<s.size()<<endl;
		for(int i=0;i<s.size();i++){
			//cout<<"i"<<i<<endl;
			best=max(solve(i),best);
		}
		printf("%d\n", best);
	}

	
	//insert code
	return 0;
}
//nyoj16.cc

//AC

