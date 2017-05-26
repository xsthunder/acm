#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif
typedef long long ll;
typedef unsigned U;
typedef pair<int,int > P;
const int D=7;
typedef ll M[7][7];
const ll MOD= 2147493647;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)inp();
	return 0;
}
void MtM(M a,M b, M ans){
	M t;
	for(int i =0;i<D;i++){
		for(int j=0;j<D;j++){
			t[i][j]=0;
			for(int k=0;k<D;k++){
				t[i][j]+=a[i][k]*b[k][j];
			}
			t[i][j]%=MOD;
		}
	}
#define CP(ans,t) memcpy(ans,t,sizeof(t))
	CP(ans,t);
}
void powM(int n,M a,M ans){
	M t;
	MS(t);
	for(int i=0;i<D;i++){
		t[i][i]=1;
	}
	//pM(t,D,D,3);
	while(n){
		if(n&1){
			MtM(a,t,t);
		}
		MtM(a,a,a);
		//cout<<"n:"<<n<<endl;
		//pM(a,D,D,3);
		//pM(t,D,D,3);
		n>>=1;
	}
	CP(ans,t);
}
void inp(){
	ll n,a,b;
	cin>>n>>a>>b;

	if(n==1){
		cout<<a<<endl;
		return ;
	}
	if(n==2){
		cout<<b<<endl;
		return ;
	}
	n-=2;
	M u = {
		{1,2,1},
		{1},
		{0,0,1,4,6,4,1},
		{0,0,0,1,3,3,1},
		{0,0,0,0,1,2,1},
		{0,0,0,0,0,1,1},
		{0,0,0,0,0,0,1}
	};
	M ans;
	MS(ans);
	powM(n,u,ans);
	cout<<(ans[0][0]*b+ans[0][1]*a+ans[0][2]*3*3*3*3+ans[0][3]*3*3*3+ans[0][4]*3*3+ans[0][5]*3+ans[0][6]*1)%MOD<<endl;
}
//C.cc by xsthunder at Tue May  9 18:36:01 2017


