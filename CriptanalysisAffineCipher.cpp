//cryptanalysis of Affine Cipher

#include<iostream>
#include<algorithm>
using namespace std;

//inverse of a number under modulo
int getInverse(int num, int mod){
	
	int q,t1=0,t2=1,t,r1,r2,r;
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
	return t1;
}


int main(){
	cout<<"Enter length of plain text :";
	int length;
	cin>>length;
	cout<<"Enter plain text and cipher text :";
	string p,c;
	cin>>p>>c;
	bool flag=0;
	int a[2][2], b[2];
	int p1,p2,c1,c2;
	a[0][0]=toupper(p[0])-'A';a[0][1]=1;
	a[1][0]=toupper(p[1])-'A';a[1][1]=1;
	b[0]=toupper(c[0])-'A';
	b[1]=toupper(c[1])-'A';
		int det=a[0][0]*a[1][1] - a[0][1]*a[1][0];
	if(det==0){
		flag =1;
		cout<<"can't be deciphered using "<<p<<" and "<<c<<endl;
	}
	if(!flag){
		//making determinant positive
	 while(det<0){
	 	det+=26;
	 }	 
	 // calculating inverse of determinant
	 int detInverse= getInverse(det,26);
	 // calculating inverse of 2D matrix
	 swap(a[0][0], a[1][1]);
	 a[0][1]=-1*a[0][1];
	  a[1][0]=-1*a[1][0];
	  
	  //calcuating inverse under mod
	  for(int i=0;i<2;++i){
	  	for(int j=0;j<2;++j){
	  		a[i][j]=(a[i][j]*detInverse)%26;
	  		while(a[i][j]<0){
	  			a[i][j]+=26;
			  }
		  }
	  }
	  
	  //calculating alpha anad beta
	  int result[2];
	  for(int i=0;i<2;++i){
	  	int temp=0;
	  	for(int j=0;j<2;++j){
	  		temp+=a[i][j]*b[j];
		  }
		  result[i]=temp%26;
	  }
	  cout<<"alpha :"<<result[0]<<" beta :"<<result[1]<<endl;
	}
	return 0;
}
