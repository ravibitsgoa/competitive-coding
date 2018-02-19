#include<iostream>
using namespace std;
int main()
{   int rows=5;//this program prints a square
    for(int i=0; i<rows; i++)
    {   for(int j=0; j<rows; j++)
        {   cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}
