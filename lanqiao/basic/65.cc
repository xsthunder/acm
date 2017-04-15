void sol(){
	int time=0;
	int tpos=0;
	int rpos=0;
	int v1,v2,t,s,l;
	int stop=0;
	cin>>v1>>v2>>t>>s>>l;
	while(tpos!=l&&rpos!=l){
		time++;
		int rv=v1,
				tv=v2;
		if(stop){
			stop--;
			rv=0;
		}
		tpos+=tv;
		rpos+=rv;
		IF {printf("time :%d (pos,v)\n",time);
			cout<<rpos<<' '<<rv<<endl;
			cout<<tpos<<' '<<tv<<endl;
			cout<<"stop:"<<stop<<endl;
		}
		if(rpos-tpos>=t){
			if(stop);
			else stop=s;
		}
	}
	int kind=0;
	if(tpos==rpos){
		kind=3;
	}
	else if(tpos==l){
		kind=2;
	}
	else kind=1;
	char ans[]={
		' ','R','T','D'
	};
	printf("%c\n%d",ans[kind],time);
}
int main()
{
	sol();
	return 0;
}
//65.cc
//generated automatically at Sat Feb  4 15:48:30 2017
//by xsthunder
