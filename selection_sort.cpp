#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void randomize(int a[], int n){
	srand(time(0));
	for(int i=0; i<n; i++){
		a[i] = rand()%n;
	}
}

void print(const int a[], int n){
	for(int i=0; i<n; i++){
		cout<< a[i] << " ";
	}
}

void swap(int& x, int& y){
	int temp = x;
	x=y;
	y=temp;
}

int& max(int a[], int n){
	int maxIndex = 0;
	for(int i=1; i<n-1; i++){
		if(a[maxIndex] <= a[i])
			maxIndex= i;
	}
	return a[maxIndex];
}
void sort(int a[], int n){
	for(int i=n-1; i>=0; i--){
		swap(a[i], max(a,i+1));
	}
}	
int main(){

	int a[10];
	randomize(a,10);
	print(a,10);

	//swap(a[9], max(a,10));
	cout << endl;
	sort(a, 10);
	print(a,10);
}
