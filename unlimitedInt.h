#ifndef UNLIMITED_INT_H
#define UNLIMITED_INT_H

#include <iostream>
#include <string>
#include <deque>
#include <assert.h>

using namespace std;
  
class unlimitedInt{

private:

  deque <unsigned short> dequeInt;
   
  friend unlimitedInt operator + ( const unlimitedInt & a, const int& addVal);
  friend unlimitedInt operator + ( const int& addVal, const unlimitedInt & a);
  friend unlimitedInt operator + ( const unlimitedInt& c, const unlimitedInt & a);
  
  friend unlimitedInt operator * ( const unlimitedInt & a, const int& multiVal);
  friend unlimitedInt operator * ( const int& multiVal, const unlimitedInt & a);
  friend unlimitedInt operator * ( const unlimitedInt & a, const unlimitedInt & c);

public:
     
    unlimitedInt(deque <unsigned short> a);		//constructor, initialize with a deque (used in operators)
    unlimitedInt(unsigned short initializer = 1);	//class constructor, overloading the initiallization at 1
    const unsigned int sizeUnlimitedInt() const;	//return the size of the integer (number of digits) 
    const int getSum() const;				//function that returns the sum of the digits of the unlimitedInt   
    unlimitedInt& operator = (const unsigned short& a);	// overloading assignment operator
    ostream& tostream (ostream& os) const;		//helper function for the operator "<<"

};
//helper functions 
deque <unsigned short> intToDeque(const short& a);	//function that returns a deque output from an integer, each digit per position
deque<unsigned short> sumDeque(const deque <unsigned short> &a, const deque <unsigned short> &b); //addittion function for deques return the sum. Use of scaled addittion elementary school style.
deque <unsigned short> multiplyDeques ( const deque <unsigned short> &a, const deque <unsigned short> &b); //multiply function for deques return the product. Use of scaled multiplication-addittion elementary school style

#endif
