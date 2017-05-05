#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
#define iF if(Te)
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
void inp();
void gg(){
	cout<<-1<<endl;
	exit(0);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	return 0;
}
const int N = 2e3;
int A[N];
void inp(){
	int n,k,p,x,y;
	cin>>n>>k>>p>>x>>y;
	int sum =0;
	for(int i=0;i<k;i++){
		cin>>A[i];
		sum+=A[i];
	}
	int s = x-sum;
	if(s<0){
		cout<<-1<<endl;
		exit(0);
	}
	int ind=0;
	sort(A,A+n);;
	for(int i =0;i< n;i++){
		if(A[i]>=y){
			ind=i;
			break;
		}
	}
	int me=A[ind];
	vector<int > v;
	ind++;
	int r = n-k;
	int m = (n+1)/2;
	iF cout<<me<<' '<<r<<' '<<m<<' '<<s<<endl;
	if(me<y){
		if(ind<m){
			if((r+1)*y>s){
				cout<<-1<<endl;
				exit(0);
			}
			else {
				s-=(r+1)*y;
				if(r-1-k>s){
					cout<<-1<<endl;
					exit(0);
				}
				else {
					for(int i =0;i<r-1-k;i++){
						cout<<1<<' ';
					}
					for(int i=0;i< r+1;i++){
						cout<<y;
					}
				}
			}
		}
		else if(ind>=m){
			gg();
		}
	}
	while(r--){
		if(ind>m){
			v.push_back(1);
			s--;
			ind--;
		}
		else if(ind<=m){
			v.push_back(me);
			s-=me;
			ind++;
		}
		if(s<0){
			gg();
		}
	}
	for(U i=0;i< v.size();i++){
		cout<<v[i]<<' ';
	}
	cout<<endl;
}
//c.cc
//generated automatically at Sun Apr 30 20:08:54 2017
//by xsthunder

