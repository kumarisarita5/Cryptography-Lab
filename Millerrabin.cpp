//Primality Testing
//Miller Rabin
#include<bits/stdc++.h>
using namespace std;

int power(int a , int d , int n){
	long int x=1;
	for( int i=0;i<d;++i){
		x=(x*a)%n;
	}
	return x;
}

bool millerRabin(int d, int n) { 
    int a=2+rand()%(n-4); 
    int x=power(a,d,n); 
  
    if(x==1 || x == n-1) 
       return true; 
    while(d!=n-1){ 
        x=(x*x)%n; 
        d*=2;  
        if(x==1)      
		return false; 
        if (x==n-1)    
		return true; 
    }  
    return false; 
} 

bool isPrime(int num){
	if(num== 2 || num==3) 
	return true;
	if(num==1 || num == 4) 
	return false;
	
	int n=num-1,k=0;
	while(n%2 ==0){
		k++;
		n/=2;
	}
         if (!millerRabin(n, num)) 
              return false; 
  
    return true; 
}

int main(){
	int num;
	cout<<"Enter number :";
	cin>>num;
	if(isPrime(num))
	 cout<<num<<" is Prime as per Miller Rabin Test"<<endl;
	else
	 cout<<num<<" is Composite as per Miller Rabin Test"<<endl;
	return 0;
}
