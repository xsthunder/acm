#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
void inp(){
	int n,a,b;scanf("%d%d%d",&n,&a,&b);
	int ans=0;
	int c =0 ;
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x==1){
			if(a)a--;
			else if(b){
				b--;c++;
			}
			else if(c){
				c--;
			}
			else ans++;
		}
		else {
			if(b)b--;
			else ans+=2;
		}
	}
	printf("%d\n",ans);
}
//cf828a.cc by xsthunder at Wed Aug  9 08:38:57 2017

//AC at Wed Aug  9 09:13:50 2017
 
