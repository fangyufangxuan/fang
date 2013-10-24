#include <iostream>

using namespace std;

int main()
{
    char *ptr[] = {"one", "two", "three"};
    char **p = ptr;

    cout << *ptr + 2 << endl;
    cout << *ptr[2] << endl;
    cout << **++p <<endl;
    cout << *(p+1) <<endl;


    cout << "Hello world!" << endl;
    return 0;
}
