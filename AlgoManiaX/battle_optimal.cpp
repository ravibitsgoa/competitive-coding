#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const long double EPS = 1e-14;
vector<long double> polynomial;
vector<long double> derivative;
long double f(long double x)      //Polynomial of which we want to find a root (zero).
{   long double x_pow_i =1, ans=0;
    for(int i=0; i<polynomial.size(); i++)
    {   ans+= polynomial[i]*x_pow_i;
        x_pow_i *= x;
    }
    return ans;
}

long double fd(long double x)     //Derivative of above polynomial.
{   long double x_pow_i =1, ans=0;
    for(int i=0; i<derivative.size(); i++)
    {   ans+= derivative[i]*x_pow_i;
        x_pow_i *= x;
    }
    return ans;
}

//This finds the root of function f by Newton's (sqrt) method.
//Parameters: x0: initial guess, iterations: index of this iteration.
long double findZero(long double guess, int iterations)
{
    //cout<<guess<<endl;
    if(fd(guess)<EPS && fd(guess)>-EPS)   //If derivative of f becomes 0 at x0, we can't proceed further.
        return guess;

    double next_guess = guess - (f(guess)/fd(guess));   //This is Newton's method. x = x0 - f(x)/f'(x0)
    iterations++;
    //if(iterations > 100)
        //return next_guess;
    if(f(next_guess)>EPS || f(next_guess)<-EPS)
        return findZero(next_guess, iterations);
    else
        return next_guess;
}

bool valid(long double x, int n)
{
    if(x> 1e18)
        return false;
    long double logx = log(x)/log(10.0);
    return (n < 4000/logx);
}

int main()
{
    int n;
    cin>>n;
    if(n<=1)
    {   cout<<"NO";
        return 0;
    }
    for(int i=0; i<n+1; i++)
    {
        double x;
        cin>>x;
        polynomial.push_back(x);
        if(i>0)
            derivative.push_back(i* polynomial[i]); //d/dx (x^n) = n*x^n-1
    }
    if(f(0)< 0)
    {   cout<<"NO";
        return 0;
    }
    //cout<<n<<endl;
    double first_root = findZero(0, 0);
    cout<<first_root;
    //return 0;
    if(first_root > EPS)//first root is > 0.
    {
        long double start =-1;
        long double second = findZero(start, 0);
        while(second > EPS && valid(-start, n))
        {   start*=2;
            second = findZero(start, 0);
            //cout<<second<<endl;
            if(isnan(second))
                break;
        }
        cout<<second<<endl;
        cout<<start<<' '<<valid(-start, n)<<endl;
        if(second <0)
            cout<<"YES\n"<<first_root;
        else //if(!valid(-start, n) )
            cout<<"NO";
        //else
            //return 1;
    }
    else
    {
        //dividing p(x) by (x-first_root).
        vector<long double> q(n-1);
        double second= -1;
        while(second < 0 && polynomial.size()>1)
        {
            q.resize(polynomial.size()-1);
            q[polynomial.size()-2] = polynomial[polynomial.size()-1];
            for(int i=polynomial.size()-3; i>=0; i--)
                q[i] = polynomial[i+1]+ polynomial[i+2]*first_root;
            polynomial = q;
            //for(auto i : polynomial)
                //cout<<i<<' ';
            //return 0;
            if(polynomial.size() == 2)
            {   second = -q[0]/q[1];
                break;
            }
            second = findZero(0, 0);
            cout<<second<<endl;
        }
        if(second >0)
            cout<<"YES\n"<<second;
        else if(polynomial.size()<2)
            cout<<"NO";
        else
            return 1;
    }
    return 0;
}
