// given a positive number n, write the number 
// from 1 t on, cavulate the times of 1
// eg: n = 12, we write 1 2 3 4 5 6 7 8 9 10 11 12
// so the times of 1 is 5
// last modified in 2013/11/02
// by fangrenxiao

#include <iostream>
#include <cstring>

const int LENGTH = 8 * sizeof(int);

using namespace std;

long count(long n)
{
	long n_count = 0;

	while (n != 0)
	{
		n_count += (n % 10 == 1) ? 1 : 0;
		n /= 10;
	}

	return n_count;
}
// Record the every times of 1, then caculate the sum
long times_1(long n)
{
	long count_1 = 0;

	for (long i = 1; i <= n; i++)
	{
		count_1 += count(i);
	}

	return count_1;
}

// Judge the current byte's number, 0,1,or >1
// then caculate the byte's times of 1
// last summrize the total
long times_2(long n)
{
	long count_1 = 0;
	// the current byte number, eg:1, 10, 100 ...
	long cur_byte_num = 1;   
	long cur_number = 0;
	long high_number = 0;
	long low_number = 0;

	while (n / cur_byte_num != 0)
	{
		low_number = n - (n / cur_byte_num) * cur_byte_num;
		cur_number = (n / cur_byte_num) % 10;
		high_number = n / (cur_byte_num * 10);

		switch(cur_number)
		{
			case 0:
				count_1 += high_number * cur_byte_num;
				break;
			case 1:
				count_1 += high_number * cur_byte_num + low_number + 1;
				break;
			default:
				count_1 += (high_number + 1) * cur_byte_num;
		}

		cur_byte_num *= 10;
	}

	return count_1;
}

// if the num is binary, caculate the 1 times
// the same method as above
char * dec2bin(int n, char * binary)
{
	//	static int len = sizeof(int);
	for (int i =LENGTH  - 1; i >=0; i--)
	{
		binary[i] = (01 & n) + '0';
		n >>= 1;
	}
	binary[LENGTH] = '\0';

	return binary;
}

int power(int num, int k)
{
	int total = 1;
	for (int i = 0; i < k; i++)
	{
		total *= num;
	}
	return total;
}

int bin2dec(char * binary)
{
	int temp = 0;
	if (binary == NULL)
		return temp;
	
	int len = strlen(binary);
	
//	cout << "lengh of binary is : " << len << endl;

	for (int i = len -1; i >= 0; i--)
	{
		temp += (1 & (binary[i] - '0')) * (power(2, len-1-i));
	}
	return temp;
}

int times_3(char * binary)
{
	int count_1 = 0;

	int cur_type_num = 0;
	char low_num[LENGTH] = "";
	char cur_num[LENGTH] = "";
	char high_num[LENGTH] = "";
	
	int len = strlen(binary);
	for (int i = 1; i <= len; i++)
	{
		strncpy(high_num, binary, len - i);
		strncpy(low_num, binary + len + 1 - i, i);
		strncpy(cur_num, binary + len - i, 1);
	//	cout << high_num << "   " << cur_num << "    " << low_num << endl;
	//	cout << bin2dec(high_num) << "   " << bin2dec(cur_num) << "   " << bin2dec(low_num) << endl;

		int flag = bin2dec(cur_num);
		int high_dec_num = bin2dec(high_num) * power(2, i - 1);
		if (flag == 0)
		{
			count_1 += high_dec_num;
		}
		if (flag == 1)	
		{
			count_1 += high_dec_num + bin2dec(low_num) + 1;
		}

		memset(low_num, 0, 32);
		memset(cur_num, 0, 32);
		memset(high_num, 0, 32);
	}

	return count_1;
}


int main(int argc, char * argv[])
{
	long num;
	cout << "Please input the num : ";
	cin >> num;

	cout << "The 1(O(n*logn) times of " << num << " is " << times_1(num) << endl;
	cout << "The 1(O(lengh) times of " << num << " is " << times_1(num) << endl;

	// int lengh = 8 * sizeof (int);
	char binary[LENGTH] = "";
	cout << "Please input binary : " ;
	cin >> binary;

	int int_num;
	int_num = bin2dec(binary);
	cout << "The binary " << binary << "  to dec is : " << int_num << endl;

//	cout << "The decinal " << int_num << " to binary is : " << binary << endl;
	int count_times;

	count_times = times_3(binary);
	cout << "The binary " << binary << " has 1 times of " << count_times << endl;


	return 0;
}
