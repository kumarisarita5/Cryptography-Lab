//differential cryptanalysis
//page 134 wasington book
//000111011011 000011100101 101110011011 100100011000 K 001001101
//stago algo use krna and stago image generate krna for all images in dataset
//given an image from stago + normal set classify whether stago image normal image
//use svm
//search gaan algo for image generation
#include "desHeder.h"
#include<bits/stdc++.h>
using namespace std;

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

string Result(string ip, string op,bool flag){
	cout<<ip<<op<<endl;
	
	int input=COL(ip);
	int n,r1,r2,c1,c2,i=0;
	for(;i<15;++i){
		n=i^input;
		r1=0;c1=i;r2=0;c2=n;
		if(i>=8){
			r1=1;c1-=8;
		}	
		if(n>=8){
			r2=1;c2-=8;
		}		
	
	//	cout<<s1[r1][c1]<< " "<<s1[r2][c2]<<endl;
	string ch;
	if(flag)
	ch=XOR(s1[r1][c1],s1[r2][c2]);
	else
	ch=XOR(s2[r1][c1],s2[r2][c2]);
	if(ch.compare(op)==0){
		cout<<i<<" "<<n<<endl;
		cout<<InttoString(i)<<" "<<InttoString(n)<<endl;
		return InttoString(i) + InttoString(n);
		}		
	}
}

int main(){
	in();
	string l1r1,l4r4,l1r1Star,l4r4Star,L1,R1,L4,R4;
	string L1Star,R1Star,L4Star,R4Star,temp,_temp,S1ip,S2ip,_R4, _L1,S1op,S2op,EL4;
	/*
	cout<<"Enter L1R1 : ";
	cin>>l1r1;
	cout<<"Enter L4R4 : ";
	cin>>l4r4;
	cout<<"Enter L1R1Star : ";
	cin>>l1r1Star;
	cout<<"Enter L1R1Star : ";
	cin>>l4r4Star;
	*/
	l1r1="000111011011";
	l4r4="000011100101";
	l1r1Star="101110011011";
	l4r4Star="100100011000";
	
	L1=l1r1.substr(0,6);R1=l1r1.substr(6,6);
	L4=l4r4.substr(0,6);R4=l4r4.substr(6,6);
	L1Star=l1r1Star.substr(0,6);R1Star=l1r1Star.substr(6,6);
	L4Star=l4r4Star.substr(0,6);R4Star=l4r4Star.substr(6,6);
	
	_R4=XOR(R4,R4Star);
	_L1=XOR(L1,L1Star);
	_temp=XOR(_R4,_L1);
	cout<<"R' = "<<_R4<<" "<<"\nL' = "<<_L1<<" "<<_temp<<endl;
	
	 temp=XOR(E(L4),E(L4Star));
	 //cout<<E(L4)<<" "<<E(L4Star)<<" "<<temp<<endl;
	 S1ip=temp.substr(0,4),S2ip=temp.substr(4,4);
	 S1op=_temp.substr(0,3),S2op=_temp.substr(3,3);
	 
	 cout<<temp<<" "<<S1ip<<" "<<S1op<<endl;
	 cout<<_temp<<" "<<S2ip<<" "<<S2op<<endl;
	 
	 string resLeft = Result(S1ip,S1op,true); 
	 string resRight = Result(S2ip,S2op,false); 
	 cout<<"Pairs obtained for S1 are :";
	 cout<<resLeft.substr(0,4)<<" "<<resLeft.substr(4,4)<<" and "<<resLeft.substr(4,4)<<" "<<resLeft.substr(0,4)<<endl;
	 //E(l4)^K4 = values obtained => k4= E(l4)^ values
	 EL4 = E(L4);
	 
	 cout<<"First 4 bits of key can be :"<<XOR(EL4.substr(0,4),resLeft.substr(0,4))<<
	 " or "<<XOR(EL4.substr(0,4),resLeft.substr(4,4))<<endl;
	 
	 
	 cout<<"Pairs obtained for S2 are :";
	 cout<<resRight.substr(0,4)<<" "<<resRight.substr(4,4)<<" and "<<resRight.substr(4,4)<<" "<<resRight.substr(0,4)<<endl;
	 
	 cout<<"Last 4 bits of key can be :"<<XOR(EL4.substr(4,4),resRight.substr(0,4))<<
	 " or "<<XOR(EL4.substr(4,4),resRight.substr(4,4))<<endl;
		return 0;
}
