#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    int data;
    string typee;
    string model;
    Node *next;
    Node *previous;

    Node()
    {
        key = 0;
        data = 0;

        next = NULL;
        previous = NULL;
    }

    Node(int k, int d, string t, string m)
    {
        key = k;
        data = d;
        typee = t;
        model = m;
    }
};
class DoublyLinkedList{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node *n)
    {
        head = n;
    }
    //Check if vehicle exists ID
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    void AddAtEnd(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Vehicle Already exists with ID : " << n->key << ". Add another vehicle with different ID" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
            }
            cout<<"Vehicle Added"<<endl;
        }
    }
    //Add a vehicle at beginning
    void AddAtBeginning(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Vehicle Already exists with ID : " << n->key << ". Add another vehicle with different ID" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
            }
            else
            {
                head->previous = n;
                n->next = head;
                head = n;
            }
            cout<<"Vehicle Added"<<endl;
        }
    }
    //Delete a vehicle with ID
    void DeleteVehicle(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Vehicle exists with ID: " << k << endl;
        }
        else
        {

            if (head->key == k)
            {

                if (head->next == NULL)
                {
                    cout<<"Vehicle Deleted"<<endl;
                    free(head);
                    head = NULL;
                    
                }
                else
                {
                    Node *temp = head->next;
                    free(temp->previous);
                    head = temp;
                    cout<<"Vehicle Deleted"<<endl;
                }
            }
            else
            {
                Node *nextNode = ptr->next;
                Node *prevNode = ptr->previous;
                if (nextNode == NULL)
                {
                    free(ptr);
                    prevNode->next = NULL;
                    cout<<"Vehicle Deleted"<<endl;
                }

                else
                {
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                    free(ptr);
                    cout<<"Vehicle Deleted"<<endl;
                }
            }
        }
    }
    //Printing all vehicles from end
    void PrintVehicle()
    {
        Node *temp = head;
        Node *tail = NULL;
        while (temp != NULL)
        {
            tail = temp;
            temp = temp->next;
        }
        cout << "Showing All Vehicle From End: \n";
        while (tail != NULL)
        {
            if (tail->key != 0)
            {
                cout << "Vehicle ID: "<<tail->key << ", Type: " << tail->typee << ", Model: " << tail->model << ", Price: $" << tail->data << "\n";
            }

            tail = tail->previous;
        }
    }
};

int main()
{
    DoublyLinkedList obj;
    string type, modell;
    char option;
    int key1, k1, data1, count = 0;

    for (int i = 1; i > 0; i++)
    {
        cout << "\nWhat operation do you want to perform? Enter Q to exit." << endl;
        cout << "[A]: Add a vehicle at beginning" << endl;
        cout << "[B]: Add a vehicle at end" << endl;
        cout << "[D]: Delete a vehicle with ID" << endl;
        cout << "[S]: Show all vehicles from end" << endl;
        cout << "[N]: Number of vehicles" << endl;
        cout << "[Q]: Quit" << endl;

        cin >> option;
        option = toupper(option);
        Node *n1 = new Node();

        if (option == 'A')
        {
            cout << "Enter Vehicle ID, Type, Model, Price" << endl;
            cout<<"Enter Vehicle ID: ";
            cin >> key1;
            cout<<"Enter Vehicle Type: ";
            cin >> type;
            cout<<"Enter Vehicle Model: ";
            cin >> modell;
            cout<<"Enter Vehicle Price: ";
            cin >> data1;
            count++;
            n1->key = key1;
            n1->typee = type;
            n1->model = modell;
            n1->data = data1;
            obj.AddAtBeginning(n1);
        }
        else if (option == 'B')
        {
            cout << "Enter Vehicle ID, Type, Model, Price" << endl;
            cout<<"Enter Vehicle ID: ";
            cin >> key1;
            cout<<"Enter Vehicle Type: ";
            cin >> type;
            cout<<"Enter Vehicle Model: ";
            cin >> modell;
            cout<<"Enter Vehicle Price: ";
            cin >> data1;
            count++;
            n1->key = key1;
            n1->typee = type;
            n1->model = modell;
            n1->data = data1;
            obj.AddAtEnd(n1);
        }
        else if (option == 'D')
        {
            cout << "Enter ID of the Vehicle to be deleted:";
            cin >> k1;
            count--;
            obj.DeleteVehicle(k1);
        }
        else if (option == 'S')
        {
            obj.PrintVehicle();
        }
        else if (option == 'N')
        {
            cout << "Number of vehicles: ";
            cout << count << endl;
        }
        else if (option == 'Q')
        {
            cout<<"\n****Quited****\n";
            break;
        }
        else
        {
            cout << "Please enter specific character." << endl;
        }
    }

    return 0;
}
