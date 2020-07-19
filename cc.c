
#include<stdio.h>
const int N = 6;

//function declarations
void getData(int *array,int size);
void displayData(int *array, int size);

//main function
int main(){
	int grade[N],i;
	 for( i=0;i<N;++i)
	 grade[i]= 0;
	 
	 //function call to getData function
	 getData(grade,N);
	 
	//function call to displayData function
	 displayData(grade,N);
	 
   	  printf("Grades displayed from main() :\n");
	 for(i=0;i<N;++i){
		printf("%d ",grade[i]);
	}
	return 0;
}

//function definition
void getData(int *array,int size){
	int i;
	printf("Enter grades :\n");
	for(i=0;i<size;i++){
		scanf("%d",&(array[i]));
	}
}

//function definition
void displayData(int *array, int size){
		int i;
	printf("Grades displayed from displayData function :\n");
	for(i=0;i<size;++i){
		printf("%d ",array[i]);
	}
}
