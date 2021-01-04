#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    for(int k=0 ; k<2 ; k++)
    {
        double b[4],c[4],x[4],r=0,s=0;
        b[1]=1;
        b[0]=1;
        for(int i=0 ;i<4 ;i++)
        {
          cout<<"a"<<i<<" = ";
          cin>>x[i];
          cout<<endl;
        }
        double delr,dels,errs = 1,errr = 1;
        while(max(errr,errs) > 0.00001 , max(b[1],b[0]) != 0)
        {
          b[3] = x[3];
          b[2] = x[2] + b[3] * r;
          b[1] = x[1] + b[2] * r + b[3] * s;
          b[0] = x[0] + b[1] * r + b[2] * s;
          c[3] = b[3];
          c[2] = b[2] + c[3] * r;
          c[1] = b[1] + c[2] * r + c[3] * s;
          c[0] = b[0] + c[1] * r + c[2] * s;
          dels = (-b[0] * c[2] + c[1] * b[1]) / (c[2] * c[2] - c[1] * c[3]);
          delr = (- b[1] - c[3] * dels) / c[2];
          errr = abs(delr * 100 / (r + delr));
          errs = abs(dels * 100 / (s + dels));
          cout<<"r ="<<r<<"  "<<"s = "<<s<<"  "<<"b0 = "<<b[0]<<"  "<<"b1 = "<<b[1]<<"  "<<"b2 = "<<b[2]<<"  "<<"b3 = "<<b[3]<<"  "<<"dels = "<<dels<<"  "<<"delr = "<<delr<<"  "<<"errr = "<<errr<<"  "<<"errs = "<<errs<<"  "<<endl;
          r = r + delr;
          s = s + dels;
        }
        double t;
        if(r * r + 4 * s>0)
          {
            t = sqrt(r * r + 4 * s);
            cout<<"x1 = "<<-b[2] / b[3]<<"  x2 = "<<(r + t) / 2<<"  x3 = "<<(r - t) / 2<<endl;
          }
        else
          {
            cout<<"x1 = "<<-b[2] / b[3]<<endl;
          }
      }
      return 0;
    }
