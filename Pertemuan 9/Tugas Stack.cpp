#include <iostream>
using namespace std;

#define MAX 10

class Stack {
private:
    int data[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int nilai) {
        if (isFull()) {
            cout << "Stack penuh!\n";
            return;
        }
        data[++top] = nilai;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong!\n";
            return;
        }
        cout << "Data yang dihapus: " << data[top--] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack kosong!\n";
            return;
        }

        cout << "\nIsi Stack (TOP -> BOTTOM)\n";
        for (int i = top; i >= 0; i--) {
            cout << data[i] << endl;
        }
    }
};

int main() {
    Stack s;

    // sesuai ilustrasi
    s.push(621);
    s.push(999);
    s.push(201);
    s.push(94);
    s.push(124);

    s.display();

    return 0;
}
