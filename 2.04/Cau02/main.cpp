#include "header.h"
void main()
{
	string X;	//string of decimal variable
	int N;	//số bit can bieu dien neu la so nguyen

	cout << "Dien gia tri thap phan X ( <= 18 digits ): ";
	getline(cin, X);

	while (!Xcheck(X))
	{
		cout << "Gia tri khong hop le, vui long dien lai: ";
		getline(cin, X);
	}

	cout << "So " << X << "d co bieu dien cham dong chinh xac don la " << singleP(X) << endl;

	cout << "So " << X << "d co bieu dien cham dong chinh xac kep la " << doubleP(X) << endl;

	if (isInteger(X))
	{
		cout << "Dien so bit N: ";
		cin >> N;

		while (!Ncheck(X, N))
		{
			cout << "N khong hop le, vui long dien lai: ";
			cin >> N;
		}



		/* Quy uoc chung cho dau luong, bu 1, bu 2 va qua K: neu khong the bieu dien thi tra ve string rong (empty string)
		 !!! KHONG BIEU DIEN DUOC BOI VI:
			+ Dau luong: tran bit
			+ Bu 1: chua biet (._.)
			+ Bu 2: tran bit
			+ qua_2021d: add K ma` van so am
		*/

		if (!empty(signMag(X, N)))
			cout << "So " << X << "d co bieu dien bang " << N << " bit o dang dau luong la " << signMag(X, N) << endl;

		if (!empty(oneComplement(X, N)))
			cout << "So " << X << "d co bieu dien bang " << N << " bit o dang bu 1 la " << oneComplement(X, N) << endl;

		if (!empty(twoComplement(X, N)))
			cout << "So " << X << "d co bieu dien bang " << N << " bit o dang bu 2 la " << twoComplement(X, N) << endl;

		if (!empty(excess_2021d(X, N)))
			cout << "So " << X << "d co bieu dien bang " << N << " bit o qua 2021d la " << excess_2021d(X, N) << endl;

	}
}