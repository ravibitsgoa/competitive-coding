#include<bits/stdc++.h>
using namespace std;

// Utiltity function to find the divisors of
// n and store in vector v[]
vector<int> findDivisors(int n)
{
    vector<int> v;

    // Vector is used to store  the divisors
    for (int i = 1; i<= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If n is a square number, push
            // only one occurrence
            if (n/i == i)
                v.push_back(i);
            else
            {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    return v;
}

// Function to find pairs such that (a%b = k)
bool printPairs(int arr[], int n, int k)
{
    // Store all the elements in the map
    // to use map as hash for finding elements
    // in O(1) time.
    unordered_map<int, int> occ;
    for (int i = 0; i < n; i++)
        occ[arr[i]]++;

    int count =0;
    for (int i = 0; i<n ; i++ )
    {
        // Print all the pairs with (a, b) as
        // (k, numbers greater than k) as
        // k % (num (> k)) = k i.e. 2%4 = 2
        if (occ[k] && k < arr[i])
        {
            cout << "hi";
            count+= occ[k];
            //cout << "(" << k << ", " << arr[i] << ") ";
            //isPairFound = true;
        }

        // Now check for the current element as 'a'
        // how many b exists such that a%b = k
        if (arr[i] > k)
        {
            // find all the divisors of (arr[i]-k)
            vector<int> v = findDivisors(arr[i]-k);

            // Check for each divisor i.e. arr[i] % b = k
            // or not, if yes then print that pair.
            for (int j = 0; j < v.size(); j++)
            {
                if (arr[i]%v[j] == k &&
                    //arr[i]!= v[j] &&
                    occ[v[j]])
                {
                    count+= occ[v[j]];
                }
            }

            // Clear vector
            v.clear();
        }
    }
    cout << count;
    return true;
}

// Driver program
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    if (printPairs(arr, n, k) == false)
        cout << "No such pair exists";
    return 0;
}
