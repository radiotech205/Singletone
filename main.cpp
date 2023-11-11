#include <iostream>
//1.23
using namespace std;
class Singleton1
{
private:
    Singleton1() {cout << "Singleton1 created" << endl;}
    static Singleton1* singleton1;
public:
    static Singleton1* GetInstance()
    {
        if(singleton1 == nullptr)
            singleton1 = new Singleton1();
        return singleton1;
    }
};
Singleton1* Singleton1::singleton1 = nullptr;

class Singleton1a
{
private:
    Singleton1a(int val = 0) : value(val) {cout << "Singleton1a created" << endl;}
    int value;
    static Singleton1a* singleton1a;
public:
    static Singleton1a* GetInstance(int val = 0)
    {
        if(singleton1a == nullptr)
            singleton1a = new Singleton1a(val);
        return singleton1a;
    }
    void SetValue(int val) {this->value = val;}
    int GetValue() {return this->value;}
};
Singleton1a* Singleton1a::singleton1a = nullptr;
/******************************/
class Singleton2
{
public:
   static Singleton2* Instance() {
      static Singleton2 inst;
      return &inst;
   }
private:
  Singleton2() {
    cout << "Singleton 2 created" << endl;
  }
  ~Singleton2() {}
  Singleton2(const Singleton2&)= delete;                 // Prevent copy-construction
  Singleton2& operator=(const Singleton2&) = delete;     // Prevent assignment
};

int main()
{
    Singleton1* singleton1 = Singleton1::GetInstance();
    cout << singleton1 << endl;
    Singleton1* singleton1Clone = Singleton1::GetInstance();
    cout << singleton1Clone << endl;

    Singleton1a* singleton1a = Singleton1a::GetInstance();
    cout << singleton1a << ", value = " << singleton1a->GetValue() << endl;
    singleton1a->SetValue(13);
    Singleton1a* singleton1aClone = Singleton1a::GetInstance(666);
    cout << singleton1aClone << ", value = " << singleton1aClone->GetValue() << endl;
    /*************************/
    Singleton2* singleton2 = Singleton2::Instance();
    cout << singleton2 << endl;

    Singleton2* singleton2Clone = Singleton2::Instance();
    cout << singleton2Clone << endl;


    cout << "Hello World!" << endl;
    return 0;
}
