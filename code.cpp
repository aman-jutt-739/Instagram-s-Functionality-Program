#include<iostream>
#include<string>
using namespace std;
class node {
public:
	int data;
	node* next;

};
class LinkedList {
	node* head, * temp, * temp2;
public:
	LinkedList() {
		head = nullptr;
		temp = nullptr;
		temp2 = nullptr;
	}
	void insertNodeAtEnd(int data) //O(n)
	{
		node* n = new node;
		n->data = data;
		n->next = nullptr;
		if (head == nullptr) {
			head = n;
		}
		else {
			temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = n;
		}
	}
	void insertNodeAtBeginning(int data) // O(1)
	{
		node* n = new node;
		n->data = data;
		n->next = head;
		head = n;
	}
	void insertNodeAtMiddle(int data, int key) //O(n)
	{
		node* n = new node;
		n->data = data;
		temp = head;
		while (temp != nullptr) {
			if (temp->data == key) {
				temp2 = temp;
				break;
			}
			temp = temp->next;
			if (temp == nullptr) {
				cout << "Not Found" << endl;
				return;
			}
		}
		n->next = temp2->next;
		temp2->next = n;
	}
	bool deleteFirstNode() // O(1)
	{
		if (head == nullptr) {
			return false;
		}
		temp = head;
		head = temp->next;
		delete temp;
		temp = nullptr;
		return true;
	}
	bool deleteNode(int data) // O(n)
	{
		temp = head;
		if (head == nullptr) {
			return false;
		}
		if (temp->data == data) {
			temp2 = temp;
			head = temp->next;
		}
		else {
			while (temp->next != nullptr) {
				if (temp->next->data == data) {
					break;
				}
				temp = temp->next;
			}
			if (temp->next == nullptr) {
				return false;
			}
			else {
				temp2 = temp->next;
				if (temp->next->next == nullptr) {
					temp->next = nullptr;
				}
				else {
					temp->next = temp->next->next;
				}
			}
		}
		delete temp2;
		temp2 = nullptr;
		return true;
	}
	bool deleteLastNode() // O(n)
	{
		if (head == nullptr) {
			return false;
		}
		temp = head;
		if (temp->next == nullptr) {
			temp2 = temp;
			head = nullptr;
		}
		else {
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			temp2 = temp->next;
			temp->next = nullptr;
		}
		delete temp2;
		temp2 = nullptr;
		return true;

	}
	bool search(int data) //O(n)
	{
		temp = head;
		if (head == nullptr) {
			cout << "Not Found" << endl;
			return false;
		}
		while (temp != nullptr) {
			if (temp->data == data) {
				cout << "Found" << endl;
				return true;
			}
			temp = temp->next;
		}
		cout << "Not Found" << endl;
		return false;
	}
	void display() // O(n)
	{
		temp = head;
		if (head != nullptr) {
			while (temp != nullptr) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		else {
			cout << "No Elements" << endl;
		}
	}
	~LinkedList()
	{
		temp = head;
		while (temp != nullptr) {
			temp2 = temp;
			temp = temp->next;
			delete temp2;
			temp2 = nullptr;
		}
		temp = nullptr;
	}
};





int main() {
	cout << "Hello world";
	system("pause");
	return 0;
}