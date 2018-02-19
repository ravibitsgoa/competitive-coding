#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int T=1; T<=t; T++)
    {   int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        int worst_pivot = 1, minel=1, maxel=n;
        while(arr.size()>1)
        {   int temp =(arr.size()-1)/2;
            //cout<<arr[temp]<<endl;
            if(arr[temp] == minel)
            {   minel++;
                arr.erase(arr.begin() + temp);
            }
            else if( arr[temp] == maxel)
            {   maxel--;
                arr.erase(arr.begin() + temp);
            }
            else
            {   worst_pivot =0;
                break;
            }
        }
        if(worst_pivot)
            cout<<"Case #"<<T<<": YES"<<'\n';
        else
            cout<<"Case #"<<T<<": NO"<<'\n';
    }
    return 0;
}
