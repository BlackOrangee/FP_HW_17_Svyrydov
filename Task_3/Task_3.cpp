// Task 3. Write a function that determines the number of positive, negative and zero elements of the array passed to it.
//

#include <iostream>
using namespace std;

int DeterminateNumber(int arr[], int SIZE, int menu, int positive, int zero, int negative, int i);
void OutputArray(int arr[], int SIZE, int i); //Output array

int main()
{
	int menu = 0;
	const int SIZE = 10;
	int arr[SIZE] = { 5, 3, -2, 0, -4, 6, 0, -9, 4, 10 };

	cout << "\n\n\t";
	OutputArray(arr, SIZE, 0);

	while (true)
	{	//User menu
		cout << "\n\n\t1 -- Determinate number of positive elements\n\t2 -- Determinate number of zero elements\n\t3 -- Determinate number of negative elements\n\t0 -- Exit\n\n\t"; cin >> menu;
		if (menu == 0)
		{
			return 0;
		}
		cout << "\n\t" << DeterminateNumber(arr, SIZE, menu, 0, 0, 0, 0);	//Show chosen option
	}
}

int DeterminateNumber(int arr[], int SIZE, int menu, int positive, int zero, int negative, int i)
{
	if (i == SIZE)
	{
		switch (menu) //Return option
		{
		case 1:
			return positive;
		case 2:
			return zero;
		case 3:
			return negative;
		default:
			break;
		}
	}
	if (arr[i] > 0)
	{
		positive++;	//Determinate number of positive elements
	}
	if (arr[i] == 0)
	{
		zero++;	//Determinate number of zero elements
	}
	if (arr[i] < 0)
	{
		negative++;	//Determinate number of negative elements
	}
	DeterminateNumber(arr, SIZE, menu, positive, zero, negative, ++i);
}

void OutputArray(int arr[], int SIZE, int i) //Output array
{
	if (i == SIZE)
	{
		return;
	}
	cout << arr[i] << " ";
	OutputArray(arr, SIZE, ++i);
}