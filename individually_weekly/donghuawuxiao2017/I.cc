#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int,int > P;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1)inp();
	return 0;
}
const int N  =2e5;
int vis[N];
bool operator > (const  P a,const P b){

	return 0;
}
void inp(){
	int n,k;
	if(!(cin>>n>>k))exit(0);
	MS(vis);
	priority_queue<P,vector<P> ,greater<P> >pq;
	for(int i =0;i<n;i++){
		int a;
		cin>>a;
		vis[a]++;
	}
	for(int i =1;i<=n;i++){
		if(vis[i])pq.push(P(i,vis[i]));
	}
	int flag=1;
	for(int i =1;i<=n;){
		P c = pq.top();
		pq.pop();
		if(c.first==i){
			c.second--;
			i++;
			c.first+=k;
			if(c.second)pq.push(c);
		}
		else if(c.first>i){
			flag=0;
			break;
		}
		else {
			c.first+=k;
			pq.push(c);
		}
	}
	cout<<(flag?"Jerry":"Tom")<<endl;
}
//I.cc by xsthunder at Fri May 26 20:06:39 2017

