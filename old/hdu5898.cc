#include <cstdio>
using namespace std;
typedef long long int ll;
ll l,r;
int arr[20];

int dfs(int len,int pre,bool odd,bool num,bool limit,bool iszer){
	if(len==-1)return odd!=num;
	int ans=0;
	int up=limit?arr[len]:9;
	for(int i=0;i<up;i++){
		if(iszer){
			if(i==0){
				ans+=dfs(len-1,i,true,true,true,true);
			}else ans+=dfs(len-1,i,isodd(i),1,islimt,false);
		}
	}
}
void solve(){
    while{

		}
		printf("%d",)
}
int main(){
	int t;
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++){
		scanf("%lld%lld",&l.&r);
		printf("Case%d: ",ca);
		solve();
	}
}
