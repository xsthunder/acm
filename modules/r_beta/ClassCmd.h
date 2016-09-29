#include<string>
#include<iostream>
#include<cstdlib>
using namespace std;
class Cmd:public string
{
	using string::string;
	public:
		int Run(int test=0){
			if((*this).length()==0){
				cout<<("refuse to run, the Cmd can't be empty\n");
			}
			else {
				if(test){
					cout<<"debuging:Cmd is \"";
					cout<<*this<<"\"";
					cout<<endl;
				}
				return system((*this).c_str());
			}
			}
};
//int main(){
//	Cmd str,str1;
//	str1=("echo hello");
//	str.append("echo hello");
//	str.Run(1);
//	cout<<str.length()<<endl;
//	cout<<str;
//	return 0;
//}
