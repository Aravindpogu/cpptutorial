#include<iostream>
using namespace std;

int count = 0;

struct Book
{
  Book(string title, string author, int id, bool out=false);
  //Book(string title, string author, int id);
  Book();  
 
  ~Book();
  string m_title;
  string m_author;
  int    m_id;
  bool   m_out;
};

Book::Book(){ 
	cout << "Object count is : " << ++count << endl;
}

Book::~Book(){
	cout << "Object Count is : "<< --count << endl;
}
Book::Book(string title, string author, int id, bool out){
	m_title = title;
	m_author = author;
	m_id = id;
	m_out = out;
	cout << "Object count is :  " << ++count << endl;
}

//Book::Book(string title, string author, int id){
//	m_title = title;
//	m_author = author;
//	m_id = id;
//	cout << "Object count is : " << ++count << endl;
//}
void pass()
{
  Book b("Atlas Shrugged", "Rand", 120, false);

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
  Book b1("Candide", "Voltaire", 101, false);
  Book b2("Lolita",  "Nabokov", 102, true );
  Book b3();
  Book b4("Alchemist", "Paulo", 104, false);
  Book b5("WhiteTiger",  "Aravind", 105);
  Book b6("HarryPotter",  "Rowling", 106);
  Book b7;

  pass();
  Book b[5];
  pass();

  Recommendations r;

  r.m_classic   = Book("Hard Times", "Dickens", 109);
  r.m_scifi     = Book("The War of the Worlds", "Wells", 110);
  r.m_mystery   = Book("The Big Sleep", "Chandler", 111);  
}
