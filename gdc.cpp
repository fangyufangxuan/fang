// solve the Greatest Common Division of two elems
// Here we suppose the elem is int not bigint
// modified in 20132206
// by fangrenxiao

#include <iostream>

using namespace std;

// zhanzhuanxiangchu 
int gcd_div(int x, int y)
{
	return (!y) ? x : gcd_div(y , x % y);
}

// zhanzhuanxiangjian
int gcd_sub(int x, int y)
{
	if (x < y)
	{
		return gcd_sub(y, x);
	}

	if (y == 0)
	{
		return x;
	}
	else
	{
		return gcd_sub(x - y, y);
	}
}

// the combination of gcd_div and gcd_sub
bool is_even(int x)
{
	if ( (x % 2) == 0)
		return true;
	else
		return false;
}

int gcd(int x, int y)
{
	if (x < y)
		return gcd(y, x);
	
	if (y == 0)
		return x;
	else
	{
		if (is_even(x))
		{
			if (is_even(y))
				return gcd(x >> 1, y >> 1) << 1;
			else
				return gcd(x >> 1, y);
		}
		else
		{
			if (is_even(y))
				return gcd(x, y >> 1);
			else
				return gcd(x - y, y);
		}
	}
}

int main(int argc, char * argv[])
{
	int x;
	int y;
	cout << "Please input x, y : " << endl;
	cin >> x >> y;

	int gcd[3] = {0};
	gcd[0] = gcd_div(x, y);
	gcd[1] = gcd_div(x, y);
	gcd[2] = gcd_div(x, y);
	for (int i = 0; i < 3; i++)
	{
		cout << "The GCD of " << x << " and " << y << " is : " << gcd[i] << endl;
	}

	return 0;
}
