#include<bits/stdc++.h>
//#include "DiffieHellmanHeader.h"
using namespace std;

 long int power(int a,int b,int p){
 	int ans =1;
 	while(b--){
 		ans=(ans*a)%p;
	 }
	 return ans;
 }
 
 int inverse(int num, int mod){
	
	int q,t1=0,t2=1,t,r1,r2,r;
	r1=mod;
	r2=num;
	while(r2>0){
	q=r1/r2;
	r=r1-r2*q;	
	t=t1-t2*q;
	
	r1=r2;
	r2=r;
	
	t1=t2;
	t2=t;	
	}
	
	if(t1<0){
		t1+=mod;
	}
	return t1;
}

 int main(){
 	
 	int g,p;
 	cout<<"Enter generator and modulus :";
 	cin>>g>>p;
 	
 	srand(time(0));
 	//bob 
 	int b,B;
 	b=rand();
 	//bob's public key
 	B=power(g,b,p);
 	
 	//alice
 	int a,A;
 	a=rand();
 	//alices public key
 	A=power(g,a,p);
 	
 	int message ;
 	cout<<"Enter message (int for now) :";
 	cin>>message;
 	
 	//message sent to bob (A,A1)
 	int A1 = message* power(B,a,p);
 	cout<<"Message sent to BOB :"<<A1<<endl;
 	
 	//computation done by bob 
 	int B1= power(A,b,p);
 	B1=inverse(B1,p);
 	int mess=(A1*B1)%p;
 	cout<<"Message decripted by BoB :"<<mess<<endl;
 	return 0;
 }
