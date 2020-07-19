//playfair
#include<bits/stdc++.h>
using namespace std;
int keyMat[5][5];


initialiseMatrix(string key){
	int len=key.length(), i, j;
	bool dict[26];
	memset(dict, sizeof(dict), false);
	vector<int>v;
	for(int i=0;i<len;++i){
		int x=toupper(key[i])-'A';
		if(dict[x]==false && x!=9){
		v.push_back(x);	
		dict[x]=true;
		}
	}
	
	for(int k=0;k<26;++k){
				if(!dict[k] && k!=9){
					v.push_back(k);
				}
	}
	
	int l=v.size();
	for(i=0;i<5;++i){
		for(j=0;j<5;++j){
			for(int k=0;k<l;++k){
				keyMat[k/5][k%5]=v[k];
			}
		}
	}
	
	for(i=0;i<5;++i){
		for(j=0;j<5;++j)
			cout<<keyMat[i][j]<<" ";
			cout<<endl;
	}
}

string encript(string px){
	//preprocessing
	string p="";
	int len=px.length();
	for(int i=0;i<len-1;++i){
		p+=toupper(px[i]);
		if(px[i]==px[i+1])
			p+="X";				
	}
	p+=toupper(px[len-1]);
	len=p.length();
	if(len%2)
		p+="X";
	cout<<p<<endl;	
	//encription
	string c="";
	for(int i=0;i<len-1;i+=2){
		int ch1=p[i]-'A', ch2=p[i+1]-'A',x1,y1,x2,y2;
	    for(int i=0;i<5;++i){
	    	for(int j=0;j<5;++j){
	    		if(keyMat[i][j]==ch1){
	    			x1=i;y1=j;
				}
				if(keyMat[i][j]==ch2){
	    			x2=i;y2=j;
				}
			}
		}
		if(x1==x2){
		c=c+char(keyMat[x1][(y1+1)%5]+'A');
		c=c+char(keyMat[x2][(y2+1)%5]+'A');
		}
		else if(y1==y2){
		c=c+char(keyMat[(x1+1)%5][y1]+'A');
		c=c+char(keyMat[(x2+1)%5][y2]+'A');	
		}
		else{
		c=c+char(keyMat[x1][y2]+'A');
		c=c+char(keyMat[x2][y1]+'A');		
		}	
	}
	
	return c;
}

int main(){
	cout<<"Enter key :";
	string key;
	cin>>key;
	
	initialiseMatrix(key);
	
	
	string plainText,cipherText;
	
			cout<<"Enter text to encript: ";		
			cin>>plainText;
			cipherText=encript(plainText);
			cout<<"Obtained Cipher Text : "<<cipherText<<endl;
	
	return 0;
}
