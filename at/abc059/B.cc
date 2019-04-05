#include<iostream>
#include<cstring>
using namespace std;
const int G=0;
const int L=1;
const int E=2;
char ans [ 3][10]{
	"GREATER\n",
		"LESS\n",
		"EQUAL\n"
};
int main(){
	char s1[200];
	char s2[200];
	cin>>s1>>s2;
	int l1=strlen(s1);
	int l2=strlen(s2);
	if(l1>l2)cout<<ans[G];
	else if(l1<l2)cout<<ans[L];
	else {
		for(int i =0;i<l1;i++){
			if(s1[i]>s2[i]){
				cout<<ans[G];
				exit(0);
			}
			else if(s1[i]<s2[i]){
				cout<<ans[L];
				exit(0);
			}
		}
		cout<<ans[E];
	}
	return 0;
}
