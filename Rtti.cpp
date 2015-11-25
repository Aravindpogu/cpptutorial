#include<iostream>
#include <vector>
#include <cstdlib>
#include <typeinfo>
#include <ctime>
using namespace std;

class File
{
public:
  virtual void open(const std::string& filename) = 0;
  virtual void close() = 0;
  virtual ~File() {}
};
 
class MediaFile : public File
{
public:
  virtual void open(const std::string& filename) {cout<<"Playing " <<endl;}
  virtual void close() {cout<<"Closing" <<endl;}
};
 
class TextFile : public File
{
public:
  virtual void open(const std::string& filename) {cout<< "Opening "<< endl;}
  virtual void close() {cout << "Closing " <<endl;}
};


File* randomFile()
{
    switch (rand() % 2) {
        case 0:
            return new MediaFile();
        case 1:
            return new TextFile();
    }
    return nullptr;
}
 
vector<File*> randomFiles(int num)
{
    vector<File*> v;
    for (int i = 0; i < num; ++i) {
        v.push_back(randomFile());
    }
    return v;
}
 
vector<MediaFile*> getFile(const vector<File*>& all)
{
    vector<MediaFile*> v;
    for (int i = 0; i < all.size(); ++i) {
        MediaFile* r = dynamic_cast<MediaFile*>(all[i]);
        if (r != nullptr) {
            v.push_back(r);
        }
    }
    return v;
}

string getMenuName(const File* file)
{  
  if(dynamic_cast<const MediaFile*>(file)){
	return "--> play" ;
  }else{
	return " --> open" ;
  }
  // if file is of type MediaFile then return "--> play"  
  // else return "--> open"
}

int main()
{
  vector<File*> all = randomFiles(16);
   for (int i = 0; i < all.size(); ++i) {
	 cout << typeid(*(all[i])).name() << getMenuName(all[i]) << endl;
   }
  // loop over the Files
    // print out the actual type of the file
    // print out the result of getMenuName
 
  // loop over the Files and call delete on them

   for (int i = 0; i < all.size(); ++i) {
        delete all[i];
    }
}
