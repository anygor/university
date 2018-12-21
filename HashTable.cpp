#include <iostream>
#include <string>

using namespace std;


class hashmap {
private:
	static const int tableSize = 16; // to define the size of a table inside of the class definition
	struct item {
		string key;
		int value;
		item* next;
	};
	item* HashTable[tableSize];
public:
	hashmap();
	int hashfunc(string key);
	void addItem(string name, int points);
	int getKey(string name);
	int ItemsInBucket(int bucket);
	void printTable();
	void printInIndex(int bucket);
};

hashmap::hashmap() {
	for (int i = 0; i < tableSize; i++) {
		HashTable[i] = new item;
		HashTable[i]->key = "none";
		HashTable[i]->value = 0;
		HashTable[i]->next = nullptr;
	}
}

int hashmap::hashfunc(string key) {
	int hash = 0;
	int bucket;
	for (int i = 0; i < key.length(); i++) { // ascii
		hash += (int)key[i];
	}
	bucket = hash % tableSize;
	return bucket;
}

void hashmap::addItem(string name, int points) {
	int bucket = hashfunc(name);
	if (HashTable[bucket]->key == "none") {
		HashTable[bucket]->key = name;
		HashTable[bucket]->value = points;
	}
	else {
		item* pointer = HashTable[bucket];
		item* tmp = new item;
		tmp->key = name;
		tmp->value = points;
		tmp->next = nullptr;
		while (pointer->next != nullptr) {
			pointer = pointer->next;
		}
		pointer->next = tmp;
	}
}

int hashmap::getKey(string name) {
	int bucket = hashfunc(name);
	int val;
	bool found = false;
	item* ptr = HashTable[bucket];
	while (ptr != nullptr) {
		if (ptr->key == name) {
			found = true;
			return ptr->value;
		}
		ptr = ptr->next;
	}
	if (found == false) {
		return -1;
	}
}

int hashmap::ItemsInBucket(int bucket) {  // UNNECESSARY
	int counter = 0;
	if (HashTable[bucket]->key == "none") {
		return counter;
	}
	else {
		counter++;
		item* pointer = HashTable[bucket];
		while (pointer->next != nullptr) {
			pointer = pointer->next;
			counter++;
		}
	}
	return counter;
}

void hashmap::printTable() {    // UNNECESSARY
	int number;
	for (int i = 0; i < tableSize; i++) {
		number = ItemsInBucket(i);
		cout << "---------------\n";
		cout << "bucket = " << i << endl;
		cout << HashTable[i]->key << endl;
		cout << HashTable[i]->value << endl;
		cout << "amount of items = " << number << endl;
		cout << "---------------\n";

	}
}

void hashmap::printInIndex(int bucket) {   // UNNECESSARY
	item* ptr = HashTable[bucket];
	if (ptr->key == "none") {
		cout << "bucket = " << bucket << " is empty" << endl;
	}
	else {
		cout << "bucket " << bucket << " contains the following items: \n";
		while (ptr != nullptr) {
			cout << "---------------\n";
			cout << ptr->key << endl;
			cout << ptr->value << " points" << endl;
			cout << "---------------\n";
			ptr = ptr->next;
		}
	}
}

int main() {
	hashmap test;
	int a, b, c, d, e, f;
	test.addItem("Andy", 15);
	test.addItem("Dave", 15);
	test.addItem("Dany", 0);
	test.addItem("John", 30);
	test.addItem("Dennis", 20);
	a = test.getKey("Andy");
	b = test.getKey("Dave");
	c = test.getKey("Dennis");
	d = test.getKey("John");
	e = test.getKey("Dany");
	f = test.getKey("Malia");
	cout << a << " " << b << " " << c << " " << d << " " << e << " " << f;
	return 0;
}
