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
const int inf=0x7fffffff;
typedef long long int ll;
using namespace std;
bool vaildUtf8(vector<int >&data){
	int mask1=1<<7;
	int mask2=(3<<6);
	int cnt=0;
	for(auto x=data.begin();x!=data.end();x++){
		cout<<'x'<<*x<<endl;
		if(cnt==0){
			if((*x&mask1)==0)continue;
			int tmp=*x;
			if(tmp&&mask1){cnt++;
				tmp<<=1;
				cout<<"tmp"<<tmp<<endl;
      			while(tmp&mask1){
      			(tmp<<=1);
				cout<<"tmp"<<tmp<<endl;
      			cnt++;
      			}
      		}
		cout<<cnt<<endl;
		}
		else if(cnt==1)return 0;
		else {
			cnt--;
			while(cnt&&(x!=data.end())&&((mask2&(*x))==128)){
		cout<<'x'<<*x<<endl;
				
				cnt--;
				x++;
			}
			
			if(cnt!=0)return 0;
//			cout<<"cnt"<<cnt<<endl;
			if(x==data.end())break;
		}
	}
	if(cnt==0)return 1;
	else return 0;
}
int main()
{
//#ifdef DEBUG
//	freopen("in", "r", stdin);
////	freopen("out", "w", stdout);
//#endif
	vector<int > data;
	data.push_back(240);
	data.push_back(130);
	data.push_back(138);
	data.push_back(147);
	data.push_back(145);
	
	cout<<"ans"<<vaildUtf8(data);
	cout<<endl;
	//insert code above
	return 0;
}
//lcW3_2.cc
//generated automatically at Sun Sep  4 20:03:47 2016
//by xsthunder

