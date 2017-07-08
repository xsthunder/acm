#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	const int Te=1;
#else 
	const int Te=0;
#endif
using namespace std;
#define IF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#define CP(des,sou,size) memcpy(des,sou,size)

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
//	freopen("poj2991.in","r",stdin);
	try{
		while(1)inp();
	}
	catch(... ){
		IF printf("%s","exception");
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 1e4+1e3;
int w[N];
int pre[N];
int angle[N];
typedef double M [2][2];
M m[N*4];
void init(int root , int l ,int r ){
	if(l==r){
		m[root][1][1]=w[l];
		return;
	}
	int mid =(l+r)/2;
	int lch = root*2;
	int rch = root*2+1;
	init(lch,l,mid);
	init(rch,mid+1,r);
	m[root][1][1] = m[lch][1][1]+m[rch][1][1];
}
const double PI= acos(-1); 
inline void getM(int a,M tmp){
#define getRad(x) (PI/180.0*x)
	double rad = getRad(a);
	tmp[0][0]=cos(rad);
	tmp[0][1]=-sin(rad);
	tmp[1][0]=sin(rad);
	tmp[1][1]=cos(rad);
}
inline void MtM(M a,M b,M ans){
	M tmp;
	for(int i = 0;i<2;i++){
		for(int j=0;j<2;j++){
			double &tar = tmp[i][j];
			tar = 0.0;
			for(int k=0;k<2;k++){
				tar+=a[i][k]*b[k][j];
			}
		}
	}
	CP(ans,tmp,sizeof(M));
}
inline void MpM(M a,M b,M ans){
	M tmp;
	for(int i =0;i<2;i++){
		for(int j=0;j<2;j++){
			tmp[i][j]=a[i][j]+b[i][j];
		}
	}
	CP(ans,tmp,sizeof(tmp));
}

void upd(int s,int a,int root,int l,int r){
	if(s<l){
		return;
	}
	if(s>=r)return;
	if(l==r)return;
	int mid = (l+r)/2;
	int lch = root*2;
	int rch = root*2+1;
	upd(s,a,lch,l,mid);
	upd(s,a,rch,mid+1,r);
	M tmp;
	if(s<=mid)angle[root]+=a;
	getM(angle[root],tmp);
	MtM(tmp,m[rch],m[root]);
	MpM(m[root],m[lch],m[root]);
}
void inp(){
	int n,c;
	if(!~scanf("%d%d",&n,&c))exit(0);
	for(int i =1;i<=n;i++)scanf("%d" ,&w[i]),pre[i]=180,angle[i]=0;
	MS(m);
	init(1,1,n);
	//	printf("%.2lf %.2lf\n",m[1][0][1],m[1][1][1]);
	//	exit(0);
	while(c--){
		int s,a;
		scanf("%d%d", &s,&a);
		upd(s,a-pre[s],1,1,n);
		pre[s]=a;
		printf("%.2lf %.2lf\n",m[1][0][1],m[1][1][1]);
	}
	printf("\n");
}
//poj2991.cc by xsthunder at Sat Jul  8 13:44:06 2017

//AC at Sat Jul  8 15:38:34 2017
 
