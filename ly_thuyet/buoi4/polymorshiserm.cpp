#include <iostream>
using namespace std;

// encapsulation
//adstraction = truu tuong
//polymorphism = da hinh
// inheritance kế thừa
//+ public: public, protected->public, protect
//+ protect: public, protected->protected, protected
//+ private: public, protected->privated, private

//chủ  nhật dạy doubly linked list
//complexity
//sort

class people
{
public:
  string name;
  // private:
  string job;
  // protected:
  void printN()
  {
    cout << "name";
  }
};

class student : protected people
{
public:
  string className;
  // gọi đc
  void printN()
  {
    // printN();
    cout << "123";
  }
};

int main()
{
  people A;
  student B;
  A.printN();
  B.printN();
  return 0;
}