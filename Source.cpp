#include <iostream>
using namespace std;

class dlinkedlist {

private:
	struct node {
		int value = NULL;
		node*prev = nullptr;//null
		node*next = nullptr;//null
	};
	int count;
	node* head;
	node* tail;
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
	void changeEl(int item, int pos);
	void insert(int item, int pos);
};

void dlinkedlist::push_back(int item) {
	node*tmp = new node();
	tmp->next = nullptr;
	tmp->value = item;
	if (head != nullptr) { tmp->prev = tail; tail->next = tmp; tail = tmp; count++; }
	else { tmp->prev = nullptr; head = tail = tmp; count++; }
}

void dlinkedlist::push_front(int item) {
	node*tmp = new node();
	tmp->prev = nullptr;
	tmp->value = item;
	if (head != nullptr) { tmp->next = head; head->prev = tmp; head = tmp; count++; }
	else { tmp->next = nullptr; head = tail = tmp; count++; };
}

int*  dlinkedlist::pop_back() {
	if (!is_empty()) {
		int* tmp_val = new int(tail->value);
		tail = tail->prev;
		count--;
		if (count == 0)head = nullptr;
		return tmp_val;
	}
	return nullptr;
}

int* dlinkedlist::pop_front() {
	if (!is_empty()) {
		int* tmp_val = new int(head->value);
		head = head->next;
		count--;
		return tmp_val;
	}
}

bool dlinkedlist::is_empty() {
	return !head;
}

void dlinkedlist::changeEl(int item, int pos) {
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

void dlinkedlist::insert(int item, int pos) {
	node* tmp_1 = head;
	int tmp_c = 0;
	if (pos == tmp_c) { push_back(item); }
	if (pos == 0) { push_front(item); }
	if (pos > tmp_c) {
		while (pos > tmp_c) {
			tmp_1 = tmp_1->next;
			tmp_c++;
		}
		node* prevIns = tmp_1->prev;
		node* tmp_2 = new node();
		tmp_2->value = item;
		if (prevIns != 0 && count != 1)
			prevIns->next = tmp_2;
		tmp_2->next = tmp_1;
		tmp_2->prev = prevIns;
		tmp_1->prev = tmp_2;
		count++;
	}
}

void dlinkedlist::reverse() {
	node* tmp = NULL;
	node* iter = head;
	while (iter != nullptr) {
		tmp = iter->prev;
		iter->prev = iter->next;
		iter->next = tmp;
		iter = iter->prev;
	}
	tmp = head;
	head = tail;
	tail = tmp;
}

void dlinkedlist::erase(int pos) {
	node* tmp_tail(tail);
	int tmp_count(count);
	if (tmp_count == pos) { pop_back(); }
	if (tmp_count == 1) { pop_front(); }
	if (!is_empty()) {
		while (pos < tmp_count) {
			tmp_tail = tmp_tail->prev;
			tmp_count--;
		}
		node* beforeDel = tmp_tail->prev;
		node* afterDel = tmp_tail->next;
		beforeDel->next = afterDel;
		afterDel->prev = beforeDel;
		count--;
		delete tmp_tail;
	}
}


int main() {
	dlinkedlist test;
	test.push_back(5);
	test.push_back(6);
	test.push_back(7);
	test.insert(3, 2);
	test.reverse();
	cout << *test.pop_back();
	cout << *test.pop_back();
	cout << *test.pop_back();
	cout << *test.pop_back();
	return 0;
}