#include<string>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const bool TEST=1;
#define IF if(TEST)
set<string> ss;
string tws(string s){
	int a = 0 , b  = s.size();
	b--;
	while(a<b){
		swap(s[a],s[b]);
		a++;b--;
	}
	return s;
}
int main(){
	string s = "aaabbbbccccc";
	//aaabbbbccccc
	int len = s. size();
	int res=0;
	cout<<len<<' '<<res<<endl;
	do{
		if(ss.count(s)){
			continue;
		}
		else {
			res++;
		for(int i = 0 ; i< len;i++){
			string ts=s.substr(i)+s.substr(0,i);
			ss.insert(ts);
			ss.insert(tws(ts));
			//IF cout<<ts<<endl<<tws(ts)<<endl;
			}
		}
		//IF break;
	}while(next_permutation(s.begin(),s.end()));
	cout<<res<<endl;
	return 0;
}

//ans=1170 support from https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&tn=monline_4_dg&wd=%E6%89%8B%E9%93%BE%E6%A0%B7%E5%BC%8F%20%E8%93%9D%E6%A1%A5%E6%9D%AF%201170&oq=%25E6%2589%258B%25E9%2593%25BE%25E6%25A0%25B7%25E5%25BC%258F%2520%25E8%2593%259D%25E6%25A1%25A5%25E6%259D%25AF%252027720&rsv_pq=ef3f133b000a1a26&rsv_t=7313nUeZqQR%2FQrHyIOtPeWpmxk%2FmQcyIDkE76QYQuq1ljs321da9dxWMaG2eMPPaEwHp&rqlang=cn&rsv_enter=1&rsv_sug3=10&rsv_sug1=6&rsv_sug7=000&rsv_sug2=0&inputT=2075&rsv_sug4=2951&rsv_sug=1
