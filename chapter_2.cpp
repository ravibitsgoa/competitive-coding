#include <iostream>
#include <string>
using namespace std;
int main()
{
    // ask for the person's name
    cout << "Please enter your first name: ";
    // read the name
    string name;
    cin >> name;
    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";
    // the number of blanks surrounding the greeting
    const int ypad = 1, xpad=2;
    // the number of rows and columns to write
    const int rows = ypad * 2 + 3;
    const string::size_type cols = greeting.size() + xpad * 2 + 2;
    // write a blank line to separate the output from the input
    cout << endl;
    // write rows rows of output
    // invariant: we have written r rows so far
    for (int r = 0; r != rows; ++r)
    {    string::size_type c = 0;
        // invariant: we have written c characters so far in the current row
        while (c != cols)
        {    // is it time to write the greeting?
            if (r == ypad + 1 && c == xpad + 1)
            {   cout << greeting;
                c += greeting.size();
            }
            else
            {   // are we on the border?
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                {   cout << "*";
                    ++c;
                }
                else if(r != ypad +1)
                {   string y(2*xpad+greeting.size(), ' ');
                    cout << y; c+=2*xpad+greeting.size();
                }
                else
                {   cout<<' ';
                    ++c;
                }
            }
        }
        cout << endl;
    }
return 0;
}
