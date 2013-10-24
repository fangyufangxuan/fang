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

// �����ӱ���ת��Ϣ
// pCakeArray : �洢�ӱ���������
// nCakeCnt   : �ӱ�����

void CPrefixSorting::Run(int * pCakeArray, int nCakeCnt)
{
	Init(pCakeArray, nCakeCnt);

	m_nSearch = 0;
	Search(0);
}

// ����ӱ�����ķ�ת����
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

    // ������ཻ������
    m_nMaxSwap = UpperBound(m_nCakeCnt);

    // ��ʼ�������������
    m_SwapArray = new int[m_nMaxSwap + 1];
    assert(m_SwapArray != NULL);

    // ��ʼ���м佻�������Ϣ
    m_ReverseCakeArray = new int[m_nCakeCnt];
    assert(m_ReverseCakeArray != NULL);

    for(int i = 0; i < m_nCakeCnt; i++)
    {
        m_ReverseCakeArray[i] = m_CakeArray[i];

    }

    m_ReverseCakeArraySwap = new int[m_nMaxSwap];
    assert(m_ReverseCakeArraySwap != NULL);

}

// Ѱ�ҵ�ǰ��ת���Ͻ�
int CPrefixSorting::UpperBound(int nCakeCnt)
{
    return (nCakeCnt-1) * 2;
}

// Ѱ�ҵ�ǰ��ת���½�
int CPrefixSorting::LowBound(int * pCakeArray, int nCakeCnt)
{
    int t, ret = 0;

    // ���ݵ�ǰ�����������Ϣ������ж�������Ҫ�������ٴ�
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

    // ���Ʊ�����������Ҫ����С��������
    nEstimate = LowBound(m_ReverseCakeArray, m_nCakeCnt);

    if (step + nEstimate >= m_nMaxSwap)
    {
        return;
    }

    //����Ѿ��ź�����ת��ɣ�������
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

    // �ݹ���з�ת
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

    // ��ת�ӱ���Ϣ
    for (i = nBegin, j = nEnd; i < j; i++, j--)
    {
        t = m_ReverseCakeArray[i];
        m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
        m_ReverseCakeArray[j] = t;
    }
}
