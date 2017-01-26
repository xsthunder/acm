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
int used[10];
void build(int dep, string now , vector<string> &v){
	if(dep==4){
		v.push_back(now);
		return ;
	}
	for(int i=0;i<10;i++){
		if(!used[i]){
			used[i]=1;
			build(dep+1,now+char(i+'0'),v);
			used[i]=0;
		}
	}
}
pair<int ,int > query(string s ){
	point tmp;
	cout<<s<<endl;
	fflush(stdout);
	cin>>tmp.first>>tmp.second;
	return tmp;
}
point check (string a, string b){
	int bull=0,cow=0 ;
	for(int i=0;i<4;i++){
		if(a[i]==b[i]){bull++;
		}
		used[a[i]-'0']=1;
	}
	for(int i=0;i<4;i++){
		cow+=used[b[i]-'0'];
	}
	for(int i=0;i<10;i++)used[i]=0;
	IF cout<<"in check "<<a<<' '<<b<<' '<<bull<<' '<<cow-bull<<endl;
	return make_pair(bull,cow-bull);
}
vector<string > rebuild (vector<string > v, point rep){
	vector<string > tmp;
	for(unsigned int i=1;i<v.size();i++){
		if(check(v[i],v[0])==rep){
	//		cout<<v[i]<<' '<<v[0]<<endl;
			tmp.push_back(v[i]);
		}
	}
	return tmp;
}
void sol(){
	srand(2333333);
	vector<string > v;
	build(0,"",v);
	pair<int ,int > rep;
	do{
		random_shuffle(v.begin(),v.end());
		rep=query(v[0]);
		v=rebuild(v, rep);
		IF cout<<"v.size:"<<v.size()<<endl;
		IF {point a=check(v[0],"7269");
			cout<<a.first<<' '<<a.second<<endl;
		}
		if(rep.first==4||v.size()==0)break;
	}while(1);
}
int main()
{
//	IF {
//		string a ,b ;
//		cin>>a>>b;
//		point p = check (a,b);
//		cout<<p.first<<' '<<p.second<<endl;
//	}
	sol();
	return 0;
}
//C.cc
//generated automatically at Sun Jan  8 15:54:13 2017
//by xsthunder

//AC at Sun Jan  8 17:45:32 2017
 
