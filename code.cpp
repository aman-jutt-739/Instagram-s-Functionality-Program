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

	bstNode(string name, user* User)
	{
		username = name;
		users = User;
		left = nullptr;
		right = nullptr;
	}
};

class userSearch
{
public:
	bstNode* root;

	userSearch()
	{
		root = nullptr;
	}

	bstNode* insert(bstNode* root, string userName, user* User)
	{
		if (!root)
		{
			root = new bstNode(userName, User);
		}

		else if (userName < root->username)
		{
			root->left = insert(root->left, userName, User);
		}

		else if (userName > root->username)
		{
			root->right = insert(root->right, userName, User);
		}

		else
		{
			cout << "Username should be unique! \n";
		}

		return root;
	}

	user* searchUser(bstNode* root, string userName)
	{
		if (!root)
		{
			return nullptr;
		}

		else if (root->username == userName)
		{
			return root->users;
		}

		else if (userName < root->username)
		{
			return searchUser(root->left, userName);
		}

		else
		{
			return searchUser(root->right, userName);
		}
	}

	void inOrderTraversal(bstNode* root)
	{
		if (root)
		{
			inOrderTraversal(root->left);
			cout << root->username << endl;
			inOrderTraversal(root->right);
		}
	}
};

int main() 
{
    //UserManager userManager;

    int choice;
    //User* currentUser = nullptr;

    do
    {
        cout << "\n--- Mini Instagram ---\n";
        cout << "1. Signup\n";
        cout << "2. Login\n";
        cout << "3. Reset Password\n";
        cout << "4. Send Friend Request\n";
        cout << "5. View Notifications\n";
        cout << "6. Post Content\n";
        cout << "7. View Timeline\n";
        cout << "8. View Friend Requests\n";
        cout << "9. Accept Friend Request\n";
        cout << "10. View Followers\n";
        cout << "11. Search Users\n";
        cout << "12. Logout\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            string name, password, city, answer;
            cout << "Enter username: ";
            cin >> name;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter city: ";
            cin >> city;
            //userManager.signup(name, password, city, answer);
            break;

        case 2:
            string name, password;
            cout << "Enter username: ";
            cin >> name;
            cout << "Enter password: ";
            cin >> password;
            //currentUser = userManager.login(name, password);
            break;

        case 3:
            string name, answer;
            cout << "Enter username: ";
            cin >> name;
            cout << "Enter security answer: ";
            cin >> answer;
            //userManager.resetPassword(name, answer);
            break;

        case 4:
            //if (!currentUser)
        {
            cout << "Please log in first.\n";
            continue;
        }
        string friendName;
        cout << "Enter username to send friend request: ";
        cin >> friendName;
        //User* friendUser = userManager.searchTree.search(userManager.searchTree.root, friendName);
        //if (!friendUser)
        {
            cout << "User not found.\n";
            continue;
        }
        //userManager.sendFriendRequest(currentUser, friendUser);
        break;

        case 5:
            //userManager.viewNotifications(currentUser);
            break;

        case 6:
            //if (!currentUser)
        {
            cout << "Please log in first.\n";
            continue;
        }
        string content;
        cin.ignore();
        cout << "Enter post content: ";
        getline(cin, content);
        //userManager.addPost(currentUser, content);
        break;

        case 7:
            //if (!currentUser) 
        {
            cout << "Please log in first.\n";
            continue;
        }
        //userManager.viewTimeline(currentUser);
        break;

        case 8:
            //if (!currentUser) 
        {
            cout << "Please log in first.\n";
            continue;
        }
        //userManager.viewFriendRequests(currentUser);
        break;

        case 9:
            //if (!currentUser) 
        {
            cout << "Please log in first.\n";
            continue;
        }
        string friendName;
        cout << "Enter username to accept friend request: ";
        cin >> friendName;
        //User* friendUser = userManager.searchTree.search(userManager.searchTree.root, friendName);
        //if (!friendUser) 
        {
            cout << "User not found.\n";
            continue;
        }
        //userManager.acceptFriendRequest(currentUser, friendUser);
        break;

        case 10:
            //if (!currentUser) 
        {
            cout << "Please log in first.\n";
            continue;
        }
        //userManager.viewFollowers(currentUser);
        break;

        case 11:
            string query;
            cout << "Enter search query: ";
            cin >> query;
            //userManager.searchUsers(query);
            break;

        case 12:
            //currentUser = nullptr;
            cout << "Logged out successfully.\n";
            break;

        case 0:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    }while (choice != 0);

	system("pause");
	return 0;
}