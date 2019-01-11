#include <iostream>

using namespace std;

class mystring {
private:
	int length;
	char* mas;
public:
	mystring();
	mystring(mystring&);
	mystring(char*);
	char* getMas();
	mystring append(mystring&);
	mystring substring(int start, int length);
	mystring* split(char delim);
	mystring format_single(char&, char&);
	mystring format_multiple(char* , char* );
};

mystring::mystring() :length(0), mas(nullptr) {}

mystring::mystring(char* string) {
	mas = string;
	length = strlen(string);
}

mystring::mystring(mystring& taken) {
	length = taken.length;
	mas = taken.mas;
}

char* mystring::getMas() {
	return mas;
}

mystring mystring::append(mystring& added) {
	int tmp = length;
	tmp += added.length;
	char* tmpchar = new char[tmp];
	for (int i = 0; i < length; i++) {
		tmpchar[i] = mas[i];
	}
	for (int i = 0; i < tmp - length; i++) {
		tmpchar[i + length] = added.mas[i];
	}
	tmpchar[tmp] = '\0';
	return tmpchar;
}

mystring mystring::substring(int start, int range) {
	char* tmp = new char[range];
	int index = 0;
	for (int i = start; i < range+1; i++){
		tmp[index] = mas[i];
		index++;
	}
	tmp[range] = '\0';
	return tmp;
}

mystring* mystring::split(char delim) {
	mystring* core = new mystring[length];
	char* tmp = new char[length + 1];
	int main_index = 0, sup_index = 0;
	for (int i = 0; i < length + 1; i++) {
		if (mas[i] != delim) {
			tmp[sup_index] = mas[i];
			sup_index++;
		}
		else if (mas[i] == delim) {
			tmp[sup_index] = delim;
			tmp[sup_index + 1] = '\0';
			sup_index = 0;
			core[main_index].mas = tmp;
			core[main_index].length = strlen(tmp);
			main_index++;
			continue;
		}
		if (i == length) {
			tmp[sup_index] = '\0';
			core[main_index].mas = tmp;
			break;
		}
	}
	return core;
}

mystring mystring::format_single(char& taken, char& comin) {  // single character;  void couldn't allow access :(
	char* tmp = new char[length + 1];
	for (int i = 0; i < length; i++) {
		if (mas[i] != taken) {
			tmp[i] = mas[i];
		}
		else {
			tmp[i] = comin;
		}
	}
	tmp[length] = '\0';
	return tmp;
}

mystring mystring::format_multiple(char* taken, char* comin) {
	int new_length = length * strlen(comin), taken_length = strlen(taken), comin_length = strlen(comin);
	char* tmp = new char[new_length];
	for (int i = 0; i < new_length; i++) {
		if (mas[i] == taken[0]) {
			int equality_reached = 0;
			for (int j = i; j < taken_length + i; j++) {
				if (mas[j] == taken[j-i]) {
					equality_reached++;
				}
			}
			if (equality_reached == taken_length) {
				int helping_i = i, filled = 0;
				char* tmp_support = new char[new_length - i];
				for (int q = 0; q < comin_length; q++) {
					tmp[q + helping_i] = comin[q];
					tmp_support[q] = mas[i + comin_length - 1];
					i++;
					filled++;
				}
				if (filled == comin_length) {
					for (int q = 0; q <comin_length; q++) {
						tmp[q + i] = tmp_support[q];
					}
				}
			}

		}
		else if(mas[i] != '\0'){
			tmp[i] = mas[i];
		}
		else {
			tmp[i+1] = '\0';
			break;
		}
	}
	return tmp;
}

int main() {
	//mystring q("stalinka");
	//q = q.format_multiple("in", "noy");
	mystring q("i love me");
	q = q.format_multiple("love", "hayte");
	cout << q.getMas();
	return 0;
}