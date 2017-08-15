#include<cstdio>
#include<queue>
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
freopen("cf839b.in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
const int K = 2000;
void inp(){
	int n,k;scanf("%d%d",&n,&k);
	int a;
	priority_queue<int>pq;
	for(int i =0;i<k;i++){
		scanf("%d",&a);pq.push(a);
	}
	int s2=2*n,s4=n;
	int cnt1=0;
	while(!pq.empty()&&pq.top()>=3&&s4){
		a=pq.top();pq.pop();
		s4--;a-=4;
		if(a>0)pq.push(a);
	}
	if(s4){
		while(!pq.empty()&&pq.top()==2&&s4){
			cnt1++;
			pq.pop();
			s4--;
		}
		if(s4){
			while(!pq.empty()&&pq.top()==1&&s4){
				s4--;
				cnt1++;
				pq.pop();
			}
			cnt1+=s2;
			while(!pq.empty()&&pq.top()==1&&cnt1){
				cnt1--;
				pq.pop();
			}
		}
		else {
			while(!pq.empty()&&pq.top()==2&&s2){ s2--; pq.pop(); }
			if(s2){
				cnt1+=s2;
				while(!pq.empty()&&cnt1){ cnt1--; pq.pop(); }
			}
			else {
				while(!pq.empty()&&cnt1){
					a=pq.top();pq.pop();
					cnt1--; a--;
					if(a>0)pq.push(a);
				}
			}
		}
	}
	else {
		while(!pq.empty()&&s2){
			a=pq.top();pq.pop();
			s2--;a-=2;
			if(a>0)pq.push(a);
		}
	}
	char ans[][10]={
		"NO\n","YES\n"
	};
	printf("%s",ans[pq.empty()?1:0]);
}
//cf839b.cc by xsthunder at Mon Aug 14 08:48:01 2017

//AC at Mon Aug 14 14:19:46 2017
 
