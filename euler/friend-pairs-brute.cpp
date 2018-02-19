#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    //sort(arr, arr+n);
    int count = 0;
    for(int i=0; i<n; i++)
    {   for(int j=0; j<n; j++)
        {   if(arr[i] % arr[j] == k)
            {   //cout<< i <<' '<<j<<endl;
                count++;
            }
        }
    }
    cout << count;
}
