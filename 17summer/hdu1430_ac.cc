#include<cstdio>
#include<cassert>
#include<string>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
const int D  = 8;
int fac[D];
char s[D];
int kantor(int *s,int n){
	int ans =0 ,i,j,cnt;
	for(i=0;i<n;i++){
		cnt=0;
		for(j = i+1;j<n;j++){
			if(s[i]>s[j])cnt++;
		}
		ans+=fac[n-i-1]*cnt;
	}
	return ans;
}
int vtmp[30],cnt;
void Ikantor(int *a,int num,int n){
	for(int i=0;i<n;i++){ vtmp[i]=i; }
	cnt=n;
	int r;int q;
	for(int i =0;i<n;i++){
//		assert(fac[n-i-1]>0);
		q=num/fac[n-i-1];
		r=num-q*fac[n-i-1];
		a[i]=vtmp[q];
		for(int i = q;i<n;i++){
			vtmp[i]=vtmp[i+1];
		}
		cnt--;
		num=r;
	}
}

int atmp[D];
int abuf[D];
const int N = 40320;
int vis[N];
struct Q{ int cur;string sep;
	Q();Q(int cur,string sep){this->cur=cur,this->sep=sep;} };
queue<Q> q;
string ans[N];
void dfs(){
	int tmp;
	MS(vis,0);
	q.push(Q(0,string("")));
	while(!q.empty()){
		Q p = q.front();q.pop();
		if(!vis[p.cur]){
			ans[p.cur]=p.sep;
			vis[p.cur]=1;
		}
		Ikantor(abuf,p.cur,D);//abuf
		//1
		for(int i = 0;i<D;i++){ atmp[i]=abuf[D-i-1]; }
		tmp=kantor(atmp,D); if(!vis[tmp])
			q.push(Q(tmp,p.sep+"A"));
		//2
		atmp[0]=abuf[3];
		for(int i = 1;i<4;i++){ atmp[i]=abuf[i-1];}
		atmp[7]=abuf[4];
		for(int i = 4;i<7;i++){ atmp[i]=abuf[i+1];}
		tmp=kantor(atmp,D); if(!vis[tmp])
			q.push(Q(tmp,p.sep+"B"));
		//3
		atmp[0]=abuf[0],atmp[3]=abuf[3],atmp[4]=abuf[4],atmp[7]=abuf[7];
		atmp[1]=abuf[6],atmp[2]=abuf[1],atmp[5]=abuf[2],atmp[6]=abuf[5];
		tmp=kantor(atmp,D); if(!vis[tmp])
			q.push(Q(tmp,p.sep+"C"));
	}
}
int mp[300];
void inp(){
	if(scanf("%s",s)==EOF)exit(0);
	for(int i =0;i<D;i++){atmp[i]=s[i]-'0';}
	for(int i =0;i<D;i++){mp[atmp[i]]=i;}
	scanf("%s",s);
	for(int i =0;i<D;i++){atmp[i]=s[i]-'0';}
	for(int i =0;i<D;i++){atmp[i]=mp[atmp[i]];}
	int k=kantor(atmp,D);
	puts(ans[k].c_str());
}
int main(){
#ifdef XS
	freopen("hdu1430.in","r",stdin);
#endif
	fac[0]=1;
	for(int i =1;i<D+D;i++){ fac[i]=i*fac[i-1]; }
	dfs();
	while(1){ inp(); }
	return 0;
}

//hdu1430.cc by xsthunder at Thu Aug 10 10:16:30 2017

//AC at Sun Aug 20 09:57:44 2017
 
