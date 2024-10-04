// COMSC-210 | Lab 17 | Daniil Malakhov
// IDE used: Codeblocks
#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node *next;
};

void output(Node *);
Node* addNode(Node *, int);
Node* deleteNode(Node *, Node *, Node *, int);
Node* insertNode(Node *, Node *, Node *, int, int);
Node* deleteList(Node *, Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addNode(head, tmp_val);
    }
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    Node* prev = head;

    current = deleteNode(head, prev, current, entry);

    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;


    current = head;
    prev = head;

    head = insertNode(head, current, prev, entry, 10000);


    output(head);

    head = deleteList(head, current);

    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// adds nodes to linked list
// arguments: a node object representing the head node, an int representing value to put into new node
// returns: the new head node
Node* addNode(Node* hd, int val)
{
    Node *newVal = new Node;
    // adds node at head
    if (!hd) { // if this is the first node, it's the new head
        hd = newVal;
        newVal->next = nullptr;
        newVal->value = val;
    }
    else { // its a second or subsequent node; place at the head
        newVal->next = hd;
        newVal->value = val;
        hd = newVal;
    }
    return hd;
}

// deletes nodes from linked list
// arguments: a node object representing the head, previous, and current node, an int representing which node to delete
// returns: the new current node
Node* deleteNode(Node * head, Node * prev, Node *current, int entry)
{
    // traverse that many times and delete that node
    current = head;
    prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }

    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }

    return current;
}

// inserts nodes into linked list
// arguments: a node object representing the head, previous, and current node, an int representing where to insert node and an int representing value in inserted node
// returns: the new head node
Node* insertNode(Node * head, Node * prev, Node *current, int entry, int val)
{
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = val;
    newnode->next = current;
    prev->next = newnode;

    return head;
}

// deletes the list and all of its nodes
// arguments: a node object representing the head and current node
// returns: the new head node
Node* deleteList(Node * head, Node * current)
{
    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    return head;
}
