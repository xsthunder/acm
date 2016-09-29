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
const int N=250000+10;
int c1[N],c2[N];
int V[55],M[55];

int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n;
	while(SC(n)!=EOF&&n>0){
		int sum=0;
		MS(V);MS(M);
		MS(c1);MS(c2);
		for(int i=1;i<=n;i++){
			SC(V[i]);SC(M[i]);
			sum+=V[i]*M[i];
		}
		for(int i=0;i<=M[1];i++){
			c1[i*V[1]]=1;
		}
		for(int i=2;i<=n;i++){
			//cout<<i<<endl;
			for(int j=0;j<=N;j++){
				if(!c1[j])continue;
				for(int k=0;k<=M[i];k++){
					c2[k*V[i]+j]+=c1[j];//改动这里，指数以k×V的倍数增加
				}
			}
//			for(int i=0;i<=sum;i++){
//				if(c2[i])printf("%dx^%d " ,c2[i],i);
//			}
//			cout<<endl;
			for(int i=0;i<=N;i++){
				c1[i]=c2[i];
				c2[i]=0;
			}
		}
//		for(int i=0;i<=sum;i++){
//			if(c1[i])printf("%dx^%d " ,c1[i],i);
//		}
//		cout<<endl;
		for(int i=sum/2;i>=0;i--){
			if(c1[i]){
				cout<<sum-i<<' ' <<i<<endl;
				break;

			}
		}
		//break;
	}
	//insert code
	return 0;
}
//hdu1171.cc

