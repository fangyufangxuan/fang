#include <iostream>
#include <cstring>

using namespace std;

void ReverseStr1(char * str)
{
		int length = strlen(str) -1;
		for (int i =0; i < length - i; i++)
		{
			char temp;
			temp = str[i];
			str[i] = str[length-i];
			str[length-i] = temp;
		}
		// str[length + 1] = "\0";
		str[length + 1] = 0;

		cout << str << endl;
}

void ReverseStr2(char * str)
{
	char * ptr1 = str;
	char * ptr2 = str;

	for ( ; *ptr1 != '\0'; ptr1++)
	{
	}
	// 没有给出字符串的长度
	for ( ptr1--; ptr2 < ptr1; ptr1--,ptr2++ )
	{
		char temp;
		temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
	}

	cout << str << endl;

}

void ReverseStr3(char * str)
{
		int length = strlen(str) -1;
		for (int i =0; i < length - i; i++)
		{
			// char temp;
			// temp = str[i];
			str[i] = str[i]^str[length-i];
			str[length-i] = str[i]^str[length-i];
			str[i] = str[i]^str[length-i];
		}
		// str[length + 1] = '\0';
		str[length + 1] = 0;

		cout << str << endl;
}



int main()
{
    struct structs {
        int a;
        double b;
        char c;
    };
    cout << sizeof(struct) << endl;

    http://www.sogou.com

    int i = 0;

    int j = 1.2;
    double d = 12.8;
    int array[10];
    int k;
    for ( k= 0; k < 10;k++ )
    {
        array[k]= k;
        j += k;
        i++;
        cout << i << endl;
        cout << array[k] << endl;
    }
    cout << j << endl;
    cout << k << endl;
    // cout << array[k] << endl;

	char str[] = "ABCDEFG HIJKLMN OPQRSTUVWXYZ";
	cout << "Orignal string : " << str << endl;
    cout << endl;



	cout << "Reversed string : " << endl;
	ReverseStr1(str);
    cout << endl;

	cout << "Again Reversed string : " << endl;
	ReverseStr2(str);
    cout << endl;

	cout << "Again again Reversed string : " << endl;
	ReverseStr3(str);
    cout << endl;

	return 0;
}
