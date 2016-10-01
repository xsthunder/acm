#include<iostream>
#include<cctype>
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
#include<cmath>
#include<cassert>
const int inf=0x7fffffff;
const bool test=0;
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
void pS(const string &tmp,int n){
	for(int i=0;i<n;i++){
		cout<<"    ";
	}
	cout<<tmp;
}
void pA(int *begin,int n){
	for(int i=0;i<n;i++){
		printf("%2d",*(begin+i));
	}
	printf("\n");
}
char line[100];
vector<string> IDcache;
vector<int >head;
struct node{
	vector<string> v;
	string name;
};
Node link[1000];
int cnt=0;
void init(){
	cnt=0;
	IDcache.clear();
	head.clear();
	memset(link,0,sizeof(link));
}
int getID(const string &tmp){
	auto id=find(IDcache.begin(),IDcache.end(),tmp);
	if(id==IDcache.end()){//create ID
		IDcache.push_back(tmp);
		ID[IDcache.size()-1]=tmp;
		return IDcache.size()-1;
	}
	else return id-IDcache.begin();
}
void pN(int d,int n){
	const node &tmp=link[d];
	if(tmp.v.size()==0){
		pS(tmp.name,n);
		return ;
	}
	sort(tmp.v.begin(),tmp.v.end());
	for(unsigned int i=0;i<tmp.v.size();i++){
		pN(getID(tmp.v[i]),n+1);
	}
}
int main()
{
	int flag=0;
	init();
	while(scanf("%s",line)!=EOF){
		if(line[0]==0&&strlen(line)==1){
			printf("Case# %d:\n",++flag);
			sort(head.begin(),head.end());
			for(unsigned  int i=0;i<head.size();i++){
				pN(getID(head[i]),0);
			}
			init();
		}
		char *pch;
		pch=strtok(line,"/");
		int first=1;
		while(pch!=NULL){
			if(first){
				//int id=getID(pch);
				//head.push_back(id);
				
			}
		}
	}
	return 0;
}
//01.cc
//generated automatically at Sat Sep 24 12:09:51 2016
//by xsthunder

