//DES
#include<bits/stdc++.h>
using namespace std;

string roundKeys[16];

string shift_left_once(string key_chunk){ 
    string shifted="";  
        for(int i = 1; i < 28; i++){ 
            shifted += key_chunk[i]; 
        } 
        shifted += key_chunk[0];   
    return shifted; 
} 
// Function to do a circular left shift by 2
string shift_left_twice(string key_chunk){ 
    string shifted=""; 
    for(int i = 0; i < 2; i++){ 
        for(int j = 1; j < 28; j++){ 
            shifted += key_chunk[j]; 
        } 
        shifted += key_chunk[0]; 
        key_chunk= shifted; 
        shifted =""; 
    } 
    return key_chunk; 
}
void generate_keys(string key){
	// The PC1 table 
	int pc1[56] = {
	57,49,41,33,25,17,9, 
	1,58,50,42,34,26,18, 
	10,2,59,51,43,35,27, 
	19,11,3,60,52,44,36,		 
	63,55,47,39,31,23,15, 
	7,62,54,46,38,30,22, 
	14,6,61,53,45,37,29, 
	21,13,5,28,20,12,4 
	};
	// The PC2 table
	int pc2[48] = { 
	14,17,11,24,1,5, 
	3,28,15,6,21,10, 
	23,19,12,4,26,8, 
	16,7,27,20,13,2, 
	41,52,31,37,47,55, 
	30,40,51,45,33,48, 
	44,49,39,56,34,53, 
	46,42,50,36,29,32 
	}; 
	// 1. Compressing the key using the PC1 table
	string perm_key =""; 
	for(int i = 0; i < 56; i++){ 
		perm_key+= key[pc1[i]-1]; 
	} 
	// 2. Dividing the result into two equal halves
	string left= perm_key.substr(0, 28); 
	string right= perm_key.substr(28, 28); 
	// Generating 16 keys
	for(int i=0; i<16; i++){ 
		// 3.1. For rounds 1, 2, 9, 16 the key_chunks
		// are shifted by one.
		if(i == 0 || i == 1 || i==8 || i==15 ){
			left= shift_left_once(left); 
			right= shift_left_once(right);
		} 
		// 3.2. For other rounds, the key_chunks
		// are shifted by two
		else{
			left= shift_left_twice(left); 
			right= shift_left_twice(right);
		}
	// 4. The chunks are combined
	string combined_key = left + right;
	string round_key = ""; 
	// 5. Finally, the PC2 table is used to transpose
	// the key bits
	for(int i = 0; i < 48; i++){ 
		round_key += combined_key[pc2[i]-1]; 
	}   
	round_keys[i] = round_key;
	cout<<"Key "<<i+1<<": "<<round_keys[i]<<endl; 
	} 

}
int main(){  
	string key = "10101010101110110000100100011000001001110011"
	"01101100110011011101";
  	generate_keys(key);
} 


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
		int temp=((p[i] -'A') - (k[i]-'A')+26)%26;
	 	c=c+char(temp+'A');	
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
