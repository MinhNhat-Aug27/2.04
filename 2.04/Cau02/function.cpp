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

string toBin(string x) 
//input : 1 so nguyen dang string
//output : day bit tuong ung voi x
{
	long long int x_int = 0;
	for (int i = 0; i < x.length(); i++)
	{
		x_int = x_int * 10 + getNum(x[i]);
	}
	string res = "";
	do {
		res = getChar(x_int % 2) + res;
		x_int /= 2;
	} while (x_int != 0);
	return res;
}

unsigned long long int binToDec(string input)
//input : 1 chuoi nhi phan
//output : 1 so thap phan tuong ung voi input
{
	int begin = 0;

	unsigned long long int result = 0;
	for (begin; begin < input.length(); begin++)
	{
		result += getNum(input[begin]) * pow(2, input.length() - begin - 1);
	}
	return result;
}


string DecimalToBase(unsigned long long int lli, int base)
//input : so thap phan, va co so base can chuyen qua, o day la 16.
//output : chuoi co so base tuong ung
{
	string res = "";
	do {
		long long int temp = lli % base;
		lli /= base;
		res = getChar(temp) + res;
	} while (lli != 0);
	return res;
}

string Precision(string x, bool isSingle)
//input : 1 so thuc can chuyen qua dau cham dong chinh xac kep
//output : dang chinh xac kep tuong ung 
{
	string kq = "";
	int bitCount = 1;
	int start = 0;
	if (x[0] == '-')
	{
		kq = '1' + kq;
		start = 1;
	}
	else {
		kq = '0' + kq;
	}

	int dot_pos = 0;
	for (dot_pos; dot_pos < x.length(); dot_pos++)
	{
		if (x[dot_pos] == '.')
			break;
	}

	string x_nguyen = "";
	for (int i = start; i < dot_pos; i++)
	{
		x_nguyen = x_nguyen + x[i];
	}
	string x_nguyen_bin = toBin(x_nguyen);
	bitCount += x_nguyen_bin.length();
	
	float x_abs = toDec(x, 10);
	int bit_rem, exponent;
	if(isSingle == true)
	{
	    bit_rem = 24 - bitCount + 1 ;
	    exponent = 23 - bit_rem + 127;
	}
	else {
	    bit_rem = 53 - bitCount +1;
	    exponent = 52 - bit_rem + 1023 ;
	}
	long long int temp = round(x_abs * pow(2, bit_rem));
	string temp_str_bin = toBin(to_string(temp));
	string e_str = "";
	while (exponent != 0)
	{
		e_str = getChar(exponent % 10) + e_str;
		exponent /= 10;
	}
	string e_str_bin = toBin(e_str);
	kq = kq + e_str_bin;
	for (int j = 1; j < temp_str_bin.length(); j++)
	{
		kq = kq + temp_str_bin[j];
	}
	return DecimalToBase(binToDec(kq), 16);
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
