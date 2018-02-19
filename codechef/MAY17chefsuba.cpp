#include<deque>
#include<iostream>
using namespace std;
int main()
{ ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k, p;
  cin>>n>>k>>p;
  int A[n];
  for(int i=0; i<n; i++)
    cin>>A[i];
  int sums[n]={0};      //This stores sums of k numbers starting from ith position.
  for(int j=0; j<k && j<n; j++)
    sums[0]+=A[j];
  if(k>=n)
  { char c;
    while(p-- && cin>>c)
    { if(c=='?')
        cout<<sums[0]<<'\n';
    }
    return 0;
  }
  for(int i=1; i<n; i++)
    sums[i]=sums[i-1]+A[(i+k-1)%n]-A[i-1];

  int maxsum[n]={0};
  // A Dequeue (Double ended queue) based method for printing maixmum element of
// all subarrays of size k
  // Create a Double Ended Queue, Qi that will store indexes of array elements
  // The queue will store indexes of useful elements in every window and it will
  // maintain decreasing order of values from front to rear in Qi, i.e.,
  // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
  std::deque<int>  Qi(n);

  /* Process first n (or first window) elements of array */
  int i;
  for (i = 0; i <=n-k; ++i)
  {
    // For very element, the previous smaller elements are useless so
    // remove them from Qi
    while ( (!Qi.empty()) && sums[i] >= sums[Qi.back()])
      Qi.pop_back();  // Remove from rear
    // Add new element at rear of queue
    Qi.push_back(i);
  }

  int count=0;//the index of the element from which we're starting.
  // Process rest of the elements, i.e., from arr[k] to arr[n-1]
  for (i=1; i<n; ++i, count++)
  {
    // The element at the front of the queue is the largest element of
    // previous window, so add it to the maxsum array.
    maxsum[count]=sums[Qi.front()];
    // Remove the element which are out of this window
    while ( (!Qi.empty()) && (Qi.front() ==i-1) )
      Qi.pop_front();  // Remove from front of queue

    // Remove all elements smaller than the currently
    // being added element (remove useless elements)
    while ( (!Qi.empty()) && sums[(i+n-k)%n] >= sums[Qi.back()])
      Qi.pop_back();

    // Add current element at the rear of Qi
    Qi.push_back((i+n-k)%n);
  }
  // store the maximum element of last window
  maxsum[count]=sums[Qi.front()];
  int start=0;
  char c;
  for(int i=0; i<p; i++)
  { cin>>c;
    if(c=='!')
      start--;
    else if(c=='?')
    { cout<<maxsum[start]<<'\n';
    }
    if(start<0)
      start+=n;
  }

return 0;
}
/* Lesson learnt:
Never change your code without understanding it.
Never modify (pre-)calculation part in your code.
Modify output part if possible.
*/
