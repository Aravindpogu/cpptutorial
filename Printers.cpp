#include<iostream>
#include<string>

using namespace std;

class Printer
{
public:
  Printer(string name);
  Printer();
 ~Printer();

  void print(string file);

private:
  string m_name;
  int    m_jobId;
};


Printer::Printer(string name){
//	name = name;
}

Printer::Printer(){
	//this.name = name;
}
Printer::~Printer(){
	cout << "destructing .." << endl;
}
void Printer::print(string file){
	cout << "Printing file " << file << endl;
}

Printer* ports[3];


void connect(int n, string name)
{
  // call operator new to dynamically create a printer and
  // store the pointer at position n in ports[].
  ports[n] = new Printer(name);
}

void disconnect(int n)
{
  // delete the printer at port n and set the port to null.
  delete ports[n];
  ports[n] = NULL;
}

int main()
{
  char command;

  do
  {
    cout << "\n? ";

    cin >> command;

    switch (command)
    {
      case 'c':
      {
        int n;
        string name;
        cin >> n >> name;

        // if port n is not in use (i.e. is null), call connect, else print error message
        if(ports[n] == NULL){
		connect(n, name);
	}else{
		cout<< "error : port " << n << " is already in use on " << name << endl; 
	}
      }
      case 'd':
      {
        int n;

        cin >> n;

        // if port n is in use, call disconnect, else print error message
        
        if(ports[n] != NULL){
		disconnect(n);
	}else{
		cout<< "error : port " << n << " is not connected " << endl; 
	}
      }
      case 'p':
      {
        int n;
        string file;

        cin >> n >> file;

        // if port n is connected, call print() on that printer, else print error message
        if(ports[n] != NULL){
		ports[n]->print(file);
	}else{
		cout<< "error : port " << n << " is not connected " << endl; 
	}
      }
    }
  }
  while (command != 'x');
}
