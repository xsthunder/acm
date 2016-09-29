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
int n,k;
const int N=1000+50;
const int NN=2000+50;
int A[NN];//可以节省空间
int D[N][N];
int P[N];
int s1(int x,int y){
	int ans=D[x][y];
	if(ans==-1)return inf;
	return ans;
}
int s2(int x,int y){
	int ans=D[x][y];
	if(ans==-1)return inf;
	return ans+P[];
}

int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	while(cin>>n>>k){
		memset(D,-1,sizeof(D));
		for(int i=1;i<=n;i++){
			SC(A[i]);
//			cout<<A[i];
		}
		sort(A+1,A+n+1);
		for(int i=2;i<=n;i+=2){
			P[i/2]=A[i]-A[i-1];
			P[i/2]*=P[i/2];
		}
//		for(int i=1;i<=n/2;i++){
//			printf("%3d", P[i]);
//		}
//		cout<<endl;
		D[1][1]=P[1];
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=i;j++){
				D[i][j]=min(s1(i-1,k),s2(i-1,k-1));
				//D[i][j]=min(D[i-1][k],D[i-1][k-1]+P[i]);
			}
		}
		for(int i=1;i<=n/2;i++){
			cout<<"i#"<<i<<' ';
			for(int j=1;j<=i;j++){
				printf("%3d",D[i][j]);
			}
			cout<<endl;
		}
		cout<<D[n/2][k]<<endl;
	}

	
	//insert code
	return 0;
}
//hdu1421.cc

