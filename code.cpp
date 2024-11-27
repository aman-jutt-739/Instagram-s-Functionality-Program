#include<iostream>
#include<string>
using namespace std;
struct userPost{
	string date;
	string time;
	string content;
};
class userNode {
public:
	string name;
	string password;
	string city;
	userNode* next;
	userNode(string name, string password, string city) {
		this->name = name;
		this->city = city;
		this->password = password;
		next = nullptr;
	}
};
class userList {
	userNode* head, * temp, * temp2;
public:
	userList() {
		head = nullptr;
		temp = nullptr;
		temp2 = nullptr;
	}
	void insertUserAtEnd(string name, string password, string city) //O(n)
	{
		userNode* n = new userNode(name,password,city);
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
	void insertUserAtBeginning(string name, string password, string city) // O(1)
	{
		userNode* n = new userNode(name, password, city);
		n->next = head;
		head = n;
	}
	void insertuserNodeAtMiddle(string name, string password, string city, string keyName) //O(n)
	{
		userNode* n = new userNode(name, password, city);
		temp = head;
		while (temp != nullptr) {
			if (temp->name == keyName) {
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
	bool deleteFirstUser() // O(1)
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
	bool deleteUserNode(string keyName) // O(n)
	{
		temp = head;
		if (head == nullptr) {
			return false;
		}
		if (temp->name == keyName) {
			temp2 = temp;
			head = temp->next;
		}
		else {
			while (temp->next != nullptr) {
				if (temp->next->name == keyName) {
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
	bool deleteLastUser() // O(n)
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
	void display() // O(n)
	{
		temp = head;
		if (head != nullptr) {
			while (temp != nullptr) {
				cout << temp->name << " ";
				cout << temp->city << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		else {
			cout << "No Elements" << endl;
		}
	}
	~userList()
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
	
	system("pause");
	return 0;
}