#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
using namespace std;
const int inf=0x7fffffff;
const int N_UN=300;
const int N_S=1e3+10;
int p[N_UN];
int ieul[N_UN];
int oeul[N_UN];
int eul[N_UN];
int t;
char s [N_S];
const int un_s ='a';
const int un_e='z';
const char ans[][100]={
	"The door cannot be opened.",
	"Ordering is possible."};
void init(){
	memset (eul,0,sizeof(eul));
	memset (ieul,0,sizeof(oeul));
	memset (oeul,0,sizeof(oeul));
	for(int i=un_s;i<=un_e;i++){
		p[i]=i;
	}
}
int un_find(int x){
	if(p[x]==x)return x;
	else return un_find(p[x]);
}
void un_set(int x,int y){
	int xfa,yfa;
	xfa=un_find(x);
	yfa=un_find(y);
	if(xfa==yfa){
		return ;
	}
	else {
		p[xfa]=yfa;
		return ;
	}
}
bool check_un(){
	int head=0;
	for(int i=un_s;i<=un_e;i++){
		if(eul[i])head=un_find(i);
	}
	if(!head)cout<<"wrong head";
	else {
		for(int i=un_s;i<=un_e;i++){
			if(eul[i])if(head!=un_find(i))return 0;
		}
	}
	return 1;
}
bool check_eul(){
	int flag=0;
	int cntodd=0;
	for(int i=un_s;i<=un_e;i++)if(eul[i]){
		if(ieul[i]!=oeul[i]){
			cntodd++;
			if(abs(ieul[i]-oeul[i])!=1)return 0;
			flag+=ieul[i]-oeul[i];
		}
	}
	if(cntodd==0)return 1;
	else if(cntodd==2){if(flag==0)return 1;}
	else return 0;
}

int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d", &n);
		init();
		t=n;
		while(n--){
			scanf("%s" , s);
			int x,y;
			x=s[0];
			y=s[strlen(s)-1];
			eul[x]++;
			eul[y]++;
			ieul[x]++;
			oeul[y]++;
			un_set(x,y);
//			for(int i=un_s;i<=un_e;i++)if(eul[i]){cout<<(char)i<<"eul "<<eul[i]<<" p "<<(char)p[i]<<" ieul "<<ieul[i]<<" oeul "<<oeul[i]<<endl;}
		}
		printf("%s\n", ans[check_un()&&check_eul()]);
	}

	
	//insert code
	return 0;
}
//uva10129.cc

