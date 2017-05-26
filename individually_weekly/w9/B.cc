#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n;
const int N = 2e5+1000;
vector<int > v[N];
int used[N];
int find(int x){
	if(used[x])return 0;
	used[x]=1;
	int sum = 1;
	for(int y:v[x]){
		sum+=find(y);
	}
	return sum;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v[x].push_back(i);
	}
	int q;
	cin>>q;
	while(q--){
		int sum = 0;
		memset(used,0,sizeof(used));
		cin>>n;
		for(int i =0;i<n;i++){
			int x;
			cin>>x;
			sum+=find(x);
		}
		cout<<sum<<endl;
	}
	return 0;
}
