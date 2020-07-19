//vigenere
#include<bits/stdc++.h>
using namespace std;


string encript(string p, string k){
	//preprocessing	
	int len_p=p.length(), len_k=k.length(), i=0;
	while(i+len_k<len_p){
		k+=k[i%len_k];
		i++;
	}
	for(int i=0;i<len_p;++i){
			k[i]=toupper(k[i]);
			p[i]=toupper(p[i]);
		}
	cout<<k<<"\n"<<p<<endl;
	
	string c="";
	for(int i=0;i<len_p;++i){
		int temp=((k[i]-'A') + (p[i] -'A'))%26;
	 	c=c+char(temp+'A');	
	}
	
	return c;
}

string decript(string c, string k){
		//preprocessing	
	int len_c=c.length(), len_k=k.length(), i=0;
	while(i+len_k<len_c){
		k+=k[i%len_k];
		i++;
	}
	for(int i=0;i<len_c;++i){
			k[i]=toupper(k[i]);
			c[i]=toupper(c[i]);
		}
	cout<<k<<"\n"<<c<<endl;
	
	
	string p="";
	
	for(int i=0;i<len_c;++i){
		int temp=((c[i] -'A') - (k[i]-'A')+26)%26;
	 	p=p+char(temp+'A');	
	}
	
	return p;
}

int main(){
	
	cout<<"select from given options : 1. Encription\n2. Decription\n";
	int option;
	cin>>option;
	string plainText,cipherText;
		string key;
	switch(option){
		case 1:
			cout<<"Enter key :";
		
			cin>>key;
			cout<<"Enter text to encript: ";		
			cin>>plainText;
			cipherText=encript(plainText,key);
			cout<<"Obtained Cipher Text : "<<cipherText<<endl;
			break;
		case 2:
			cout<<"Enter key :";
			//string key;
			cin>>key;
			cout<<"Enter text to decript: ";
			cin>>cipherText;
			plainText=decript(cipherText,key);
			cout<<"Obtained Plain Text : "<<plainText<<endl;
			break;
		default:
			cout<<"Enter correct option"<<endl;
	}
	return 0;
}
