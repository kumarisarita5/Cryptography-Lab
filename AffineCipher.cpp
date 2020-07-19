#include<iostream>
#include<algorithm>
using namespace std;

int alpha, beta;

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

string encript(string plainText){
	string cipherText="";
	int len=plainText.length();
	for(int i=0;i<len;++i){
		plainText[i]=toupper(plainText[i]);
		int x=plainText[i]-'A';
		x=((x*alpha)%26+beta)%26;
		x+='A';
		cipherText+=char(x);
	}
	return cipherText;
}

string decript(string cipherText){
	string plainText="";
	int len=cipherText.length();
	for(int i=0;i<len;++i){
		int x=cipherText[i]-'A';
		x=(x+26-beta)%26;
		x=(x*inverse(alpha,26))%26;
		plainText+=char(x+'A');
	}
    return plainText;
}

int main(){
	cout<<"Enter alpha and beta:";
	
	cin>>alpha>>beta;
	cout<<"select from given options : 1. Encription\n2. Decription\n";
	int option;
	cin>>option;
	string plainText,cipherText;
	switch(option){
		case 1:
			cout<<"Enter text to encript: ";		
			cin>>plainText;
			cipherText=encript(plainText);
			cout<<"Obtained Cipher Text : "<<cipherText<<endl;
			break;
		case 2:
			cout<<"Enter text to decript: ";
			cin>>cipherText;
			plainText=decript(cipherText);
			cout<<"Obtained Plain Text : "<<plainText<<endl;
			break;
		default:
			cout<<"Enter correct option"<<endl;
	}
	return 0;
}
