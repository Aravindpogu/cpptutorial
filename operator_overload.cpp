#include<iostream>
using namespace std;

class Rational 
{
 public:
  Rational():n(0),d(1){}
  Rational(int num, int den):n(num), d(den){};

  int n;  // numerator
  int d;  // denominator

  friend int gcd(int i, int j);
  friend ostream& operator<<(ostream& s, Rational a);
  void reduce();
  friend Rational operator-(Rational a);

  friend Rational operator+(Rational a, Rational b);
  friend Rational operator-(Rational a, Rational b);
  friend Rational operator*(Rational a, Rational b);
  friend Rational operator/(Rational a, Rational b);
};

Rational operator+(Rational a, Rational b)
{
     a.reduce();
     b.reduce();
     cout << " After reduce a is : "<<endl << a << endl <<" and b is : " <<endl<< b;
     return Rational(a.n * b.d + b.n * a.d, a.d * b.d);
}

Rational operator-(Rational a, Rational b)
{
     a.reduce();
     b.reduce();
     cout << " After reduce a is : "<<endl << a << endl <<" and b is : " <<endl<< b;
     Rational r =  Rational(a.n * b.d - b.n * a.d, a.d * b.d);
     r.reduce();
     return r;
}


Rational operator*(Rational a, Rational b)
{
     Rational r = Rational(a.n * b.n , b.d * a.d);
     r.reduce();
     return r;
}
Rational operator/(Rational a, Rational b)
{
     Rational r = Rational((a.n * b.d) , (b.n * a.d));
     r.reduce();
     return r;
}
Rational operator-(Rational a){
     return Rational(-(a.n), a.d);
}

int gcd(int i, int j)
{
  if (j == 0)
    return i;
  else
    return gcd(j, i % j);
}
void Rational::reduce()
{
  
  if (d < 0)
  {
    d = -d;
    n = -n;
  }

  int g = n < 0 ? gcd(-n, d) : gcd(n, d);

  n /= g;
  d /= g;
}
ostream& operator<<(ostream& out, Rational a)
{
  out << a.n << endl << "-- " <<endl << a.d ;
  return out;
}

int main()
{
  Rational r(3,9); // one half
  Rational s(2,12); // two thirds

  Rational t = r + s;  // sum is seven sixths
  t.reduce();
  cout <<"sum is : " <<endl << t <<endl;

  cout << endl << "negative t value is : " << endl << -t << endl;
  t = r-s;  
  cout << endl << "r-s value is : " << endl << t << endl;
  t = r *s ;
  cout << endl<< "r*s  value is : " << endl << t << endl;
  t = r/s;  
  cout << endl<< "r/s value is : " << endl << t << endl;
}


