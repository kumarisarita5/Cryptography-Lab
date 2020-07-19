//DES
#include "desHeder.h"
#include<bits/stdc++.h>
using namespace std;

string keys[4];
string s1[2][8];
string s2[2][8];

void in(){
	s1[0][0]="101";s1[0][1]="010";s1[0][2]="001";s1[0][3]="110";
	s1[0][4]="011";s1[0][5]="100";s1[0][6]="111";s1[0][7]="000";
	s1[1][0]="001";s1[1][1]="100";s1[1][2]="110";s1[1][3]="010";
	s1[1][4]="000";s1[1][5]="111";s1[1][6]="101";s1[1][7]="011";
	
	s2[0][0]="100";s2[0][1]="000";s2[0][2]="110";s2[0][3]="101";
	s2[0][4]="111";s2[0][5]="001";s2[0][6]="011";s2[0][7]="010";
	s2[1][0]="101";s2[1][1]="011";s2[1][2]="000";s2[1][3]="111";
	s2[1][4]="110";s2[1][5]="010";s2[1][6]="001";s2[1][7]="100";
}


void keyGen(string k){
	for(int i=0;i<4;++i)
		keys[i]="";
	for(int i=0;i<4;++i){
		for(int j=0;j<8;++j){
			keys[i]+=k[(i+j)%9];
		}
	}
}

string DES(string text, string k){
	string left=text.substr(0,6),right=text.substr(6,6),r=right;
	cout<<left << " "<<right<<endl;
	
	keyGen(k);
		
	for(int i=1;i<4;++i){
	cout<<"round key :"<<keys[i]<<endl;
	r=E(r);  
	r=XOR(r,keys[i]);
	
	int row1=r[0]-'0', row2=r[4]-'0';
	int col1=COL(r.substr(1,3)),col2=COL(r.substr(5,3));
	string temp=s1[row1][col1]+s2[row2][col2];
	r=XOR(left,temp);
	
	left=right;
	right=r;
	cout<<left << " "<<right<<endl;
	}
	return (left+right);
}

int main(){
	in();
	cout<<"Simplified DES with 12 bit input\n";
	cout<<"select from given options : 1. Encription\n2. Decription\n";
	int option;
	cin>>option;
	string plainText,cipherText;
		string key;
	switch(option){
		case 1:
			cout<<"Enter 9 bit key :";		
			cin>>key;
			cout<<"Enter 12 bit plaintext: ";		
			cin>>plainText;
			cipherText=DES(plainText,key);
			cout<<"Obtained Cipher Text : "<<cipherText<<endl;
			break;
		case 2:
			cout<<"Enter 9 bit key :";
			cin>>key;
			cout<<"Enter 12 bit ciphertext: ";
			cin>>cipherText;
			plainText=DES(cipherText,key);
			cout<<"Obtained Plain Text : "<<plainText<<endl;
			break;
		default:
			cout<<"Enter correct option"<<endl;
	}
	return 0;
}

//001001101 key
//L1R1 000111011011 l4r4 000011100101
//l1r1* 101110011011 l4r4* 100100011000.
