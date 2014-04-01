#ifndef UNLIMITED_INT_CPP
#define UNLIMITED_INT_CPP
#include "unlimitedInt.h"

//constructor, initialize with a deque (used in operators)
unlimitedInt::unlimitedInt(deque <unsigned short> a){	

  dequeInt = a;      
}

//class constructor, overloading the initiallization at 1
unlimitedInt::unlimitedInt(unsigned short initializer /*= 1*/){	
  
  dequeInt = intToDeque(initializer);
}

//return the size of the integer (number of digits)
const unsigned int unlimitedInt::sizeUnlimitedInt() const {

  return dequeInt.size();
} 

//function that returns the sum of the digits of the unlimitedInt
const int unlimitedInt::getSum() const {
  
  int sum = 0;
  for (int i = 0; i<sizeUnlimitedInt(); i++){
    sum = sum + dequeInt[i];
  }
  return sum;
}

unlimitedInt& unlimitedInt::operator = (const unsigned short& a)  {
      
  this->dequeInt.clear();
  this->dequeInt =  intToDeque(a);
  return *this;
}

//helper function for the operator <<
ostream& unlimitedInt::tostream (ostream& os) const { 

  for (unsigned int i = 0; i < dequeInt.size(); i++){    
    os<< dequeInt[i];	
  }
return os;
}

ostream& operator<<( ostream& os, unlimitedInt other){
   
  return other.tostream(os);
}

//function that returns a deque output from an integer, each digit per position
deque <unsigned short> intToDeque(const short& a){
    
  assert(a>=0 && "ERROR: INPUT CANNOT BE A NEGATIVE NUMBER");	//check if input is negative number
  deque <unsigned short> returnDeque;
  string stringInt = to_string(a);  
  
  if ( stringInt.size() == 1){
  
    returnDeque.push_back(a);
  }
  else {			// if integer input is bigger than 9, string size >1, then iterate each digit seperatelly
    unsigned short z ;
    for(int i = 0; i< stringInt.size(); i++){
      
      z = stringInt[i] - '0';	//make it into int type (could use static_cast)
      returnDeque.push_back(z);	
    }
  }
  
  return returnDeque;
}

//addittion function for deques return the sum. Use of scaled addittion elementary school style.
deque<unsigned short> sumDeque(const deque <unsigned short> &a, const deque <unsigned short> &b){ 
  
  int i = 0, j = 0;	
  int k = a.size();
  if( a.size() < b.size()){k = b.size();}
  
  int decade = 0;
  int value = 0;
  
  deque <unsigned short> returnDeque(k);	//
  
  for ( i = b.size() - 1, j = a.size() - 1, k  = k - 1 ; i>=0 || j>= 0 ; i--, j--, k--){// use a separate counter for each one, k equals counter of the bigger. 
    
    value = 0;
    value = value + decade;
    if( i >= 0 ) { value = value + b[i];}	//if any counter is negative, there is no position and nothing to add to final deque
    if( j >= 0 ) { value = value + a[j];}
    if (value < 10) {		// value can range from 0+0 to 9+9 = 18

      returnDeque[k] = value;
      decade = 0;
    }
    else {

      returnDeque[k] = value - 10;
      decade = 1;
    }
  }
  if (decade == 1) {returnDeque.push_front(1); decade = 0;} //add the last decade on the deque if left over
  
  return returnDeque;
} //end sumDeque
    

//multiply function for deques return the product. Use of scaled multiplication-addittion elementary school style
deque <unsigned short> multiplyDeques ( const deque <unsigned short> &a, const deque <unsigned short> &b){ 

  deque <unsigned short> resultDeque;
  resultDeque.push_back(0); 		//initialize 1 element, so that it is valid when used by the sumDeque
  deque <unsigned short> tempDeque;
  int zerosb = 0;
  int zerosa = 0;
  int product = 1;  
  
  for (int i = a.size() - 1 ; i >= 0; i--){ //itarate backwards on the deque, from the last digit, to the first
    
    for (int j = b.size() - 1; j >= 0; j--){

      tempDeque.clear();    
      product = a[i]*b[j];	//maximum multiplication 9*9
      
      if (product < 10 ){tempDeque.push_back(product);}
      else {tempDeque = intToDeque(product);}
	
      if(zerosb+zerosa>0){    
	for(int kk = 0; kk<zerosb+zerosa;kk++){
	  tempDeque.push_back(0);
	}
      }     
      resultDeque = sumDeque(resultDeque,tempDeque);      
      zerosb++;
    }//end for b deque

    zerosb = 0;
    zerosa++;
    
  } //end for a deque   
  
  return resultDeque;
}

//implementation of the + operator
unlimitedInt operator + ( const unlimitedInt & a, const int& addVal)  {
      
  deque <unsigned short> adDeque = intToDeque(addVal);//turn the integer into a deque
  unlimitedInt b(sumDeque( a.dequeInt, adDeque)); 	//add deques 
  return b;
}

unlimitedInt operator + ( const unlimitedInt& c, const unlimitedInt & a) {
  
  unlimitedInt b(sumDeque( a.dequeInt, c.dequeInt)); //add deques 
  return b;
}

unlimitedInt operator + ( const int& addVal, const unlimitedInt & a) {
  
  deque <unsigned short> adDeque = intToDeque(addVal); //turn the integer into a deque
  unlimitedInt b(sumDeque( a.dequeInt, adDeque)); 	//add deques
  return b;
}

//implementation of the * operator
unlimitedInt operator * ( const unlimitedInt & a, const int& multiVal)  {
      
  deque <unsigned short> mDeque = intToDeque(multiVal); //turn the integer into a deque
  unlimitedInt b(multiplyDeques( a.dequeInt, mDeque)); 	//multiply deques
  return b;
}

unlimitedInt operator * (  const int& multiVal, const unlimitedInt & a)  {
      
  deque <unsigned short> mDeque = intToDeque(multiVal); //turn the integer into a deque
  unlimitedInt b(multiplyDeques( a.dequeInt, mDeque)); 	//multiply deques
  return b;
}

unlimitedInt operator * ( const unlimitedInt & a, const unlimitedInt & c)  {
      
  unlimitedInt b(multiplyDeques( a.dequeInt,c.dequeInt)); 	//multiply deques
  return b;
}


#endif