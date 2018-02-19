#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main()
{   map<int, int> rows, cols;
    int N, Q;
    scanf("%d %d",&N,&Q);
    while(Q--)
    {   string x;
        int num, value;
        cin>>x>>num>>value;
        if(x=="RowAdd")
            rows[num]+=value;
        else
            cols[num]+=value;
    }
    int rmaxv=0, cmaxv=0;
    for(map<int,int>::const_iterator i=rows.begin(); i!=rows.end(); i++)
    {   if(rmaxv < (i->second) )
            rmaxv= (i->second);
    }
    for(map<int,int>::const_iterator i=cols.begin(); i!=cols.end(); i++)
    {   if(cmaxv < (i->second) )
            cmaxv= (i->second);
    }
    cout<<rmaxv+cmaxv<<endl;
    return 0;
}
