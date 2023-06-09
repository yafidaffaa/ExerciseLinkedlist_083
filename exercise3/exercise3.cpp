#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** andriansyah, Node** yafi);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { //write your answer here
	int rollno;
	string name;

	cout << "Enter your roll number: ";
	cin >> rollno;
	cout << "Enter your name: ";
	cin >> name;

	Node* newNode = new Node(); //a.1
	newNode->rollNumber = rollno;  //a.2
	newNode->name = name;

	if (listEmpty()) {//a.3
		newNode->next = newNode;
		LAST = newNode;//a.4
	}
	else {
		newNode->next = LAST->next;//b.1
		LAST->next = newNode;
		LAST = newNode;
	}
	cout << "\nAdd successfuly" << endl;

}
bool CircularLinkedList::search(int rollno, Node** andriansyah, Node** yafi) {
	*andriansyah = LAST->next;
	*yafi = LAST->next;
	while (*yafi != LAST) {
		if (rollno == (*yafi)->rollNumber) {
			return true;
		}
		*andriansyah = *yafi;
		*yafi = (*yafi)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //write your answer here
	if (listEmpty()) { //1.a
		cout << "\nList is Empty" << endl;
		return false;//1.b
	}

	int rollno;
	cout << "Enter your roll number to delete: ";
	cin >> rollno;

	Node* andriansyah = NULL;
	Node* yafi = NULL;

	if (!search(rollno, &andriansyah, &yafi)) {
		cout << "Your roll number " << rollno << " Not found" << endl;
		return false;
	}
	if (yafi == LAST && yafi->next == LAST) {//a.2 & a.3
		LAST = NULL;
	}
	else if (yafi == LAST) {//b.2
		andriansyah = LAST;//b.1  
		andriansyah->next = LAST->next;//b.5
	}
	else {
		andriansyah->next = yafi->next;//b.4
	}

	delete yafi;
	cout << "\nDelete successfuly" << endl;
	return true;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "\nInvalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}