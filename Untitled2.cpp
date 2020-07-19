#include<iostream>
using namespace std;

class IndiaBix{
	public :int x ;
	IndiaBix( int x){
		cout<<x<<endl;
	}
	//cout<<"Final";
	~IndiaBix();
};

int main(){
    IndiaBix *ptr= new IndiaBix(2);
	return 0;
}

