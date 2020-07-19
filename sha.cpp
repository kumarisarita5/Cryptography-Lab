//ECC
#include<bits/stdc++.h>
using namespace std;
#define N 20


int main(){
	string  m="001001010000000000000001000100100000011010010010101110101";
	int len=m.length();
	string dummy="0000000000";
	if(len%N)
	m+= dummy.substr(0,N-len%N);
	string digest = SHA(m);
	cout<<"Message Digest : "<<digest<<endl;
	
	return 0;
}

