
#include <iostream>
#include <iomanip>

using namespace std;
struct Node {
	int data;
	Node* next;
};

int DoubleLinkedlistInsert(int data, int index, Node** head)
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
int DoubleLinkedlistDelete(int index, Node** head)
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
void Results(Node* head) {
	while (head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node* head = nullptr;
	DoubleLinkedlistInsert(1, 0, &head);
	DoubleLinkedlistInsert(2, 1, &head);
	DoubleLinkedlistInsert(3, 2, &head);
	cout << "Double Linked list after insertions: ";
	Results( head);
	DoubleLinkedlistDelete(1, &head);

	
	cout << "Double Linked list after deletion: ";
	Results(head);
    cout << endl;
}