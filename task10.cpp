#include <iostream>
using namespace std;

struct Node
{
    string name;
    int value;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    ~LinkedList();
    void display();
    void addFront(string name, int value);
    void removeFront();
    void addEnd(string name, int value);
    void removeEnd();
    void copyToFront(int i);
    void mergingLists(LinkedList list2);
    void cutList(LinkedList &list2, int after_index);
    void addBefor(string name, int value, int index);
    void addAfter(string name, int value, int index);
};

LinkedList::LinkedList()
{
    head = NULL;
}
LinkedList::~LinkedList()
{
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::display()
{
    Node *current = head;
    while (current != NULL)
    {
        cout << "Name: " << current->name << ", Value: " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void LinkedList::addFront(string name, int value)
{
    Node *newNode = new Node{name, value, head};
    head = newNode;
}

void LinkedList::removeFront()
{
    if (head != NULL)
    {
        Node *oldhead = head;
        head = head->next;
        delete oldhead;
    }
}

void LinkedList::addEnd(string name, int value)
{
    Node *newNode = new Node{name, value, NULL};
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::removeEnd()
{
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *current = head;
            while (current->next->next != NULL)
            {
                current = current->next;
            }
            delete current->next;
            current->next = NULL;
        }
    }
}

void LinkedList::copyToFront(int i)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        exit(1);
    }
    int j = 0;
    Node *current = head;
    while (current != NULL)
    {
        if (i == j)
        {
            Node *newNode = new Node{current->name, current->value, head};
            head = newNode;
            return;
        }
        current = current->next;
        j++;
    }
    cout << "List doesn't have so much elements" << endl;
    exit(1);
}

void LinkedList::mergingLists(LinkedList list2)
{
    if (head == NULL)
    {
        head = list2.head;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = list2.head;
    }
}

void LinkedList::cutList(LinkedList &list2, int after_index)
{
    if (head == NULL && head->next == NULL)
    {
        cout << "Not enought elements" << endl;
        exit(1);
    }
    int j = 0;
    Node *current = head;
    while (current != NULL)
    {
        if (after_index == j)
        {
            list2.head = current->next;
            current->next = NULL;
            return;
        }
        current = current->next;
        j++;
    }
    cout << "List doesn't have so much elements" << endl;
    exit(1);
}

void LinkedList::addBefor(string name, int value, int index)
{
    Node *newNode = new Node{name, value, NULL};
    if (head == NULL || index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        int j = 0;
        Node *current = head;
        while (current->next != NULL)
        {
            if ((index - 1) == j){
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        current->next = newNode;
    }
}
void LinkedList::addAfter(string name, int value, int index)
{
    Node *newNode = new Node{name, value, NULL};
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        int j = 0;
        Node *current = head;
        while (current->next != NULL)
        {
            if (index == j){
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        current->next = newNode;
    }
}
int main()
{\
    LinkedList list;
    list.addEnd("one", 10);
    list.addEnd("two", 20);
    list.addEnd("three", 30);
    list.removeFront();
    list.removeEnd();
    list.addFront("four", 40);
    list.copyToFront(1);
    list.display();
    cout << "---------------" << endl;

    LinkedList list2;
    list2.addEnd("five", 50);
    list2.addEnd("six", 60);
    list2.addEnd("seven", 70);

    list.mergingLists(list2);
    list.display();
    cout << "---------------" << endl;

    LinkedList list3;
    list.cutList(list3, 2);
    list.display();
    list3.display();
    cout << "---------------" << endl;

    list.addBefor("eight", 80, 0);
    list.display();
    list.addAfter("nine", 90, 0);
    list.display();

    return 0;
}