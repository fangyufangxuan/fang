#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
    int i = 0;
    cout << i << endl;
    // char *str = new char [100];
    string str = "asdfghjkl";
    cout << str << endl;

    cout << "Hello world!" << endl;

    int     a;
    double  d;

    if (a < 0) {
        cout << "a<0\n";
    } else if (a == 0) {
        cout << "a == 0\n";
    } else {
        cout << "a > 0\n";
    }

    if (a < 0)
    {
        cout << "a<0\n";
    }
    else if (a == 0)
    {
        cout << "a == 0\n";
    }
    else
    {
        cout << "a > 0\n";
    }

    cin.get();


    return 0;
}
