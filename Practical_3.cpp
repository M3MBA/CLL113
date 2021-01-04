#include<iostream>
#include<array>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double a[n][n + 1], b[n], m[n], num[n];
    int k = 0;
    int i = 0;
    while (i < n)
    {
        cout << "\tEnter the Elemnts " << i + 1 << "\n";
        int j = 0;
        while (j <= n) {
            if (j < n) {
                cin >> a[i][j];
            }
            else {
                cin >> b[i];
            }
            j++;
        }
        i++;
    }
    cout << "initializing value of x\n";
    int p = 0;
    while (p < n) {
        cout << "x:[" << p << "]=";
        cin >> m[p];
        p++;
    }
    cout << "\nIteration number : ";
    int iter;
    cin >> iter;
    while (iter > 0) {

        for (int i = 0; i < n; i++) {
            num[i] = (b[i] / a[i][i]);
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                num[i] = num[i] - ((a[i][j] / a[i][i]) * m[j]);
                m[i] = 1.5 * num[i] - 0.5 * m[i];
            }
            cout << "x" << i + 1 << " = " << num[i] << endl;
        }
        cout << "\n";
        iter--;
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>
using namespace std;
int main()
{
  cout.setf(ios::fixed);
  ifstream read("input1.txt");
  if (!read)
    cout<<"File not found"<<"\n";

  else
  {
    int n;
    read>>n;
    cout<<"order of matrix: "<<n<<"\n";
    double a[n][n+1];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n+1; j++)
        read >> a[i][j];
      read.close();

    cout<<"Augmented matrix is: "<<"\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
          cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
        double x[n];                //store the values
        double accuracy,cal;
        for(int i=0;i<n;i++)
            x[i]=0;
            
        cout<<"\nEnter the error tollerence :  ";
        cin>>accuracy;
        double res;
        for(int i = 0;i<n;i++)                    //makeing the equations diagonally dominant
            for(int j = i+1;j<n;j++)
                if (abs(a[j][i])>abs(a[i][i]))
                    for(int k = 0;k<=n;k++)
                    {
                        res=a[i][k];
                        a[i][k]=a[j][k];
                        a[j][k]=res;
                    }
ofstream outfile;
outfile.open("output1.txt");
if(outfile.is_open())
{
        outfile<<"Gauss Sidel Method"<<endl<<endl<<"Iteration"<<setw(8);
        for(int i=1;i<=n;i++)
            outfile<<"x"<<i<<setw(18);
        outfile<<endl<<endl<<endl;
        int count = 0,check = 0;

        do                            //calculating x1,x2,x3...xn
        {

            outfile<<"\n"<<count+1<<"."<<setw(16);
            for (int i=0;i<n;i++)
            {
                cal=x[i];
                x[i]=a[i][n];
                for (int j=0;j<n;j++)
                {
                    if (j!=i)
                    x[i]=x[i]-a[i][j]*x[j];
                }
                x[i]=x[i]/a[i][i];
                if (abs(x[i]-cal)<=accuracy)            //checking the value with tollerence
                    check++;
                outfile<<x[i]<<setw(18);
            }
            count++;
        }while(check<n);

        cout<<endl<<endl;
        for (int i=0;i<n;i++)

            outfile<<endl<<"The value of x"<<i+1<<" = "<<x[i]<<endl;
    }
  }
    return 0;
  }
