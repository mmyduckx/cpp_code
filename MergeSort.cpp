//HW1 by Wanxiang Xie
//SU Net ID: wxie15  SUID: 408358088
//CSE674 HW1
//Due: 11:59PM, Thursday (9/12)

#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node(int i) { value = i; next = nullptr; }
	Node() { next = nullptr; }
};

class LinkedList {
public:
	int numNodes;
	Node* head;
	LinkedList() { numNodes = 0; head = nullptr; }
	void makeRandomList(int m, int n);
	void printList();


	//Recursively merge sort i numbers starting at node pointed by p
	void mergeSort(Node*& p, int i);//in-place recursive merge sort


	//Merge i1 numbers starting at node pointed by p1 with i2 numbers
	//starting at node pointed by p2
	void merge(Node*& p1, int i1, Node* p2, int i2);
};

void LinkedList::makeRandomList(int m, int n) {

	for (int i = 0; i < m; i++) {
		Node* p1 = new Node(rand() % n);
		p1->next = head;
		head = p1;
		numNodes++;
	}
}

void LinkedList::printList() {
	cout << endl;
	Node* p1 = head;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->next;
	}
}

/*Sort Linkedlist by mergeSort by ascending order*/

void LinkedList::mergeSort(Node*& p, int i) {
	if ( p ==nullptr || p->next == nullptr || i == 0 || i == 1) return;
		Node* p1 = p;
		Node* p2 = nullptr;
		Node* mid = p;
		int a, b;
		a = i / 2;  //even:a=b odd:a<b
		b = i - a;

		for (int n = 0; n < a-1; n++) {
			mid = mid->next;
		}

		p2 = mid->next;    //actually p2 is the middle node
		mid->next = nullptr;   
		mergeSort(p1, a);
		mergeSort(p2, b);
		merge(p1,a,p2,b);
		p = head;
}

/*merge each two Linkedlist into one*/

void LinkedList::merge(Node*& p1, int i1, Node* p2, int i2) {
	if (p1->value <= p2->value) {
		head = p1;
		p1 = p1->next;
	}
	else {
		head = p2;
		p2 = p2->next;
	}
	Node* cur = head;
	while (p1 != nullptr && p2 != nullptr) {
		if (p1->value <= p2->value) {
			cur->next = p1;
			p1 = p1->next;
		}
		else
		{
			cur->next = p2;
			p2 = p2->next;
		}
		cur = cur->next;
	}
	if (p1 != nullptr) {
		cur->next = p1;
	}
	if (p2 != nullptr) {
		cur->next = p2;
	}
	//printList();   //print out each merge
}

int main() {

	LinkedList d1;

	d1.makeRandomList(40, 20);
	d1.printList();

	d1.mergeSort(d1.head, d1.numNodes);
	d1.printList();

	getchar();
	getchar();
	return 0;

}