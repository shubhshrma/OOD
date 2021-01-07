/*
Interface segregation principle - make segregated interfaces instead of heavy ones because then the subclasses don't need to implement all functions and can extend only the behaviour they need.
*/
#include <bits/stdc++.h>
using namespace std;

class IPrinter{
public:
  virtual void print(){}
};
class IScanner{
public:
  virtual void scan(){}
};
class IFaxMachine{
public:
  virtual void fax(){}
};

class Printer: public IPrinter{
public:
  void print() override{
    cout<<"printing\n";
  }
};

class PrinterScanner: public IPrinter, public IScanner{
public:
  void print() override{
    cout<<"printing\n";
  }
  void scan() override{
    cout<<"scanning\n";
  }
};
int main() {
  Printer p;
  p.print();

  PrinterScanner ps;
  ps.print();
  ps.scan();
}
