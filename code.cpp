#include<iostream>
#include<string>
#include<ctime>

using namespace std;

class post
{
public:
	string dateTime;
	string content;
	post* next;
};

class friendNode
{
	struct Friend
	{
		string relationshipType;
		string status;
	};

public:
	string friendName;
	Friend relation;
	friendNode* next;
};

class message
{
public:
	string content;
	string timestamp;
	message* next;
};

class notification
{
public:
	string content;
	notification* next;
};

class friendRequest
{
public:
	string fromUser;
	friendRequest* next;
};

class user
{
public:
	string name;
	string password;
	string city;
	post* posts;
	string lastLogin;
	friendNode* friends;
	notification* notifications;
	friendRequest* friendRequests;
	user* next;
};

class bstNode
{
public:
	string username;
	user* users;
	bstNode* left;
	bstNode* right;
};

int main() 
{

	system("pause");
	return 0;
}