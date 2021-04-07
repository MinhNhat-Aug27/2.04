#include "header.h"
bool Xcheck(string X)
{
	if (X == "") return false;
	int i = 0;
	if (X[0] == '-') i = 1;
	int dotCount = 0;
	int numberCount = 0;
	int length = X.length();
	if (X[i] == '.' || X[length - 1] == '.') return false;
	for (i; i < length; i++)
	{
		if (X[i] < '0' || X[i] > '9')
		{
			if (X[i] == '.' && dotCount < 1)
			{
				dotCount++;
				continue;
			}
			else return false;
		}
		else
		{
			if (numberCount < 18)
			{
				numberCount++;
				continue;
			}
			else return false;
		}
	}
	return true;
}

float toDec(string X, int base)
{
	int i = 0;
	if (X[0] == '-') i = 1;
	float sum = 0;
	int length = X.length();
	int dotIndex = length;                                  // index của dấu '.'
	for (int j = 0; j < length; j++)
	{
		if (X[j] == '.') dotIndex = j;
	}

	for (i; i < dotIndex; i++) {
		sum += (X[i] - '0') * pow(base, dotIndex - i - 1);      // xử lý trước dấu .
	}
	for (i = dotIndex + 1; i < length; i++)
	{
		sum += (X[i] - '0') * pow(base, dotIndex - i);          // xử lý sau dấu chấm
	}
	return sum;
}

string singleP(string X)
{
	return string();
}

string doubleP(string X)
{
	return string();
}

bool isInteger(string X)
{
	int i = 0;
	if (X[0] == '-') i = 1;
	int length = X.length();
	bool isInteger = true;
	for (i; i < length; i++)
	{
		if (X[i] == '.') break;
	}
	for (i = i + 1; i < length; i++)
	{
		if (X[i] != '0') isInteger = false;
	}
	return isInteger;
}

bool Ncheck(string X, int N)
{
	int nArray[5] = { 4, 8, 16, 32, 64 };
	long long int valueArray[5] = { 7, 127, 32767, 2147483647, 9223372036854775807 };
	int i = 0;
	for (i; i < 5; i++)
	{
		if (N == nArray[i]) break;
	}
	if (i<5 && valueArray[i] > toDec(X, 10)) return true;
	else return false;
}

string signMag(string X, int N)
{
	return string();
}

string oneComplement(string X, int N)
{
	return string();
}

string twoComplement(string X, int N)
{
	return string();
}

string excess_2021d(string X, int N)
{
	return string();
}
