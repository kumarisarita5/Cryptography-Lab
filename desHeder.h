#include<bits/stdc++.h>
//#include <boost/lexical_cast.hpp> 
using namespace std;

string InttoString(int x){
string str="",s = "0000";
int n=x,r;
while(n){
str+=(char(n%2)+'0');
n/=2;	
}
reverse(str.begin(), str.end());
if(str.length()<4){
	str=s.substr(0,4-str.length())+str;
}
return str;
}

string E(string s){
	string p="",temp=s.substr(2,2);
	reverse(temp.begin(),temp.end());
	p=s.substr(0,2);
	p+=temp;
	p+=temp;
	p+=s.substr(4,2);
	return p;
}

string XOR(string a, string b){
	int n=a.length();
	for(int i=0;i<n;++i){
		if(a[i]==b[i])
		a[i]='0';
		else
		a[i]='1';
	}
	return a;
}

int COL(string s){
	int n=s.length(),num=0;
	for(int i=0;i<n;++i)
		num=num+(s[i]-'0')*(int)pow(2,n-i-1);
	
	return num;
}
