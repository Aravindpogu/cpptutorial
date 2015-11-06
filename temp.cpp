#include<iostream>
using namespace std;

int main(){
int my_array[5] = {1, 2, 3, 4, 5};
// double the value of each element in my_array:
for (int& x : my_array) {
    x *= 2;
}

cout << " With &x, the result is :  " << endl;
for (int &x : my_array) {
    cout << "x is : " <<  x << " and &x is : " << &x << endl;
}

cout << " With x, the result is :  " << endl;
for (int x : my_array) {
    cout << "x is : " << x << " and &x is : " << &x <<  endl;
}
}
