// CMPS 368_Assignment 12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
using namespace std;
int binarySearch(int array[],int size, int target)
{
	int left = 0;
	int right = size - 1;

	while (left <= right) {

		int mid = left + (right - left) / 2;
		if (array[mid] == target)
			return(mid);
		else if (array[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
void displayArray(int array[]) 
{
	cout << "Array: " << endl;
	for (int i = 0; i < sizeof(array)-1; i++)
	{

		cout << array[i] << ", ";
	}
	cout << endl;
}
int main() {
	int array[] = { 11,2,27,18,5,21,42 };
	displayArray(array);
int size = sizeof(array) / sizeof(array[0]);
int target = 18;
cout << "Target: " << target << endl;

int result = binarySearch(array, size, target);
if (result != -1)
cout << "Target found at index " << result << endl;
else
cout << "target not found  " << result << endl;


system("pause");
return 0;


}

