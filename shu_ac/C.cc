#include<cstdio>
#include<cstring>
int used[150];
int main(){
	int n ;
	scanf("%d",&n);
	memset(used,0,sizeof(used));
	char s[50];
	char ans[2][20]{
		"Successful\n",
			"Failed\n"
	};
	while(n--){
		scanf("%s", s);
		int x;
		switch(s[0]){
			case 'N':
				for(int i =1;i<=100;i++){
					if(!used[i]){
						used[i]=1;
						printf("%d\n", i);
						break;
					}
				}
				break;
			case 'D':
				scanf("%d", &x);
				if(used[x]){
					printf("%s", ans[0]);
					used[x]=0;
				}
				else {
					printf("%s", ans[1]);
				}
		}
	}
	return 0;
}
