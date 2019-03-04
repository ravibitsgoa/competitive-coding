#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        long long int sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        //    if(mini > arr[i])
          //      mini = arr[i];
            sum += arr[i];
        }
        cout << (sum+1-n) << endl;
    }
    return 0;
}
