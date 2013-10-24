#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = a;
}

// ����汾�Ŀ������������
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

int partition1(int data[],int low,int high)  //˫��ɨ�衣
{
     int key = data[low];   //�Ե�һ��Ԫ��Ϊ��Ԫ
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

     data[l] = key;  //1.key��ֻ�г���Ҫ��ֵ������������ȱ���õ�һ��Ԫ�ص�ֵ��

     return l;     //������������е�Hoare�ı��ΰ汾���Ƿ��ص�����ŦԪ�أ�����ԪԪ��l��
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
