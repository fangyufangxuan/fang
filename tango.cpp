// find the tango in the ID[]
// suppose there is one tango whose number > 1/2
// if there are n-1, each number > 1/n
// the time is O(n)

#include <iostream>
#include <string>

using namespace std;

string find_tango_1(string * ID, int n)
{
	string candidate;
	int times_num = 0;          // Record the number of candidate
	for (int i = 0; i < n; i++)
	{
		if (times_num == 0)
		{
			candidate = ID[i];
		}
		else
		{
			if (candidate == ID[i])
			{
				times_num++;
			}
			else
			{
				times_num--;
			}
		}
	}

	return candidate;
}

void find_tango_3(string * ID, int n)
{
	string candidate[3];
	int times_num[3] = {0};

	for (int i = 0; i < n; i++)
	{
		if (times_num[0] == 0)
		{
			if (ID[i] == candidate[1])
			{
				times_num[1]++;
			}
			else if (ID[i] == candidate[2])
			{
				times_num[2]++;
			}
			else
			{
				candidate[0] = ID[i];
				times_num[0] = 1;
			}
		}
		else if (times_num[1] == 0)
		{
			if (ID[i] == candidate[0])
			{
				times_num[0]++;
			}
			else if (ID[i] == candidate[2])
			{
				times_num[2]++;
			}
			else
			{
				candidate[1] = ID[i];
				times_num[1] = 1;
			}
		}
		else if (times_num[2] == 0)
		{
			if (ID[i] == candidate[0])
			{
				times_num[0]++;
			}
			else if (ID[i] == candidate[1])
			{
				times_num[1]++;
			}
			else
			{
				candidate[2] = ID[i];
				times_num[2] = 1;
			}
		}
		else
		{
			if (ID[i] == candidate[0])
				times_num[0]++;
			else if (ID[i] == candidate[1])
				times_num[1]++;
			else if (ID[i] == candidate[2])
				times_num[2]++;
			else
			{
				times_num[0]--;
				times_num[1]--;
				times_num[2]--;
			}
		}
	}

	cout << "The three tangoes are : " << candidate[0] << " , " << candidate[1] << " and " << candidate[2] << endl;
}

int main(int argc, char * argv[])
{
	int flag;
	cout << "Please choose 1 or 3[tango] : ";
	cin >> flag;
	if (flag == 1 || flag == 3)
	{
	int n;
	cout << "Please input the number of ID : ";

	string ID[n];
	cout << "Please input the IDs : [divide them in backspcae] " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> ID[i];
	}

	if (flag == 1)
	{
		string tango_id;
		tango_id = find_tango_1(ID, n);

		cout << "The only tango is : " << tango_id << endl;
	}
	else
	{
		find_tango_3(ID, n);
	}
	}
	else
	{

		cout << "Your choice is erro! Exit" << endl;
		return -1;
	}

	return 0;
}

