#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int factorial(int n)     // function to calculate (2n)!
{
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}
int main()
{
  double sum ,f,x = 0.94247779,error= 0; //x = 0.3*π = 0.3*3.1415926535


      for(int i=0;i<10;i++)
        {
          int fact = factorial(i*2);   // (2n)! factorial
          f = (pow(-1,i))*(pow(x,2*i))/(fact);

          sum += f;
          error = sum - error;
          error=fabs(error)*100/sum;
          cout<<"Term no. : "<<i+1<<setprecision(8)<<" Value : "<<sum<<" Error : "<<error<<endl;

          if(error<0.0000005) break;
          error = sum;

        }
return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
  float val,f1,error1,f2,error2;

  val = pow(3.14159265,4)/90;
  cout<<"Increment"<<endl<<endl;
  for(int i=1;i<10000;i++)
  {
    f1 = f1 + 1/pow(i,4);
    error1 = (fabs(val-f1)*100)/val;
    if(i<=15) cout<<" Term No. : "<<i<<" Value : "<<f1<<" Error : "<<error1<<endl;
  }
  cout<<endl<<"True Relative Error : "<<error1;
  cout<<endl<<endl<<"Decrement"<<endl<<endl;
  for(int j=10000;j>=1;j--)
  {
    f2 = f2 + 1/pow(j,4);
    error2 = (fabs(val-f2)*100)/val;
    if((j<=15)&&(j>=1)) cout<<" Term No. : "<<j<<" Value : "<<f2<<" Error : "<<error2<<endl;
  }
  cout<<endl<<"True Relative Error : "<<error2;
  return 0;
}
