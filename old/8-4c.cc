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
#define MS(x) memset(x, 0 ,sizeof(x))
#define SC(x) scanf("%d", & (x) )
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int inf=1e9;;
typedef long long int lld;
typedef long long unsigned llu;
int ex,ey;
set<pair<int ,int > >s;
llu cnt;
llu lcn(llu x,llu y){
	return x/__gcd(x,y)*y;
}
void defs(int x,int y,int cur,vector<pair<int,int> >v){
	//cout<<x<<' ' <<y<<endl;
	if(x==ex&&y==ey){cnt+=cur-1;
		for(pair<int ,int> p:v){
			cout<<p.first<<' '<<p.second<<endl;
		}

	}
	if(x>ex||y>ey)return ;
	if(s.count(make_pair(x,y)))return ;
	s.insert(make_pair(x,y));
	v.push_back(make_pair(x,y));
	llu c=lcn(x,y);
	if(x+c>ex) ;
	else {
		defs(x+c,y,cur+1,v);
	}
	if(y+c>ey) ;
	else {
		defs(x,y+c,cur+1,v);
	}
	return ;
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	SC(T);
	rep(t,1,T){
		s.clear();
		cnt=0;
		SC(ex);SC(ey);
		for(int ix=1;ix<=ex;ix++){
		    s.erase(s.begin(),s.upper_bound(make_pair(ix,1)));
			for(int iy=1;iy<=ey;iy++){
                    if(ix==ex&&iy==ey)continue;
				if(!s.count(make_pair(ix,iy))){
					vector<pair<int,int> >v;
					defs(ix,iy,1,v);
				}
			}
		}
		printf("Case #%d: %llu\n", t,cnt+1);
	}


	//insert code
	return 0;
}
//8-4c.cc

