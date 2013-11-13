// use the precise fraction format to sigify the double
// modified in 20131106
// by fangrenxiao

#include <iostream>

using namespace std;

// when the elem is long long and so on
long long gcd(long long x, long long y)
{
	if (x < y)
	{
		long long tmp = x;
		x = y;
		y = tmp;
	}

	int k = 0;
	while (y != 0)
	{
		if ((x & 1) == 0)
		{
			if ((y & 1) == 0)
			{
				x >>= 1;
				y >>= 1;
				k++;
			}
			else
			{
				x >>= 1;
			}
		}
		else
		{
			if ((y & 1) == 0)
			{
				y >>= 1;
			}
			else
			{
				x = x - y;
			}
		}

		if ( x < y)
		{
			long long tmp = x;
			x = y;
			y = tmp;
		}
	}

	return x << k;
}

void accurate_double(long long intger, long long fraction_a, long long fraction_b)
{
	// a, b, c stands for not_cycle fraction/cycle fraction/intger
	long long a = fraction_a;
	long long b = fraction_b;
	long long c = intger;

	if (a == 0 || b == 0)
	{
		cout << "The intger is : " << c << endl; 	
	}
	// record the numerator
	// power_a/_b stands power of byte a / b
	long long numerator = c;
	long long denomitor = 1;

	long long power_a = 1;
	long long power_b = 1;

	while (a)
	{
		power_a *= 10;
		a /= 10;
	}
	a = fraction_a;
	numerator = power_a * c + a;	

	while (b)
	{
		power_b *= 10;
		b /= 10;
	}
	b = fraction_b;
	numerator = numerator * (power_b - 1) + b ;
	denomitor = power_a * (power_b - 1);

	long long gcd_nd = gcd(numerator, denomitor);

	cout << "The gcd of num and deno is : " << gcd_nd << endl;
	cout << "The fraction format is : ";
	cout << numerator/gcd_nd << " / " << denomitor/gcd_nd << endl;
}


int main(int argc, char * argv[])
{
	long long intger;
	long long fraction_a;
	long long fraction_b;

	cout << "Please input : c a b like 24 333 333 : " << endl;
	cin >> intger >> fraction_a >> fraction_b;
	//cout << "The gcd of a and b is :" << gcd(fraction_a, fraction_b) << endl;
	accurate_double(intger, fraction_a, fraction_b);

	cout << endl;

	return 0;
}
