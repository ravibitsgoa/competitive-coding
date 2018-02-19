#include<iostream>
using namespace std;
void swap(int &x, int &y)
{ int temp=y;
  y=x;
  x=temp;
}
int main()
{ int size=10, heap[size+1]={0};//This is a max heap.
  for(int i=1; i<=size; i++)
  { int x;
    cin>>x;
    heap[i]=x;
    int j=i;
    while(j>1 && heap[j]>=heap[j/2])
    { swap(heap[j],heap[j/2]);
      j/=2;
    }
  }//This was the insertion function.
  for(int i=1; i<=size; i++)
    cout<<heap[i]<<endl;
  //now, extract min function.
  cout<<"->"<<heap[1];
  swap(heap[size], heap[1]);
  size--;
  int j=1;
  while((2*j + 1)<=size && heap[j]<(max(heap[2*j],heap[2*j +1])))
  { if(heap[2*j]>heap[2*j +1])
    { swap(heap[j],heap[2*j]);
      j*=2;
    }
    else
    { swap(heap[j],heap[2*j+1]);
      j= 2*j + 1;
    }
  }
  cout<<endl<<"->"<<heap[1]<<endl;
  swap(heap[size], heap[1]);
  size--;
  j=1;
  while((2*j + 1)<=size && heap[j]<(max(heap[2*j],heap[2*j +1])))
  { if(heap[2*j]>heap[2*j +1])
    { swap(heap[j],heap[2*j]);
      j*=2;
    }
    else
    { swap(heap[j],heap[2*j+1]);
      j= 2*j + 1;
    }
  }

  for(int i=1; i<=size; i++)
    cout<<heap[i]<<endl;

  return 0;
}
