#include<cstdio>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
typedef set<P> Set;
Set s;
void inp();
bool _gm (const P a,const P b){
	if(a.first == b.first)return a.second < b.second;
	return a.first > b.first;
}
int main(){
#ifdef XS
	freopen("zoj3261.in","r",stdin);
#endif
	//cout<<boolalpha;
	//cout<<"P(3,2)>P(2,2)"<<boolalpha<<(P(3,2)>P(2,2))<<endl;
	//cout<<"P(2,3)>P(2,1)"<<(P(2,3)>P(2,1))<<endl;
	//return 1;
	try{
		while(1)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 1e4 + 100;
int _pow[N];
struct T{
	int a,b;// b = -1 if des
	int ans ;
	void set(int a,int b = -1){
		this->a = a;
		this->b = b;
	}
	void setans(int ans){
		this->ans = ans;
	}
}nod[5*N];
int p[N];
P w[N];//first: weight second : index
int find(int);
void con(int a,int b){
		int fa = find(a);
		int fb = find(b);
		if(p[fa]>p[fb]){
			swap(a,b);
			swap(fa,fb);
		}
		if(fa == fb)return ;
#define gm(x,y) _gm(x,y)?x:y
		p[fa] += p[fb];
		p[fb] = fa;
		w[fa] = w[fb] = gm(w[fa], w[fb]);
}
int que(const int a){
	int fa = find(a);
	P ans = w[fa];
	
	if(ans.first == _pow[a]||ans.second == a)return -1;
	return ans.second;
}
void start(int q ){
	while(q--){
		int a = nod[q].a, b = nod[q].b;
		if(b==-1){
			nod[q].ans = (que(a));
		}
		else {
			con(a,b);
		}
	}
}
int find (int a){
	if(p[a]<0)return a;
	return p[a] = find(p[a]);
}
void init(){
	for(auto x : s){
		int a = x.first;
		int b = x.second;
		con(a,b);
	}
}
int flag = false;
void inp(){
	MS(nod);MS(_pow);MS(w);
	s.clear();
	memset(p,-1,sizeof(p));
	int n;if(!~scanf("%d",&n))exit(0);
	if(flag){
		printf("\n");
	}
	flag = true;
	for(int i = 0 ;i<n;i++){
		scanf("%d", 	&_pow[i]);
		w[i] = P(_pow[i],i);
	}
	int m;scanf("%d",&m);
	while(m--){
		int a,b;scanf("%d%d",&a,&b);
		if(a>b)swap(a,b);
		s.insert(P(a,b));
	}
	int q;scanf("%d",&q);
	for(int i = 0;i<q;i++){
		char str[10]; scanf("%s",str);
		if(str[0]=='d'){
			int a,b; scanf("%d%d", &a,&b);
			if(a>b)swap(a,b);
			s.erase(P(a,b));
			nod[i].set(a,b);
		}
		else {
			int a;scanf("%d",&a);
			nod[i].set(a);
		}
	}
	init();
	start(q);
	for(int i = 0;i<q;i++){
		if(nod[i].b == -1)printf("%d\n", nod[i].ans);
	}
}
//zoj3261.cc by xsthunder at Mon Jul 24 07:05:12 2017

//AC at Mon Jul 24 13:46:25 2017
 
