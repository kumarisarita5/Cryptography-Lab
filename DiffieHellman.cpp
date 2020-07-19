//Diffie hellman key exchange algorithm

#include<bits/stdc++.h>
using namespace std;
 
 long int power(int a,int b,int p){
 	int ans =1;
 	while(b--){
 		ans=(ans*a)%p;
	 }
	 return ans;
 }
 
 void DiffieHellman(){
 	int g,p,a,b,A,B,AliceKey,BobKey;
	cout<<"Enter generator and modulus :";
	cin>>g>>p;
	
	srand(time(0));
	//alice's random private value
	a=rand();
	
	//bob's random private value
	b=rand();
	
	cout<<"a :"<<a<<"\nb :"<<b<<endl;
	//alice sends A to bob
	A=power(g,a,p);
	
	//bob sends B to alice
	B=power(g,b,p);
	
	cout<<"A :"<<A<<"\nB :"<<B<<endl;
	
	//alice generates its private key for comm
	AliceKey=power(B,a,p);
	
	//bob generates its key from A received from alice 
	BobKey=power(A,b,p);
	
	cout<<"Key Calculated by Alice :"<<AliceKey<<endl<<"Key Calculated by Bob :"<<BobKey<<endl;

 }
 
int main(){
	DiffieHellman();
	return 0;
}
