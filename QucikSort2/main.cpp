#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = a;
}

// 这个版本的快速排序出错误
int partition2(int items[], int p, int r)
{
    int key = items[p];
    int i = p - 1;
    int j = r + 1;

    while (1)
    {
        do
        {
            j -= 1;
        } while (items[j] > key);

        do
        {
            i += 1;
        } while (items[i] < key);

        if (i < j)
        {
            swap(items[i], items[j]);
        }
        else
        {
            return j;
        }
    }
}

int partition1(int data[],int low,int high)  //双向扫描。
{
     int key = data[low];   //以第一个元素为主元
     int l = low;
     int h = high;

     while (l < h)
     {
      while( (key <= data[h]) && (l < h) )
            h--;
      data[l] = data[h];

      while((data[l] <= key) && (l < h) )
            l++;
      data[h] = data[l];
     }

     data[l] = key;  //1.key。只有出现要赋值的情况，才事先保存好第一个元素的值。

     return l;     //这里和以下所有的Hoare的变形版本都是返回的是枢纽元素，即主元元素l。
}

void quick_sort(int items[], int first, int last)
{
    if (first < last)
    {
        int pivot = partition2(items, first, last);

        quick_sort(items, first, pivot);
        quick_sort(items, pivot+1, last);
    }
}

int main()
{
    int array[8] = {3, 8, 7, 1, 2, 5, 6, 4};

    quick_sort(array, 0, 7);

    for (int i = 0; i <=7; i++)
    {
            cout << array[i] << ", ";
    }

    return 0;
}
