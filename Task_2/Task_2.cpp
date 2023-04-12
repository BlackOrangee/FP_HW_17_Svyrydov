// Task_2. Write a function that determines the arithmetic mean of the elements of the array passed to it
//

#include <iostream>
using namespace std;

int Average(int arr[], int SIZE, int sum, int i); //Calculate array average
void OutputArray(int arr[], int SIZE, int i); //Output array
void GenerateArray(int arr[], int SIZE, int i); // Generate array

int main()
{
	srand(time(NULL));
	const int SIZE = 10;
	int arr[SIZE];

	GenerateArray(arr, SIZE, 0);
	cout << "\n\n\t";
	OutputArray(arr, SIZE, 0);

	cout << "\n\n\tAverage: " << Average(arr, SIZE, 0, 0) << "\n\n\n";
}

int Average(int arr[], int SIZE, int sum, int i) //Calculate array average
{
	if (i == SIZE)
	{
		return sum / SIZE;
	}
	sum += arr[i];
	
	Average(arr, SIZE, sum, ++i);
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

void GenerateArray(int arr[], int SIZE, int i) // Generate array
{
	if (i == SIZE)
	{
		return;
	}
	arr[i] = rand() % 10;
	
	GenerateArray(arr, SIZE, ++i);
}