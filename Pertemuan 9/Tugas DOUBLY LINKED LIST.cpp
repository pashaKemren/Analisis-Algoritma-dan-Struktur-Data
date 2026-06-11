#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void tambahBelakang(int nilai) {
        Node* baru = new Node;
        baru->data = nilai;
        baru->next = NULL;
        baru->prev = NULL;

        if (head == NULL) {
            head = tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }

    void tampilMaju() {
        Node* bantu = head;

        cout << "Data dari Head ke Tail : ";
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }

    void tampilMundur() {
        Node* bantu = tail;

        cout << "Data dari Tail ke Head : ";
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->prev;
        }
        cout << endl;
    }
};

int main() {

    DoublyLinkedList dll;

    // sesuai ilustrasi
    dll.tambahBelakang(24);
    dll.tambahBelakang(10);
    dll.tambahBelakang(33);
    dll.tambahBelakang(33);

    dll.tampilMaju();
    dll.tampilMundur();

    return 0;
}
