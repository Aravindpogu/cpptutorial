#include<iostream>
using namespace std;

class RefCounted
{
    int count;
    RefCounted(const RefCounted&);
    RefCounted& operator=(const RefCounted&);
public:
    static RefCounted* newRefCounted() { return new RefCounted(); }
    void AddRef() { ++count; }
    void DelRef() { if (--count == 0) { delete this; } }
    RefCounted() : count(0) {}
    ~RefCounted() { std::cout << "RefCounted deleted" << std::endl; }
};
 
template<typename T>
class SmartPtr
{
    T* p_;
public:
    SmartPtr(T* p) : p_(p) {}
    ~SmartPtr() { delete p_; }
    void AddRefSmrtPtr() { (p_.count)++; }
    void DelRefSmrtPtr() { if (--(p_.count) == 0) { delete this; } }
};


int main()
{
  RefCounted* rp = RefCounted::newRefCounted();
 
  rp->AddRef();
 
  // rp may be inserted into a container, passed to a call back, etc ...
  // each of these operations calling AddRef and DelRef if needed
  rp->DelRef();

  //SmartPtr<RefCounted> sp = new SmartPtr(RefCounted::newRefCounted());
 
  //sp.ddRefSmrtPtr();
  //sp.DelRefSmrtPtr();
 
}
