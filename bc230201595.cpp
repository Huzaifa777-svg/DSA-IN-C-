#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Product {
private:
    int data;
    Product* next;
    int productId;

public:
    Product() {
        data = 0;
        next = NULL;
        productId = 0;
    }
    int getData() {
        return data;
    }
    void setData(int d) {
        data = d;
    }
    Product* getNext() {
        return next;
    }
    void setNext(Product* nextNode) {
        next = nextNode;
    }

    int getProductId() {
        return productId;
    }
    void setProductId(int pid) {
        productId = pid;
    }
};

class Queue {
private:
    Product* front;
    Product* rear;

public:
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int data, int pid) {
        Product* temp = new Product();
        temp->setData(data);
        temp->setProductId(pid);
        temp->setNext(NULL);

        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->setNext(temp);
            rear = temp;
        }
        cout << "Added -> Serial: " << data << ", Product ID: " << pid << "\n";
    }
    int dequeue() {
        if (front == NULL) {
            cout << "Queue is empty, nothing to dequeue.\n";
            return -1;
        }

        Product* temp = front;
        int serial = temp->getData();
        cout << "Sold product with serial: " << serial << " and ID: " << temp->getProductId() << "\n";
        front = front->getNext();

        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return serial;
    }

    void displayFront() {
        if (front != NULL) {
            cout << "First product in queue -> Serial: " << front->getData()
                 << ", Product ID: " << front->getProductId() << "\n";
        } else {
            cout << "Queue is empty!\n";
        }
    }

    void displayRear() {
        if (rear != NULL) {
            cout << "Last product in queue -> Serial: " << rear->getData()
                 << ", Product ID: " << rear->getProductId() << "\n";
        } else {
            cout << "Queue is empty!\n";
        }
    }
};

int main() {
    string studentId = "BC230201595"; 
    int lastThreeDigits = atoi(studentId.substr(studentId.length() - 3).c_str());

    int smartphones = lastThreeDigits / 100;        
    int tablets = (lastThreeDigits / 10) % 10;     
    int smartWatches = lastThreeDigits % 10;        

    int serial = 1;
    int productId = atoi(studentId.substr(studentId.length() - 4).c_str()); 

    Queue inventory;

    cout << "Student ID: " << studentId << "\n";
    cout << "================================\n";

    cout << smartphones << " smartphones being added to inventory:\n";
    for (int i = 0; i < smartphones; i++) {
        inventory.enqueue(serial++, productId++);
    }
    cout << "\n";

    cout << tablets << " tablets being added to inventory:\n";
    for (int i = 0; i < tablets; i++) {
        inventory.enqueue(serial++, productId++);
    }
    cout << "\n";

    cout << smartWatches << " smart watches being added to inventory:\n";
    for (int i = 0; i < smartWatches; i++) {
        inventory.enqueue(serial++, productId++);
    }
    cout << "\n";
    cout << "--------------------------------------\n";
    inventory.displayFront();
    cout << "---------------------------------------\n";
    inventory.displayRear();
    cout << "----------------------------------------\n";

    cout << "Selling 2 products...\n";
    inventory.dequeue();
    inventory.dequeue();
    cout << "----------------------------------------\n";
    inventory.displayFront();
    cout << "----------------------------------------\n";

   
    return 0;
}