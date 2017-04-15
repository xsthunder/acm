#include<iostream>
#include<algorithm>
#include<set>
const int test=1;
#define IF if(test)
using namespace std;
int b,q,l,m;
set<int >si ;
void dea();
void inp();
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	inp();
	dea();
}
void dea(){
	long long int sum  ;
	int ans=0;
	int cnt=0;
	sum=b;
	ans++;
	if(b==0){
		if(si.count(0))cout<<0<<endl;
		cout<<"inf\n";
		return;
	}
	if(!q){
		if(si.count(0)){
			int ans = 1-si.count(b);
			cout<<ans<<endl;
		}
		else cout<<"inf\n";
		return ;
	}
	if(q==1){
		if(si.count(b))cout<<0<<endl;
		else cout<<"inf\n";
		return ;
	}
	if(q==-1){
		if(si.count(b)&&si.count(-b))cout<<0<<endl;
		else cout<<"inf\n";
		return ;
	}
	if(abs(b)>b)ans--;
	while(cnt<35&&abs(sum)<=l){
		IF cout<<cnt<<' '<<sum<<endl;
		sum*=q;
		ans++;
		if(si.count(sum))ans--;
		cnt++;
	}
	if(cnt==35){
		if(!ans&&(q==1||q==-1))cout<<0<<endl;
		cout<<"inf\n";
	}
	else cout<<ans<<endl;;
}
void inp(){
	cin>>b>>q>>l>>m;
	int x;
	while(m--){
		cin>>x;
		si.insert(x);
	}
}
