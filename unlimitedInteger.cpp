
#include "unlimitedInt.cpp"

using namespace std;

int main()
{
  
  unlimitedInt a(156);
  cout<<"My int has size: "<<a.sizeUnlimitedInt()<<endl;
  cout<<a<<endl;
  
  unlimitedInt b;
  b = a+9999;
  cout<<b<<endl;
  
  cout<<a+2<<endl;
  cout<<2+a<<endl;  
  cout<<a+b<<endl;
  cout<<156+a+a+156<<endl;
  
  unlimitedInt c(0);
  
  cout<< a+c<<endl;
  
  cout<< a + 2.2 <<endl; 
  
  cout<<a*22<<endl;
  cout<<22*a<<endl;
  cout<<a*a<<endl;
  
  c = 12;
  cout<<c<<endl;
  c = a;
  cout<<c<<endl;
  
    //NOTE, assertions
//   int bbb = -3;
//   c = bbb;
//   unlimitedInt bbbb(-3);
  
  //factorial test
  unlimitedInt test(1);
  for (int i = 2; i<=10; i++){
    test = test*i;
  }
  cout<<test<<endl;
  cout<<"sum of digits = "<<test.getSum()<<endl;
  
  return 0;
}

