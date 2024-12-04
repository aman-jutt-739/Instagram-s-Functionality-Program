#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class user;
class friendRequestList;
class friendList;

class messageNode
{
public:
    string dateTime;
    string content;
    messageNode* next;
    messageNode(string dateTime, string content) {
        this->dateTime = dateTime;
        this->content = content;
        next = nullptr;
    }
};

class messageQueue {
    messageNode* front;
    messageNode* rear;
public:
    messageQueue()
    {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(messageNode msg)
    {
        messageNode* newNode = new messageNode(msg.dateTime, msg.content);
        if (front == nullptr)
        {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void dequeue(messageNode& msg)
    {
        if (front == nullptr)
        {
            return;
        }
        if (front == rear)
        {
            msg = *front;
            front = nullptr;
            rear = nullptr;
            return;
        }
        messageNode* temp = front;
        msg = *front;
        front = front->next;
        delete temp;
    }
    void messagePop()
    {
        if (front == nullptr)
        {
            return;
        }
        while (front)
        {
            messageNode temp("", "");
            dequeue(temp);
        }
    }
};

class messageList {
public:
    messageNode* top;
    messageList() {
        top = nullptr;
    }
    bool isempty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }
    void push(char dateTime[], string content) {

        messageNode* n = new messageNode(dateTime, content);
        n->next = top;
        top = n;

    }
    void pop(string dateTime, string content) {
        if (!isempty()) {
            messageNode* temp = top;
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
    void displayMessages()
    {
        if (top == nullptr)
        {
            cout << "No messages \n";
            return;
        }
        messageNode* tempMsg = top;
        while (tempMsg)
        {
            cout << tempMsg->content << endl;
            tempMsg = tempMsg->next;
        }
    }
};

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
    messageList* mList;
    string relationship;
    string status;
    relationNode(user* users) {
        this->users = users;
        next = nullptr;
        mList = new messageList;
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
    messageQueue* msgQueue;
    user* left;
    user* right;
    user(string name, string password, string city, string login) {
        this->name = name;
        this->password = password;
        this->city = city;
        this->lastLogin = login;
        left = nullptr;
        right = nullptr;
        nList = nullptr;
        pList = nullptr;
        msgQueue = nullptr;
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
    void display() // O(n)
    {
        temp = head;
        if (head != nullptr) {
            while (temp != nullptr) {
                cout << temp->friendUser->name << " with lastlogin " << temp->friendUser->lastLogin << endl;
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
        return true;
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
                //temp->relationship = "Not Friend";
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
    relationNode* isFriend(user* userA, user* userB) {
        int first = index(userA);
        int second = index(userB);
        relationNode* temp = friends[first];
        while (temp != nullptr) {
            if (temp->users->name == friends[second]->users->name) {
                return friends[second];

            }
            temp = temp->next;
        }
        return nullptr;
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
        buffer[24] = '\0';
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
        buffer[24] = '\0';
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
    void sendMessgae(user* userA, user* userB, string content) {
        if (Relations->isFriend(userA, userB) && Relations->isFriend(userB, userA)) {
            time_t now = time(0);
            char buffer[26];
            ctime_s(buffer, sizeof(buffer), &now);
            buffer[24] = '\0';
            Relations->isFriend(userA, userB)->mList->push(buffer, content);
            cout << "Sent" << endl;
            string msg = userA->name + " Sent You a Message at " + buffer;
            userB->nList->push(msg);
            messageNode msgNode(buffer, content);
            userB->msgQueue->enqueue(msgNode);
        }
        else {
            cout << "NOT Mutual Friends" << endl;
            return;
        }
    }
    void showMessages(user* userA, user* userB)
    {
        cout << "Messages: \n";
        Relations->isFriend(userB, userA)->mList->displayMessages();
        userA->msgQueue->messagePop();
    }
    void showSuggestions(user* userA) {
        bool flag = false;
        cout << "Friend Suggestions: \n";
        suggestiondfs(users, userA, flag);
        if (flag == false)
        {
            cout << "No friend suggestions to show\n";
        }
    }
    void suggestiondfs(user* users, user* userNode, bool& flag)
    {
        if (!users)
        {
            return;
        }
        suggestiondfs(users->left, userNode, flag);
        suggestiondfs(users->right, userNode, flag);
        if (!Relations->isFriend(users, userNode)) {
            if (users != userNode)
            {
                cout << users->name << endl;
                flag = true;
            }
        }
    }
};

int main() {
    int userSize = 100; // Adjust this based on expected users
    userManager manager(userSize); // Initialize user manager with user size
    user* loggedInUser = nullptr;

    int choice, choice2;
    do {
        system("cls");
        cout << "\n=== Mini Instagram - Menu ===\n";
        cout << "1. Sign Up\n";
        cout << "2. Log In\n";
        cout << "3. Exit\n";
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
            if (loggedInUser) {
                do
                {
                    system("cls");
                    cout << "\n=== Mini Instagram - Menu ===\n";
                    cout << "1. Send Friend Request\n";
                    cout << "2. Accept Friend Request\n";
                    cout << "3. Reject Friend Request\n";
                    cout << "4. View Friend List\n";
                    cout << "5. View Friend Requests\n";
                    cout << "6. Unfriend\n";
                    cout << "7. Block Friend\n";
                    cout << "8. View Notifications\n";
                    cout << "9. Crete a Post\n";
                    cout << "10. Show  TimeLine\n";
                    cout << "11. Show own Posts\n";
                    cout << "12. Send messages\n";
                    cout << "13. Show user messages\n";
                    cout << "14. Search Users\n";
                    cout << "15. Friend Suggestions\n";
                    cout << "16. Log out\n";
                    cout << "Enter your choice: ";
                    cin >> choice2;
                    switch (choice2)
                    {
                    case 1: {
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
                    case 2: {
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
                    case 3: {
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
                    case 4: {
                        if (!loggedInUser) {
                            cout << "Please log in first.\n";
                            break;
                        }
                        cout << "Your Friends: ";
                        loggedInUser->fList->display();
                        break;
                    }
                    case 5: {
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
                    case 6: {
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
                    case 7: {
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
                    case 8: {  // View Notifications
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
                    case 9: {
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
                    case 10: {
                        if (!loggedInUser) {
                            cout << "Please log in first.\n";
                            break;
                        }
                        cout << "Posts" << endl;
                        manager.showTimeline(loggedInUser);
                        break;
                    }
                    case 11: {
                        if (!loggedInUser) {
                            cout << "Please log in first.\n";
                            break;
                        }
                        cout << "Your Posts" << endl;
                        manager.showPosts(loggedInUser);
                        break;
                    }
                    case 12: {
                        if (!loggedInUser) {
                            cout << "Please log in first.\n";
                            break;
                        }
                        string name, message;
                        cout << "Enter friend name: ";
                        cin >> name;
                        user* friendUser = manager.searchUser(manager.users, name);
                        if (friendUser == nullptr)
                        {
                            cout << "No such friend exist! \n";
                        }
                        else
                        {
                            cout << "Enter message: ";
                            cin >> message;
                            manager.sendMessgae(loggedInUser, friendUser, message);
                        }
                        break;
                    }
                    case 13: {
                        string name;
                        cout << "Enter name of friend to see message stack: ";
                        cin >> name;
                        user* friendNode = manager.searchUser(manager.users, name);
                        if (friendNode == nullptr)
                        {
                            cout << "No such friend exists";
                        }
                        else
                        {
                            manager.showMessages(loggedInUser, friendNode);
                        }
                        break;
                    }
                    case 14: {
                        string name;
                        cout << "Enter name of user to be searched: ";
                        cin >> name;
                        user* userNode = manager.searchUser(manager.users, name);
                        if (userNode == nullptr)
                        {
                            cout << "No such user exists";
                        }
                        else
                        {
                            cout << userNode->name << " found \n";
                        }
                        break;
                    }
                    case 15: {
                        manager.showSuggestions(loggedInUser);
                        break;
                    }
                    case 16: {
                        loggedInUser = nullptr;
                        cout << "Logged out successfully \n";
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Please try again.\n";
                        break;
                    }
                    }
                    system("pause");
                } while (choice2 != 16);
            }
            break;
        }
        case 3: {
            cout << "Exiting the program. Goodbye!\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        system("pause");
    } while (choice != 3);

    return 0;
}