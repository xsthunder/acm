#include<iostream>
#include<cstring>
using namespace std;
const int MN = 2;
typedef int M[MN][MN];
void MtM(M a,M b,M res){
	M ans={{0}};
	for(int i =0;i<MN;i++){
		for(int j =0;j< MN;j++){
			ans[i][j]=0;
			for(int k =0 ;k<MN;k++){
				ans[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	memcpy(res,ans,sizeof(ans));
}
void pM(const M a){
	for(int i =0;i< MN;i++){
		for(int j =0;j< MN;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}
void qpM(M a, int n,M ans){
	for(int i=0;i<MN;i++){
		for(int j =0;j<MN;j++){ 
			ans[i][j]=0;
			if(i==j)ans[i][j]=1;
		}
	}
	while(n){
		if(n&1)MtM(a,ans,ans);
		n>>=1;
		MtM(a,a,a);
	}
}
int qp(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=a*ans;
		n>>=1;
		a*=a;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	if(n<=2){cout<<1<<endl;
		return 0;
	}
	n-=2;
	M ans={{0}};
	M v{ 1,1,
		1,0 };
	qpM(v,n,ans);
	pM(ans);
	cout<<ans[0][1]+ans[0][0]<<endl;
	return 0;
}
