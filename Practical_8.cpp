#include <iostream>
#include<math.h>
using namespace std;
double func(double z)
{
    return 2*pow((1-z),(-1.25));
}
 int main()
{
    double x=0,b=0.9,n=1,da,a,sum=0,f=0,e=0,y,sum0=0;
    bool t;
    do
    {
        da=b/n;
        for(int i=1;i<n;i=i+2)
        {
            a=x+i*da;
            sum = sum+func(a);
        }
        for(int i=2;i<(n-1);i=i+2)
        {
            y=x+i*da;
            sum0=sum0+func(y);
        }
        f =(da/3)*(func(x)+func(b)+4*sum+2*sum0);
        e=abs(592.445178/pow(n,4));
        n=n+1;
        sum=0;
        sum0=0;
    }while(e>0.001);
     cout<<"integral :  "<< f<< endl;
     cout<<"simpson_1/3 :  "<< n-1<<endl<<endl;

     do
    {
        da=b/n;
        for(int i=1;i<n;i++)
        {
            a=x+i*da;
            sum=sum+func(a);
        }
        f =(da/2)*(func(x)+func(b)+2*sum);
        e=abs(15.44/pow(n,2));
        n=n+1;
        sum=0;
    }while(e>0.001);
     cout<<"integral :  "<< f<< endl;
     cout<<"trapezoidal :  "<< n-1<< endl<<endl;
     e=0;
     f=0;
     sum=0;
     sum0=0;
     n=1;
      do
    {
       da=b/n;
        for(int i=1;i<n;i=i+1)
        {
            if(i%3==0)
            {
                a=x+i*da;
                sum=sum+func(a);
            }
            else
            {
                y=x+i*da;
                sum0=sum0+func(y);
            }
        }

        f =(3*da/8)*(func(x)+func(b)+2*sum+3*sum0);
        e=abs(1333.0016505/pow(n,4));
        n=n+1;
        sum=0;
        sum0=0;
    }while(e>0.001);

     cout<<"integral :  "<< f<< endl;
     cout<<"simpson_3/8 :  "<< n-1<< endl<<endl;
     return 0;
}
