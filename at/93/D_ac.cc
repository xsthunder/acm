#include<cstdio>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
#ifdef XS
const int w = 10,h = 10;
#else
const int w = 100,h = 100;
#endif
char ans[200][200];
void inp(){
	int a,b;scanf("%d%d", &a,&b);
	char ca = '.',cb = '#';
	int i;
	// xian gao b yong a 
	for(i =0 ; b > 1 && i< h;i++){
		if( i % 2 == 0 ){
			for(int j = 0; j < w;j++){
				if(b == 1 || j % 2)ans[i][j] = ca;
				else {
					ans[i][j] = cb;
					b --;
				}
			}
		}
		else for(int j =0 ;j<w;j++)ans[i][j] = ca;
	}

	for(int j = 0;j<w;j++)ans[i][j] = ca;
	i++;
	a --;
	// ...........

	// ############
	for(int j = 0;j<w;j++)ans[i][j] = cb;
	i++;
	b --;

	assert( b == 0);
	int f = 0;
	for(;a > 0 &&  i < h;i++, f ++){
		if( f % 2  == 0){
			for(int j =0 ;j<w;j++){
				if( a == 0||j % 2 == 1){
					ans[i][j] = cb;
				}
				else {
					ans[i][j] = ca;
					a--;
				}
			}
		}
		else {
			for(int  j= 0;j<w;j++)ans[i][j] = cb;
		}
	}
	assert(a == 0&& b == 0);
	printf("%d %d\n", i,w);
	for(int k =0 ;k<i;k++){
		for(int j =0 ;j<w;j++){
			putchar(ans[k][j]);
		}
		putchar('\n');
	}
}
//D.cc by xsthunder at Sun Mar 25 20:22:27 2018

//AC at Sun Mar 25 22:01:10 2018
 
