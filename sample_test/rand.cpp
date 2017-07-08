#include<cstdio>
#include<ctime>
#include<iostream>
#include<cstdlib>
#include<cctype>
#include<climits>
using namespace std;
int main()
{
	srand(time(0));
	int t = 1;
	cout<<t<<endl;
	while(t--){
	int n = rand()%10+1;
	cout<<n<<' ';
	for(int i =0;i<n;i++)cout<<rand()%100<<' ';
	cout<<endl;
}
}
