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
