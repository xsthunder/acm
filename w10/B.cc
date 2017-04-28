#include<iostream>
#include<cmath>
#include<iomanip>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#define mk(a,b) make_pair(a,b)
using namespace std;
void inp();
void fld();
const int N =100+100;
typedef int E[N][N];
E e;
int n,ec;
typedef pair<int,int> pqe;
const int test=0;
#define IF if(test)
void pM(int width=4){
	cout<<0;
	for(int j =1;j<=n;j++){
		cout<<setw(width)<<j;
	}
	cout<<endl;
	for(int i =1;i<=n;i++){
		cout<<i<<' ';
		for(int j =1;j<=n;j++){
			cout<<setw(width)<<e[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
void fld(){
	for(int k=1;k<=n;k++){
		for(int i =1;i<=n;i++){
			for(int j=1;j<=n;j++){
				e[i][j]=max(e[i][j],min(e[i][k],e[k][j]));
			}
			//IF pM();
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int cnt=0;
	while(cin>>n>>ec){
		if(n==0&&ec==0)return 0;
		inp();
		int s,t,p;
		cin>>s>>t>>p;
		fld();
		p++;
		int div;
		div  =  e[s][t]-1;
		IF cout<<s<<' '<<t<<endl;;
		IF cout<<p<<' '<<div<<endl;
		IF if(div==0){
			pM();
			return 0;
		}
		cout<<"Scenario #"<<++cnt<<endl;
		if(cnt==7)cout<<div<<endl;
		cout<<"Minimum Number of Trips = "<<ceil((p*1.0f)/div)<<endl;;
		cout<<endl;
	}
	return 0;
}
const int inf = 1e9;
void inp(){
	for(int i =1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[i][j]=0;
		}
	}
	for(int i =0;i<ec;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e[a][b]=c;
		e[b][a]=c;
	}
}
