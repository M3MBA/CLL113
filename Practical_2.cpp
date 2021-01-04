#include<iostream>
#include<conio.h>
#include <fstream>
using namespace std;

int main()
{
    cout << "Enter the number of variables in the equations: ";
    int n;
     cin >> n;
    float mat[n][n],b,x[10];
    float a[10][10];
     for (int i = 1; i <= n; i++)
   {
        for (int j = 1; j <= n+1; j++)
        {
             cout << "Matrix[" << i << ", " << j << " ]=";    // Values in the Matrix are filled here
             cin >> mat[i][j];
      }
    }
      cout<<endl<<"Matrix obtained :"<<endl;
      for (int i = 1; i <= n; i++)
       {
         for (int j = 1; j <= n+1; j++)
           {                                           // initial matrix formed
              cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
         }

        for(int j=1; j<=n; j++)
         {
           for(int i=1; i<=n; i++)
            {
              if(i!=j)
               {
                 b=a[i][j]/a[j][j];                   //Using Gauss elimination
                 for(int k=1; k<=n+1; k++)
                 {
                    mat[i][k]=mat[i][k]-b*mat[j][k];
                 }
              }
           }
        }

        ofstream outfile;
        outfile.open("output1.txt");
        if(outfile.is_open())
        {
        for(int i=1; i<=n; i++)
        {
           x[i]=mat[i][n+1]/mat[i][i];
           outfile<<"x"<<i << "="<<x[i]<<" ";          //Printing the value of x1,x2,x3 .......
        }
      }

    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
#include <bits/stdc++.h>
#include<fstream>
void printMatrix(float a[][10], int n)
{
    int i = 0;
    ofstream outfile;
    outfile.open("output2.txt");
    if(outfile.is_open())
    {
      outfile<<"Augumented Matrix is :"<<endl;
      while(i<n)
      {
          int j = 0;
          while(j<=n)
          {
              outfile<<a[i][j]<<" ";
              j++;
          }
          outfile<<endl;
          i++;
      }
  }

}
// Driver code
int main()
{
    int n = 10;
    int r = 3;
    int c = 4;
    float a[10][10];
    cout<<"Enter the values of the matrix"<<endl;

    int row = 0;
    while(row<r)
    {
        int col = 0;
        while(col<c)
        {
            cin>>a[row][col];
            col++;
        }
        row++;
    }
    // Order of Matrix(n)
    n = 3;
    int flag = 0;

    // Performing Matrix transformation
    //flag = PerformOperation(a, n);

    //perform
    int i = 0;
    int k = 0;
    flag = 0;
    while(i <n)
    {
        if (a[i][i] == 0)
        {
            c = 1;
            while ((i + c) < n && a[i + c][i] == 0)
                c++;
            if ((i + c) == n) {
                flag = 1;
                break;
            }
            int y = i;
            int z = 0;
            while(z<=n)
            {
                swap(a[y][z], a[y+c][z]);

                z++;
            }

        }

        for (int j = 0; j < n; j++) {

            // Excluding all i == j
            float res;
            if (i != j)
            {

                // Converting Matrix to reduced row
                // echelon form(diagonal matrix)
                res = a[j][i] / a[i][i];


                int x = 0;
                while(x<=n)
                {
                    a[j][x] = a[j][x] - (a[i][x] * res);
                    x++;
                }

            }
        }
        i++;
    }


    if(flag == 1)
    {
        float sum;
        int i = 0;
        while(i<n)
        {
            sum = 0;
            int j  = 0;
            while(j<n)
            {
                sum+=a[i][j];
                j++;
            }
            if (sum == a[i][j])
            {
                flag = 2;
            }
            i++;


        }



    }



    // Printing Final Matrix
    cout << "Final Augumented Matrix is : " << endl;
    printMatrix(a, n);
    cout << endl;

    // Printing Solutions(if exist)

    cout<<"The result is: ";
    switch(flag)
    {
        case 2: cout << "Infinite Solutions Exists" << endl;
            break;
        case 3: cout << "No Solution Exists" << endl;
            break;

        default: int t = 0;
        ofstream outfile;
        outfile.open("output3.txt");
        if(outfile.is_open())
        {
          outfile<<"The value of x1,x2,x3 are as follows :"<<endl;

                while(t<n)
                {
                     outfile<< a[t][n] / a[t][t] << " ";
                    t++;
                }
                break;
}
    }
    //PrintResult(a, n, flag);
    return 0;
}
