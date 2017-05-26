#define IF if(0);
#include<algorithm>
#include<cstdio>
#include<queue>
#include<iostream>
#include<vector>
#include<utility>
#include<map>
#define mk(a,b) make_pair((a),(b))
using namespace std;
const int K = 15e4+1000;
const int SIZE= 200+20;
char S[K][SIZE];
int V[K];
int k,m,q;
map<int ,int >O;
typedef pair<int ,int > P;
namespace std{
	bool operator < (P a,P b){
		if(a.first<b.first)return true;
		if(a.first==b.first)return a.second>b.second;
		return false;
	}
}
int cnt;
void sol(){
	priority_queue<P> pp;
	int t,p;
	int fp=1;
	P tmp;
	cnt=0;
	vector<P> qp;
	for(int i= 0;i< m;i++){
		scanf("%d%d",&t,&p);
		qp.push_back(mk(t,p));
	}
	sort(qp.begin(),qp.end());
	for(int i = 0 ;i<m;i++){
		t=qp[i].first,p=qp[i].second;
		for(;fp<=t;fp++){
			pp.push(mk(V[fp],fp));
//			IF cout<<"in"<<fp<<endl;
		}
		while(p--&&!pp.empty()){
			tmp= pp.top();
			pp.pop();
			O[++cnt]=tmp.second;
		}
	}
	for(;fp<=k;fp++){
		pp.push(mk(V[fp],fp));
	}
	while(!pp.empty()){
		tmp= pp.top();
		pp.pop();
		O[++cnt]=tmp.second;
	}
}
void que(){
	int kth=0;
	bool flag=0;
	while(q--){
		if(flag){
			printf(" ");
		}
		flag=1;
		scanf("%d", &kth);
		//		IF printf("%d %d", kth,O[kth]);
		printf("%s", S[O[kth]]);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&k,&m,&q);
		for(int i = 1 ;i<=k;i++){
			scanf("%s%d",&S[i][0],&V[i]);
		}
		sol();
		que();
		printf("\n");
	}
}

//AC at Sun Mar 19 21:38:22 2017
 
