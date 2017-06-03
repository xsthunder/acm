#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include</home/xs/acm/modules/mylib/De>
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
const int N = 60;
int n;
int a[N][N];;
int res[N][N];;
int dir[4][2]={
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};
const int R =0;
const int C =1;
const int inf  =1e7;
struct nod{
	int val;
	int r;
	int c;

};
bool operator< (const nod &b,const nod &a){
	return b.val>a.val;
}
priority_queue<nod> pq;

void ds(){
	pq.push(nod{0,1,1});
	res[1][1]=0;
	while(!pq.empty()){
		nod n = pq.top();pq.pop();
		int r=n.r,c=n.c;
		for(int i =0;i<4;i++){
			int nr=n.r+dir[i][R],nc=n.c+dir[i][C];
			if(a[nr][nc]<0);
			else {
				if(res[nr][nc]>res[r][c]+(a[r][c]||a[nr][nc])){
					(res[nr][nc]=res[r][c]+(a[r][c]||a[nr][nc]));
//					cout<<P(nr,nc);
					pq.push(nod{res[nr][nc],nr,nc});
				}
			}
		}
		//exit(1);
//		cout<<P(r,c)<<endl;
//		pM(res,5,5,4);
	}
}
void inp(){
	if(!(cin>>n))exit(0);
	while(!pq.empty())pq.pop();
	for(int i =0;i<n+1;i++){
		a[0][i]=-1;
		a[n+1][i]=-1;
		a[i][0]=-1;
		a[i][n+1]=-1;
	}
	for(int i=1;i<=n;i++){
		for(int j =1;j<=n;j++){
			char x;
			res[i][j]=inf;
			cin>>x;
			a[i][j]=x!='*';
		}
	}
	ds();
//	pM(res,n+2,n+2,4);
	cout<<res[n][n]<<endl;
}
//B.cc by xsthunder at Sat Jun  3 13:45:58 2017

//AC at Sat Jun  3 14:25:14 2017
 
