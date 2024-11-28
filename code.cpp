#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class post
{
public:
    string dateTime;
    string content;
    post* next;
};
class notification
{
public:
    string content;
    notification* next;

    notification(string msg, notification* notifications)
    {
        content = msg;
        next = notifications;
    }
};
class user {
public:
    string name;
    string password;
    string city;
    post* posts;
    string lastLogin;
    notification* notifications;
    user* left;
    user* right;
    user(string name, string password, string city, string login) {
        this->name = name;
        this->password = password;
        this->city = city;
        this->lastLogin = login;
        left = nullptr;
        right = nullptr;
        notifications = nullptr;
        posts = nullptr;
    }
};
class friendNode {
public:
    user* users;
    friendNode* next;
    string relationship;
    string status;
    friendNode(user* users) {
        this->users = users;
        next = nullptr;
    }
};
class graph {
public:
    int vertexSize;
    int currentSize;
    friendNode** friends;
    graph(int size) {
        this->vertexSize = size;
        friends = new friendNode * [vertexSize];
        for (int i = 0; i < vertexSize; i++) {
            friends[i] = nullptr;
        }
        currentSize = 0;
    }
    int index(user* uNode) {
        for (int i = 0; i < currentSize; i++) {
            if (uNode->name == friends[i]->users->name) {
                return i;
            }
        }
        return -1;
    }
    void addVertex(user* uNode) {
        friends[currentSize] = new friendNode(uNode);
        currentSize++;
    }
    void sendFriendRequest(user* userA, user* userB) {
        int first = index(userA);
        int second = index(userB);
        if (first == -1 || second == -1) {
            cout << "Error" << endl;
            return;
        }
        friendNode* fNode = new friendNode(friends[second]->users);
        fNode->next = friends[first]->next;
        friends[first]->next = fNode;
        fNode->relationship = "Request Send";
        fNode->status = "Pending";
    }
    void makeFriends(user* userA, user* userB) {
        int first = index(userA);
        int second = index(userB);
        friendNode* temp = friends[first];
        while (temp != nullptr) {
            if (temp->users->name == friends[second]->users->name) {
                temp->relationship = "Friend";
                temp->status = "Active";
                return;
            }
            temp = temp->next;
        }
    }
    void block(user* userA, user* userB) {
        int first = index(userA);
        int second = index(userB);
        friendNode* temp = friends[first];
        while (temp != nullptr) {
            if (temp->users->name == friends[second]->users->name) {
                temp->relationship = "Not Friend";
                temp->status = "Blocked";
                return;
            }
            temp = temp->next;
        }
    }
};
class userManager {
public:
    user* users;
    userManager() {
        users = nullptr;
    }
    user* insertion(user*& users, string name, string city, string password) {
        if (users == nullptr) {
            users = new user(name, city, password, "");
        }
        else if (name < users->name) {
            users->left = insertion(users->left, name, city, password);
        }
        else if (name > users->name) {
            users->right = insertion(users->right, name, city, password);
        }
        return users;
    }
    user* searchUser(user*& users, string keyName) {
        if (users == nullptr) {
            return nullptr;
        }
        else if (keyName < users->name) {
            return searchUser(users->left, keyName);
        }
        else if (keyName > users->name) {
            return searchUser(users->right, keyName);
        }
        else {
            return users;
        }
    }
    bool signup(string name, string password, string city) {
        if (searchUser(users, name)) {
            cout << "The UserName already Exist" << endl;
            return false;
        }
        if (password.length() < 6) {
            cout << "Password should be atleast 6 characters long" << endl;
            return false;
        }
        insertion(users, name, password, city);
        cout << "Signed Up successfully" << endl;
        return true;
    }
    user* login(string name, string password) {
        user* tempUser = searchUser(users, name);
        if (!tempUser) {
            cout << "The user doesnot Exist" << endl;
            return nullptr;
        }
        if (tempUser->password != password) {
            cout << "Wrong Password" << endl;
            return nullptr;
        }
        time_t now = time(0);
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &now);
        tempUser->lastLogin = buffer;
        cout << "Welcome, " << name << "!" << endl;
        return tempUser;
    }
    void inorderTraversal(user* users) {
        if (users == nullptr) {
            return;
        }
        inorderTraversal(users->left);
        cout << users->name << endl;
        inorderTraversal(users->right);
    }
};
int main() {
    userManager UserManager;

    int choice;
    user* currentUser = nullptr;

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
        string name, password, city;
        switch (choice)
        {
        case 0:

            cout << "Goodbye!\n";
            break;


        case 1:


            cout << "Enter username: ";
            cin >> name;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter city: ";
            cin >> city;
            UserManager.signup(name, password, city);
            break;


        case 2:

            /* string name, password;*/
            cout << "Enter username: ";
            cin >> name;
            cout << "Enter password: ";
            cin >> password;
            currentUser = UserManager.login(name, password);
            break;
        case 3:
            if (currentUser) {
                UserManager.inorderTraversal(UserManager.users);
            }
            else {
                cout << "User Doesnot Exist" << endl;
            }
        default:
            break;
        }
    } while (choice != -1);

    system("pause");
    return 0;
}





















