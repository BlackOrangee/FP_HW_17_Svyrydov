// Task 1. Write a function that takes two dates (that is, the function takes six parameters) 
// and calculates the difference in days between those dates. To accomplish this task, 
// you must also write a function that determines whether a year is a leap year.
//

#include <iostream>
using namespace std;

int DataDays(int months[], int SIZE_MONTHS, int month, int data_days, int day, int i);
void LeapYears(int leap[], int SIZE_LEAP, int year_1, int year_2, int month_1, int month_2, int day_2);

int main()
{
	int day_1, month_1, year_1, day_2, month_2, year_2, first_data_days = 0, second_data_days = 0;

	const int SIZE_MONTHS = 12;
	int months[SIZE_MONTHS] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

	cout << "\n\tEnter the first date\n\n\tDay: "; cin >> day_1;
	cout << "\n\tMonth: ";	cin >> month_1;
	cout << "\n\tYear: ";	cin >> year_1;

	cout << "\n\tEnter the second date\n\n\tDay: "; cin >> day_2;
	cout << "\n\tMonth: ";	cin >> month_2;
	cout << "\n\tYear: ";	cin >> year_2;

	//Swap dates if it need
	if ((year_1 > year_2) || ((year_1 == year_2) && (month_1 > month_2)) || ((year_1 == year_2) && (month_1 == month_2) && (day_1 > day_2)))
	{
		swap(day_1, day_2);
		swap(month_1, month_2);
		swap(year_1, year_2);
	}

	const int SIZE_LEAP = 2;
	int leap[SIZE_LEAP] = {year_1, 0 };

	//Calculate how many high years were in a given interval
	LeapYears(leap, SIZE_LEAP, year_1, year_2, month_1, month_2, day_2);

	//Calculate how many days have passed in a year before the start date
	first_data_days = DataDays(months, SIZE_MONTHS, month_1, first_data_days, day_1, 0);

	//Calculate how many days have passed in a year until the end date
	second_data_days = DataDays(months, SIZE_MONTHS, month_2, second_data_days, day_2, 0);

	if (year_1 == year_2)
	{
		cout << "\n\n\tDays between dates: " << (second_data_days - first_data_days) + leap[1] << endl;
	}
	else
	{
		cout << "\n\n\tDays between dates: " << (year_2 - year_1) * 365 + ((second_data_days - first_data_days) + leap[1]) << endl;
		cout << "\n\tLeap Years: " << leap[1] << endl;
	}
}

int DataDays(int months[], int SIZE_MONTHS, int month, int data_days, int day, int i)
{
	if (i == month)
	{
		return data_days += day;
	}
	data_days += months[i];
	DataDays(months, SIZE_MONTHS, month, data_days, day, ++i);
}

void LeapYears(int leap[], int SIZE_LEAP, int year_1, int year_2, int month_1, int month_2, int day_2)
{
	if (leap[0] > year_2)
	{
		leap[0]--;
		//If the start date of a leap year is greater than February 29, then subtract 1 from the number of leap years
		if ((year_1 % 4 == 0 && leap[0] % 100 != 0 || leap[0] % 400 == 0) && month_1 > 2)
		{
			leap[1] = leap[1] - 1;
		}
		//If the end date is before February 29, then subtract 1 from high years
		if ((year_2 % 4 == 0 && leap[0] % 100 != 0 || leap[0] % 400 == 0) && day_2 <= 29 && month_2 < 3)
		{
			leap[1] = leap[1] - 1;
		}
		return;
	}
	if (leap[0] % 4 == 0 && leap[0] % 100 != 0 || leap[0] % 400 == 0)
	{
		leap[1] = leap[1] + 1;
	}
	leap[0]++;
	LeapYears(leap, SIZE_LEAP, year_1, year_2, month_1, month_2, day_2);
}