#include "PrefixSorting.h"

using namespace std;

int main()
{
    CPrefixSorting cake;

    // int Cake[10] = {3,2,1,6,5,4,9,8,7,0};
    int n;
    scanf("%d", &n);

    int Cake[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Cake[i]);
    }

    cake.Run(Cake, 3);
    cake.OutPut();

    return 0;
}
