#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
string smalls(string s)//convert capital word to small
{
    for (int i=0;i<s.length();i++)
    {
        if ('A'<=s[i] && s[i]<='Z'){
           s[i]=char(((int)s[i])+32);
        }
    }
    return s;
}
int filter(string l)
{
    bool b=(l=="show")||(l=="give")||(l=="me")||(l=="i")||(l=="want")||(l=="to")||(l=="know")||(l=="determine")||(l=="the")||(l=="a")||(l=="an");
    if(b){return 0;}
    else if(l=="not"){return 1;}
    else if(l=="and"){return 2;}
    else if(l=="or"){return 3;}
    else return 4;
}
int finds(string arr[6][5],string O)
{
    for(int i=1;i<6;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(O==arr[i][j]){return j;}
        }
    }
    return -1;
}
int main()
{
    string x[6][5];//data
    vector<int>out;
    vector<string>out2;
    x[0][0]="name";x[0][1]="gender";x[0][2]="age";x[0][3]="relationship";x[0][4]="city";//main address
    for(int i=1;i<6;i++)//data entry
    {
        for(int j=0;j<5;j++)
        {
            cin>>x[i][j];
        }
    }//to show the memory

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<x[i][j]<<"    ";
        }
        cout<<endl;
    }
    int an=0;
    int v=0,c=0;//number of words in line
    cin>>v;
    for(int i=0;i<v;i++)
    {
        string l,r;
        cin>>l;
        r=smalls(l);
        out2.push_back(r);
        int filt=filter(r);
        if(filt==4)
        {
            if(c==1)
            {
                filt=0;
                int chec=finds(x,r);
                if(out2.size()>2){
                if(out2.at(out2.size()-3)=="and")
                {
                    for(int i=0;i<out.size();i++)
                {
                    if(r==x[out.at(i)][chec]){out.erase(out.begin()+i);i--;}
                }
                    c=filt;
                    continue;
                }
                else if(out2.at(out2.size()-3)=="or")
                {
                    for(int i=1;i<6;i++)
                {
                    if(r==x[i][chec]){out.push_back(i);}
                }
                    c=filt;
                    continue;
                }
                }
                if(chec!=-1)
                {
                    for(int i=1;i<6;i++)
                    {
                        if(r!=x[i][chec]){out.push_back(i);}
                    }
                }
            }
            else if(c==2)
            {

                filt=0;
                int chec=finds(x,r);
                for(int i=0;i<out.size();i++)
                {
                    if(r!=x[out.at(i)][chec]){out.erase(out.begin()+i);i--;}
                }

            }
            else if(c==3)
            {
                filt=0;

                int chec=finds(x,r);

                for(int i=1;i<6;i++)
                {
                    if(r==x[i][chec]){out.push_back(i);}
                }
            }
            else
            {
                int chec=finds(x,r);
                if(chec!=-1)
                {
                    for(int i=1;i<6;i++)
                    {
                        if(r==x[i][chec]){out.push_back(i);}
                    }
                }

            }

        }
        c=filt;
    }if(out.size()!=0){
    for(int i=0;i<out.size();i++)
    {
        cout<<"you mean row"<<out.at(i);
        for(int j=0;j<out2.size();j++)
        {
            int p=finds(x,out2.at(j));
            if(out2.at(j)==x[out.at(i)][p])
            {
                cout<<" and col "<<p;
            }
            else if(j!=0)
            {
                if(out2.at(j-1)=="not")
                {
                    cout<<" and col "<<p;
                }
            }
        }
        cout<<endl;
    }
    }
    else
    {
        cout<<"null"<<endl;
    }
    return 0;
}
