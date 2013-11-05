// find the most k largest number of an array
// last modified in 20131205
// writen by fangrenxiao
#include <iostream>
#include <algorithm>

const int LENGTH = 9;
const int K = 4;

using namespace std;
// The first method is :
// sort the array
// time complexity is O(N*logN)
//
// The second method is :
// sort the part of the array
// using the selection sort or heap sort
// time is O(N*K)

// The third is :
// using one time quick sort
// time is O(N*logK)
void swap(int & a, int &b)
{
	int tmp;
	tmp = a;
	a	= b;
	b	= tmp;
}

int partition(int array[], int low, int high)
{
	int i = low - 1;
	int pivot = array[high];

	for (int j = low; j < high; j++)
	{
		if (array[j] > pivot)
		{
			swap(array[j], array[i+1]);
			//int tmp;
			//tmp = array[j];
			//array[j] = array[i+1];
			//array[i+1] = tmp;
			i++;
		}
	}
	swap(array[i+1], array[high]);
	
	return i+1;
}

int find_k_max(int array[], int low, int high, int k)
{
	if (low < high)
	{
		int q = partition(array, low, high);
		// Record the kth location
		int len = q + 1 - low;
		if (k == len)
		{
			return q;
		}
		else if (len < k)
		{
			return find_k_max(array, q + 1, high, k - len);
		}
		else
		{
			return find_k_max(array, low, q - 1, k);
		}
	}
}

// The fourth method is :
// using the min to max (binary search)
// Be equal to find the k th number
// time is O(N*log(MAX_MIN))

int get_sum(int array[], int mid)
{
	int sum = 0;
	for (int i = 0; i < LENGTH; i++)
	{
		if (array[i] >= mid)
		{
			sum += 1;
		}
	}
	return sum;
}

int get_kth(int array[])
{
	int max = array[0];
	int min = array[0];

	for (int i = 1; i < LENGTH; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		if (array[i] < min)
		{
			min = array[i];
		}
	}

	// get the k th number using the binary search
	while ( (max - min) > 1)
	{
		int mid = min + (max - min) / 2;
		if(get_sum(array, mid) >= K)
		{
			min = mid;
		}
		else
		{
			max = mid;
		}
	}

	return min;
}

// The fifth method is:
// bulid a k min heap, and compare the N-k elems
// time is O(N*logK)
void find_top_k(int array[])
{
	// bulid a heap using the include function in algorithm
	make_heap(array, array + K, greater<int>());

	for (int i = K; i < LENGTH; i++)
	{
		if (array[i] > array[0])
		{
			int tmp = array[0];
			array[0] = array[i];
			array[i] = tmp;
			make_heap(array, array + K, greater<int>());
		}
	}
}

// The sixth method is :
// using the idea of bucket sorting
// when there are many repeated elems in [min, max] 
// using count[i] to record the times of every number
// time is linear
int find_top_k2(int array[])
{
	int count[LENGTH] = {0}; 

	for (int i = 0; i < LENGTH; i++)
	{
		count[array[i]] +=1;
	}

	int sum_count = 0;
	int kth = 0;
	for (int j = LENGTH -1; j >= 0; j--)
	{
		sum_count += count[j];
		if (sum_count >= K)
		{
			kth = j;
			break;
		}
	}

	return kth;
}

int main(int argc, char * argv[])
{
	int array[LENGTH] = {1, 4, 7, 2, 9, 8, 3, 6, 5};
//	int kth = find_k_max(array, 0, LENGTH - 1, K);

	cout << "The k max number of array are : " << endl;
/*	int kth = get_kth(array);
	cout << "The k largest number is : " << kth << endl;
	for (int i = 0; i < LENGTH; i++)
	{
		if (array[i] >= kth)
			cout << array[i] << "   ";
	}
	cout << endl;
*/
	find_top_k(array);
	for (int i = 0; i < K; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;

	return 0;
}
