#include<iostream>
#include<ctime>
#include<string>
#include"ClassCmd.h"
using namespace std;
extern string filename;
extern string name;
extern string inname;
extern string outname;
extern string outnamemy;
int FuncConfirm(){
		cout<<"press Y to confirm:";
		string com;
		cin>>com;
		if(com[0]!='Y')return 1;
		else return 0;
}
void FuncMenu()
{	
	cout<<"----------------------\n";
	cout<<"----------------------\n";
	cout<<"----------------------\n";
	cout<<"###r to run the program with file \"in\""<<endl;
	cout<<"###R to run"<<endl;
	cout<<"###v to vim "<<filename<<endl;
	cout<<"###c to add AC to "<<filename<<" "<<endl;
	cout<<"###d to generate out.my and compare it with out\n";
	cout<<"###g to build the file"<<endl;
	cout<<"###i to vim in\n";
	cout<<"###n to create a new file copying u.cc"<<endl;
	cout<<"###a to restart the program\n";
	cout<<"###q to exit at once"<<endl;
	cout<<"###o to vim out"<<endl;
	cout<<"###h to generate "+name+".html"<<endl;
	cout<<"###l to gedit "+filename<<endl;
	//cout<<"###b to move to codeblocks"<<endl;
	//cout<<"###p to move from codeblocks"<<endl;
}
void FuncH(){
	Cmd str1;
	str1+="cp "+filename+" "+name+".html";
	str1.Run();
}
void FuncR(){
	Cmd str1;
	str1.append("./");		
	str1.append(name);
	str1.Run();
}
void Funcr(){
	Cmd str1;
	str1.append("./");		
	str1.append(name);
	str1.append(" ");
	str1+=inname;
	str1.Run();
}
void FuncGcc(){
	Cmd cmd;
	cmd+="g++ -std=c++11 -Wall "+filename+" -o "+name;
	cmd.Run();
}
void FuncCreate(){//for n
	//create file copying 
		if(FuncConfirm())return ;
		Cmd createfile;
		createfile="cp ~/acm/modules/u.cc ";
		createfile.append(filename);
		createfile.Run();
		//adding info
		time_t rawtime;
		time(&rawtime);
		createfile=("echo \"//");
		createfile.append(filename);
		createfile+="\n//generated automatically at ";createfile+=ctime(&rawtime);createfile+="//by xsthunder";createfile+="\n\"";
		createfile.append(">>");
		createfile+=filename;
		createfile.Run();
}
void FuncVimout(){//for o
			Cmd str1="vim ";
			str1+=outname;
			str1.Run();
}
void FuncVimin(){//for i
			Cmd str1="vim ";
			str1+=inname;
			str1.Run();
}
void FuncDiff(){//for d
			Cmd str1="./";
			str1+=name+string(" < ") +inname +string(" > ") +outnamemy;
			if(!str1.Run()){
				str1="";
				str1.append(string("diff ")+outnamemy+string(" ")+ outname);
				str1.Run();
			}
			else cout<<"fail Diff\n";
}
void FuncVim(){//for v
			Cmd str1="vim ";
			str1.append(filename);
			str1.Run();
}
void FuncAc(){//for c
	if(FuncConfirm())return ;
	time_t rawtime;
	time(&rawtime);
	Cmd createfile;
	createfile="echo \"//AC at ";
	createfile+=ctime(&rawtime);
	createfile+=" \" >> ";
	createfile.append(filename);
	createfile.Run();
}
void FuncGedit(){//for l
	Cmd cmd;
	cmd+="gedit "+filename;
	cmd.Run();
}
