#include <iostream>
#include <string>

using namespace std;

int book_count = 0;
int author_count = 0;

struct Author
{
  Author(): m_name("Anonymous"){cout << author_count++ << "  Author()" << endl;}
  Author(string name):m_name(name){cout << author_count++ << "  Author()" << endl;}
 ~Author(){cout << author_count-- << " ~Author(" << m_name << ")" << endl;}

  string m_name;
};

struct Book
{
    Book();
    Book(string title, Author author, int id, bool out = false);
    ~Book();
    
    string m_title;
    Author m_author;
    int    m_id;
    bool   m_out;
};


Book::Book()
{
    m_title  = "Untitled";
    m_author = Author("Anonymous");
    m_id     = 0;
    m_out    = false;
    
    book_count++;
    
    cout << book_count << "  Book()" << endl;
}


Book::Book(string title, Author author, int id, bool out)
{
    m_title  = title;
    m_author = author;
    m_id     = id;
    m_out    = out;
    
    book_count++;
    
    cout << book_count << "  Book(" << title << ", " << author.m_name << ", " << id << ", " << (out ? "true" : "false") << ")" << endl;
}


Book::~Book()
{
    book_count--;
    
    cout << book_count << " ~Book(" << m_title << ")" << endl;
}


void pass()
{
    Book b("Atlas Shrugged", Author("Rand"), 120, false);
    
    cout << "passing time\n";
}


struct Recommendations
{
    Book m_classic;
    Book m_scifi;
    Book m_mystery;
};


int main()
{
    Book b1("Candide", Author("Voltaire"), 101, false);
    Book b2("Lolita",  Author("Nabokov"),  102, true );
    
    Book b3("Walden", Author("Thoreau"), 103);
    
    Book b4;
    
    Book bs[5];
    
    bs[0] = Book("Babbit", Author("Lewis"), 104);
    bs[1] = Book("The Jungle", Author("Sinclair"), 105);
    bs[2] = Book("Brave New World", Author("Huxley"), 106);
    bs[3] = Book("The Catcher in the Rye", Author("Salinger"), 107);
    bs[4] = Book();
    
    pass();
    pass();
    
    Recommendations r;
    
    r.m_classic = Book("Hard Times", Author("Dickens"), 109);
    r.m_scifi   = Book("The War of the Worlds", Author("Wells"), 110);
    r.m_mystery = Book("The Big Sleep", Author("Chandler"), 111);
    
    cout << "done" << endl;
}

