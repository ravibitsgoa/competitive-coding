#include<iostream>

using namespace std;

const double EPS= 1e-10; //Any value in [-EPS, EPS] is considered approx 0.

double f(double x)      //Function of which we want to find a root (zero).
{   return (x*x - 3*x);
}

double fd(double x)     //Derivative of above function.
{   return (2*x - 3);
}

//This finds the root of function f by Newton's (sqrt) method.
//Parameters: x0: initial guess, iterations: index of this iteration.
double findZero(double guess, int &iterations)
{
    if(fd(guess)<EPS && fd(guess)>-EPS)   //If derivative of f becomes 0 at x0, we can't proceed further.
        return guess;

    double next_guess = guess - (f(guess)/fd(guess));   //This is Newton's method. x = x0 - f(x)/f'(x0)

    iterations++;
    if(f(next_guess)>EPS || f(next_guess)<-EPS)
        return findZero(next_guess, iterations);
    else
        return next_guess;
}

int main()
{   int iter=0;
    printf("%.10lf\n", findZero(1.75, iter) );
    cout<<"no of iterations "<<iter<<endl;
    return 0;
}
//This program can work in both ways: 1. finding roots until f(x) is near to 0,
//or 2. doing fixed no. of iterations.
