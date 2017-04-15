#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
void dea(char *s);
char cs[5000];
int main(){
	string s;
	while(fgets(cs,5000,stdin)&&!feof(stdin)){
		int index=0;
		//cout<<cs;
		int len =strlen(cs);
		cs[len-1]='\0';
		//cout<<cs;
		while(index<len){
			printf("%04x:",index);
			dea(cs+index);
			index+=16;
			printf("\n");
		}
	}
}
void rev(char *s){
	int cnt = 0;
	while(cnt<16&&s[cnt]){
		if(isupper(s[cnt]))s[cnt]=tolower(s[cnt]);
		else s[cnt]=toupper(s[cnt]);
		cnt++;
	}
}
void dea(char *s){
	char t[20];
	memcpy(t,s,20);
	t[16]=0;
	bool flag=0;
	for(int i =0 ;i< 16;i++){
		if(!s[i]){
			flag=1;
		}
		if(!(i%2))printf(" ");
		if(flag){
			printf("  ");
		}
		else printf("%02x" , s[i]);
	}
	rev(t);
	printf(" %s", t);
}
