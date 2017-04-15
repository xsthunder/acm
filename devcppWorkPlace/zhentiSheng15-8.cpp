#include<iostream>
using namespace std;
int main()
{
	int n ;
	//cin>>n;
	n=10000;
	long long ans = 0 ; 
	ans+=n;
	while(n>=3){
		ans+=n/3;
		n=n/3+n%3;
	}
	cout<<ans<<endl;
}
