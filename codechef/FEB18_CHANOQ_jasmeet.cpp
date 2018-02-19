//suboptimal
#include<iostream>
#include<bitset>
#include<vector>
#include<cstring>
#define MAX 100004
using namespace std;
 
bitset <MAX> matrix[MAX];
bitset <MAX> result;
 
 
int main() {
 
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
      
        for(int i = 0; i< n;i++){
            int l,r;
            cin>>l>>r;
            matrix[l][i]=1;
            matrix[r+1][i]=1;
        }
        for (int i=1; i<=n+1; i++)
        {
            matrix[i]=(matrix[i] ^ matrix[i-1]);
        }
        int q;
        cin>>q;
        
        while(q--){          
            int m;
//            result.reset();
            cin>>m;
            int x;
            for(int i = 0; i < m;i++){
                
                cin>>x;
                result = result ^ matrix[x];                               
            }
            
          
            int ans = result.count();
            result = result ^ result;
            
            cout<<ans<<endl;
           
        }
 
        for (int i=0; i<=n+1; i++)
        {
            matrix[i]=0;
        }
        
        //matrix.reset();
 
 
    }
	
	return 0;
} 
