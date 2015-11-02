#include<iostream>

using namespace std;

int a, b,c;

int *sel = &a; // current selection
int *prev = &b; // previous selection

char tag(int *p){
	if(p == sel){
		return '\'';
	}else if(p == prev){
		return'"';
	}else{
		return ' ';
	}
}


int main(){

	while(true){
		cout << "[";
    		cout << "a" << tag(&a) << a << "  ";
    		cout << "b" << tag(&b) << b << "  ";
    		cout << "c" << tag(&c) << c << "]";

    		cout << " ? ";
		
		char ch;
		cin >>ch;
		switch(ch){
			case 'a' : if(sel != &a) {
					prev = sel;
			} 
			sel = &a;
			break;
			case 'b' : if(sel != &b) {
					prev = sel;
			} 
			sel = &b;
			break;
			case 'c' : if(sel != &c) {
					prev = sel;
			} 
			sel = &c;
			break;
			case '.' : *sel += 1;
			break;
		}
	}
}
