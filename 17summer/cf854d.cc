#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<cassert>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef unsigned long long ll;
void inp();
int main(){
#ifdef XS
	freopen("cf854d.in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int  N= 2e5,M = 2e6;
map<int ,int> I[N],O[N];
typedef map<int ,int >::iterator IT;
int tim[M];
vector<int > ve;
queue<int >qd;
queue<P > qp;
ostream & operator << (ostream &ou,P a){
	ou<<'('<<a.first<<','<<a.second<<')';
	return ou;
}
void deqp(){
	while(!qp.empty()){ cout<<qp.front()<<endl; qp.pop(); }
}
void deqd(){
	while(!qd.empty()){ cout<<qd.front()<<endl; qd.pop(); }
}
template<class T>
void psize(T a){
	cout<<a.size()<<endl;
}
void inp(){
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	int d,f,t,c,x;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&d,&f,&t,&c);
		if(f==0){
			d--;
			if(O[t].count(d)){
				O[t][d]=min(O[t][d],c);
			}
			else O[t][d]=c;
		}
		else if(t==0){
			d++;
			if(I[f].count(d)){
				I[f][d]=min(I[f][d],c);
			}
			else I[f][d]=c;
		}
		ve.push_back(d);
	}
	for(int i=1;i<=n;i++){
		if(I[i].empty()||O[i].empty()){
			puts("-1");return ;
		}
	}
	for(int i=1;i<=n;i++){ tim[I[i].begin()->first]=1; tim[O[i].rbegin()->first+1]=-1; }
	for(int i=1;i<M;i++){ tim[i]+=tim[i-1]; }
	f=0,t=0,x=0;
	for(int i=1;i<M;i++){
		if(tim[i]==n){
			if(!f)f=i;
			x++;
		}
		else {
			if(f&&x>=k){
				t=i-1;
				qp.push(P(f,t));
			}
			f=0,t=0,x=0;
		}
	}
	P p;
	ll mx=(-1LL),sum;
	sort(ve.begin(),ve.end());
	ve.resize(unique(ve.begin(),ve.end())-ve.begin());
	sort(ve.begin(),ve.end());
	for(auto x:ve){ qd.push(x); }
	for(int i = 1;i<=n;i++){
		int pre = 1e9;
		for(auto it  = O[i].rbegin();it!=O[i].rend();it++){
			it->second=pre = min(pre,it->second);
		}
		pre = 1e9;
		for(auto it = I[i].begin();it!=I[i].end();it++){
			it->second = pre = min(pre ,it->second);
		}
	}
	if(qp.empty()){
		puts("-1");
		return;
	}
	while(!qp.empty()){
		p = qp.front(),qp.pop();
		f = p.first,t=p.second;
		while(!qd.empty()&&qd.front()<f)qd.pop();
		//psize(qd);
		if(qd.empty())break;
		//psize(qd);
		while(!qd.empty()&&t-qd.front()+1>=k){
			//psize(qd);
			f = qd.front();sum=0; qd.pop();
			for(int i=1;i<=n;i++){
				IT it1 = I[i].lower_bound(f);
				if(it1==I[i].end()||it1->first>f)it1--;
				IT it2 = O[i].lower_bound(f+k-1);
				sum+=it1->second+it2->second;
			}
			mx=min(mx,sum);
		}
	}
	assert(mx!=(-1LL));
	printf("%llu\n",mx);
}
//cf854d.cc by xsthunder at Fri Sep 29 20:36:40 2017

