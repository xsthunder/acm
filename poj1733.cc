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
typedef unsigned long long int llu;
map<llu,llu>parent;
map<llu,llu>offsetval;
llu Find(llu x){
	if(!parent.count(x))parent[x]=x;
	if(x==parent[x])return x;
	return Find(parent[x]);
}
int offset(llu tem,llu tem2){
	llu x=min(tem,tem2);
	llu y=max(tem,tem2);
	if(parent[y]==x)return offsetval[y];
	else return offsetval[y]+offset(parent[x],Find(parent[x]));

}
int turn(char x)
{
	switch(x){
		case 'o' :return 1;
		case 'e':return 0;
		default:exit(1);
	}
}
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int k;
	llu n;
	scanf("%llu%d",&n,&k);
	int ans=0;
	llu x,y;
	char s[10];
	while(k--){
		scanf("%llu%llu%s",&x,&y,s);
		if(x>n||y>n)goto out;
		else if(x>=y)goto out;
		else {
			char ch=s[0];
			int d=turn(ch);
			llu xfa,yfa;
			x-=1;
			xfa=Find(x);
			yfa=Find(y);
			if(xfa==yfa){
				if((offset(yfa,y)+d)%2==offset(xfa,x))ans++;
				else goto out;
			}
			else{
				ans++;
				parent[max(yfa,xfa)]=min(yfa,xfa);
				if(xfa>yfa){
					offsetval[xfa]=(offset(y,yfa)-offset(x,xfa)+d)%2;
				}
				else{
					offsetval[yfa]=(offset(x,xfa)-offset(y,yfa)+d)%2;
				}
			}
		}
	//for(int x=1;x<11;x++)printf("%5d",x);cout<<endl;
	//for(auto it=parent.begin();it!=parent.end();it++)printf("%2llu:%2llu",it->first,it->second);cout<<endl;
	//for(auto it=offsetval.begin();it!=offsetval.end();it++)printf("%2llu:%2llu",it->first,it->second);cout<<endl;
	}
out:
	printf("%d\n",ans);
	//insert code
	return 0;
}
//poj1733


