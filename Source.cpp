#include <iostream>

using namespace std;

class complex {
private:
	double real;
	double image;
public:
	complex();
	complex(double re, double im);
	~complex() = default;
	void set(double&, double &);
	double getReal();
	double getImage();
	void sum(complex& a);
	void prod(complex& a);
	complex squarert(complex& a);
};

complex::complex() : real(0), image(0) {}

complex::complex(double re, double im) : real(re), image(im) {}

void complex::set(double& re, double& im) {
	real = re;
	image = im;
}

double complex::getReal() {
	return real;
}

double complex::getImage() {
	return image;
}

void complex::sum(complex& a) {
	real += a.getReal();
	image += a.getImage();
}

void complex::prod(complex& a) {
	double _real = real;
	double _image = image;
	real = _real*a.getReal() - _image*a.getImage();
	image = _image*a.getReal() + _real*a.getImage();
}

complex complex::squarert(complex& a) {
	double _re, _im;
	double re = a.getReal();
	double im = a.getImage();
	_re = sqrt(re + sqrt(re*re + im*im) / 2);
	_im = im / (2 * _re);
	a.set(_re, _im);
	return a;
}





class mylist {
private:
	struct node {
		complex value;
		node* next = nullptr;
	};
	int counter = 0;
	bool is_empty();
	node* head;
public:
	mylist();
	~mylist() = default;
	void push(complex& item);
	complex pop();
	int dimension();
};

mylist::mylist() :head(nullptr) {}

bool mylist::is_empty() {
	return !head;
}

void mylist::push(complex& item) {
	node* tmp = new node();
	tmp->value = item;
	tmp->next = head;
	head = tmp;
	counter++;
}

complex mylist::pop() {
	node* tmp = new node;
	tmp = head;
	head = head->next;
	counter--;
	return tmp->value;
}

int mylist::dimension() {
	return counter;
}




class vector {
private:
	mylist vect;
public:
	void add_element(complex& );
	void add(vector& );
	complex absolute();
	complex mult(vector&);
};

void vector::add_element(complex& vitya) {
	vect.push(vitya);
}

void vector::add(vector& vikusya) {
	int firstd, secondd;
	firstd = vect.dimension();
	secondd = vikusya.vect.dimension();
	if (firstd > secondd) {
		complex complex_null;
		for (int i = 0; i < (firstd - secondd); i++) {
			vikusya.vect.push(complex_null);
		}
	}
	else if (secondd > firstd) {
		complex complex_null;
		for (int i = 0; i < (secondd - firstd); i++) {
			vect.push(complex_null);
		}
	}
	complex* added_array = new complex[secondd];
	for (int i = 0; i < secondd; i++) {
		added_array[i] = vikusya.vect.pop();
	}
	complex* init_array = new complex[firstd];
	for (int i = 0; i < firstd; i++) {
		init_array[i] = vect.pop();
		init_array[i].sum(added_array[i]);
		vect.push(init_array[i]);
	}
}

complex vector::absolute() {
	int dim = vect.dimension();
	complex * array = new complex[dim];
	complex sumnum;
	for (int i = 0; i < dim; i++) {
		array[i] = vect.pop();
		array[i].prod(array[i]);
	}
	for (int i = 0; i < dim; i++) {
		sumnum.sum(array[i]);
	}
	sumnum = sumnum.squarert(sumnum);
	return sumnum;
}

complex vector::mult(vector& vikusya) {
	int firstd, secondd;
	complex result;
	firstd = vect.dimension();
	secondd = vikusya.vect.dimension();
	if (firstd > secondd) {
		complex complex_null;
		for (int i = 0; i < (firstd - secondd); i++) {
			vikusya.vect.push(complex_null);
		}
	}
	else if (secondd > firstd) {
		complex complex_null;
		for (int i = 0; i < (secondd - firstd); i++) {
			vect.push(complex_null);
		}
	}
	complex* added_array = new complex[secondd];
	for (int i = 0; i < secondd; i++) {
		added_array[i] = vikusya.vect.pop();
	}
	complex* init_array = new complex[firstd];
	for (int i = 0; i < firstd; i++) {
		init_array[i] = vect.pop();
		init_array[i].prod(added_array[i]);
		result.sum(init_array[i]);
	}
	return result;

}



int main() {
	vector hello;
	vector world;
	complex seven(7, 0);
	complex one(1, 0);
	complex eight(8, 0);
	hello.add_element(seven);
	hello.add_element(one);
	world.add_element(eight);
	world.mult(hello);
	world.absolute();
	return 0;
}