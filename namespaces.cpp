#include<iostream>
using namespace std;
namespace Tool
{
  class Mallet
  {
	public:
		void pound()
		{
  			cout << "pound tool:mallet\n"; 
		}
  };

  class Saw  
  {
	public:
		void pound()
		{
  			cout << "pound tool:saw\n"; 
		}
  };

  class Plane
  {
	public:
		void pound()
		{
  			cout << "pound tool:plane\n"; 
		}
  };
}

namespace Transport
{
  class Plane
  {
	public:
		void pound()
		{
  			cout << "pound transport:plane\n"; 
		}
  };

  class Truck
  {
	public:
		void pound()
		{
  			cout << "pound transport truck\n"; 
		}
  };

  class Ship
  {
	public:
		void pound()
		{
  			cout << "pound transport ship\n"; 
		}
  };
}

using namespace Tool;
using Transport::Ship;
int main(){
  Mallet m1;
  Saw    s1;
  Plane  p1;

  Transport::Plane p2;
  Transport::Truck t2;
  Transport::Ship  s2;

  m1.pound();
  s1.pound();
  p1.pound();
  p2.pound();
  t2.pound();
  s2.pound();
}
