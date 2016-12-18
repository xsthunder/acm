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
vector<int > pro;
vector<int >per;

void sol(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		pro.clear();
		per.clear();
		ll ans=0;
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			pro.push_back(x);
		}
		for(int i=0;i<m;i++){
			int x;
			scanf("%d", &x);
			per.push_back(x);
		}
		if(n>m){
			printf("gg\n");
			continue;
		}
		sort(pro.begin(),pro.end());
		sort(per.begin(),per.end());
		unsigned int j=0;
		bool flag=0;
		for(unsigned int i=0;i<pro.size();i++){
			int hard= pro[i];
			while(j<per.size()&&hard>per[j]){
				j++;
			}
			if(j==per.size()){
				flag=1;
				break;
			}
			ans+=per[j];
			j++;
		}
		if(!flag)cout<<ans<<endl;
		else printf("gg\n");
	}
}
int main()
{
	sol();
	return 0;
}
//C.cc
//generated automatically at Sun Dec 11 18:55:12 2016
//by xsthunder

//AC at Sun Dec 11 19:12:13 2016
 
