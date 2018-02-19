#include<iostream>
#include<vector>
using namespace std;

vector<int> maxc(int p[], int low, int mid, int high)
{ int maxleft, leftsum=p[mid], sum=leftsum;
  for(int i=mid-1; i>=low; i++)
  { sum+=p[i];
    if(sum>leftsum)
    { leftsum=sum;
      maxleft=i;
    }
  }
  int maxright, rightsum=p[mid+1]; sum=rightsum;
  for(int i=mid+2; i<=high; i++)
  { sum+=p[i];
    if(sum>rightsum)
    { rightsum=sum;
      maxright=i;
    }
  }
  vector<int> b;
  b.push_back(maxleft);
  b.push_back(maxright);
  b.push_back(leftsum+rightsum);
  return b;
}
vector<int> maxsum(int p[], int low, int high)
{ if(high - low>1)
  { int mid=(low+high)/2;
    vector<int>left = maxsum(p, low, mid);
    vector<int>right= maxsum(p, mid+1, high);
    vector<int>cross= maxc(p, low, mid, high);
    if(left[2]>=right[2] && left[2]>=cross[2])
      return left;
    else if(left[2]<=right[2] && right[2]>=cross[2])
      return right;
    else
      return cross;
  }
  else
  { vector<int>a;
    a.push_back(low);a.push_back(high);a.push_back(p[low]);return a;
  } //base case
  cout<<'a';
}

int main()
{ //int A[]={13,–3,–25,20,–3,–16,–23,18,20,–7,12,–5,–22,15,–4,7};
  int A[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
  int ans=maxsum(A, 0, 15)[2];
  cout<<ans;
}
