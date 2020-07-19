#include <bits/stdc++.h>
using namespace std;

//to store continued fraction sequence
int continued_fraction[1000];

//initialise continued fraction sequence array
void initialize(double e, double n){
	double fraction,ratio;
	ratio =(double)(e)/(double)(n);
	long long whole;
	whole=floor(ratio);
	fraction=ratio-whole;
	
	continued_fraction[0]=whole;
	for(int i=1;i<1000;++i){
	ratio=1/fraction;
	whole=floor(ratio);
	fraction=ratio-whole;
	continued_fraction[i]=whole;
	}
	
}

//to check if a number is integer or float
bool isint(double a){
	if(a-floor(a)<0.000001)
	return 1;
	
	return 0;
}

//to solve quadratic equation and check if roots are integers
bool solveQuadratic(long int phiN, long int n){
	long long int  a=1,b=(phiN-1-n),c=n;
	long long  int det=b*b-4*a*c;
	if(det<0) return 0;
	
		double p=(-1*(double)b+sqrt(det))/2;
		double q=(-1*(double)b-sqrt(det))/2;
		
		if(isint(p) && isint(q)){
			cout<<"P and Q are :"<<p<<" "<<q;
			return 1;
		}
		return 0;
		
}

//function to calculate private key
void weinersAttack(double e,double N){
	bool flag=0;
	for(int i=1;i<1000;++i){
	long long temp=continued_fraction[i],num,den=1,t;
	for(int j=i-1;j>=0;--j){
		swap(temp,den);
		num=continued_fraction[j];
		temp=num*den+temp;
	}
	num=temp;
	long int k,d;
	k=num,d=den;
	double phiN=(e*d-1)/k;
	if(isint(phiN)){
	
	  if(solveQuadratic(phiN,N)){
	  	cout<<"\nPrivate key is "<<d<<endl;
        flag=true;
	  }
	}
	if(flag) break;
	}
	if(!flag)
	cout<<"Result couldn't be found in 1000 iterations."<<endl;
}

//main fxn
int main(){
	double e,N;
	printf("Enter the public key (e) & N :");
	cin>>e>>N;
	
	initialize(e,N);
	
	weinersAttack(e,N);
	
	return 0;
}


//testcases checked
//25411171 27962863 529x529
//17993 90581 379x239
