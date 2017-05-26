const bool test=1;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
struct sub{
	char content;
	sub *nxt=NULL;
};
struct header {
	char content=0;
	sub * left=NULL;
	sub *right=NULL;
}head;
void print (sub* nxt){
	if(nxt==NULL)return;
	print((*nxt).nxt);
	cout<<(*nxt).content;
	return ;
}
void sol(){
	int n;
	string s ;
	cin>>n>>s;
	bool flag=0;
	if(n%2)flag=1;
	bool first=0;
	for(unsigned int i=0;i<s.length();i++){
		sub * rnxt;
		sub * lnxt;
		char x=s[0];
		if(flag){
			head.content=x;
			flag=0;
			continue;
		}
		if(first){
			first=0;
			sub * r=new sub;
			sub * l = new sub;
			lnxt=head.left=l;
			rnxt=head.right=r;
			(*l).content= x;
			(*r).content= s[i+1];
			i++;
		}
		sub * r=new sub;
		sub * l = new sub;
		(*rnxt).nxt=r;
		(*lnxt).nxt=l;
		(*l).content= x;
		(*r).content= s[i+1];
		i++;
	}
	print(head.left);
	if(head.content)cout<<head.content;
	print(head.right);
	cout<<endl;
}
int main()
{
	sol();
	return 0;
}
//B.cc
//generated automatically at Sun Dec 18 18:56:40 2016
//by xsthunder

