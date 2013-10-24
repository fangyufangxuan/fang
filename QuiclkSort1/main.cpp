#include <iostream>

using namespace std;

void Swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a   = b;
    b = tmp;
}

int Partition(int items[], int p, int r)
{
    int key = items[r];          // The last elem is the pivot
    int i = p -1;
    int j;

    for (j = p; j <= r-1; j++)
    {
        if (items[j] <= key )
        {
            i += 1;
            if (i!=j)
            {
                /** \brief
                int tmp;
                tmp= items[i];
                items[j] = items[j];
                items[j] = tmp;
                 */
                Swap(items[i], items[j]);
            }
        }

    }
    Swap(items[i+1], items[r]);

        //for (int i = 0; i <= r; i++)
        //{
        //    cout << items[i] << "\t" ;
        //}
        //cout << endl;

    return i+1;
}

void quick_sort(int items[], int first, int last)
{
    if (first < last)
    {
        int pivot = Partition(items, first, last);

        quick_sort(items, first, pivot-1);
        quick_sort(items, pivot+1, last);
    }
}

int main()
{
    int array[8] = {3, 8, 7, 1, 2, 5, 6, 4};

    quick_sort(array, 0, 7);

    for (int i = 0; i <= 7; i++)
    {
        cout << array[i] << ", " ;
    }
    cout << endl;

    return 0;
}
