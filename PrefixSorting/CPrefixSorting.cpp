#ifndef PREFIXSORTING_H_
#define PREFIXSORTING_H_
#endif // PREFIXSORTING_H_

#include "PrefixSorting.h"

CPrefixSorting::CPrefixSorting()
{
    m_nCakeCnt = 0;
    m_nMaxSwap = 0;
}

CPrefixSorting::~CPrefixSorting()
{
    if (m_CakeArray != NULL)
        delete m_CakeArray;

    if (m_SwapArray != NULL)
        delete m_SwapArray;

    if (m_ReverseCakeArray != NULL)
        delete m_ReverseCakeArray;

    if (m_ReverseCakeArraySwap != NULL)
        delete m_ReverseCakeArraySwap;
}

// 计算烙饼翻转信息
// pCakeArray : 存储烙饼索引数组
// nCakeCnt   : 烙饼个数

void CPrefixSorting::Run(int * pCakeArray, int nCakeCnt)
{
	Init(pCakeArray, nCakeCnt);

	m_nSearch = 0;
	Search(0);
}

// 输出烙饼具体的翻转次数
void CPrefixSorting::OutPut()
{
    for (int i = 0; i < m_nMaxSwap; i++)
    {
        printf("%d ", m_SwapArray[i]);

    }

    printf("\n | Search Times| : %d\n", m_nSearch);
    printf("Total Search Times : %d\n", m_nMaxSwap);
}

void CPrefixSorting::Init(int * pCakeArray, int nCakeCnt)
{
    assert(pCakeArray != NULL);
    assert(nCakeCnt > 0);

    m_nCakeCnt = nCakeCnt;

    // initialization cake array
    m_CakeArray = new int[m_nCakeCnt];
    assert(m_CakeArray != NULL);
    for (int i = 0; i < m_nCakeCnt; i++)
    {
        m_CakeArray[i] = pCakeArray[i];
    }

    // 设置最多交换次数
    m_nMaxSwap = UpperBound(m_nCakeCnt);

    // 初始化交换结果数组
    m_SwapArray = new int[m_nMaxSwap + 1];
    assert(m_SwapArray != NULL);

    // 初始化中间交换结果信息
    m_ReverseCakeArray = new int[m_nCakeCnt];
    assert(m_ReverseCakeArray != NULL);

    for(int i = 0; i < m_nCakeCnt; i++)
    {
        m_ReverseCakeArray[i] = m_CakeArray[i];

    }

    m_ReverseCakeArraySwap = new int[m_nMaxSwap];
    assert(m_ReverseCakeArraySwap != NULL);

}

// 寻找当前翻转的上界
int CPrefixSorting::UpperBound(int nCakeCnt)
{
    return (nCakeCnt-1) * 2;
}

// 寻找当前翻转的下界
int CPrefixSorting::LowBound(int * pCakeArray, int nCakeCnt)
{
    int t, ret = 0;

    // 根据当前数组的排序信息情况来判断最少需要交换多少次
    for (int i = 1; i < nCakeCnt; i++)
    {
        t = pCakeArray[i] - pCakeArray[i-1];
        if ((t == 1) | (t == -1))
        {
        }
        else
        {
            ret++;
        }
    }
    return ret;
}

void CPrefixSorting::Search(int step)
{
    int i;
    int nEstimate;

    m_nSearch++;

    // 估计本次搜索所需要的最小交换次数
    nEstimate = LowBound(m_ReverseCakeArray, m_nCakeCnt);

    if (step + nEstimate >= m_nMaxSwap)
    {
        return;
    }

    //如果已经排好序，则翻转完成，输出结果
    if (IsSorted(m_ReverseCakeArray, m_nCakeCnt))
    {
        if (step < m_nCakeCnt)
        {
            m_nMaxSwap = step;
            for (i = 0; i < m_nMaxSwap; i++)
            {
                m_SwapArray[i] = m_ReverseCakeArraySwap[i];
            }
        }
        return;
    }

    // 递归进行翻转
    for (i = 1; i < m_nCakeCnt; i++)
    {
        Reverse(0, i);
        m_ReverseCakeArraySwap[step] = i;
        Search(step + 1);
        Reverse(0, i);
    }
}

//
bool CPrefixSorting::IsSorted(int * pCakeArray, int nCakeCnt)
{
    for (int i = 1; i < nCakeCnt; i++)
    {
        if (pCakeArray[i-1] > pCakeArray[i])
        {
            return false;
        }
    }
    return true;

}

void CPrefixSorting::Reverse(int nBegin, int nEnd)
{
    assert(nEnd > nBegin);
    int i, j, t;

    // 翻转烙饼信息
    for (i = nBegin, j = nEnd; i < j; i++, j--)
    {
        t = m_ReverseCakeArray[i];
        m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
        m_ReverseCakeArray[j] = t;
    }
}
