/*//#include "stdafx.h"
  #include <iostream>
 // #include "stdio.h"
  #include <cstdlib>

    using namespace std;
  int length;
  void PrintSolutions(int *flag)
  {
      for (int i=0; i<length; i++)
      {
         if (flag[i] == 1)
         {
             cout << i+1 << "+";
         }
     }
     cout << endl;
 }

 void BagProblem(int m, int n, int *flag)
 {
     if(n<1 || m<1)
         return;
     if(m < n)
         n = m;
     if (n == m)
     {
         flag[n-1] = 1;
         PrintSolutions(flag);
         flag[n-1] = 0;
     }
     flag[n-1] = 1;
     BagProblem(m-n, n-1, flag);
     flag[n-1] = 0;

     BagProblem(m, n-1, flag);
 }

 int main()
 {
     int m, n;
     cout << "Please input the m and n:" << endl;
     cin >> m >> n;
     cout << "The solution is:" << endl;
     length = n;
     int *flag = (int *)malloc(sizeof(int)*n);
   //  memset(flag, 0, sizeof(flag));
     BagProblem(m,n,flag);
     //delete flag;//����ط�����һ��ԭ���ԵĴ��� new��delete�ɶ�ʹ�ã� mallocӦ�ú�free�ɶ�ʹ�ã�Ҫ��Ȼ�ͻ�����ڴ�й¶
     free(flag);
     return 0;


 }
 */

 #include<list>
#include<iostream>
using namespace std;

list<int>list1;
void find_factor(int sum, int n)
{
    // �ݹ����
    if(n <= 0 || sum <= 0)
        return;

    // ����ҵ��Ľ��
    if(sum == n)
    {
        // ��תlist
        list1.reverse();
        for(list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
            cout << *iter << " + ";
        cout << n << endl;
        list1.reverse();
    }

    list1.push_front(n);      //���͵�01��������
    find_factor(sum-n, n-1);   //��n��n-1��������sum-n
    list1.pop_front();
    find_factor(sum, n-1);     //����n��n-1��������sum
}

int main()
{
    int sum, n;
    cout << "��������Ҫ���ڶ��ٵ���ֵsum:" << endl;
    cin >> sum;
    cout << "��������Ҫ��1.....n������ȡֵ��n��" << endl;
    cin >> n;
    cout << "���п��ܵ����У����£�" << endl;
    find_factor(sum,n);
    return 0;
}
