//r2.0 beta impoving with moduling 
//to improve effecience on acm programming with cygwin
//this program works with cygwin on Windows 10
//time fuction will go wrong at linux system
//by xsthunder
//change filename while ac is added at the begining of Dec ,2016
#include "FuncMenu.h"
using namespace std;
string name;
string filename;//with .cc 
string inname;
string outname;
string outnamemy;
void init(){
	if(name.find(".cc")!=string::npos)filename=name;
	else filename=name+".cc";
	inname=name+".in";
	outname=name+".out";
	outnamemy=outname+".my";
	cout<<"------------\n:";
}
void input(){
	cout<<"###q to exit"<<endl;
	cout<<"###the name of origin file(file.cc):";
	cin>>name;
	if(name[0]=='q'||name[0]=='Q')exit(0);
	init();
}
/*option list 
 *
*/
int loop(){
	string opt;
	cin>>opt;//cin will make sure the length of opt >1;
	switch(opt[0]){
		case'r': Funcr();break;
		case'R': FuncR();break;
		case'G':case'g':FuncGcc();break;
		case'n':case'N':FuncCreate();break;
		case'i':case'I':FuncVimin();break;
		case'o':case'O':FuncVimout();break;
		case'D':case'd':FuncDiff();break;
		case'V':case'v':FuncVim();break;
		case'c':case'C':FuncAc();break;
		case'm':case'M':FuncMenu();break;
		case'h':case'H':FuncH();break;
		case'l':case'L':FuncGedit();break;
		case'a':case'A':if(!FuncConfirm()) {input();return 1;}else break;
		case'q':case'Q':if(!FuncConfirm()) exit(0);else break;
		case'!':{
							Cmd st1;
							st1.append(opt.substr(1));
							st1.Run();
							break;
						}
		default:cout<<"unvailed option, m for menu\n";
	}
	cout<<"------------\n:";
	return 0;
}//return 0 to exit the loop;
int Main(){
	int status;
	for(;;){
		status=loop();//return 0 to loop, 1 to start again
		if(status)return 1;
	}
	return 0;
}
int main(int argc, char* argv[]){
	if(argc>=2){
		name=string(argv[1]);
		init();
	}
	else input();
	while(Main());
	return 0;
}
