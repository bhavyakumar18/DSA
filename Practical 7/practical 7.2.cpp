#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    int choice,patient;

    while(true)
    {
        cout<<"\n1. Patient Arrive\n2. Attend Patient\n3. Display Front\n4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter patient number: ";
            cin>>patient;

            q.push(patient);
            cout<<"Patient added successfully\n";
        }
        else if(choice==2)
        {
            if(q.empty())
            {
                cout<<"Error: No patients waiting\n";
            }
            else
            {
                cout<<"Attended patient: "<<q.front()<<"\n";
                q.pop();
            }
        }
        else if(choice==3)
        {
            if(q.empty())
                cout<<"Queue is empty\n";
            else
                cout<<"Front patient: "<<q.front()<<"\n";
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
