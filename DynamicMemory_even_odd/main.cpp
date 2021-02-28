#include <iostream>
using namespace std;
#define delimiter "------------------------------------------------------------------------------";
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void FillDynamic(int even[], int odd[], int arr[], const int n);
void Print(int even[], int odd[], int a, int b);
void main()
{
	setlocale(LC_ALL, "Russian");
	const int n=10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << delimiter;
	int a, b;
	cout <<endl<< "Введите количество все четные элементы массива: "; cin >> a;
	cout << delimiter;
	cout <<endl<< "Введите количество все нечетные элементы массива: "; cin >> b;
	cout << delimiter;
	int* even = new int[a] {};
	int* odd = new int[b] {};
	FillDynamic(even, odd, arr, n);
	Print(even, odd, a, b);
	cout << delimiter;
	delete[] even;
	delete[] odd;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout << endl;
}

void FillDynamic(int even[], int odd[], int arr[], const int n)
{
	int m = 0;
	int v = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) 
			{ even[m] = arr[i]; ++m; }
		else 
			{ odd[v] = arr[i]; ++v; }
	}
}
void Print(int even[], int odd[], int a, int b)
{
	cout <<endl<< "Все четные числа в массиве:" << endl;
	for (int i = 0; i < a; i++)
	{
		cout << even[i] << "\t";
	}
	cout << endl;
	cout << "Все нечетные числа в массиве:" << endl;
	for (int i = 0; i < b; i++)
	{
		cout << odd[i] << "\t";
	}
	cout << endl;
}
/* Есть массив из 10-ти элементов, заполненный случайными числами. 
   Необходимо создать еще два массива even[] и odd[], минимально возможного размера, 
   в массив even[] скопировать все четные элементы исходного массива, а в массив odd[] - все нечетные элементы.
   Массивы even[] и odd[] вывести на экран, используя функцию Print();*/