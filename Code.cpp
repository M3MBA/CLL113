#include <bits/stdc++.h>
using namespace std;

int main()

{
    double conversion,oil,residue,gas,Mp,Mr,Mo;
    cout<<"Enter Mp"<<endl;
    cin>>Mp;
    cout<<"Enter Mr"<<endl;
    cin>>Mr;
    cout<<"Enter Mo"<<endl;
    cin>>Mo;
    //"{Conversion (wt.%) }"
    conversion=((Mp-Mr)/Mp)*100;
    cout<<"{Conversion (wt.%)="<<conversion<<endl;
    //Liquid Yield:
    //Oil (wt.% )
    oil=(Mo/Mp)*100;
    cout<<"Oil (wt.% )="<<oil<<endl;
    //Residue (Char) Yield:
    //Residue (wt.%)
    residue=(Mr/Mp)*100;
    cout<<"Residue (wt.% )="<<residue<<endl;
    //Gas Yield:
    //Gas (wt.%)
    gas=100-oil-residue;
    cout<<"Gas (wt.%)="<<gas<<endl;
    //The resulting fuel product is specifically based on density(ρ60◦C ), Specific Weight(Sg) and API
    double APIgravity,DH2O,Dsub,Specificgravity;
    cout<<"ρH2O"<<endl;
    cin>>DH2O;
    cout<<"ρsub"<<endl;
    cin>>Dsub;
    Specificgravity=Dsub/DH2O;
    APIgravity=(141.5/Specificgravity)-131.5;
    cout<<"APIgravity= "<<APIgravity<<endl;
}
