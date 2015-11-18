#include <iostream>

using namespace std;

class Rational
{
public:
    Rational();
    Rational(int num, int den);
    
    //Rational& operator+=(Rational a);
    //Rational& operator-=(Rational a);
    //Rational& operator*=(Rational a);
    //Rational& operator/=(Rational a);
    friend bool operator==(Rational a, Rational b){return (a.n==b.n) && (a.d==b.d); }
    friend bool operator!=(Rational a, Rational b){return !(a==b);}

    //friend bool operator<=(Rational a, Rational b);
    //bool operator>=(Rational a, Rational b);
    //bool operator< (Rational a, Rational b);
    //bool operator> (Rational a, Rational b);    
    
    int n;  // numerator
    int d;  // denominator
    
    void reduce();
};


ostream& operator<<(ostream& os, Rational a)
{
    os << a.n << "/" << a.d;
    
    return os;
}


Rational::Rational()
{
}


Rational::Rational(int num, int den)
{
    n = num;
    d = den;
    
    reduce();
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


Rational operator+(Rational a, Rational b)
{
    return Rational(a.n * b.d + b.n * a.d, a.d * b.d);
}


Rational operator-(Rational a, Rational b)
{
    return Rational(a.n * b.d - b.n * a.d, a.d * b.d);
}


Rational operator*(Rational a, Rational b)
{
    return Rational(a.n * b.n, a.d * b.d);
}


Rational operator/(Rational a, Rational b)
{
    return Rational(a.n * b.d, a.d * b.n);
}


int main()
{
    Rational r(1, 3), s(1, 6), u(2, 5), v(-5, 6);
    
    // Basic arithmetic
    
    Rational t;
    
    t = r + s;
    
    cout << "1/3 + 1/6 = " << t << endl;
    Rational x(2,4);
    bool val = (t==x);
    cout << val << endl;

    cout << (x!=t) <<endl;
}

