#include<bits/stdc++.h>
using namespace std;

int main(){
	cout<<"Enter a, b , modulo :";
	long long a, b, p;
	cin>>a>>b>>p;
	//y^2 = x^3 + a*x + b mod p; 
	
	vector<pair<int, int> >points;
	
	for(int i=0;i<p;++i){
		long long t=i*i*i + a*i + b;
			t=t%p;
			if(t<0) t+= p;
		for(int j=0;j<p;++j){
			long long temp=(j*j)%p;
			if(temp==t){
				points.push_back(make_pair(i,j));
			}
		}
	}
	
	long long int len=points.size();
	for(long long i=0; i<len; i++){
		cout<<points[i].first <<" "<<points[i].second<<endl;
	}
	
	return 0;
	
}
