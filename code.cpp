#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class user;
class friendRequestList;
class friendList;
class postNode
{
public:
    string dateTime;
    string content;
    postNode* next;
    postNode(string dateTime, string content) {
        this->dateTime = dateTime;
        this->content = content;
        next = nullptr;
    }
};
class postList {
public:
    postNode* top;
    postList() {
        top = nullptr;
    }
    bool isempty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }
    void push(string dateTime, string content) {

        postNode* n = new postNode(dateTime, content);
        n->next = top;
        top = n;

    }
    void pop(string dateTime, string content) {
        if (!isempty()) {
            postNode* temp = top;
            string data = temp->content;
            content = data;
            data = temp->dateTime;
            dateTime = data;
            top = top->next;
            delete temp;
            temp = nullptr;

        }
        else {
            cout << "Node is empty" << endl;
        }
    }

};
class notificationNode
{
public:
    string content;
    notificationNode* next;

    notificationNode(string msg)
    {
        content = msg;
        next = nullptr;
    }
};
class notificationsList {
public:
    notificationNode* top;
    notificationsList() {
        top = nullptr;
    }
    bool isempty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }
    void push(string content) {

        notificationNode* n = new notificationNode(content);
        n->next = top;
        top = n;

    }
    void pop(string content) {
        if (!isempty()) {
            notificationNode* temp = top;
            string data = temp->content;
            content = data;
            top = top->next;
            delete temp;
            temp = nullptr;

        }
        else {
            cout << "Node is empty" << endl;
        }
    }

};

class friendNode {
public:
    user* friendUser;
    friendNode* next;
    friendNode(user* friendUser) {
        this->friendUser = friendUser;
        next = nullptr;
    }

};






class requestsNode {
public:
    user* requestUser;
    requestsNode* next;
    requestsNode(user* requestUser) {
        this->requestUser = requestUser;
        next = nullptr;
    }
};
class friendRequestsList {

public:
    requestsNode* front;
    requestsNode* rear;
    int numPeople;
    friendRequestsList() {
        front = nullptr;
        rear = nullptr;
        numPeople = 0;
    }
    bool isEmpty() {
        if (numPeople == 0) {
            return true;
        }
        return false;
    }
    void enquene(user* requestUser) {
        requestsNode* n = new requestsNode(requestUser);
        if (isEmpty()) {
            front = n;
            rear = n;
            rear->next = nullptr;
        }
        else {
            rear->next = n;
            rear = n;
        }
        numPeople++;
    }
    void dequene(user*& requestUser) {
        if (!isEmpty()) {
            requestsNode* temp = front;
            requestUser = front->requestUser;
            front = front->next;
            delete temp;
            temp = nullptr;
            numPeople--;
        }
        else {
            cout << "Quene is Empty" << endl;
        }
    }
    ~friendRequestsList()
    {
        requestsNode* temp = front;
        requestsNode* temp2;
        while (temp != rear->next) {
            temp2 = temp;
            temp = temp->next;
            delete temp2;
            temp2 = nullptr;
        }
        numPeople = 0;
    }
};





