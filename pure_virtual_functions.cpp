#include<iostream>
#include<string>

using namespace std;

class Pet{
public:
  Pet(string name): m_name(name){cout << "calling Pet Constructor " << endl;}
  virtual void speak(bool loud)=0;
  virtual string getName(){ return m_name;}
  virtual ~Pet(){cout << "calling Pet Destructor" << endl; }
private:
  string m_name;

};

class Cat:public Pet{
public:
  Cat(string name):Pet(name){cout<< "calling Cat constructor " << endl;}
  virtual ~Cat(){cout<< "calling Cat Destructor " << endl;}
  virtual void speak(bool loud){
	if(loud)
		cout <<getName() <<  " : meow" <<endl;
	else
		cout <<getName () << "purr" <<endl;
  }

};

class Fish:public Pet{
public:
  Fish(string name):Pet(name){cout<< "calling Fish constructor " << endl;}
  virtual ~Fish(){cout<< "calling Fish Destructor " << endl;}
  virtual void speak(bool loud){
        if(loud)
                cout <<getName() <<  " This is whale !!" <<endl;
        else
                cout <<getName () << "Small fish" <<endl;
  }

};
class Bird:public Pet{
public:
  Bird(string name):Pet(name){cout<< "calling Bird constructor " << endl;}
  virtual ~Bird(){cout<< "calling Bird Destructor " << endl;}
  virtual void speak(bool loud){
        if(loud)
                cout <<getName() <<  " I am Ostrich" <<endl;
        else
                cout <<getName () << "I am nightingale" <<endl;
  }

};
class Snake:public Pet{
public:
  Snake(int length, string name):Pet(name), m_length(length){cout<< "calling  Snake constructor " << endl;}
  virtual ~Snake(){cout<< "calling Snake Destructor " << endl;}
  virtual void speak(bool loud){
        if(loud)
                cout <<getName() <<  " : meow" <<endl;
        else
                cout <<getName () << "purr" <<endl;
  }
private:
    int m_length;
};

void chorus(Pet* pets[], int n, bool loud)
{
   for (int i = 0; i < n; i++)
      pets[i]->speak(loud);

   cout << endl;
}

int main()
{
   const int NPETS = 3;
   Pet* pets[NPETS];

   pets[0] = new Fish("Nemo");
   pets[1] = new Bird("Tweety");
   pets[2] = new Snake(4, "Kaa");  // length in meters
   for (int i = 0; i < NPETS; i++)
      cout << pets[i]->getName() << " ";
 
   cout << endl;

   chorus(pets, NPETS, false);
   chorus(pets, NPETS, true );
   chorus(pets, NPETS, false);
   chorus(pets, NPETS, true );
   chorus(pets, NPETS, true );

   for (int i = 0; i < NPETS; i++)
    delete pets[i];

}
