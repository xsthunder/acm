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
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
void inp(){
	int n;scanf("%d",&n);
	int x,cnt=0;;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x&1){cnt=1;
			break;
		}
	}
	puts(cnt?"First":"Second");

}
//cf841b.cc by xsthunder at Tue Aug 29 09:25:08 2017

//AC at Tue Aug 29 09:41:12 2017
 
