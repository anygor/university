//
#include <iostream>

using namespace std;

struct node {
	int value;
	node* prev = nullptr;
};


node* g_top(nullptr); // init top of stack

bool isempty() {
	return !g_top;
}

void push(int value) {
	node* tmp = new node();
	tmp->value = value;
	tmp->prev = g_top;
	g_top = tmp;
}

int* pop() {
	if (!isempty()) {
		//int tmp_val = g_top->value;
		int* tmp_val = new int(g_top->value);
		node* tmp_top = g_top;
		g_top = g_top->prev;
		delete tmp_top;
		return tmp_val;
	}
	return nullptr;
}



int main() {
	for (int i = 1; i < 10; i++) {
		push(i);
	}
	int* a[9];
	for (int i = 0; i < 9; i++) {
		a[i] = pop();
	}
	for (int i = 0; i < 9; i++) {
		push(*a[i]);
	}

	while (!isempty()) {
		cout << *pop() << endl;
	}
	return 0;
}