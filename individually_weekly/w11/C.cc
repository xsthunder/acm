#include<iostream>
#include<vector>
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
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	return 0;
}
int m[300][300];
char s[300];
char ans[2][10]={
	"No.\n",
	"Yes.\n"
};
vector<int  > v[300];
#define cor(x,y) m[x][y]
int flag=0;
int vis[300];
void find(int b){
	if(vis[b])return ;
	vis[b]=1;
	if(b=='m'){
		cout<<ans[1];
		exit(0);
	}
	for(int i ='a';i<'z'+1;i++){
		if(m[b][i])
			find(i);
	}
}
void inp(){
	MS(m);
	MS(vis);
	while(1){
		cin>>s;
		if(s[0]=='0')break;
		int len = strlen(s);
		int a=s[0];
		int b=s[len-1];
		m[a][b]=1;
	}
	find('b');
	cout<<ans[0];
}
//C.cc by xsthunder at Fri May  5 18:47:13 2017

