#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

void insertAtBeginning(Node** head, int data) {
    Node* newNode = new Node(data);

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = new Node(data);

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void deleteAtBeginning(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty. Unable to delete." << endl;
        return;
    }

    Node* toDelete = *head;
    *head = (*head)->next;
    if (*head != nullptr) {
        (*head)->prev = nullptr;
    }

    delete toDelete;
}

void deleteAtEnd(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty. Unable to delete." << endl;
        return;
    }

    Node* current = *head;
    while (current->next != nullptr) {
        current = current->next;
    }

    if (current->prev != nullptr) {
        current->prev->next = nullptr;
    } else {
        *head = nullptr;
    }

    delete current;
}

void displayForward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void displayBackward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

Node* search(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void insertAfter(Node* prevNode, int data) {
    if (prevNode == nullptr) {
        cout << "Previous node cannot be NULL." << endl;
        return;
    }

    Node* newNode = new Node(data);
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    
    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }
    
    prevNode->next = newNode;
}

void deleteNode(Node** head, Node* delNode) {
    if (*head == nullptr || delNode == nullptr) {
        return;
    }

    if (*head == delNode) {
        *head = delNode->next;
    }
    
    if (delNode->next != nullptr) {
        delNode->next->prev = delNode->prev;
    }
    
    if (delNode->prev != nullptr) {
        delNode->prev->next = delNode->next;
    }

    delete delNode;
}

void reverseList(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) {
        return;
    }

    Node* current = *head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        *head = temp->prev;
    }
}

int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}


int main() {
    Node* head = nullptr;

    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    displayForward(head);   // Output: 1 2 3 4
    displayBackward(head);  // Output: 4 3 2 1

    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    displayForward(head);   // Output: 1 2 3 4 5 6
    displayBackward(head);  // Output: 6 5 4 3 2 1

    deleteAtBeginning(&head);
    displayForward(head);   // Output: 2 3 4 5 6
    displayBackward(head);  // Output: 6 5 4 3 2

    deleteAtEnd(&head);
    displayForward(head);   // Output: 2 3 4 5
    displayBackward(head);  // Output: 5 4 3 2

    return 0;
}
