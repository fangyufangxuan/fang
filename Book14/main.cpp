#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
const int larg = 100000;//����һ�����ֵ���൱��ȡ��Сֵʱ�������λ�õ�ֵ

template <typename T>
void rerank(T m[],int length)//ð������
 {
    for (int i = length-1; i >0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (m[j]>m[j +1])
            {
                T temp;
                temp = m[j + 1];
                m[j + 1] = m[j];
                m[j] = temp;
            }
        }
    }
 }

 double Min(double a, double b, double c, double d, double e)//������Сֵ
 {
    double nn[5]={a,b,c,d,e};
    rerank(nn,5);

    return nn[0];
 }

double find_BestSol(int x1, int x2, int x3, int x4, int x5)//��̬�滮���ݹ�ʵ�֣�
{
    int n[5] ={ x1, x2, x3, x4, x5 };
    rerank(n,5);//��n���д�С��������
    x1 = n[0];
    x2 = n[1];
    x3 = n[2];
    x4 = n[3];
    x5 = n[4];
    /* x1 < x2 < x3 < x4  < x5*/
    if (n[0] > 0)//��С�Ķ�����0�������о���������0��Ȼ�����п����ۿ����г�����������Сֵ
    {
        return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1),
                       2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
                       3 * 8 * 0.9 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1),
                       4 * 8 * 0.8 + find_BestSol(x1, x2 - 1, x3 - 1, x4 - 1, x5 - 1),
                       5 * 8 * 0.75 + find_BestSol(x1 - 1, x2 - 1, x3 - 1, x4 - 1, x5 - 1));

    }
    else if ((n[0] == 0) && (n[1] > 0))
    {
        return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1),
                    2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
                    3 * 8 * 0.9 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1),
                    4 * 8 * 0.8 + find_BestSol(x1, x2 - 1, x3 - 1, x4 - 1, x5 - 1), larg);

    }
    else if ((n[0] == 0) && (n[1] == 0) && (n[2] > 0))
    {
        return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1),
                            2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
                            3 * 8 * 0.9 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1),
                            larg, larg);
    }
    else if ((n[0] == 0) && (n[1] == 0) && (n[2] == 0) && (n[3] > 0))
    {
        return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1),
                            2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
                            larg, larg, larg);
    }
    else if ((n[0] == 0) && (n[1] == 0) && (n[2] == 0) && (n[3] == 0) && (n[4] > 0))
    {
        return 8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1);
    }
    else//��Ϊ0
    {
        return 0;
    }
}

int  main()
{
   //int n1[5] = {3,4,2,1,0};
   int n1[5] = {3,2,2,1,1};
   double solution = find_BestSol(n1[0],n1[1],n1[2],n1[3],n1[4]);
   cout << "���ѵ����ٷ���Ϊ��"<< solution << endl;

   return 0;
}
