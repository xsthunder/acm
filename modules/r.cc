//to improve effecience on acm programming with cygwin
//this program works with cygwin on Windows 10
//time fuction will go wrong at linux system
//by xsthunder
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
void menu(string &filename)
{	
	cout<<"----------------------\n";
	cout<<"----------------------\n";
	cout<<"----------------------\n";
	cout<<"###r to run the program with file \"in\""<<endl;
	cout<<"###R to run"<<endl;
	cout<<"###v to vim "<<filename<<" and rebuild it"<<endl;
	cout<<"###c to add AC to "<<filename<<" "<<endl;
	cout<<"###d to generate out.my using in and compare it with out using diff\n";
	cout<<"###l to show local directory files"<<endl;
	cout<<"###g to rebuild the file"<<endl;
	cout<<"###i to vim in\n";
	cout<<"###n to create a new file copying u.cc"<<endl;
	cout<<"###a to restart the program\n";
	cout<<"###q to exit at once"<<endl;
	cout<<"###o to vim out"<<endl;
	cout<<"###b to move to codeblocks"<<endl;
	cout<<"###p to move from codeblocks"<<endl;
	cout<<"###![command] to run other command in shell\n";
	
}

	

int main()
{
	time_t rawtime;
	time(&rawtime);
re:
	char cmd[100];
	char opt;
	string t;
	string str1="g++ -std=c++11 -Wall ";
	string str2=" -o ";
	string filename;
	cout<<"###note:Don't believe this programme, once you finished a file, save it right away"<<endl;
	cout<<"###q to exit"<<endl;
	cout<<"###the origin filename(filename.cc):";
	cin>>t;
	
	t.append(".cc");
	filename=t;
	if(filename[0]=='q'||filename[0]=='Q')exit(0);
	string file;
	file=filename;
	file.erase(file.end()-3,file.end());
	t.insert(0,str1);
	t.append(str2);
	t.append(file);
	int i;
	for(i=0;i<t.length();i++)
	{
		cmd[i]=t[i];
	}
	cmd[i]='\0';
	printf("###the command is \"%s\"\n", cmd);
	string t_backup;
	t_backup=t;
build:
	int status=system(cmd);
	//printf("with empty file it shows :%d\n",status);
	if(0)
	{
create:
		int create_status;
		cout<<"###now create file "<<filename<<" copying modules/u.cc\n";
		string createfile;
		createfile="cp ./modules/u.cc ";
		createfile.append(filename);
		for(i=0;i<createfile.length();i++)
		{ 
			cmd[i]=createfile[i];
		}
		cmd[i]='\0';
		printf("###the command is \"%s\"\n", cmd);
		create_status=system(cmd);
		if(!create_status){
			createfile=("echo -e \"//");
			createfile.append(filename);
			createfile+="\n//generated automatically at ";createfile+=ctime(&rawtime);createfile+="//by xsthunder";createfile+="\n\"";
			createfile.append(">>");
			createfile+=filename;

		}
		for(i=0;i<createfile.length();i++)
		{ 
			cmd[i]=createfile[i];
		}
		cmd[i]='\0';
		create_status=system(cmd);
		printf("###adding init info\n");
		if(create_status!=0)
		{
			cout<<"###:u.cc file may not exists"<<endl;
build1:
			cout<<"###q to quit programm"<<endl;
			cout<<"###c to continue and create an empty file"<<endl;
			cin>>opt;
			switch(opt)
			{
			case'c': case'C':
				createfile="echo \"//AC\" >> ";
				createfile.append(filename);
				for(i=0;i<createfile.length();i++)
				{
					cmd[i]=createfile[i];
				}
				cmd[i]='\0';
				printf("###the command is \"%s\"\n", cmd);
				create_status=system(cmd);
				if(create_status)
				{
					cout<<"###fail to create an empty file, please check the system.\n";
					exit(1);
				}
				break;
			case'q':case'Q':
				exit(0);
				break; 
			default:
			cout<<"###unkown option"<<endl;
			goto build1;
			}
			goto build;
		}
		goto loop;
	}

	menu(filename);
loop:
	cout<<"### m to show menu"<<endl;
	str1.erase(str1.begin(),str1.end());
	string p;
	cin>>p;
	opt=p[0];
	//opt=option[0];
	memset(cmd, 0, 30);
//	cout<<"opt:"<<(int)opt;
	switch(opt)
	{
		case 'o':
			str1="vim out";
			t=str1;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			system(cmd);
		case'm':
			menu(filename);
			break;
		case'c':
			str1="echo -e \"//AC\n\">>";
			str1.append(filename);
			t=str1;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###adding \\\\ACto the end of file\n");
			if(system(cmd));
			break;
		case'!':
			t=p;
			cout<<"p:"<<t<<endl;
			for(i=0;i<t.length()-1;i++)
			{
				cmd[i]=t[i+1];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			if(system(cmd));
			break;
		case'n':cout<<"This will cover all changes you've done and reset the file according to u.cc\n";
			cout<<"enter y to confirm(any other characters to cancel.:";
			cin>>p;
			opt=p[0];
			if(opt=='y')goto create;
			break;
		case'l':
			str1="ls";
			t=str1;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			if(system(cmd));
			break;
		case'i':
			str1="vim ";
			str1.append("in");
			t=str1;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			if(system(cmd));
			break;
			
		case'a':goto re;break;
		case'd':
		case'D':
			str1="./";
			str1.append(file);
			str1.append(".exe <in >out.my");
			t=str1;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			if(!system(cmd))
			{
				str1="diff out out.my";
				t=str1;
				for(i=0;i<t.length();i++)
				{
					cmd[i]=t[i];
				}
				cmd[i]='\0';
				system(cmd);
				printf("###the command is \"%s\"\n", cmd);
			}

//			exit(0);
			break;
		case 'b':
			str1="cp "+filename+" /home/cb/main.cpp";
			str2="cp in /home/cb/in";
			t=str1;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			system(cmd);
			t=str2;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			system(cmd);
			
			break;
		case 'p':
			str1="cp /home/cb/main.cpp "+filename;
			str2="cp in /home/cb/in";
			t=str1;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			system(cmd);
			t=str2;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			system(cmd);
			break;
			
		case 'v':
			{
			str1="vim ";
			str1.append(filename);
			t=str1;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			if(system(cmd));
rebuild:
			t=t_backup;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			if(system(cmd));
			break;
			}

		case 'q':
		case'Q':
			exit(0);
			break;
		case 'r':
			str1.append("./");		
			str1.append(file);
			str1.append(" <in");
			//cout<<str1;
			t=str1;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			if(system(cmd));
			break;
		case'R':
			str1.append("./");		
			str1.append(file);
			//cout<<str1;
			t=str1;
			for(i=0;i<t.length();i++)
			{
				cmd[i]=t[i];
			}
			cmd[i]='\0';
			printf("###the command is \"%s\"\n", cmd);
			if(system(cmd));
			break;
		case'g':
			goto rebuild;
		default:
			cout<<"###unkown option"<<endl;
	}
	goto loop;


	return 0;
}
