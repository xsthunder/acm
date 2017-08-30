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
const int N = 300;
int mp[N];
char s[N];
void inp(){
	int n,k;scanf("%d%d%s",&n,&k,s);
	for(int i =0;i<n;i++){
		mp[int(s[i])]++;
	}
	int flag=1;
	for(int i=int('a');i<=int('z');i++){
		if(mp[i]>k){flag=0;
			break;
		}
	}
	puts(flag?"yes":"NO");
}
//cf841a.cc by xsthunder at Tue Aug 29 09:21:36 2017

//AC at Tue Aug 29 09:25:03 2017
 
