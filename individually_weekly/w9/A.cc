#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	char ans[2][10]={
		"Bob",
		"Alice"
	};
	cout<<ans[n&1]<<endl;
	return 0;
}
