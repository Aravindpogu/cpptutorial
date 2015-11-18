#include<iostream>
#include<exception>
using namespace std;

template<typename T> const T& max(const T& a, const T& b)
{ 
  return a>b ? a : b;
}

// Here are a few invocations to try
/*int a, b;
int i = max(a, b);

double a, b;
double d = max(a, b);

char a, b;
char c = max(a, b);

int a;
char b;
int i = max(a, b); // this won’t compile, compiler cannot deduce the type for T
int ii = max<int>(a, b); // explicitly tell the compiler the type for T

template<typename SrcT, typename DstT>
DstT implicit_cast(const SrcT& x) { return x; }

int j = 10;
double d = implicit_cast<int, double>(i);*/

//const int NUM_ELEMENTS = 10;

template<typename T, int NUM_ELEMENTS>
class CheckedArray {
  T data[NUM_ELEMENTS];
public:
  int get(int index) {
    if (index < 0 || index > (NUM_ELEMENTS - 1) ) {
      throw "out of range";
    }
    return data[index];
  }

  void set(int index, T value) {
    if (index < 0 || index > (NUM_ELEMENTS - 1) ) {
      throw "out of range";
    }
    data[index] = value;
  }
};
int main()
{
  try {
    // create a CheckedArray of 5 doubles
    CheckedArray<double, 5> arr;

    //fine, within range
    arr.set(0, 2.5);

    // returns 2.5
    double x = arr.get(0);

    // out of range, throw exception
    arr.set(3, 4.2);
  } catch (char* e) {
    std::cout << "exception occurred" << endl;
  }
}
