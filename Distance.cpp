#include<iostream>
using namespace std;

class Distance 
{
public:
  Distance(int miles, int feet, int inches);
  Distance(int ticks = 0);

  void set(int miles, int feet, int inches);
  void set(int ticks);

  int  inches() const;
  int  feet  () const;
  int  miles () const;

  int  ticks() const;
  friend Distance add(Distance d1, Distance d2);

private:
  int m_ticks;
};

Distance add(Distance d1, Distance d2){
	return Distance(d1.ticks() + d2.ticks());
}

Distance::Distance(int miles, int feet, int inches){
	m_ticks = 5280 *12* miles + 12 * feet + inches; 
}
Distance::Distance(int ticks){
	m_ticks = ticks;
}

void Distance::set(int miles, int feet, int inches){
	m_ticks = 5280 *12* miles + 12 * feet + inches; 
}
void Distance::set(int ticks){
	m_ticks= ticks;
}
int  Distance::inches() const{
	return m_ticks%12;
}
int  Distance::feet () const{
	return m_ticks/5260%12;
}  
int  Distance::miles () const{
	return m_ticks/5280/12;
}
int Distance::ticks() const{
	return m_ticks;
}

int main()
{
  Distance d1(3, 2562, 9);
  Distance d2(10000);
  Distance d3= add(d1, d2);

  //d3.set(d1.ticks() + d2.ticks());

  cout << "d3 = "
       << d3.miles () << " miles "
       << d3.feet  () << " feet "
       << d3.inches() << " inches "
       << "= "
       << d3.ticks () << " ticks\n";
}
