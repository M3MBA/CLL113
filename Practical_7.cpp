#include<iostream>
#include<cmath>
using namespace std;

float fun(float m)
{
    return pow(m,0.1)*(1.2-m)*(1-exp(20*(m-1)));
}

float simpson_ruleonethird(float a,float b,int n){
    float h = (b-a)/n;
    float sum = fun(a)+fun(b);
    float value;
    float trueval = 0.602298;

    for(int i=1;i<=n-1;i++){
        if(i%2==0){
            sum += 2*fun(a+i*h);
        }else{
            sum += 4*fun(a+i*h);
        }
    }
    value = (h/3)*(sum);

    return value;

}

float simpson_rulethreeeight(float n)
{
    float m0 = 0;
    float m1 = m0 + 1/(3*n);
    float m2 = m1 + 1/(3*n);
    float m3 = m2 + 1/(3*n);
    float sum = 0;
    while(m3<=1)
    {
        sum += (1/n)*(fun(m0)+3*fun(m1)+3*fun(m2)+fun(m3))/8;
        m0 = m3;
        m1 = m0 + 1/(3*n);
        m2 = m1 + 1/(3*n);
        m3 = m2 + 1/(3*n);
    }
    return sum;
}

float Trapezoidal(int n,float b,float a)
{
    float trueval = 0.602298;
    float h = (b-a)/n;
    float sum = fun(a)+fun(b);
    for(int i=1;i<=n-1;i++)
    {
        sum = sum + 2*fun(a+i*h);

    }
    float value = (h/2)*sum;
    return value;
}



int main()
{

    float trueval = 0.602298;
    float m0=0;
    float m1=1;
    float seg[11] = {10,50,100,250,500,750,1000,1250,1500,1750,100};

    for(int i=0;i<=9;i++)
    {
        cout<<"Segment number : "<<seg[i]<<endl<<endl;
        cout<<"Integrating by Trapezoidal : "<<Trapezoidal(seg[i],m1,m0)<<endl;
        cout<<"error in Trapezoidal : "<<abs(trueval - Trapezoidal(m0,m1,seg[i]))<<endl<<endl;
        cout<<"Integrating by simpson 1/3th : "<<simpson_ruleonethird(m0,m1,seg[i])<<endl;
        cout<<"error in simpson 1/3rd : "<<abs(trueval - simpson_ruleonethird(m0,m1,seg[i]))<<endl<<endl;
        cout<<"Integrating by simpson 3/8th : "<<simpson_rulethreeeight(seg[i])<<endl;
        cout<<"error in simpson 3/8th : "<<abs(trueval - simpson_rulethreeeight(seg[i]))<<endl;
        cout<<"****************************************************************"<<endl;

    }
return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<math.h>
using namespace std;

float fun(float m){
    float w = 250*1000;
    float E = 200*pow(10,9);
    float I = 0.0003;
    float L = 3;
    return (w/(120*E*I*L))*(-5*pow(m,4)+6*pow(L,2)*pow(m,2)-pow(L,4));

}
float fundiff(float m){
    float w = 250*1000;
    float E = 200*pow(10,9);
    float I = 0.0003;
    float L = 3;
    return (w/(120*E*I*L))*(-20*pow(m,3)+20*pow(L,2)*pow(m,1));

}
float fundoublediff(float m){
    float w = 250*1000;
    float E = 200*pow(10,9);
    float I = 0.0003;
    float L = 3;
    return (w/(120*E*I*L))*(-60*pow(m,2)+20*pow(L,2));

}

float integrate(float a,float b,int n){
    float h = (b-a)/n;
    float sum = fun(a)+fun(b);
    float value;

    for(int i=1;i<=n-1;i++){
        if(i%2==0){
            sum += 2*fun(a+i*h);
        }else{
            sum += 4*fun(a+i*h);
        }
    }
    value = (h/3)*(sum);

    return value;

}




float differentiate(float m){
    float h = 0.125;
    float inc = -fun(m+2*h)+8*fun(m+h)-8*fun(m-h)+fun(m-2*h);
    float run = 12*h;
    float slope = inc/run;
    return slope;

}

float doubledifferentiate(float m){
    float h = 0.125;
    float inc = fun(m+h)-2*fun(m)+fun(m-h);
    float run = pow(h,2);
    float slope = inc/run;
    return slope;

}



int main(){
    float w = 250*1000;
    float E = 200*pow(10,9);
    float I = 0.0003;
    float L = 3;
    float n=24;
    float m0=0;
    float m_values[25]={0,0.125,0.25,0.375,0.5,0.625,0.75,0.875,1,1.125,1.25,1.375,1.5,1.625,1.75,1.875,2,2.125,2.25,2.375,2.5,2.625,2.75,2.875,3};



    for(int i=0;i<=n;i++){
        cout<<"X : "<<(m_values[i])<<endl;
        cout<<"DEFLECTION : "<<integrate(m0,m_values[i],n)<<" m"<<endl;
        cout<<"MOMENT : "<<(E*I*differentiate(m_values[i]))<<" Nm"<<endl;
        cout<<"SHEAR : "<<(E*I*doubledifferentiate(m_values[i]))<<" N"<<endl<<endl<<endl;

    };

}
