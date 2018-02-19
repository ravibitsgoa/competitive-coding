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
    int n;
    int k;
    cin >> n >> k;
    int rQ;
    int cQ;
    cin >> rQ >> cQ;
    
    int r[8]={1, 1, 1, rQ, rQ, rQ+cQ-n, rQ, rQ},c[8]={cQ-rQ+1, cQ, rQ+cQ-1, 1, n, n,cQ,};
    for(int i = 0; i < k; i++){
        int rObs;
        int cObs;
        cin >> rObs >> cObs;
        if(rObs==rQ && cObs!=cQ)
            
        // your code goes here
    }
    return 0;
}

