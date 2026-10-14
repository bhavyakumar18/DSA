#include<iostream>
using namespace std;

int main()
{
    int table[10];
    int n,id,index,step;

    for(int i=0;i<10;i++)
        table[i]=-1;

    cout<<"Enter number of student IDs: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter student ID: ";
        cin>>id;

        int h1=id%10;
        int h2=7-(id%7);
        int j=0;

        while(j<10)
        {
            index=(h1+j*h2)%10;

            if(table[index]==-1)
            {
                table[index]=id;
                cout<<"Student ID stored at slot "<<index<<"\n";
                break;
            }

            j++;
        }

        if(j==10)
            cout<<"Hash table is full or no slot is available\n";
    }

    cout<<"\nFinal Hash Table:\n";

    for(int i=0;i<10;i++)
    {
        if(table[i]==-1)
            cout<<i<<" : Empty\n";
        else
            cout<<i<<" : "<<table[i]<<"\n";
    }

    return 0;
}
