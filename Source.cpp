#include <iostream>
#include<Windows.h>
using namespace std;
//            _______
class dlinkedlist {										//Tail->     |_______| 
														//           |_______|
private:												//           |_______|
	struct node {										//           |_______|
		int value = NULL;								//           |_______|
		node*prev = nullptr;//null						//           |_______|
		node*next = nullptr;//null						//           |_______|
	};													//           |_______|
	int count;											//           |_______|
	node* head;											//           |_______|
	node* tail;											//head->     |_______|
	bool is_empty();
public:
	dlinkedlist() :head(nullptr), tail(nullptr), count(0) {}
	~dlinkedlist() {}
	int* pop_back();
	int* pop_front();
	void push_back(int item);
	void push_front(int item);
	void reverse();
	void erase(int pos);
	void merge(node* first, node* second);
	void changeEl(int item, int pos);
	void insert(int item, int pos);
};
inline void dlinkedlist::push_back(int item) {
	node*tmp = new node();
	tmp->next = nullptr;
	tmp->value = item;
	if (head != nullptr) { tmp->prev = tail; tail->next = tmp; tail = tmp; count++; }
	else { tmp->prev = nullptr; head = tail = tmp; count++; }
}
inline void dlinkedlist::push_front(int item) {
	node*tmp = new node();
	tmp->prev = nullptr;
	tmp->value = item;
	if (head != nullptr) { tmp->next = head; head->prev = tmp; head = tmp; count++; }
	else { tmp->next = nullptr; head = tail = tmp; count++; };
}
//remove back element form list
inline int*  dlinkedlist::pop_back() {
	if (!is_empty()) {
		int* tmp_val = new int(tail->value);
		node* tmp_tail = tail;
		tail = tail->prev;
		delete tmp_tail;
		return tmp_val;
	}
	return nullptr;
}
//remove front element from list
inline int*	 dlinkedlist::pop_front() {
	if (!is_empty()) {
		int* tmp_val = new int(head->value);
		node* tmp_head = head;
		head = head->next;
		delete tmp_head;
		return tmp_val;
	}
}
inline bool dlinkedlist::is_empty() {
	return !head;
}
inline void dlinkedlist::reverse() {
	if (count <= 1) {}
	else {
		;
	}
}


// change element on pos (item,pos);
inline void dlinkedlist::changeEl(int item, int pos) {
	node* tmp = tail;
	int tmp_c = count;
	if (pos == tmp_c) { tail->value = item; }
	if (pos == 0) { head->value = item; }
	if (pos < tmp_c) {
		while (pos < tmp_c) {
			tmp = tmp->prev;
			tmp_c--;
		}
		tmp->value = item;
	}
}
inline void dlinkedlist::insert(int item, int pos) {
	node* tmp_1 = tail;
	int tmp_c = count;
	if (pos == tmp_c) { push_back(item); }
	if (pos == 0) { push_front(item); }
	if (pos < tmp_c) {
		while (pos < tmp_c) {
			tmp_1 = tmp_1->prev;
			tmp_c--;
		}
		node* prevIns = tmp_1->prev;
		node* tmp_2 = new node();
		tmp_2->value = item;
		tmp_2->next = tmp_1;
		tmp_2->prev = prevIns;
		tmp_1->prev = tmp_2;
		count++;
	}
}
int main() {
	dlinkedlist test;
	test.push_back(5);
	test.push_back(6);
	test.push_back(7);
	test.insert(3, 2);
	cout << *test.pop_back();
	cout << *test.pop_back();
	cout << *test.pop_back();
	cout << *test.pop_back();
	return 0;
}
