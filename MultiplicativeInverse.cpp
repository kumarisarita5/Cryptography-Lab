//implementation of extended euclidian algo
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long int num, mod, inv;
	cout<<"enter number :";
	cin>>num;
	cout<<"enter modulo :";
	cin>>mod;
	if(__gcd(num,mod)!=1){
		cout<<"Inverse not possible\n";
		return 0;
	}
	long long int q,t1=0,t2=1,t,r1,r2,r;
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
	cout<<"Inverse of "<<num<<" under mod "<<mod<<" is : "<<t1<<endl;
	return 0;
}
