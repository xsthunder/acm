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
const int inf=0x7fffffff;
typedef long long int ll;
int a[5][4][11];
int main()
{
#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	memset(a,0,sizeof(a));
	int n;
	scanf("%d", &n);
	while(n--){
		int b,f,r,v;scanf("%d%d%d%d", &b,&f,&r,&v);
		a[b][f][r]+=v;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=10;k++){ 
				printf(" %d", a[i][j][k]);
			}
			printf("\n");
		}
		if(i!=4){for(int z=0;z<20;z++)printf("#");
		printf("\n");}
	}
	
	//insert code
	return 0;
}
//aog1_6_c.cc

