// A C program to match wild card characters
#include <cstdio>
#include <cstdbool>
#include <iostream>
using namespace std;
// The main function that checks if two given strings
// match. The first string may contain wildcard characters
bool match(char *first, char * second)
{
    // If we reach at the end of both strings, we are done
    if (*first == '\0' && *second == '\0')
        return true;

    // Make sure that the characters after '*' are present
    // in second string. This function assumes that the first
    // string will not contain two consecutive '*'
    if (*first == '*' && *(first+1) != '*' && *(first+1)!='\0' && *second == '\0')
        return false;
    if (*second=='*' && *(second+1)!='*' && *(second+1)!='\0' && *first=='\0')
        return false;
    if(*first=='*' && *second=='*')
    { bool a=match(second+1, first+1) || match(second+1, first+2) ||match(second+1, first+3) ||match(second+1, first+4);
      bool b=match(second+2, first+1) || match(second+2, first+2) ||match(second+2, first+3) ||match(second+2, first+4);
      bool c= match(second+3, first+1) || match(second+3, first+2) ||match(second+3, first+3) ||match(second+3, first+4);
      return a||b||c|| match(second+4, first+1) || match(second+4, first+2) ||match(second+4, first+3) ||match(second+4, first+4);
    }
    // If the first string contains '?', or current characters
    // of both strings match
    if (*first == *second)
        return match(first+1, second+1);

    // If there is *, then there are two possibilities
    // a) We consider current character of second string
    // b) We ignore current character of second string.
    if (*second == '*')
        return match(second+1, first) || match(second+1, first+1) || match(second+1, first+2) ||match(second+1, first+3) ||match(second+1, first+4);
    if (*first == '*')
        return match(first+1, second) || match(first+1, second+1) || match(first+1, second+2) ||match(first+1, second+3) ||match(first+1, second+4);
    return false;
}

// A function to run test cases
void test(char *first, char *second)
{  match(first, second)? puts("TRUE"): puts("FALSE"); }

// Driver program to test above functions
int main()
{   int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    { //string x, y;
      char x[2100], y[2100];
      scanf("%s\n%s",x,y);
      //cin>>x>>y;
      cout<<"Case #"<<i<<": ";
      test(x,y);
    }
    //test("g*ks", "geeks"); // Yes
    //test("ge?ks*", "geeksforgeeks"); // Yes
    //test("g*k", "gee");  // No because 'k' is not in second
    //test("*pqrs", "pqrst"); // No because 't' is not in first
    //test("abc*bcd", "abcdhghgbcd"); // Yes
    //test("abc*c?d", "abcd"); // No because second must have 2
                             // instances of 'c'
    //test("*c*d", "abcd"); // Yes
    //test("*?c*d", "abcd"); // Yes
    return 0;
}