class relationNode {
public:
    user* users;
    relationNode* next;
    string relationship;
    string status;
    relationNode(user* users) {
        this->users = users;
        next = nullptr;
    }
};
class user {
public:
    string name;
    string password;
    string city;
    friendRequestsList* frList;
    friendList* fList;
    postList* pList;
    string lastLogin;
    notificationsList* nList;
    user* left;
    user* right;
    user(string name, string password, string city, string login) {
        this->name = name;
        this->password = password;
        this->city = city;
        this->lastLogin = login;
        /*   frList = new friendRequestsList;
           fList = new friendList;*/
        left = nullptr;
        right = nullptr;
        nList = nullptr;
        pList = nullptr;
    }
};
class friendList {
public:
    friendNode* head, * temp, * temp2;
    friendList() {
        head = nullptr;
        temp = nullptr;
        temp2 = nullptr;
    }
    void insertNodeAtEnd(user* friendUser) //O(n)
    {
        friendNode* n = new friendNode(friendUser);
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
    bool deleteNode(user* friendUser) // O(n)
    {
        temp = head;
        if (head == nullptr) {
            return false;
        }
        if (temp->friendUser == friendUser) {
            temp2 = temp;
            head = temp->next;
        }
        else {
            while (temp->next != nullptr) {
                if (temp->next->friendUser == friendUser) {
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
    //bool search(int data) //O(n)
    //{
    //    temp = head;
    //    if (head == nullptr) {
    //        cout << "Not Found" << endl;
    //        return false;
    //    }
    //    while (temp != nullptr) {
    //        if (temp->data == data) {
    //            cout << "Found" << endl;
    //            return true;
    //        }
    //        temp = temp->next;
    //    }
    //    cout << "Not Found" << endl;
    //    return false;
    //}
    void display() // O(n)
    {
        temp = head;
        if (head != nullptr) {
            while (temp != nullptr) {
                cout << temp->friendUser->name << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else {
            cout << "No Elements" << endl;
        }
    }
    ~friendList()
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


class graph {
public:
    int vertexSize;
    int currentSize;
    relationNode** friends;
    graph(int size) {
        this->vertexSize = size;
        friends = new relationNode * [vertexSize];
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
        friends[currentSize] = new relationNode(uNode);
        currentSize++;
    }
    bool sendFriendRequest(user* userA, user* userB) {
        int first = index(userA);
        int second = index(userB);
        if (first == -1 || second == -1) {
            return false;
        }
        relationNode* fNode = new relationNode(friends[second]->users);
        fNode->next = friends[first]->next;
        friends[first]->next = fNode;
        fNode->relationship = "Request Send";
        fNode->status = "Pending";
    }
    void makeFriends(user* userA, user* userB) {
        int first = index(userA);
        int second = index(userB);
        relationNode* temp = friends[first];
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
        relationNode* temp = friends[first];
        while (temp != nullptr) {
            if (temp->users->name == friends[second]->users->name) {
                temp->relationship = "Not Friend";
                temp->status = "Blocked";
                return;
            }
            temp = temp->next;
        }
    }
    void deleteRelation(user* userA, user* userB) {
        int first = index(userA);
        int second = index(userB);
        relationNode* temp = friends[first];
        while (temp->next != nullptr) {
            if (temp->next->users->name == friends[second]->users->name) {
                relationNode* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                temp2 = nullptr;
                return;
            }
            temp = temp->next;
        }
    }
    bool isFriend(user* userA, user* userB) {
        int first = index(userA);
        int second = index(userB);
        relationNode* temp = friends[first];
        while (temp != nullptr) {
            if (temp->users->name == friends[second]->users->name) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

};
class userManager {
public:
    user* users;
    graph* Relations;

    userManager(int userSize) {
        users = nullptr;
        Relations = new graph(userSize);
    }
    user* insertion(user*& users, string name, string city, string password) {
        if (users == nullptr) {
            users = new user(name, city, password, "");
            users->frList = new friendRequestsList;
            users->fList = new friendList;
            users->nList = new notificationsList;
            users->pList = new postList;
        }
        else if (name < users->name) {
            users->left = insertion(users->left, name, city, password);
        }
        else if (name > users->name) {
            users->right = insertion(users->right, name, city, password);
        }
        return users;
    }
    user* searchUser(user* users, string keyName) {
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
        Relations->addVertex(searchUser(users, name));
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
    void sendFriendRequest(user* userA, user* userB) {
        bool successfullySent = Relations->sendFriendRequest(userA, userB);
        if (!successfullySent) {
            cout << "Request Already Sent" << endl;
            return;
        }
        userB->frList->enquene(userA);
        string msg = userA->name + " Sent you a Friend Request";
        userB->nList->push(msg);
        cout << "Friend Request Sent Succesfully" << endl;
    }
    void acceptFriendRequest(user* userA, user* userB) {
        Relations->makeFriends(userA, userB);
        cout << "Friend Request Accepted" << endl;
        userB->frList->dequene(userA);
        userA->fList->insertNodeAtEnd(userB);
        string msg = userB->name + " Accepted Your Friend Request";
        userA->nList->push(msg);
    }
    void cancelFriendRequest(user* userA, user* userB) {
        Relations->deleteRelation(userA, userB);
        cout << "Friend Request Rejected" << endl;
        userB->frList->dequene(userA);
    }
    void unFriend(user* userA, user* userB) {
        Relations->deleteRelation(userA, userB);
        cout << "Friend Removed" << endl;
        userA->fList->deleteNode(userB);
    }
    void blocKFriend(user* userA, user* userB) {
        Relations->block(userA, userB);
        cout << "Friend Blocked" << endl;
    }
    void createPost(user* userA, string content) {
        time_t now = time(0);
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &now);
        userA->pList->push(buffer, content);
        cout << "Posted" << endl;
    }
    void showPosts(user* userA) {
        postNode* temp = userA->pList->top;
        while (temp) {
            cout << "Posted by " << userA->name << " at " << temp->dateTime << endl;
            cout << temp->content << endl;
            temp = temp->next;
        }
    }
    void showTimeline(user* userA) {
        relationNode* temp = Relations->friends[Relations->index(userA)];
        if (temp->next != nullptr) {
            temp = temp->next;
        }
        else {
            return;
        }
        while (temp != nullptr)
        {
            showPosts(temp->users);
            temp = temp->next;
        }
    }

};

int main() {
    int userSize = 100; // Adjust this based on expected users
    userManager manager(userSize); // Initialize user manager with user size
    user* loggedInUser = nullptr;

    int choice;
    do {
        cout << "\n=== Mini Instagram - Menu ===\n";
        cout << "1. Sign Up\n";
        cout << "2. Log In\n";
        cout << "3. Send Friend Request\n";
        cout << "4. Accept Friend Request\n";
        cout << "5. Reject Friend Request\n";
        cout << "6. View Friend List\n";
        cout << "7. View Friend Requests\n";
        cout << "8. Unfriend\n";
        cout << "9. Block Friend\n";
        cout << "10. View Notifications\n";
        cout << "11. Crete a Post\n";
        cout << "12. Show  TimeLine\n";
        cout << "13. Show own Posts\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, password, city;
            cout << "Enter username: ";
            cin >> name;
            cout << "Enter password (at least 6 characters): ";
            cin >> password;
            cout << "Enter city: ";
            cin >> city;
            manager.signup(name, password, city);
            break;
        }
        case 2: {
            string name, password;
            cout << "Enter username: ";
            cin >> name;
            cout << "Enter password: ";
            cin >> password;
            loggedInUser = manager.login(name, password);
            break;
        }
        case 3: {
            if (!loggedInUser) {
                cout << "Please log in first.\n";
                break;
            }
            string friendName;
            cout << "Enter username to send friend request to: ";
            cin >> friendName;
            user* friendUser = manager.searchUser(manager.users, friendName);
            if (friendUser) {
                manager.sendFriendRequest(loggedInUser, friendUser);
            }
            else {
                cout << "User not found.\n";
            }
            break;
        }
        case 4: {
            if (!loggedInUser) {
                cout << "Please log in first.\n";
                break;
            }
            user* sender = nullptr;
            loggedInUser->frList->dequene(sender);
            if (sender) {
                manager.acceptFriendRequest(sender, loggedInUser);
            }
            else {
                cout << "No friend requests to accept.\n";
            }
            break;
        }
        case 5: {
            if (!loggedInUser) {
                cout << "Please log in first.\n";
                break;
            }
            user* sender = nullptr;
            loggedInUser->frList->dequene(sender);
            if (sender) {
                manager.cancelFriendRequest(sender, loggedInUser);
            }
            else {
                cout << "No friend requests to reject.\n";
            }
            break;
        }
        case 6: {
            if (!loggedInUser) {
                cout << "Please log in first.\n";
                break;
            }
            cout << "Your Friends: ";
            loggedInUser->fList->display();
            break;
        }
        case 7: {
            if (!loggedInUser) {
                cout << "Please log in first.\n";
                break;
            }
            cout << "Friend Requests:\n";
            requestsNode* temp = loggedInUser->frList->front;
            while (temp) {
                cout << temp->requestUser->name << endl;
                temp = temp->next;
            }
            break;
        }
        case 8: {
            if (!loggedInUser) {
                cout << "Please log in first.\n";
                break;
            }
            string friendName;
            cout << "Enter username to unfriend: ";
            cin >> friendName;
            user* friendUser = manager.searchUser(manager.users, friendName);
            if (friendUser) {
                manager.unFriend(loggedInUser, friendUser);
            }
            else {
                cout << "User not found.\n";
            }
            break;
        }
        case 9: {
            if (!loggedInUser) {
                cout << "Please log in first.\n";
                break;
            }
            string friendName;
            cout << "Enter username to block: ";
            cin >> friendName;
            user* friendUser = manager.searchUser(manager.users, friendName);
            if (friendUser) {
                manager.blocKFriend(loggedInUser, friendUser);
            }
            else {
                cout << "User not found.\n";
            }
            break;
        }
        case 10: {  // View Notifications
            if (!loggedInUser) {
                cout << "Please log in first.\n";
                break;
            }
            cout << "Notifications:\n";
            notificationNode* temp = loggedInUser->nList->top;
            while (temp) {
                cout << temp->content << endl;
                temp = temp->next;
            }
            break;
        }
        case 11: {
            if (!loggedInUser) {
                cout << "Please log in first.\n";
                break;
            }
            string content;
            cout << "Enter Content: " << endl;
            cin >> content;
            cin.ignore();
            manager.createPost(loggedInUser, content);
            break;
        }
        case 12: {
            if (!loggedInUser) {
                cout << "Please log in first.\n";
                break;
            }
            cout << "Posts" << endl;
            manager.showTimeline(loggedInUser);
            break;
        }
        case 13: {
            if (!loggedInUser) {
                cout << "Please log in first.\n";
                break;
            }
            cout << "Your Posts" << endl;
            manager.showPosts(loggedInUser);
            break;
        }
        case 0:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

//int main() {
//    userManager UserManager(1000);
//    int choice;
//    user* currentUser = nullptr;
//
//    do
//    {
//        cout << "\n--- Mini Instagram ---\n";
//        cout << "1. Signup\n";
//        cout << "2. Login\n";
//        cout << "3. Reset Password\n";
//       /* cout << "4. Send Friend Request\n";
//        cout << "5. View Notifications\n";
//        cout << "6. Post Content\n";
//        cout << "7. View Timeline\n";
//        cout << "8. View Friend Requests\n";
//        cout << "9. Accept Friend Request\n";
//        cout << "10. View Followers\n";
//        cout << "11. Search Users\n";
//        cout << "12. Logout\n";*/
//        cout << "0. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//        string name, password, city;
//        switch (choice)
//        {
//        case 0:
//
//            cout << "Goodbye!\n";
//            break;
//
//
//        case 1:
//
//           
//            cout << "Enter username: ";
//            cin >> name;
//            cout << "Enter password: ";
//            cin >> password;
//            cout << "Enter city: ";
//            cin >> city;
//            UserManager.signup(name, password, city);
//            break;
//
//
//        case 2:
//
//           /* string name, password;*/
//            cout << "Enter username: ";
//            cin >> name;
//            cout << "Enter password: ";
//            cin >> password;
//            currentUser = UserManager.login(name, password);
//            break;
//        case 3:
//            if (currentUser) {
//                UserManager.inorderTraversal(UserManager.users);
//            }
//            else {
//                cout << "User Doesnot Exist" << endl;
//            }
//            break;
//        default:
//            break;
//        }
//    } while (choice != 0 && currentUser == nullptr);
//    if (currentUser != nullptr) {
//        do {
//             //cout << "1. Send Friend Request\n";
//             cout << "2. View Notifications\n";
//             cout << "3. Post Content\n";
//             cout << "4. View Timeline\n";
//             cout << "5. View Friend Requests\n";
//             cout << "6. Accept Friend Request\n";
//             cout << "7. View Followers\n";
//             cout << "8. Search Users\n";
//             cout << "9. Logout\n";
//            cout << "0. Exit\n";
//            cout << "Enter your choice: ";
//            cin >> choice;
//            string name, password, city;
//            switch (choice)
//            {
//            case 0:
//
//                cout << "Goodbye!\n";
//                break;
//
//
//            case 1:
//
//
//                cout << "Enter username: ";
//                cin >> name;
//                cout << "Enter password: ";
//                cin >> password;
//                cout << "Enter city: ";
//                cin >> city;
//                UserManager.signup(name, password, city);
//                break;
//
//
//            case 2:
//
//                /* string name, password;*/
//                cout << "Enter username: ";
//                cin >> name;
//                cout << "Enter password: ";
//                cin >> password;
//                currentUser = UserManager.login(name, password);
//                break;
//            case 3:
//                if (currentUser) {
//                    UserManager.inorderTraversal(UserManager.users);
//                }
//                else {
//                    cout << "User Doesnot Exist" << endl;
//                }
//                break;
//            default:
//                break;
//            }
//        } while (choice != 0);
//    }
//  
//    
//    system("pause");
//    return 0;
//}
// 
// 
// 
// 
// 
// 
////#include<iostream>
////#include<string>
////#include<ctime>
////
////using namespace std;
////
////class post
////{
////public:
////    string dateTime;
////    string content;
////    post* next;
////};
////
////class friendNode
////{
////    struct Friend
////    {
////        string relationshipType;
////        string status;
////    };
////
////public:
////    string friendName;
////    Friend relation;
////    friendNode* next;
////
////    friendNode(string name, string type, string status, friendNode* ptr)
////    {
////        friendName = name;
////        relation.relationshipType = type;
////        relation.status = status;
////        next = ptr;
////    }
////};
////
////class message
////{
////public:
////    string content;
////    string timestamp;
////    message* next;
////};
////
////class notification
////{
////public:
////    string content;
////    notification* next;
////
////    notification(string msg, notification* notifications)
////    {
////        content = msg;
////        next = notifications;
////    }
////};
////
////class friendRequest
////{
////public:
////    string fromUser;
////    friendRequest* next;
////
////    friendRequest(string name, friendRequest* toUser)
////    {
////        fromUser = name;
////        next = toUser;
////    }
////};
////
////class user
////{
////public:
////    string name;
////    string password;
////    string city;
////    post* posts;
////    string lastLogin;
////    friendNode* friends;
////    notification* notifications;
////    friendRequest* friendRequests;
////    user* next;
////
////    user(string name, string password, string city, string login, user* users)
////    {
////        this->name = name;
////        this->password = password;
////        this->city = city;
////        this->lastLogin = login;
////        next = users;
////
////        posts = nullptr;
////        friends = nullptr;
////        notifications = nullptr;
////        friendRequests = nullptr;
////    }
////};
////
////class bstNode
////{
////public:
////    string username;
////    user* users;
////    bstNode* left;
////    bstNode* right;
////
////    bstNode(string name, user* User)
////    {
////        username = name;
////        users = User;
////        left = nullptr;
////        right = nullptr;
////    }
////};
////
////class userNode
////{
////public:
////    string username;
////    friendNode* friendList;
////    userNode* next;
////
////    userNode(string name, friendNode* ptr1, userNode* ptr2)
////    {
////        username = name;
////        friendList = ptr1;
////        next = ptr2;
////    }
////};
////
////class userSearch
////{
////public:
////    bstNode* root;
////
////    userSearch()
////    {
////        root = nullptr;
////    }
////
////    bstNode* insert(bstNode* root, string userName, user* User)
////    {
////        if (!root)
////        {
////            root = new bstNode(userName, User);
////        }
////
////        else if (userName < root->username)
////        {
////            root->left = insert(root->left, userName, User);
////        }
////
////        else if (userName > root->username)
////        {
////            root->right = insert(root->right, userName, User);
////        }
////
////        else
////        {
////            cout << "Username should be unique! \n";
////        }
////
////        return root;
////    }
////
////    user* searchUser(bstNode* root, string userName)
////    {
////        if (!root)
////        {
////            return nullptr;
////        }
////
////        else if (root->username == userName)
////        {
////            return root->users;
////        }
////
////        else if (userName < root->username)
////        {
////            return searchUser(root->left, userName);
////        }
////
////        else
////        {
////            return searchUser(root->right, userName);
////        }
////    }
////
////    void inOrderTraversal(bstNode* root)
////    {
////        if (root)
////        {
////            inOrderTraversal(root->left);
////            cout << root->username << endl;
////            inOrderTraversal(root->right);
////        }
////    }
////};
////
////class graph
////{
////public:
////    userNode* head;
////
////    graph()
////    {
////        head = nullptr;
////    }
////
////    void addFollower(string username, string followerName)
////    {
////        userNode* user = findOrCreateUser(username);
////        friendNode* newFollower = new friendNode(followerName, "Following", "Active", user->friendList);
////        user->friendList = newFollower;
////    }
////
////    friendNode* getFriends(string username)
////    {
////        userNode* user = findUser(username);
////        if (user)
////        {
////            return user->friendList;
////        }
////        return nullptr;
////    }
////
////    void addFriend(string username, string friendName)
////    {
////        userNode* user = findOrCreateUser(username);
////        friendNode* newFriend = new friendNode(friendName, "Friend", "Active", user->friendList);
////        user->friendList = newFriend;
////    }
////
////    userNode* findUser(string username)
////    {
////        userNode* temp = head;
////        while (temp && temp->username != username)
////        {
////            temp = temp->next;
////        }
////        return temp;
////    }
////
////    userNode* findOrCreateUser(string username)
////    {
////        userNode* user = findUser(username);
////        if (!user)
////        {
////            user = new userNode(username, nullptr, head);
////            head = user;
////        }
////        return user;
////    }
////};
////
////class userManager
////{
////public:
////    user* users;
////    userSearch searchTree;
////    graph friendGraph;
////
////    userManager()
////    {
////        users = nullptr;
////    }
////
////
////    void signup(string name, string password, string city)
////    {
////        if (searchTree.searchUser(searchTree.root, name))
////        {
////            cout << "Username already exists. Try another one.\n";
////            return;
////        }
////        if (password.length() < 6)
////        {
////            cout << "Password must be at least 6 characters long.\n";
////            return;
////        }
////
////        user* newUser = new user(name, password, city, "", users);
////        users = newUser;
////        searchTree.root = searchTree.insert(searchTree.root, name, newUser);
////        cout << "User " << name << " signed up successfully!\n";
////    }
////
////    user* login(string name, string password)
////    {
////        user* User = searchTree.searchUser(searchTree.root, name);
////        if (!User)
////        {
////            cout << "Invalid username.\n";
////            return nullptr;
////        }
////
////        if (User->password != password)
////        {
////            cout << "Invalid password.\n";
////            return nullptr;
////        }
////
////        time_t now = time(0);
////        char buffer[26];
////        ctime_s(buffer, sizeof(buffer), &now);
////        User->lastLogin = buffer;
////        cout << "Welcome, " << name << "!\n";
////        return User;
////    }
////
////    void resetPassword(string name, string securityAnswer)
////    {
////        user* User = searchTree.searchUser(searchTree.root, name);
////        if (!User)
////        {
////            cout << "Invalid username.\n";
////            return;
////        }
////
////        string newPassword;
////        cout << "Enter new password: ";
////        cin >> newPassword;
////        while (newPassword.length() < 6)
////        {
////            cout << "Password must be 6 digits long: ";
////            cin >> newPassword;
////        }
////        User->password = newPassword;
////        cout << "Password reset successfully!\n";
////    }
////
////    void addPost(user* User, string content)
////    {
////        time_t now = time(0);
////        char buffer[26];
////        ctime_s(buffer, sizeof(buffer), &now);
////        post* newPost = new post{ buffer, content, User->posts };
////        User->posts = newPost;
////    }
////
////    void viewTimeline(user* User)
////    {
////        post* Post = User->posts;
////        if (!Post)
////        {
////            cout << "No posts to show.\n";
////            return;
////        }
////
////        cout << "Your Timeline:\n";
////        while (Post)
////        {
////            cout << "[" << Post->dateTime << "] " << Post->content << "\n";
////            Post = Post->next;
////        }
////    }
////
////    void sendFriendRequest(user* fromUser, user* toUser)
////    {
////        friendRequest* newRequest = new friendRequest(fromUser->name, toUser->friendRequests);
////        toUser->friendRequests = newRequest;
////
////        notification* newNotification = new notification(fromUser->name + " sent you a friend request.", toUser->notifications);
////        toUser->notifications = newNotification;
////
////        cout << "Friend request sent. \n";
////    }
////
////    void acceptFriendRequest(user* currentUser, user* friendUser)
////    {
////        friendRequest* prev = nullptr;
////        friendRequest* request = currentUser->friendRequests;
////
////        while (request)
////        {
////            if (request->fromUser == friendUser->name)
////            {
////                if (prev)
////                {
////                    prev->next = request->next;
////                }
////                else
////                {
////                    currentUser->friendRequests = request->next;
////                }
////                delete request;
////                break;
////            }
////            prev = request;
////            request = request->next;
////        }
////
////        friendNode* newFollower = new friendNode(currentUser->name, "Following", "Active", friendUser->friends);
////        friendUser->friends = newFollower;
////
////
////        notification* newNotification = new notification(currentUser->name + " accepted your friend request.", friendUser->notifications);
////        friendUser->notifications = newNotification;
////
////        friendGraph.addFollower(currentUser->name, friendUser->name);
////
////        cout << "Friend request accepted.\n";
////    }
////
////    void viewNotifications(user* currentUser)
////    {
////        if (!currentUser->notifications)
////        {
////            cout << "No notifications.\n";
////            return;
////        }
////
////        cout << "Notifications:\n";
////        notification* temp = currentUser->notifications;
////        while (temp)
////        {
////            cout << "- " << temp->content << "\n";
////            temp = temp->next;
////        }
////    }
////
////    void viewFriendRequests(user* currentUser)
////    {
////        if (!currentUser->friendRequests)
////        {
////            cout << "No friend requests.\n";
////            return;
////        }
////
////        cout << "Friend Requests:\n";
////        friendRequest* temp = currentUser->friendRequests;
////        while (temp)
////        {
////            cout << "- From: " << temp->fromUser << "\n";
////            temp = temp->next;
////        }
////    }
////
////    void viewFollowers(user* currentUser)
////    {
////        if (!currentUser)
////        {
////            cout << "Please log in first.\n";
////            return;
////        }
////
////        friendNode* friends = friendGraph.getFriends(currentUser->name);
////        if (!friends)
////        {
////            cout << "You have no followers yet.\n";
////            return;
////        }
////
////        cout << "Your Followers:\n";
////        while (friends)
////        {
////            cout << "- " << friends->friendName << "\n";
////            friends = friends->next;
////        }
////    }
////};
////
////int main()
////{
////    userManager UserManager;
////
////    int choice;
////    user* currentUser = nullptr;
////
////    do
////    {
////        cout << "\n--- Mini Instagram ---\n";
////        cout << "1. Signup\n";
////        cout << "2. Login\n";
////        cout << "3. Reset Password\n";
////        cout << "4. Send Friend Request\n";
////        cout << "5. View Notifications\n";
////        cout << "6. Post Content\n";
////        cout << "7. View Timeline\n";
////        cout << "8. View Friend Requests\n";
////        cout << "9. Accept Friend Request\n";
////        cout << "10. View Followers\n";
////        cout << "11. Search Users\n";
////        cout << "12. Logout\n";
////        cout << "0. Exit\n";
////        cout << "Enter your choice: ";
////        cin >> choice;
////
////        switch (choice)
////        {
////        case 0:
////        {
////            cout << "Goodbye!\n";
////            break;
////        }
////
////        case 1:
////        {
////            string name, password, city;
////            cout << "Enter username: ";
////            cin >> name;
////            cout << "Enter password: ";
////            cin >> password;
////            cout << "Enter city: ";
////            cin >> city;
////            UserManager.signup(name, password, city);
////            break;
////        }
////
////        case 2:
////        {
////            string name, password;
////            cout << "Enter username: ";
////            cin >> name;
////            cout << "Enter password: ";
////            cin >> password;
////            currentUser = UserManager.login(name, password);
////            break;
////        }
////
////        case 3:
////        {
////            string name, answer;
////            cout << "Enter username: ";
////            cin >> name;
////            cout << "Enter security answer: ";
////            cin >> answer;
////            UserManager.resetPassword(name, answer);
////            break;
////        }
////
////        case 4:
////        {
////            if (!currentUser)
////            {
////                cout << "Please log in first.\n";
////                continue;
////            }
////            string friendName;
////            cout << "Enter username to send friend request: ";
////            cin >> friendName;
////            user* friendUser = UserManager.searchTree.searchUser(UserManager.searchTree.root, friendName);
////            if (!friendUser)
////            {
////                cout << "User not found.\n";
////                continue;
////            }
////            UserManager.sendFriendRequest(currentUser, friendUser);
////            break;
////        }
////
////        case 5:
////        {
////            UserManager.viewNotifications(currentUser);
////            break;
////        }
////
////        case 6:
////        {
////            if (!currentUser)
////            {
////                cout << "Please log in first.\n";
////                continue;
////            }
////            string content;
////            cin.ignore();
////            cout << "Enter post content: ";
////            getline(cin, content);
////            UserManager.addPost(currentUser, content);
////            break;
////        }
////
////        case 7:
////        {
////            if (!currentUser)
////            {
////                cout << "Please log in first.\n";
////                continue;
////            }
////            UserManager.viewTimeline(currentUser);
////            break;
////        }
////
////        case 8:
////        {
////            if (!currentUser)
////            {
////                cout << "Please log in first.\n";
////                continue;
////            }
////            UserManager.viewFriendRequests(currentUser);
////            break;
////        }
////
////        case 9:
////        {
////            if (!currentUser)
////            {
////                cout << "Please log in first.\n";
////                continue;
////            }
////            string friendName;
////            cout << "Enter username to accept friend request: ";
////            cin >> friendName;
////            user* friendUser = UserManager.searchTree.searchUser(UserManager.searchTree.root, friendName);
////            if (!friendUser)
////            {
////                cout << "User not found.\n";
////                continue;
////            }
////            UserManager.acceptFriendRequest(currentUser, friendUser);
////            break;
////        }
////
////        case 10:
////        {
////            if (!currentUser)
////            {
////                cout << "Please log in first.\n";
////                continue;
////            }
////            UserManager.viewFollowers(currentUser);
////            break;
////        }
////
////        case 11:
////        {
////            string query;
////            cout << "Enter username to search: ";
////            cin >> query;
////            user* foundUser = UserManager.searchTree.searchUser(UserManager.searchTree.root, query);
////
////            if (foundUser)
////            {
////                cout << "User found:\n";
////                cout << "Name: " << foundUser->name << "\n";
////                cout << "City: " << foundUser->city << "\n";
////                cout << "Last Login: " << foundUser->lastLogin << "\n";
////            }
////            else
////            {
////                cout << "User not found.\n";
////            }
////            break;
////        }
////
////        case 12:
////        {
////            currentUser = nullptr;
////            cout << "Logged out successfully.\n";
////            break;
////        }
////
////        default:
////        {
////            cout << "Invalid choice.\n";
////            break;
////        }
////
////        }
////    } while (choice != 0);
////
////    system("pause");
////    return 0;
////}