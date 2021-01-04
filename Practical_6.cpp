#include<iostream>
#include<math.h>
using namespace std;
int main()
{
		float v[100];
		int n = 1,k=0;
		v[0]=0;
		while(n<100)
	{
		v[n]=v[n-1]+0.1;
		n++;
	}
		cout<<"Interpolated values (0.1): "<<endl<<endl;
		while(k<=60)
		{
			float fun[8][8],a[8],b[8],x=1,sum=0;
			int i = 0,j = 1;
			a[0] = 0;
    	a[1] = 0.897598;
    	a[2] = 1.7952;
    	a[3] = 2.69279;
    	a[4] = 3.59039;
    	a[5] = 4.48799;
    	a[6] = 5.38559;
    	a[7] = 6.28319;

			fun[0][0] = 0;
			fun[0][1] = 0.781831482;
			fun[0][2] = 0.974927912;
			fun[0][3] = 0.433883739;
			fun[0][4] = -0.433883739;
			fun[0][5] = -0.974927912;
			fun[0][6] = -0.781831482;
			fun[0][7] = 0;
			while(i<8)
				{
					fun[0][i]= pow(fun[0][i],2);
					i++;
				}

				while(j<8)
				{
					int  n = 0 ;
					while(n<8-j)
				{
					fun[j][n]=(fun[j-1][n+1]-fun[j-1][n])/(a[n+j]-a[n]);
					n++;
				}
				j++;
			}
			int m=0;
			while(m<8)
		{
			b[m]=fun[m][0];
			m++;
		}
			sum=b[0];
			i = i/8;
			while(i<8)
		{
			x = x * (v[k]-(a[i-1]));
			sum = sum + x*b[i];
			i++;
		}
			cout<<sum<<endl<<endl;
			k++;
		}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<math.h>
using namespace std;

double lagrange(float a[],float b,int i)
{
    float z=1;
    int n=0;
    while(n<8)
  {
		if(n!=i)
    {
        z=z*(b-a[n])/(a[i]-a[n]);
    }
    n++;
  }
  return z;
}
int main()
{
	float v[100];
  int i=1,k=0;
	v[0]=0;
	while(i<100)
  {
		v[i]=v[i-1]+0.1;
    i++;
	}
	cout<<"Interpolated value of t ~ "<<endl;
  cout<<endl<<endl;
	while(k<=60)
  {

	float fun[1][8],a[8],b[8],sum=0;

	  a[0] = 0;
    a[1] = 0.897598;
    a[2] = 1.7952;
    a[3] = 2.69279;
    a[4] = 3.59039;
    a[5] = 4.48799;
    a[6] = 5.38559;
    a[7] = 6.28319;


	fun[0][0] = 0;
	fun[0][1] = 0.781831482;
	fun[0][2] = 0.974927912;
	fun[0][3] = 0.433883739;
	fun[0][4] = -0.433883739;
	fun[0][5] = -0.974927912;
	fun[0][6] = -0.781831482;
	fun[0][7] = 0;

	   int i=0;
     while(i<8)
     {
		    fun[0][i]= pow(fun[0][i],2);
        i++;
     }
     int j = 0;
     while(j<8)
     {
		    sum = sum +  lagrange(a,v[k],j)*fun[0][j];
        j++;
      }
	     cout<<sum<<endl<<endl;
       k++;
	   }
	return 0;
}
