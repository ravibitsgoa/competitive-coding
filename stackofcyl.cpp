#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    long long int n1, sum1=0;
    long long int n2, sum2=0;
    long long int n3, sum3=0;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
       sum1+=h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
        sum2+=h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
        sum3+=h3[h3_i];
    }
    cout<<sum1<<endl<<sum2<<endl<<sum3<<endl;
    for(int i=0, j=0, k=0; i<n1 && j<n2 && k<n3; )
    {   if(sum1==sum2 && sum2==sum3)
            break;
        if(sum1>=sum2 && sum1>=sum3)
        {   sum1-=h1[i];
            i++;
            cout<<'a';
        }
        if(sum2>=sum1 && sum2>=sum3)
        {   sum2-=h2[j];
            j++;
            cout<<'b';
        }
        if(sum3>=sum2 && sum3>=sum1)
        {   sum3-=h3[k];
            k++;
            cout<<'c';
        }
    }
    if(sum1==sum2 && sum2==sum3)
        cout<<sum1;
    else
        cout<<0;
    return 0;
}

