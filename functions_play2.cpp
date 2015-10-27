// My first program
// Simple calculator app
#include   <iostream>
#include <cmath>

using namespace std;

double distance(double x, double y){
        return sqrt(x*x + y*y);
}
bool inside(double r, double x, double y);
void draw(double r, char ch = '*', bool fill = true, double width = 1.0);
int main(){
	draw(5.3,'*', false, 2.1);
}
void draw(double r, char ch, bool fill, double width)
{
  for (int y = -r-1; y < r+1; y++)
  {
    for (int x = -r-1; x < r+1; x++){
	if(inside(r-width, x,y)){
		if(fill)
 			cout <<ch;
		else
			cout<< ' ';    
	}else if(inside (r,x,y)){
		cout << ch;
	}else{
		cout << ' ';
	}
  	}
	cout <<endl;
}
}
bool inside(double r, double x, double y){
	return r > distance(x,y);
	
}
