#include <cmath>
#include <iostream>

using namespace std;
int main()
{
    int t=10000000;
    double sqr;
    double hmm = 1.4e100;
    while(t--)
    {   hmm++;
        sqr = sqrt(hmm);
    }
    cout << sqr;
}

