#include <iostream>
#include <string>
using namespace std;


bool Xcheck(string X);	//kiem tra neu hop le tra ve 1

float toDec(string X, int base);



string singleP(string X);	//bieu dien cham dong chinh xac don (tra ve he so 16)

string doubleP(string X);	//bieu dien cham dong chinh xac kep (tra ve he so 16)

bool isInteger(string X);	//kiem tra neu la so nguyen tra ve 1

bool Ncheck(string X, int N);	//kiem tra hop le tra ve 1 (vd: cac gia tri hop le 4n voi n >= 1 dong thoi du lon de bieu dien gia tri)

string signMag(string X, int N);	//bieu dien bang N bit o dang dau luong (tra ve he so 16)

string oneComplement(string X, int N);	//bieu dien bang N bit o dang bu 1 (tra ve he so 16)

string twoComplement(string X, int N);	//bieu dien bang N bit o dang bu 2 (tra ve he so 16)

string excess_2021d(string X, int N);	//bieu dien bang N bit o dang qua 2021d (tra ve he so 16)




