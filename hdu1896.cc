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
const int inf=0x7fffffff;
typedef long long int lld;
typedef long long unsigned llu;
struct point{
	int p;
	int d;
};
struct cmp{
bool operator()(point &a,point &b){
	if(a.p==b.p)return a.d>b.d;
	return a.p>b.p;
}
};
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T=0;
	int ans=0;
	SC(T);
	rep(t,1,T){
		priority_queue<point, vector<point > ,cmp> PQ;
		int n=0;SC(n);
		//cout<<t<<' '<<n<<endl;
		rep(i,0,n-1){
		int p,d;SC(p);SC(d);
		point po;
		po.p=p;po.d=d;
		PQ.push(po);
		}
		int cnt=1;
		int cntp=0;;
		point po;
//		for(point x:PQ)cout<<x.p<<' '<<x.d<<endl;
		while(PQ.size()!=0){

			po=PQ.top();PQ.pop();
			cntp=po.p;
		//	cout<<cnt<<' '<<po.p<<' '<<po.d<<endl;
			if(cnt%2==1){
				point next;
				next.d=po.d;
				next.p=cntp+po.d;
				PQ.push(next);
		//	cout<<"size"<<PQ.size()<<endl;
			}
			else {
		//	cout<<"size"<<PQ.size()<<endl;
				if(PQ.size()==0)break;
			}
			cnt++;
		}
		printf("%d\n", cntp);
	}

	
	//insert code
	return 0;
}
//hdu1896.cc

//AC

