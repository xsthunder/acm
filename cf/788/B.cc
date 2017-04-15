#include<cmath>
#include<algorithm>
#include<set>
#include<iostream>
using namespace std;
int b,q,l,m;
int ans =0  ;
set<int > si;
char inf[]="inf";
void inp();
void dea();
void dea2();
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	inp();
	dea();
}
void dea(){
	if(!q||!b){
		if(si.count(0)){
			if(b){
				if(!si.count(b))
				{
					cout<<1<<endl;
					return ;
				}
			}
			cout<<0<<endl;
			return;
		}
		else cout<<inf<<endl;
		return ;
	}
	else if(q==1){
		if(abs(b)<=l){
			if(si.count(b)){
				cout<<0<<endl;
				return ;
			}
			else cout<<inf<<endl;
		}
		else cout<<0<<endl;
		return ;
	}
	else if(q==-1){
		if(abs(b)<=l){
			int cnt =0 ;
			cnt+=si.count(b)+si.count(-b);
			if(cnt==2)cout<<0<<endl;
			else cout<<inf<<endl;
		}
		else cout<<0<<endl;
		return ;
	}
	if(abs(b)>l){
		cout<<0<<endl;
		return ;
	}
	dea2();
}
void dea2(){
	long long int sum = 1 ; 
	sum*=b;
	int ans = 1-si.count(sum);
	while(abs(sum)<=l){
		sum*=q;
		ans++;
		if(si.count(sum))ans--;
	}
	cout<<ans<<endl;
}
void inp(){
	cin>>b>>q>>l>>m;
	int x;
	while(m--){
		cin>>x;
		si.insert(x);
	}
}
