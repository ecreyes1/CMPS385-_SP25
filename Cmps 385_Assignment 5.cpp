// Cmps 385_Assignment 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class minHeap {
private:
	vector<int>heap;
	void heapUpInsert(int i)
	{
		while (i > 0)
		{
			int parent = (i - 1) / 2;
			if (heap[i] < heap[parent]) {
				swap(heap[i], heap[parent]);
				i = parent;
			}
			else { break; }
		}

	}
	void heapDownRemove(int i) {
		int size = heap.size();
		while (true) {
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			int smallest = i;
			if (left < size && heap[left] < heap[smallest])
				smallest = left;
			if (right < size && heap[right] < heap[smallest])
				smallest = right;

			if (smallest == i)
				break;
			swap(heap[i], heap[smallest]);
			i = smallest;

		}
	}
public:
	void insert(int value) 
	{
		heap.push_back(value);
		heapUpInsert(heap.size() - 1);
	}
		void removeRoot()
		{
			if (heap.empty()) return;
			heap[0] = heap.back();
			heap.pop_back();
			heapDownRemove(0);
		}
		void printTree() {
			for (int val : heap)
				cout << val <<endl;
			cout << endl;
	}





};
int main() {
	minHeap minHeap;

	minHeap.insert(1);
	minHeap.insert(3);
	minHeap.insert(5);
	minHeap.insert(7);
	minHeap.insert(9);

	cout << "Heap tree after insertions: ";
	minHeap.printTree();

	minHeap.removeRoot();
	cout << "Heap tree after removing root: ";
	minHeap.printTree();

	return 0;
}
