#include<iostream>
using namespace std;

int main()
{
    int table[10];
    int n,id,index;

    for(int i=0;i<10;i++)
        table[i]=-1;

    cout<<"Enter number of vehicles: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter vehicle registration number: ";
        cin>>id;

        index=id%10;
        int start=index;

        while(table[index]!=-1)
        {
            index=(index+1)%10;

            if(index==start)
            {
                cout<<"Parking lot is full\n";
                break;
            }
        }

        if(table[index]==-1)
        {
            table[index]=id;
            cout<<"Vehicle parked at slot "<<index<<"\n";
        }
    }

    cout<<"\nFinal Parking Slots:\n";

    for(int i=0;i<10;i++)
    {
        if(table[i]==-1)
            cout<<i<<" : Empty\n";
        else
            cout<<i<<" : "<<table[i]<<"\n";
    }

    return 0;
}
