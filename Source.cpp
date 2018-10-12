#include <iostream>

using namespace std;


class stack {

private:
	struct node {
		int value;
		node* prev = nullptr; //NULL
	};
	node* top;
	bool is_empty();
	unsigned int sz = 0;

public: //public API
	stack() : top(nullptr) {}
	~stack() {}
	void push(int value);
	int* pop();
	void reverse(stack);
};


bool stack::is_empty() {
	return !top;
}


// stack::stack() {
// 	top = nullptr;
// }



void stack::push(int value) {
	node* tmp = new node();
	tmp->value = value;
	tmp->prev = top;
	top = tmp;
	sz++;
}

void stack::reverse(stack stack) {
	node**stack_ptrs = new node*[sz];
	for (int i = 0; i < 9; i++) {
		stack_ptrs[i] = top;
		pop();
	}
	for (int i = 0; i < 9; i++) {
		/*stack.push(*stack_ptrs[i]);*/
		cout << stack_ptrs[i]<<" ";
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
	stack kek;
	for (int i = 1; i < 10; i++) {
		kek.push(i);
	}
	kek.reverse(kek);/*
	for (int i = 0; i < 9; i++) {
		cout << *(kek.pop());
	}*/

	return 0;
}