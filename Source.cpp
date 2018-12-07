#include <iostream>

using namespace std;


class stack {

private:
	struct node {
		int value;
		node* prev = nullptr;
	};
	node* top;
	bool is_empty();
	unsigned int sz = 0;

public:
	stack() : top(nullptr) {}
	~stack() {}
	void push(int value);
	int* pop();
	void reverse(stack);
};


bool stack::is_empty() {
	return !top;
}


void stack::push(int value) {
	node* tmp = new node();
	tmp->value = value;
	tmp->prev = top;
	top = tmp;
	sz++;
}

void stack::reverse(stack stack) {
	int a = sz;
	int** string_ptrs = new int*[a];
	for (int i = 0; i < a; i++) {
		string_ptrs[i] = pop();
	}
	for (int i = 0; i < a; i++) {
		push(*string_ptrs[i]);
	}
}

int* stack::pop() {
	if (!is_empty()) {
		int* tmp_val = new int(top->value);
		node* tmp_top = top;
		top = top->prev;
		delete tmp_top;
		sz--;
		return tmp_val;
	}
	return nullptr;
}

int main() {
	stack test;
	for (int i = 1; i < 10; i++) {
		test.push(i);
	}
	test.reverse(test);

	for (int i = 0; i < 9; i++) {
		cout << *(test.pop());
	}

	return 0;
}