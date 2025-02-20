#include <iostream>
#include <iomanip>

using namespace std;
struct Node {
	int data;
	Node* next;
};

int LinkedlistInsert(int data, int index, Node** head)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = nullptr;
	if (index == 0)
	{
		newNode->next = *head;
		*head = newNode;
		return 1;
	}
	Node* tempUsage = *head;
	for (int i = 0; tempUsage != nullptr && i < index - 1; i++)
	{
		tempUsage = tempUsage->next;
	}
	if (tempUsage == nullptr)
		return 0;
	newNode->next = tempUsage->next;
	tempUsage->next = newNode;
	return 1;

}
int LinkedlistDelete(int index, Node** head) 
{
	if (*head == nullptr)
		return 0;
	Node* tempUsage = *head;
	if (index == 0)
	{
		*head = tempUsage->next;
		delete tempUsage;
		return 1;

	}
	Node* previous = nullptr;
	for (int i = 0; tempUsage != nullptr && i < index; i++)
	{
		previous = tempUsage;
		tempUsage = tempUsage->next;
	}
	if (tempUsage == nullptr) return 0;

	previous->next = tempUsage->next;
	delete tempUsage;
	return 1;  

}

int main() 
{
	Node* head = nullptr;
	LinkedlistInsert(1, 0, &head);
	LinkedlistInsert(2, 1, &head); 
	LinkedlistInsert(3, 2, &head);
	cout << "Linked list after insertions: ";
	while (head != nullptr) {
		cout << head->data << " -> "; 
		head = head->next;
	}
	cout << "NULL" << endl;
	
	LinkedlistDelete(0, &head);
	LinkedlistDelete(1, &head);
	LinkedlistDelete(2, &head);

	cout << "Linked list after deletion: ";
	while (head != nullptr) { 
		cout << head->data << " -> "; 
		head = head->next;
	}
	cout << "NULL" << endl;
	return 0;
}