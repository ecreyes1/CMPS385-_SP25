// CMPS385_Assignment 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
void sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) 
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;

			}

		}
		if (!swapped)
			break;
	}
}
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main() 
{
	int data[] = { 11,18,17,12,64,55,17 };
	int n = sizeof(data) / sizeof(data[0]);

	cout << "Unsorted array: ";
	print(data, n);
	sort(data, n);
	print(data, n);
	system("pause");
	return 0;



}

