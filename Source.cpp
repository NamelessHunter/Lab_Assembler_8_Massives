#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	const int n = 10;
	int mas1[n];
	int mas2[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		mas1[i] = rand() % 40 - 20;
		cout << mas1[i] << " ";
	}
		cout << endl;
	for (int i = 0; i < n; i++)
	{
		mas2[i] = rand() % 40 - 20;
		cout << mas2[i] << " ";
	}
	cout << endl;

	int fmas[n];

	_asm {
		mov esi, 0
		mov eax, 0
		mov ebx, 0
		M1:
		mov eax, mas1[esi * 4]
		mov ebx, mas2[esi * 4]
		sub eax, ebx
		imul eax, eax
		mov fmas[esi * 4], eax
		inc esi
		cmp esi, n
		jne M1
		
	}

	for (int i = 0; i < n; i++)
	{
		cout << fmas[i] << " ";
	}
	/*delete[] mas1;
	delete[] mas2;
	delete[] fmas;*/
}