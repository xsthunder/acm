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
bool flag;
int solve(){
	int w1,d1,w2,d2;
	scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
	//cout<<w1<<" "<<d1<<" "<<w1<<" "<<d2;
	if(!w1)w1=solve();
	if(!w2)w2=solve();
	//cout<<w1<<" "<<d1<<" "<<w1<<" "<<d2;
	if(w1*d1==w2*d2)return w1+w2;
	else {flag=0;return w1+w2;}

}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	while(n--){
		flag=1;
		solve();
		printf("%s\n",flag?"YES":"NO");
		if(n!=0)printf("\n");
	}

	
	//insert code
	return 0;
}
//7-27a.cc

