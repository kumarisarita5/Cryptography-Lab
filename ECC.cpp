//ECC
#include<bits/stdc++.h>
using namespace std;

int main(){
	string  m="00100101000000000000000100010010000001101001001010";
	int len=m.length();
	string dummy="0000000000";
	if(len%10)
	m+= dummy.substr(0,10-len%10);
	string digest = SHA(m);
	cout<<"Message Digest : "<<digest<<endl;
	
	return 0;
}

