#include<cstdio>
#include<cmath>
#include<sstream>
#include<iostream>
#include<map>
using namespace std;
int main(){
	map <int ,float> K1;
	map <int ,float > K2;
	map <int ,float > ans;
	int k;
	scanf("%d",&k);
	while(k--){
		int ex;float co;
		scanf("%d%f",&ex,&co);
		K1[ex]=co;
		//cout<<"input sex,sco"<<ex<<','<<co<<endl;
	}
	scanf("%d",&k);
//	for(auto x:K1){
//		int sex=x.first;
//		float sco=x.second;
//		cout<<"sex,sco"<<sex<<','<<sco<<endl;
//	}
//	return 1;
//	cout<<"K1.size()"<<K1.size()<<endl;
	while(k--){
		int ex;float co;
		scanf("%d%f",&ex,&co);
		for(auto x:K1){
			int sex=x.first+ex;
			float sco=x.second*co;
//			cout<<"sex,sco"<<sex<<','<<sco<<endl;
			if(fabs(sco)<0.00001)continue;
			if(ans.count(sex)){
				ans[sex]+=sco;
			}
			else {
				ans[sex]=sco;
			}
		}
	}
	int cnt=0;
	for(auto it=ans.rbegin();it!=ans.rend();it++){
		if(fabs(it->second)<0.00001)continue;
		cnt++;
	}
	printf("%d", cnt);
	for(auto it=ans.rbegin();it!=ans.rend();it++){
		if(fabs(it->second)<0.00001)continue;
		printf(" %d %.1f",it->first,it->second);
	}
	printf("\n");
}
//AC at Tue Nov 29 19:18:59 2016
 
