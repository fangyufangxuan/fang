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
     //delete flag;//这个地方犯了一个原则性的错误 new和delete成对使用， malloc应该和free成对使用，要不然就会造成内存泄露
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
    // 递归出口
    if(n <= 0 || sum <= 0)
        return;

    // 输出找到的结果
    if(sum == n)
    {
        // 反转list
        list1.reverse();
        for(list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
            cout << *iter << " + ";
        cout << n << endl;
        list1.reverse();
    }

    list1.push_front(n);      //典型的01背包问题
    find_factor(sum-n, n-1);   //放n，n-1个数填满sum-n
    list1.pop_front();
    find_factor(sum, n-1);     //不放n，n-1个数填满sum
}

int main()
{
    int sum, n;
    cout << "请输入你要等于多少的数值sum:" << endl;
    cin >> sum;
    cout << "请输入你要从1.....n数列中取值的n：" << endl;
    cin >> n;
    cout << "所有可能的序列，如下：" << endl;
    find_factor(sum,n);
    return 0;
}
