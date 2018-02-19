#include <iostream>
#include <vector>
using namespace std;

vector<string> nameVector={"one", "two", "three", "four", "five", "six", "seven",
"eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
"sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "fourty",
"fifty", "sixty", "seventy", "eighty", "ninty", "hundred", "thousand", "million",
"billion"};
vector<int> numberVector={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000, 1000000, 1000000000};

//int count = 0;

string name(int n)
{   //cout<<n<<endl;    //This is for checking the recursive values of n.
    /*count++;      //This is for stopping infinite loops while dubugging.
    if(count>=10)
        return "";*/

    if(n==0)
        return "";
    int biggestIndex = 0, biggest =1;
    for(int iter= numberVector.size()-1; iter>=0; iter--)
    {   //cout<<iter<<'\n';
        if(n>= numberVector.at(iter))
        {   biggestIndex = iter;
            biggest = numberVector[iter];
            break;
        }
    }
    if(n< 2*biggest)
    {   if(biggest >= 100)  //for "one hundred", "one hundred", "twenty", "thirty"
            return "one "+nameVector.at(biggestIndex)+" "+ name(n% biggest);
        else
            return nameVector.at(biggestIndex)+" "+ name(n% biggest);
    }

    //if(n< 2*biggest)    //"one" in "three million, one thousand" is best avoided.
        //return nameVector.at(biggestIndex)+" "+ name(n% biggest);
    //but "one million, three hundred" is a correct answer.
    if(n%biggest != 0)
        return name(n / biggest) +" "+ nameVector.at(biggestIndex)+", "+ name(n% biggest);
    else
        return name(n / biggest) +" "+ nameVector.at(biggestIndex);
}

int main()
{
    int n;
    cout<<"Enter a positive integer:\t";
    cin>>n;
    if(n<0)
        cout<<"invalid number. Please re-run with a positive integer.";
    else
        cout<<name(n);
    return 0;
}
