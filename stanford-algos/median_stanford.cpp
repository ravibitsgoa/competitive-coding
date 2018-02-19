#include<iostream>
#define SIZE 10000
using namespace std;

void swap(int &x, int &y)
{ int temp=y;
  y=x;
  x=temp;
}

int main()
{ int chhota[SIZE]={0}, bada[SIZE]={0}, ic=2, ib=2;
  int x;
  int ans=0;
  cin>>chhota[1]; ans+=chhota[1]; cout<<ans<<' ';
  cin>>bada[1];
  if(chhota[1]>bada[1])
    swap(chhota[1], bada[1]);
  ans+=chhota[1];
  cout<<chhota[1]<<endl;
  ans%=10000;
  for(int i=3; i<=SIZE; i++)
  { cin>>x;
    if(x>chhota[1])//If the element is bigger than the biggest of first i/2, we add it to the bada heap.
    { bada[ib]=x;
      int j=ib;
      while(j>1 && bada[j]<bada[j/2])//This is heap insertion operation.
      { swap(bada[j],bada[j/2]);
        j/=2;
      }
      ib++;
    }
    else//Else x belongs to the chhota heap. We add it there.
    { chhota[ic]=x;
      int j=ic;
      while(j>1 && chhota[j]>chhota[j/2])
      { swap(chhota[j],chhota[j/2]);
        j/=2;
      }
      ic++;
    }
    if(ib>ic+1)//If heaps are too much different in size, we remove excess element from bada heap.
    { int temp=bada[1];//Removing an extra element from the upperheap (bada), and storing it into temp.
      swap(bada[ib-1], bada[1]);//This adds the useless element to the end.
      ib--;
      int j=1;
      while((2*j +1)<=ib && bada[j]>(max(bada[2*j],bada[2*j +1])))//This is bubble-down of the top element of the bada heap.
      { //cout<<"HELLO";
        if(bada[2*j]<bada[2*j +1] || (2*j + 1)==ib)
        { swap(bada[j],bada[2*j]);
          //cout<<bada[j]<<bada[2*j]<<endl;
          j*=2;
        }
        else
        { swap(bada[j],bada[2*j+1]);
          //cout<<bada[j]<<bada[2*j+1]<<endl;
          j= 2*j + 1;
        }
      }
      //for(j=1; j<ib; j++)
        //cout<<bada[j]<<endl;

      chhota[ic]=temp;//Adding that element to the end of chhota heap.
      j=ic;
      while(j>1 && chhota[j]>chhota[j/2])//bubble-up new element if necessary.
      { swap(chhota[j],chhota[j/2]);
        j/=2;
      }
      ic++;
    }
    if(ic>=ib)//If the chhota heap is bigger or equal, it has the median.
    { ans=(ans + chhota[1])%10000;
      //cout<<chhota[1]<<' ';
      //cout<<chhota[1]<<ic-1<<ib-1<<'c'<<endl;//These lines are for debugging.
    }
    else//Otherwise, the bada heap has the median.
    { ans=(ans + bada[1])%10000;
      //cout<<bada[1]<<' ';
    }
    //cout<<chhota[1]<<bada[1]<<ic-1<<ib-1<<endl;

  }
  cout<<endl<<ans<<endl;
return 0;
}
