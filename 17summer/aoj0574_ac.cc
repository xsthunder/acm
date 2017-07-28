#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("aoj0574.in","r",stdin);
#endif
	try{
		//while(1)
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
typedef vector<int > VI;
typedef vector<VI> VII;
void pA(VII &vii){
	for(U i = 0;i<vii.size();i++){
		for(U j = 0;j<vii[i].size();j++){
			printf("(%2d,%2d)", i,j);
		}
		printf("\n");
		for(U j = 0;j<vii[i].size();j++){
			printf("%7d",vii[i][j]);
		}
		printf("\n");
	}
}
VII vii;
void inp(){
	int n,m;scanf("%d%d",&n,&m);
	const int A = n+3;
	vii.resize(A);
	for(U i = 0;i< vii.size();i++){
		vii[i].resize(i+4, 0 );
	}
	for(int i = 1;i<=m;i++){
		int a,b,x;scanf("%d%d%d",&a,&b,&x);
	//	printf("%d%d%d\n",a,b,x);
		vii[a-1][b	] 	+= -1;
		vii[a-1][b+1] 	+= 1;
		vii[a+x][b	] 	+= 1;
		vii[a+x][b+x+2] += -1;
		vii[a+x+1][b+1]	+=-1;
		vii[a+x+1][b+x+2]+=1;
	}
	//flow
	//pA(vii);
	for(int i = 0;i<A;i++){
		for(U j = 1;j<vii[i].size();j++){
			vii[i][j] += vii[i][j-1];
		}
	}
	//pA(vii);
	for(int j = 0;j< vii[vii.size()-1].size() ;j++){
		for(int  i = vii.size() - 2 ;i >= j-1&&i>=0 ;i--){
			vii[i][j] += vii[i+1][j];
		}
	}
	//pA(vii);
	for(U i = 1; i < vii.size();i++){
		for(U j = 1;i + j < vii.size()&&j<vii[j].size();j++){
			vii[i + j -1][j] += vii[i  +j-2][j-1];
		}
	}
	int ans = 0;
	for(int i = 1;i<= n;i++){
		for(int  j = 1;j<=i;j++){
			if(vii[i][j]) ans++;
		}
	}
#ifdef XS
	pA(vii);
#endif
	printf("%d\n", ans);
}
//aoj0574.cc by xsthunder at Wed Jul 26 03:28:21 2017

//AC at Wed Jul 26 07:05:52 2017
 
