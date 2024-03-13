#include <iostream>
using namespace std;



void estRand(int arr[], int size) //функция для задания случайных значений массиву
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 100 + 1;
	}
}

void sortArr(int arr[], int size) // функция для сортировки по возрастанию и затем вывода массива
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (*(arr + j) > *(arr + j + 1))
				swap(*(arr + j), *(arr + j + 1));
		}
		
	}

	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
}

void obr(int arrC[], int csize, int size, int arrA[], int arrB[]) // функция для заполнения третьего массива элементами из первого и второго по очереди
{
	int count = 0;
	for (int i = 0; i < csize; i++)
	{
		arrC[i] = arrA[count];
		arrC[i + 1] = arrB[count];
		cout << arrC[i] << " " << arrC[i + 1] << " ";
		i++;
		count++;
	}
}

//int main()
//{
//	setlocale(LC_ALL, "rus");
//	const int size = 10;
//	const int csize = 20;
//	srand(time(0));
//	int arrA[size];
//	int arrB[size];
//
//	estRand(arrA, size);
//	estRand(arrB, size);
//	sortArr(arrA, size);
//	cout << endl;
//	sortArr(arrB, size);
//
//	int arrC[csize];
//	cout << "\nВывод третьего массива:" << endl;
//	obr(arrC, csize, size, arrA, arrB);
//	cout << "\nУпорядоченный третий массив: " << endl;
//	sortArr(arrC, csize);
//
//
//
//
//
//
//
//	return 0;
//}

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void commonEl(int arrC[], int arrA[], int arrB[], int size, int csize)
{
	int count = 0;
	for (int i = 0; i < csize; i++)
	{
		*(arrC + i) = 0;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (*(arrA + i) == *(arrB + j))
			{
				*(arrC + count) = *(arrA + i);
				count++;
			}
		}
	}

	for (int i = 0; i < csize; i++)
	{
		cout << *(arrC + i) << " ";
	}
}

void AnotinB(int arrC[], int arrA[], int arrB[], int size, int csize)
{
	int count = 0;
	bool foundMatch;
	for (int i = 0; i < csize; i++)
	{
		*(arrC + i) = 0;
	}

	for (int i = 0; i < size; i++)
	{
		foundMatch = false;
		for (int j = 0; j < size; j++)
		{
			if (*(arrA+i) == *(arrB+j))
			{
				foundMatch = true;
				break;
			}
		}
			if(!foundMatch)
			{
				*(arrC+count) = *(arrA+i);
				count++;
			}

		
	}

	for (int i = 0; i < csize; i++)
	{
		cout << *(arrC + i) << " ";
	}
}

void BnotinA(int arrC[], int arrA[], int arrB[], int size, int csize)
{
	int count = 0;
	bool foundMatch;
	for (int i = 0; i < csize; i++)
	{
		*(arrC + i) = 0;
	}

	for (int i = 0; i < size; i++)
	{
		foundMatch = false;
		for (int j = 0; j < size; j++)
		{
			if (*(arrB + i) == *(arrA + j))
			{
				foundMatch = true;
				break;
			}
		}
		if (!foundMatch)
		{
			*(arrC + count) = *(arrB + i);
			count++;
		}
	}
	for (int i = 0; i < csize; i++)
	{
		cout << *(arrC + i) << " ";
	}

}

void notCommonEl(int arrC[], int arrA[], int arrB[], int size, int csize)
{
	int count = 0;
	bool foundMatch1, foundMatch2;
	for (int i = 0; i < csize; i++)
	{
		*(arrC + i) = 0;
	}

	for (int i = 0; i < size; i++)
	{
		foundMatch1 = false;
		foundMatch2 = false;
		for (int j = 0; j < size; j++)
		{
			if (*(arrA + i) == *(arrB + j))
			{
				foundMatch1 = true;
			}
			if (*(arrB + i) == *(arrA + j))
			{
				foundMatch2 = true;
				break;
			}
		}

		if (!foundMatch1)
		{
			*(arrC + count) = *(arrA + i);
			count++;
		}
		if (!foundMatch2)
		{
			*(arrC + count) = *(arrB + i);
			count++;
		}
	}

	for (int i = 0; i < csize; i++)
	{
		cout << *(arrC + i) << " ";
	}

}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	const int size = 10;
	const int csize = 20;
	int arrA[size];
	int arrB[size];
	estRand(arrA, size);
	estRand(arrB, size);

	printArr(arrA, size);
	printArr(arrB, size);

	int arrC[csize];
	cout << "Элементы обоих массивов: " << endl;
	obr(arrC, csize, size, arrA, arrB);

	cout << "\nОбщие элементы: " << endl;
	commonEl(arrC, arrA, arrB, size, csize);
	cout << "\nЭлементы массива А которых нет в массиве В: " << endl;
	AnotinB(arrC, arrA, arrB, size, csize);
	cout << "\nЭлементы массива B которых нет в массиве A: " << endl;
	BnotinA(arrC, arrA, arrB, size, csize);
	cout << "\nЭлементы массивов А и В, которые не являются общими: " << endl;
	notCommonEl(arrC, arrA, arrB, size, csize);

	return 0;
}