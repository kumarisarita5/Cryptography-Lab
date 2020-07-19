#include<bits/stdc++.h>
using namespace std;

int inverse(int num, int mod){
	
	int q,t1=0,t2=1,t,r1,r2,r;
	r1=mod;
	r2=num;
	while(r2>0){
	q=r1/r2;
	r=r1-r2*q;	
	t=t1-t2*q;
	
	r1=r2; r2=r;	
	t1=t2; t2=t;	
	}
	
	if(t1<0)
		t1+=mod;
	return t1;
}

long long modularExponentiation(long long int num, long long int pow, long long int mod){
unsigned res;
    for(res = 1; pow; pow >>= 1){
        if (pow & 1)
            res = (res * num) % mod;
        num = (num * num) % mod;
    }
    return res;
}

int main(){
	
	cout<<"select from given options : 1. Key Generation\n2. Encription\n3. Decription\n";
	int option,p,q,n,phi,e,d;
	cin>>option;
	long long int plainText,cipherText;
	
	switch(option){
		case 1:
			cout<<"Enter 2 pprime numbers p and q";
			cin>>p>>q;
			n=p*q;phi=(p-1)*(q-1);
			cout<<"Availabe options for e are:\n";
			for(int i=2;i<phi;++i){
				if(__gcd(i,phi)==1){
					cout<<i<<" ";
				}
			}
			cout<<"Enter e from above numbers :";
			cin>>e;
			while(__gcd(e,phi)!=1){
				cout<<"choose another public key.\n";
				cin>>e;
			}
			d=inverse(e,phi);
			cout<<"private key is :"<<d<<endl;			
			break;
		case 2:
			cout<<"Enter encription key e and n:";		
			cin>>e>>n;
			cout<<"Enter text to encript: ";		
			cin>>plainText;
			cipherText=modularExponentiation(plainText,e,n);
			cout<<"Obtained Cipher Text : "<<cipherText<<endl;
			break;
		case 3:
			cout<<"Enter decription key d and n :";
			cin>>e>>n;
			cout<<"Enter text to decript: ";
			cin>>cipherText;
			plainText=modularExponentiation(cipherText,e,n);
			cout<<"Obtained Plain Text : "<<plainText<<endl;
			break;
		default:
			cout<<"Enter correct option"<<endl;
	}
	//char ch;
	//cin>>ch;
	return 0;
}
