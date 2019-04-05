#include<iostream>
#include<cctype>
using namespace std;
int main(){
	char s[100];
	for(int i =0;i< 3;i++){
		cin>>s;
		cout<<(char )toupper(s[0]);
	}
	cout<<endl;
	return 0;
}
