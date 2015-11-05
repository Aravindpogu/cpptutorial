#include <iostream>
#include <ctime>
#include <vector>
 
using namespace std;
 
void print(const vector<int>& col)
{
    // convert the following to use a range-based for
    typedef vector<int>::const_iterator Iter;
    
    for (Iter i = col.begin(); i != col.end(); ++i)
    {
        cout << *i << " ";
    }
    
    cout << endl;
}
 
void randomize(vector<int>& col)
{
    // convert the following to use a range-based for
    typedef vector<int>::iterator Iter;
    
    for (Iter i = col.begin(); i != col.end(); ++i)
    {
        *i = rand() % 1000;
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
    // replace the verbose iterator types names with auto
    vector<int>::iterator m = begin;
    
    for (vector<int>::iterator i = m + 1; i != end; ++i)
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
    // replace the verbose iterator types names with auto
    typedef vector<int>::reverse_iterator Iter;
    
    for (Iter i = col.rbegin(); i != col.rend(); ++i)
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
    
    return 0;
    
}
