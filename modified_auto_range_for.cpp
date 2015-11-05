#include <iostream>
#include <ctime>
#include <vector>
 
using namespace std;
 
void print(const vector<int>& col)
{
    for (auto i : col)//Iter i = col.begin(); i != col.end(); ++i)
    {
        cout << i << " ";
    }
    
    cout << endl;
}
 
void randomize(vector<int>& col)
{
    for (auto &i : col)//Iter i = col.begin(); i != col.end(); ++i)
    {
        i = rand() % 1000;
    }
}
 
void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}
 
int& max(vector<int>::iterator begin, vector<int>::iterator end)
{
    auto m = begin;
    for (auto i = m + 1; i != end; ++i)
    {
        if (*i > *m)
        {
            m = i;
        }
    }
    return *m;
}
 
 
void sort(vector<int>& col)
{
    //typedef vector<int>::reverse_iterator Iter;
    for (auto i = col.rbegin(); i != col.rend(); ++i)
    {
        swap(*i, max(col.begin(), i.base()));
        print(col);
    }
}
 
int main()
{
    vector<int> a(10);
    srand(static_cast<unsigned int>(time(0)));
    randomize(a);
    print(a);
    sort(a);
}
