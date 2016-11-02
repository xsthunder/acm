const bool test=0;
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
bool sol(){
	auto npos =string::npos;
	string s;
	cin>>s;
	IF cout<<s;
	// rule 1. s has some more
	auto pos=s.find_first_not_of("PAT");
	if(pos!=npos)return 0;
	//rule 2 &3
	auto ppos=s.find_first_not_of("A");
	auto tpos=s.find_first_not_of("A",ppos+1);
	//s has lack of some P or A
	if(ppos==npos||tpos==npos)return 0;
	if(s[ppos]!='P'||s[tpos]!='T')return 0;
	pos=s.find_first_not_of("A",tpos+1);
	if(pos!=npos)return 0;
	auto alen=ppos;
	auto blen=tpos-ppos-1;
	auto clen=s.size()-tpos-1;
	IF cout<<alen<<' '<<blen<<' '<<clen<<' '<<s<<endl;
	if(blen==0)return 0;
	if(alen<0||blen<0||clen<0)return 0;
	if(clen ==blen*alen )return 1;
	else return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)printf(sol()?"YES\n":"NO\n");
	return 0;
}
//bsc_1003.cc
//generated automatically at Sun Oct 30 14:43:14 2016
//by xsthunder

//AC at Sun Oct 30 15:47:59 2016
 
