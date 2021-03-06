#ifndef PREFIXSORTING_H_INCLUDED
#define PREFIXSORTING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


class CPrefixSorting
{
public:
    CPrefixSorting();
    ~CPrefixSorting();
    void Run(int * pCakeArray, int nCakeCnt);
    void OutPut();

private:
    void Init(int * pCakeArray, int nCakeCnt);
    int UpperBound(int nCakeCnt);
    int LowBound(int *pCakeArray, int nCakeCnt);
    void Search(int step);
    bool IsSorted(int *pCakeArray, int nCakeCnt);
    void Reverse(int nBegin, int nEnd);

private:
    int * m_CakeArray;              // Cake info array
    int m_nCakeCnt;                 // Cake nums
    int m_nMaxSwap;                 // The max swap nums is m_nCakeCnt*(n-1)
    int * m_SwapArray;              // the result array of swapping

    int * m_ReverseCakeArray;       // The current reverse pancake info array
    int * m_ReverseCakeArraySwap;   // The result of m_reverseCakeArray
    int m_nSearch;                  // the current search num

};




#endif // PREFIXSORTING_H_INCLUDED
