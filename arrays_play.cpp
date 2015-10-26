#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

	int myarray[1000] ;
	int histogram [10]={0,0,0,0,0,0,0,0,0,0};
	int i=0;
	//srand(time(0));
	for(i=0; i<1000;  ++i){
		myarray[i] = rand( )%10;
	}

	for(i=0; i<1000; ++i){
		histogram[myarray[i]]+=1;
	}


	for(i=0; i<10; i++){
		int temp= histogram[i]-10;
		while(temp >0){
			cout<<"* ";
			temp-=10;
		}
		cout << histogram[i] <<endl;
	}
	
}
