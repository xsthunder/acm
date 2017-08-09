#include<cstdio>
#include<algorithm>
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
char s[300];
char M[300][300];
int cnt(P lt,P rb){
	int ans = 0;
	for(int i =lt.first;i<=rb.first;i++){
		for(int j=lt.second;j<=rb.second;j++){
			if(M[i][j]=='W')ans++;
		}
	}
#ifdef XS
	printf("%d,%d %d,%d   %d\n",lt.first,lt.second,rb.first,rb.second,ans);
#endif
	return ans;
}
void inp(){
	int n,m;scanf("%d%d",&n,&m);
	P lt,rb;int flag=1;
	for(int i =0 ;i<n;i++){
		scanf("%s",s);
		for(int j =0;j<m;j++){
			M[i][j]=s[j];
			if(s[j]=='B'){
				if(flag){ lt=rb=P(i,j); flag=0; }
				else {
					lt.first=min(lt.first,i);
					lt.second=min(lt.second,j);
					rb.first=max(rb.first,i);
					rb.second=max(rb.second,j);
				}
			}
		}
	}
	if(flag){
		puts("1");
		return;
	}
	int x=rb.first-lt.first;
	int y=rb.second-lt.second;
#ifdef XS
	printf("%d,%d %d,%d\n",lt.first,lt.second,rb.first,rb.second);
#endif
	if(x<y){//exp x
		while(x<y&&lt.first-1>=0){//try lt
			x++;
			lt.first-=1;
		}
		while(x<y&&rb.first+1<n){//try rb
			x++;
			rb.first+=1;
		}
	}
	if(x>y){
		while(x>y&&lt.second-1>=0){//try lt
			y++;
			lt.second--;
		}
		while(x>y&&rb.second+1<m){//try rb
			y++;
			rb.second+=1;
		}
	}
#ifdef XS
	printf("%d,%d %d,%d\n",lt.first,lt.second,rb.first,rb.second);
#endif
	if(x!=y){
		puts("-1");return;
	}
	else {
		printf("%d\n",cnt(lt,rb));
		return;
	}
}
//cf828b.cc by xsthunder at Wed Aug  9 08:49:39 2017

//AC at Wed Aug  9 18:17:06 2017
 
