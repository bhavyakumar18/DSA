#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    vector<stack<int>> shelf(10);
    int n,code,index;

    cout<<"Enter number of books: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter book code: ";
        cin>>code;

        index=code%10;
        shelf[index].push(code);

        cout<<"Book added to shelf "<<index<<"\n";
    }

    cout<<"\nFinal Shelf Contents:\n";

    for(int i=0;i<10;i++)
    {
        cout<<"Shelf "<<i<<": ";

        stack<int> temp=shelf[i];

        if(temp.empty())
        {
            cout<<"Empty";
        }
        else
        {
            while(!temp.empty())
            {
                cout<<temp.top()<<" ";
                temp.pop();
            }
        }

        cout<<"\n";
    }

    return 0;
}
