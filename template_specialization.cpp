#include<iostream>
using namespace std;

template<typename T>
void print(T value) {
  cout << "print<T> : ";
  cout << value << endl;
}

template<typename T>
void print(T* value) {
  cout << "print<T*> : ";
  cout << *value << endl;
}


template<>
void print(char* value) {
  cout << "print<char*> : ";
  cout << value << endl;
}

int main()
{
  int i = 42;
  int *pi = &i;
  char s[] = "hello";
  char *s1 = s;
 
  print(i);
  print(pi);
  print(s);
  print(s1);
}
