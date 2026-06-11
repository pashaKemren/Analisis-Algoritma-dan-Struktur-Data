#include <iostream>
using namespace std;

struct Node {
    Node* next;
    int data;
};

class Stack {
    private:
        Node* top;
        int size;

    public:
        Stack() {
            top = NULL;
            size = 0;
        }

        void insert(int data) {
            Node* node = new Node();
            node->data = data;
            if (top == NULL) {
                top = node;
                top->next = NULL;
            } else {
                node->next = top;
                top = node;
            }
        }

        void pop() {
            Node* temp = top;
            top = top->next;
            delete temp;
        }

        void printStack() {
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    Stack* stack = new Stack();
    stack->insert(10);
    stack->insert(20);
    stack->insert(30);
    stack->insert(40);

    stack->printStack();

    stack->pop();
    stack->pop();
	
	stack->printStack();
	
	return 0;
}
