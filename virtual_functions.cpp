#include<iostream>
using namespace std;

class Pet
{
public:
   virtual void move(){
        cout<< "Pet step" << endl;
   }
virtual void speak(bool loud)=0;
};

class Bird : public Pet
{
public:
   virtual void move(){
	cout<< "Bird is Flying.." << endl;
   }
   virtual void speak(bool loud)
   {
      if (loud)
           cout << "squawk";
      else
           cout << "chirp ";
   }
};

class Fish : public Pet
{
public:
   virtual void move(){
	cout<< "Fish is swimming" << endl;
   }
    virtual void speak(bool loud)
   {
        cout << "Fish Gurgling..";
   }

};

class Snake : public Pet
{
public:
   virtual void move(){
	cout<< "Snake is moving" << endl;
   }
 virtual void speak(bool loud)
   {
        cout << "hiss";
   }


};

void exercise(Pet& a, int n)
{
   for (int i = 0; i < n; i++)
      a.move();
}

void dance(Pet& a)
{
  a.speak(false);

  a.move();
  a.move();

  a.speak(true);

  a.move();

  a.speak(false);
  a.speak(false);

  cout << endl;
}

int main()
{
   Bird  b;
   Fish  f;
   Snake s;

   exercise(b, 3);
   exercise(f, 5);
   exercise(s, 2);

   dance(s);
   dance(b);
   dance(f);

}
