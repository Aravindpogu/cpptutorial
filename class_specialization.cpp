#include<iostream>
using namespace std;

class Publication
{
public:
  Publication():m_publisher(""), m_copyright(0){}
  Publication(string publisher, int copyright):m_publisher(publisher), m_copyright(copyright){}
 ~Publication(){}
  string getDescription() { return "Publihser: " + m_publisher; }
private:
  string m_publisher;
  int    m_copyright;
};

class Book : public Publication
{
public:
  Book(){}
  ~Book(){}
  Book(string title, string author, string publisher, int copyright):Publication(publisher, copyright), m_title(title), m_author(author){}
  string getDescription(){return Publication::getDescription() + " title: " + m_title + " author : " + m_author; }
  string getAuthor(){return m_author;}
  string getTitle(){return m_title;}
private:
  string m_title;
  string m_author;
};

void read(Book b)
{
  cout << "read " << b.getDescription() << endl;
}



int main()
{
  Book b("Walden", "Thoreau", "Beacon", 1800);

  cout << b.getDescription() << endl;
  
  read(b);
}





