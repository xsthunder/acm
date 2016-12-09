#include<cstdio>
#include<cmath>
#include<cstring>
#include<cctype>
char s[3][15];
int get(char x){
	if(isdigit(x)){
		return x-'0';
	}
	else {
		return x-'a'+10;
	}
}
long long trans(char *p, int radix){
	long long ans=0;
	int size=strlen(p);
	size--;
	while(size!=-1){
		int co = get(*p);
		ans+=co*pow(radix,size);
		p++;size--;
	}
	return ans;
}
int main(){
	for(int i=1;i<=2;i++){
		scanf("%s",s[i]);
	}
	int flag;int radix;
	scanf("%d%d",&flag,&radix);
	long long dec=trans(s[flag],radix);
	//printf("dec:%lld\n",dec);
	char *tar=s[flag==1?2:1];
	int ans=0;
	for(int i=2;i<=0x7fffffff;i++){
		int tran=trans(tar,i);
		if(dec==tran){
			ans=i;
			break;
		}
		else if(dec<tran){
			break;
		}
	}
	//printf("%d %s cmp 0\n",strcmp(tar, "0\0"),tar);
	//printf("%d %s cmp 0\n",strcmp(s[flag], "0\0"),s[flag]);
	if(!strcmp(tar,"0\0")&&!strcmp(s[flag],"0\0"))printf("1\n");
				else if(!ans)printf("Impossible\n");
				else printf("%d\n",ans);
				}
