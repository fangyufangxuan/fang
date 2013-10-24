#include <iostream>

using namespace std;

int Binary_search(int items[], int n, int value)
{
    int first = 0;
    int last = n -1;

    int middle = first + ((last - first)/2);
    while ((value != items[middle]) && (first < last))
    {
        if (value < items[middle])
        {
            last = middle - 1;
        }
        else if (value > items[middle])
        {
            first = middle + 1;
        }

        middle = first + ((last - first)/2);
    }

    return (items[middle] != value) ? -1 : middle;
}

int main()
{
    int array[] = {1, 3, 5};

    int num = Binary_search(array, 3, 2);
    cout << "The location is " << num + 1 << endl;

    cout << "Hello world!" << endl;

    return 0;
}
