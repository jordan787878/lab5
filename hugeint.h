#include <iostream>
using namespace std;
class HugeInt{

friend ostream & operator<< (ostream &,const HugeInt &);
friend void operator>> (istream &i,HugeInt &);

public:
  HugeInt();
  HugeInt(int);
  HugeInt(string);
  void operator= (const HugeInt &);
  HugeInt operator+(const HugeInt &);
  HugeInt operator-(const HugeInt &);

private:  
  int hugenumber[300];
  int  sitnumber;
};
