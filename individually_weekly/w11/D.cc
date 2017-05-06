#include<iostream>
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

typedef unsigned U;
char ans[2][30]={
	"No.\n",
	"Yes.\n"
};
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	return 0;
}
int m[300][300];
char s[300];
void inp(){
	while(1){
		cin>>s;
		int a = s[0];
		if(a=='0')break;
		int len=strlen(s);
		int b=s[len-1];
		a-='a';
		b-='a';
	//	cout<<a<<' '<<b<<endl;
		m[a][b]=1;
	}
	//pM(m,28,28,3);
	for(int k=0;k<27;k++){
		for(int i =0;i<27;i++){
			for(int j=0;j<27;j++){
//				cout<<i<<' '<<j<<' '<<k<<endl;
				m[i][j]=m[i][j]||(m[i][k]&&m[k][j]);
			}
		}
	}
	//pM(m,28,28,3);
	cout<<ans[m['b'-'a']['m'-'a']];
}
//D.cc by xsthunder at Fri May  5 23:26:17 2017

