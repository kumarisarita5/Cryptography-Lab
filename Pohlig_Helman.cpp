#include<bits/stdc++.h>
using namespace std;

// function to factorize a number
map<long long int,long long int> factor(long long int n){
	map<long long int,long long int>factors;
	for (long long int i=2;n>1;i++){
		while(n%i==0){
			factors[i]++;
			n/=i;
		}
	}
	return factors;
}

// extended euclid function
int ext_euclid(long long int a, long long int b,long long int &s,long long int &t){
	int d;
	if(b==0){
		d = a;
		s = 1;
		t = 0;
		return d;
	}
	int q,r,s2=0,s1=1,t2=1,t1=0;
	while(b>0){
		q=a/b;
		r=a-q*b;
		s=s1-q*s2;
		t=t1-q*t2;

		a = b;
		b = r;
		
		s1=s2;
		s2=s;
		
		t1=t2;
		t2=t;
	}
	d=a; 
	s=s1;
	t=t1;
	return d;
}

//function to implement chinese remainder theorem
long long int ChineseRem(vector<long long int>a,
		map<long long int,long long int>factors,
		long long int n){
			
	long long int x=0,M=1;
	vector<long long int> b;
	
	map<long long int,long long int>::iterator it;
	for(it=factors.begin();it!=factors.end();it++)
		b.push_back(pow(it->first, it->second));
	
	for(int i=0;i<b.size();i++)
		M*=b[i];
		
	long long int q,z;
	for(int i=0;i<a.size();i++){
		ext_euclid(M/b[i],b[i],q,z);
		x+=a[i]*M/b[i]*q;
		
			x%=(n-1);
			
		if(x<0)
			x += n-1;
	}
	return x;
}

// to calculate a^c%b
int Power(int a, int b, int c){
	int i = 1;
	for(int j=0;j<c;++j){
		i=(i*a)%b;
	}
	return i;
}


// function where actual calculation and various equation on x is calculated
int calculate(long long int n,long long int b,
		long long int y,long long int p,long long int h){
	int x = 0;
	int buf;
	map<int, int> r;
	for (int i = 0; i < p; i++){
		buf = Power(b, n, (n - 1) / p * i);
		r[buf] = i;
	}

	for (int i = 0; i < h; i++)
	{
		buf = Power(y, n, (n - 1) / pow(p, i+ 1));
		x += pow(p, i)*r[buf];
		buf = -r[buf];
		while (buf < 0)
			buf += n - 1;
		buf = Power(b, n, pow(p, i)*buf);
		y = y*buf;
		y %= n;
	}
	buf = pow(p, h);
	return x % buf;
}


int main(){
	long long n,alpha, beta;
	cout << "Enter a mod N: ";
	cin >> n;
	cout << "\nEnter alpha: ";
	cin >> alpha;
	cout << "\nEnter beta: ";
	cin >> beta;
	
	vector<long long int>x;
	map<long long int,long long int> factors=factor(n-1);
			
	map<long long int,long long int>::iterator it;
		
	for(it=factors.begin();it!=factors.end();it++)
		x.push_back(calculate(n,alpha,beta,it->first,it->second));
	
	cout<<n-1<<" = ";
	for(it=factors.begin();it!=factors.end();it++){
		map<long long int,long long int>::iterator ii;
		ii=++it;--it;
	if(ii==factors.end()){
		cout<<it->first<<"^"<<it->second<<endl;
	}
	else
		cout<<it->first<<"^"<<it->second<<" * ";
	}
	
	cout<<"Solution: X = "<<ChineseRem(x,factors,n)<<endl;
	return 0;
}
