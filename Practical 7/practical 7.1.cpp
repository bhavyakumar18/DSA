#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter queue size: ";
    cin>>n;

    int q[n],front=-1,rear=-1;
    int choice,value;

    while(true)
    {
        cout<<"\n1. Join\n2. Serve\n3. Display Front\n4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter token number: ";
            cin>>value;

            if((rear+1)%n==front)
            {
                cout<<"Error: Queue is full\n";
            }
            else
            {
                if(front==-1)
                    front=0;

                rear=(rear+1)%n;
                q[rear]=value;
                cout<<"Token added successfully\n";
            }
        }
        else if(choice==2)
        {
            if(front==-1)
            {
                cout<<"Error: Queue is empty\n";
            }
            else
            {
                cout<<"Served token: "<<q[front]<<"\n";

                if(front==rear)
                {
                    front=rear=-1;
                }
                else
                {
                    front=(front+1)%n;
                }
            }
        }
        else if(choice==3)
        {
            if(front==-1)
                cout<<"Queue is empty\n";
            else
                cout<<"Front token: "<<q[front]<<"\n";
        }
        else if(choice==4)
        {
            break;
        }
        else
        {
            cout<<"Invalid choice\n";
        }
    }

    return 0;
}
