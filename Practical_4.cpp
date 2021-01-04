#include <iostream>
#include <math.h>

using namespace std;
int main()
{
  int n=4;
  double x[n]={0.5,0.5,0.5,0.5},y[n],z[n],inv[n][2*n+1],mat[n][2*n+1];
  float Ca,Cb,Cc,Cd;

  for (int i=1 ; i<=5 ; i++)
  {           mat[0][0] = -3 - 0.6 * sqrt(x[0]);
              mat[0][1] = 0;
              mat[0][2] = 0.2 * x[2];
              mat[0][3] = 0;
              mat[0][4] = 0;
              mat[0][5] = 1;
              mat[0][6] = 0;
              mat[0][7] = 0;
              mat[0][8] = 0;

              mat[1][0] = 4;
              mat[1][1] = -1.6 * x[1] - 1;
              mat[1][2] = 0;
              mat[1][3] = 0;
              mat[1][4] = 0;
              mat[1][5] = 0;
              mat[1][6] = 1;
              mat[1][7] = 0;
              mat[1][8] = 0;

              mat[2][0] = 0.6 * sqrt(x[0]);
              mat[2][1] = 1.6 * x[1];
              mat[2][2] = -1 - 0.2 * x[2];
              mat[2][3] = 0;
              mat[2][4] = 0;
              mat[2][5] = 0;
              mat[2][6] = 0;
              mat[2][7] = 1;
              mat[2][8] = 0;

              mat[3][0] = 0;
              mat[3][1] = 1.6 * x[1];
              mat[3][2] = 0;
              mat[3][3] = -1;
              mat[3][4] = 0;
              mat[3][5] = 0;
              mat[3][6] = 0;
              mat[3][7] = 0;
              mat[3][8] = 1;

          Ca = (1-(3*x[0]) - (0.4*pow(x[0],1.5)) + (0.1*pow(x[2],2)));
          Cb = (4*x[0]) - (x[1]) - (0.8*pow(x[1],2));
          Cc = (-(x[2]) - (0.1*pow(x[2],2)) + (0.4*pow(x[0],1.5)) + (0.8*pow(x[1],2)));
          Cd = (-x[3]+(0.8*pow(x[1],2)));
          double f[] = {Ca,Cb,Cc,Cd};
          int k=0;
          cout<<endl;


          while(k<n)
              {
                  float t=mat[k][k];
                  int i=k;
                  while(i<2*n+1)
                  {
                        mat[k][i] = mat[k][i]/t;
                        i++;
                  }
                  int j=k+1;
                  while(j<n)
                  {
                       float z = mat[j][k];
                       int l=0;
                       while(l<2*n+1)
                            {
                                  mat[j][l] = mat[j][l] - z*mat[k][l];
                                  l++;
                            }
                       j++;
                  }
                  int m=0;
                  while(m<k)
                  {
                       float z = mat[m][k];
                       int l=0;
                       while(l<2*n+1)
                            {
                                  mat[m][l] = mat[m][l] - z*mat[k][l];
                                  l++;
                            }
                       m++;
                  }
                  k++;
              }

          cout<<endl;
          cout <<"Iteration Number : "<<i<<endl;
              int m=0;
              while(m<n)
                  {
                  int j=n+1;
                  while(j<2*n+1)
                       {
                            inv[m][j-5]=mat[m][j];
                            j++;
                        }
                  m++;
                }
                int l = 0;
              while(l<n)
                  {
                      float sum = 0;
                      int j=0;
                      while(j<n)
                        {
                            sum = sum + inv[l][j]*f[j];
                            j++;
                        }
                        z[l] = sum;
                        l++;
                  }
              cout<<endl;
              int a=0;
              while(a<n)
                  {
                      y[a] = x[a]-z[a];
                      x[a]=y[a];

                      cout<<y[a]<<endl<<endl;
                      a++;
                  }
    }
    return 0;
}
