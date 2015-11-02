#include<iostream>

using namespace std;

void pprint(int* begin, int* end)
{
  int* p = begin;

  while (p != end)
  {
    // print out element pointed to by p, and advance p by 1 
   cout << *p << " " ;
   ++p;
  }
  cout <<endl;
}


void iprint(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " " ;
  }
cout <<endl;
}
int main()
{
  int a[10];

  for (int i = 0; i < 10; i++)
  {
    *(a+i) = i * i;
  }

  /*for (i = 0; i < 10; i++)
  {
    cout << *(a+i);
  }*/

pprint(&a[3], &a[7]);
  iprint(&a[3], 4);

pprint(a + 3, a + 7);
  iprint(a + 3, 4);
}
