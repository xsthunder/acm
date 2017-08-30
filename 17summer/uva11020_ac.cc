#include<cstdio>
#include<set>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int N;
int main(){
#ifdef XS
	freopen("uva11020.in","r",stdin);
#endif
	scanf("%d",&N);for(int i=1;i<=N;i++) inp();
	return 0;
}
int TT=0;
typedef  multiset<P> S;
S s;
S::iterator it;
P p;
void inp(){
	int n;scanf("%d",&n);
	printf("Case #%d:\n",++TT);
	s.clear();
	for(int i=0;i<n;i++,printf("%lu\n",s.size())){
		scanf("%d%d",&p.first,&p.second);
		it=s.lower_bound(p);
		if(it==s.begin()||(--it)->second>p.second){
			it=s.upper_bound(p);
			while(it!=s.end()&&it->second>=p.second)s.erase(it++);
			s.insert(p);
		}
	}
	if(TT!=N)putchar('\n');
}
//uva11020.cc by xsthunder at Fri Aug 25 15:42:48 2017

//AC at Fri Aug 25 16:20:20 2017
 