//#include<iostream>
//#include<string>
//#include<ctime>
//
//using namespace std;
//
//class post
//{
//public:
//    string dateTime;
//    string content;
//    post* next;
//};
//
//class friendNode
//{
//    struct Friend
//    {
//        string relationshipType;
//        string status;
//    };
//
//public:
//    string friendName;
//    Friend relation;
//    friendNode* next;
//
//    friendNode(string name, string type, string status, friendNode* ptr)
//    {
//        friendName = name;
//        relation.relationshipType = type;
//        relation.status = status;
//        next = ptr;
//    }
//};
//
//class message
//{
//public:
//    string content;
//    string timestamp;
//    message* next;
//};
//
//class notification
//{
//public:
//    string content;
//    notification* next;
//
//    notification(string msg, notification* notifications)
//    {
//        content = msg;
//        next = notifications;
//    }
//};
//
//class friendRequest
//{
//public:
//    string fromUser;
//    friendRequest* next;
//
//    friendRequest(string name, friendRequest* toUser)
//    {
//        fromUser = name;
//        next = toUser;
//    }
//};
//
//class user
//{
//public:
//    string name;
//    string password;
//    string city;
//    post* posts;
//    string lastLogin;
//    friendNode* friends;
//    notification* notifications;
//    friendRequest* friendRequests;
//    user* next;
//
//    user(string name, string password, string city, string login, user* users)
//    {
//        this->name = name;
//        this->password = password;
//        this->city = city;
//        this->lastLogin = login;
//        next = users;
//
//        posts = nullptr;
//        friends = nullptr;
//        notifications = nullptr;
//        friendRequests = nullptr;
//    }
//};
//
//class bstNode
//{
//public:
//    string username;
//    user* users;
//    bstNode* left;
//    bstNode* right;
//
//    bstNode(string name, user* User)
//    {
//        username = name;
//        users = User;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//
//class userNode
//{
//public:
//    string username;
//    friendNode* friendList;
//    userNode* next;
//
//    userNode(string name, friendNode* ptr1, userNode* ptr2)
//    {
//        username = name;
//        friendList = ptr1;
//        next = ptr2;
//    }
//};
//
//class userSearch
//{
//public:
//    bstNode* root;
//
//    userSearch()
//    {
//        root = nullptr;
//    }
//
//    bstNode* insert(bstNode* root, string userName, user* User)
//    {
//        if (!root)
//        {
//            root = new bstNode(userName, User);
//        }
//
//        else if (userName < root->username)
//        {
//            root->left = insert(root->left, userName, User);
//        }
//
//        else if (userName > root->username)
//        {
//            root->right = insert(root->right, userName, User);
//        }
//
//        else
//        {
//            cout << "Username should be unique! \n";
//        }
//
//        return root;
//    }
//
//    user* searchUser(bstNode* root, string userName)
//    {
//        if (!root)
//        {
//            return nullptr;
//        }
//
//        else if (root->username == userName)
//        {
//            return root->users;
//        }
//
//        else if (userName < root->username)
//        {
//            return searchUser(root->left, userName);
//        }
//
//        else
//        {
//            return searchUser(root->right, userName);
//        }
//    }
//
//    void inOrderTraversal(bstNode* root)
//    {
//        if (root)
//        {
//            inOrderTraversal(root->left);
//            cout << root->username << endl;
//            inOrderTraversal(root->right);
//        }
//    }
//};
//
//class graph
//{
//public:
//    userNode* head;
//
//    graph()
//    {
//        head = nullptr;
//    }
//
//    void addFollower(string username, string followerName)
//    {
//        userNode* user = findOrCreateUser(username);
//        friendNode* newFollower = new friendNode(followerName, "Following", "Active", user->friendList);
//        user->friendList = newFollower;
//    }
//
//    friendNode* getFriends(string username)
//    {
//        userNode* user = findUser(username);
//        if (user)
//        {
//            return user->friendList;
//        }
//        return nullptr;
//    }
//
//    void addFriend(string username, string friendName)
//    {
//        userNode* user = findOrCreateUser(username);
//        friendNode* newFriend = new friendNode(friendName, "Friend", "Active", user->friendList);
//        user->friendList = newFriend;
//    }
//
//    userNode* findUser(string username)
//    {
//        userNode* temp = head;
//        while (temp && temp->username != username)
//        {
//            temp = temp->next;
//        }
//        return temp;
//    }
//
//    userNode* findOrCreateUser(string username)
//    {
//        userNode* user = findUser(username);
//        if (!user)
//        {
//            user = new userNode(username, nullptr, head);
//            head = user;
//        }
//        return user;
//    }
//};
//
//class userManager
//{
//public:
//    user* users;
//    userSearch searchTree;
//    graph friendGraph;
//
//    userManager()
//    {
//        users = nullptr;
//    }
//
//
//    void signup(string name, string password, string city)
//    {
//        if (searchTree.searchUser(searchTree.root, name))
//        {
//            cout << "Username already exists. Try another one.\n";
//            return;
//        }
//        if (password.length() < 6)
//        {
//            cout << "Password must be at least 6 characters long.\n";
//            return;
//        }
//
//        user* newUser = new user(name, password, city, "", users);
//        users = newUser;
//        searchTree.root = searchTree.insert(searchTree.root, name, newUser);
//        cout << "User " << name << " signed up successfully!\n";
//    }
//
//    user* login(string name, string password)
//    {
//        user* User = searchTree.searchUser(searchTree.root, name);
//        if (!User)
//        {
//            cout << "Invalid username.\n";
//            return nullptr;
//        }
//
//        if (User->password != password)
//        {
//            cout << "Invalid password.\n";
//            return nullptr;
//        }
//
//        time_t now = time(0);
//        char buffer[26];
//        ctime_s(buffer, sizeof(buffer), &now);
//        User->lastLogin = buffer;
//        cout << "Welcome, " << name << "!\n";
//        return User;
//    }
//
//    void resetPassword(string name, string securityAnswer)
//    {
//        user* User = searchTree.searchUser(searchTree.root, name);
//        if (!User)
//        {
//            cout << "Invalid username.\n";
//            return;
//        }
//
//        string newPassword;
//        cout << "Enter new password: ";
//        cin >> newPassword;
//        while (newPassword.length() < 6)
//        {
//            cout << "Password must be 6 digits long: ";
//            cin >> newPassword;
//        }
//        User->password = newPassword;
//        cout << "Password reset successfully!\n";
//    }
//
//    void addPost(user* User, string content)
//    {
//        time_t now = time(0);
//        char buffer[26];
//        ctime_s(buffer, sizeof(buffer), &now);
//        post* newPost = new post{ buffer, content, User->posts };
//        User->posts = newPost;
//    }
//
//    void viewTimeline(user* User)
//    {
//        post* Post = User->posts;
//        if (!Post)
//        {
//            cout << "No posts to show.\n";
//            return;
//        }
//
//        cout << "Your Timeline:\n";
//        while (Post)
//        {
//            cout << "[" << Post->dateTime << "] " << Post->content << "\n";
//            Post = Post->next;
//        }
//    }
//
//    void sendFriendRequest(user* fromUser, user* toUser)
//    {
//        friendRequest* newRequest = new friendRequest(fromUser->name, toUser->friendRequests);
//        toUser->friendRequests = newRequest;
//
//        notification* newNotification = new notification(fromUser->name + " sent you a friend request.", toUser->notifications);
//        toUser->notifications = newNotification;
//
//        cout << "Friend request sent. \n";
//    }
//
//    void acceptFriendRequest(user* currentUser, user* friendUser)
//    {
//        friendRequest* prev = nullptr;
//        friendRequest* request = currentUser->friendRequests;
//
//        while (request)
//        {
//            if (request->fromUser == friendUser->name)
//            {
//                if (prev)
//                {
//                    prev->next = request->next;
//                }
//                else
//                {
//                    currentUser->friendRequests = request->next;
//                }
//                delete request;
//                break;
//            }
//            prev = request;
//            request = request->next;
//        }
//
//        friendNode* newFollower = new friendNode(currentUser->name, "Following", "Active", friendUser->friends);
//        friendUser->friends = newFollower;
//
//
//        notification* newNotification = new notification(currentUser->name + " accepted your friend request.", friendUser->notifications);
//        friendUser->notifications = newNotification;
//
//        friendGraph.addFollower(currentUser->name, friendUser->name);
//
//        cout << "Friend request accepted.\n";
//    }
//
//    void viewNotifications(user* currentUser)
//    {
//        if (!currentUser->notifications)
//        {
//            cout << "No notifications.\n";
//            return;
//        }
//
//        cout << "Notifications:\n";
//        notification* temp = currentUser->notifications;
//        while (temp)
//        {
//            cout << "- " << temp->content << "\n";
//            temp = temp->next;
//        }
//    }
//
//    void viewFriendRequests(user* currentUser)
//    {
//        if (!currentUser->friendRequests)
//        {
//            cout << "No friend requests.\n";
//            return;
//        }
//
//        cout << "Friend Requests:\n";
//        friendRequest* temp = currentUser->friendRequests;
//        while (temp)
//        {
//            cout << "- From: " << temp->fromUser << "\n";
//            temp = temp->next;
//        }
//    }
//
//    void viewFollowers(user* currentUser)
//    {
//        if (!currentUser)
//        {
//            cout << "Please log in first.\n";
//            return;
//        }
//
//        friendNode* friends = friendGraph.getFriends(currentUser->name);
//        if (!friends)
//        {
//            cout << "You have no followers yet.\n";
//            return;
//        }
//
//        cout << "Your Followers:\n";
//        while (friends)
//        {
//            cout << "- " << friends->friendName << "\n";
//            friends = friends->next;
//        }
//    }
//};
//
//int main()
//{
//    userManager UserManager;
//
//    int choice;
//    user* currentUser = nullptr;
//
//    do
//    {
//        cout << "\n--- Mini Instagram ---\n";
//        cout << "1. Signup\n";
//        cout << "2. Login\n";
//        cout << "3. Reset Password\n";
//        cout << "4. Send Friend Request\n";
//        cout << "5. View Notifications\n";
//        cout << "6. Post Content\n";
//        cout << "7. View Timeline\n";
//        cout << "8. View Friend Requests\n";
//        cout << "9. Accept Friend Request\n";
//        cout << "10. View Followers\n";
//        cout << "11. Search Users\n";
//        cout << "12. Logout\n";
//        cout << "0. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 0:
//        {
//            cout << "Goodbye!\n";
//            break;
//        }
//
//        case 1:
//        {
//            string name, password, city;
//            cout << "Enter username: ";
//            cin >> name;
//            cout << "Enter password: ";
//            cin >> password;
//            cout << "Enter city: ";
//            cin >> city;
//            UserManager.signup(name, password, city);
//            break;
//        }
//
//        case 2:
//        {
//            string name, password;
//            cout << "Enter username: ";
//            cin >> name;
//            cout << "Enter password: ";
//            cin >> password;
//            currentUser = UserManager.login(name, password);
//            break;
//        }
//
//        case 3:
//        {
//            string name, answer;
//            cout << "Enter username: ";
//            cin >> name;
//            cout << "Enter security answer: ";
//            cin >> answer;
//            UserManager.resetPassword(name, answer);
//            break;
//        }
//
//        case 4:
//        {
//            if (!currentUser)
//            {
//                cout << "Please log in first.\n";
//                continue;
//            }
//            string friendName;
//            cout << "Enter username to send friend request: ";
//            cin >> friendName;
//            user* friendUser = UserManager.searchTree.searchUser(UserManager.searchTree.root, friendName);
//            if (!friendUser)
//            {
//                cout << "User not found.\n";
//                continue;
//            }
//            UserManager.sendFriendRequest(currentUser, friendUser);
//            break;
//        }
//
//        case 5:
//        {
//            UserManager.viewNotifications(currentUser);
//            break;
//        }
//
//        case 6:
//        {
//            if (!currentUser)
//            {
//                cout << "Please log in first.\n";
//                continue;
//            }
//            string content;
//            cin.ignore();
//            cout << "Enter post content: ";
//            getline(cin, content);
//            UserManager.addPost(currentUser, content);
//            break;
//        }
//
//        case 7:
//        {
//            if (!currentUser)
//            {
//                cout << "Please log in first.\n";
//                continue;
//            }
//            UserManager.viewTimeline(currentUser);
//            break;
//        }
//
//        case 8:
//        {
//            if (!currentUser)
//            {
//                cout << "Please log in first.\n";
//                continue;
//            }
//            UserManager.viewFriendRequests(currentUser);
//            break;
//        }
//
//        case 9:
//        {
//            if (!currentUser)
//            {
//                cout << "Please log in first.\n";
//                continue;
//            }
//            string friendName;
//            cout << "Enter username to accept friend request: ";
//            cin >> friendName;
//            user* friendUser = UserManager.searchTree.searchUser(UserManager.searchTree.root, friendName);
//            if (!friendUser)
//            {
//                cout << "User not found.\n";
//                continue;
//            }
//            UserManager.acceptFriendRequest(currentUser, friendUser);
//            break;
//        }
//
//        case 10:
//        {
//            if (!currentUser)
//            {
//                cout << "Please log in first.\n";
//                continue;
//            }
//            UserManager.viewFollowers(currentUser);
//            break;
//        }
//
//        case 11:
//        {
//            string query;
//            cout << "Enter username to search: ";
//            cin >> query;
//            user* foundUser = UserManager.searchTree.searchUser(UserManager.searchTree.root, query);
//
//            if (foundUser)
//            {
//                cout << "User found:\n";
//                cout << "Name: " << foundUser->name << "\n";
//                cout << "City: " << foundUser->city << "\n";
//                cout << "Last Login: " << foundUser->lastLogin << "\n";
//            }
//            else
//            {
//                cout << "User not found.\n";
//            }
//            break;
//        }
//
//        case 12:
//        {
//            currentUser = nullptr;
//            cout << "Logged out successfully.\n";
//            break;
//        }
//
//        default:
//        {
//            cout << "Invalid choice.\n";
//            break;
//        }
//
//        }
//    } while (choice != 0);
//
//    system("pause");
//    return 0;
//}