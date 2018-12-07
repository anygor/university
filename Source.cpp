#include <iostream>

class rational {
private:
	int numerator;
	int denominator;
public:
	rational();
	rational(int num, int den);			// constructors
	~rational() {}
	rational simplify(rational);
	void set(int, int);
	int getNum();
	int getDen();
	rational sum(rational, rational);	// sum
	rational sub(rational, rational);		// subtraction
	rational mult(rational, rational);		// multiplication
	rational div(rational, rational);		// division
	void print();				// self-explanatory, fractioned
};

using namespace std;

rational::rational() {
	numerator = 0;
	denominator = 1;
}

rational::rational(int num, int den) {
	if (num < den) {
		if (den % num == 0 && num != 1) {
			numerator = num / (den / num);
			denominator = den / (den / num);
		}
		else {
			numerator = num;
			denominator = den;
		}
	}
	else if (num > den){
		if (num % den == 0 && den != 1) {
			numerator = num / den;
			denominator = 1;
		}
		else {
			numerator = num;
			denominator = den;
		}
	}
	else {
		numerator = 1;
		denominator = 1;
	}
}

rational rational::simplify(rational a) {
	int num = a.getNum();
	int den = a.getDen();
	if (num < den) {
		if (den % num == 0 && num != 1) {
			numerator = num / (den / num);
			denominator = den / (den / num);
		}
		else {
			numerator = num;
			denominator = den;
		}
	}
	else if(num > den) {
		if (num % den == 0 && den != 1) {
			numerator = num / den;
			denominator = 1;
		}
		else {
			numerator = num;
			denominator = den;
		}
	}
	else {
		numerator = 1;
		denominator = 1;
	}

	return a;
}

void rational::set(int a, int b) {
	numerator = a;
	denominator = b;
}

int rational::getNum() {
	return numerator;
}

int rational::getDen() {
	return denominator;
}

rational rational::sum(rational a, rational b) {
	rational tmp;
	int o = a.getNum()*b.getDen();
	int p = b.getNum()*a.getDen();
	int r = a.getDen();
	int s = b.getDen();
	tmp.set(o + p, r * s);
	tmp.simplify(tmp);
	return tmp;
}

rational rational::sub(rational a, rational b) {
	rational tmp;
	tmp.set(a.getNum()*b.getDen() - b.getNum()*a.getDen(), a.getDen() * b.getDen());
	tmp.simplify(tmp);
	return tmp;
}

rational rational::mult(rational a, rational b) {
	rational tmp;
	tmp.set(a.getNum()*b.getNum(), a.getDen()*b.getDen());
	tmp.simplify(tmp);
	return tmp;
}

rational rational::div(rational a, rational b) {
	rational tmp;
	tmp.set(a.getNum()*b.getDen(), a.getDen()*b.getNum());
	tmp.simplify(tmp);
	return tmp;
}

void rational::print() {
	cout << numerator << "/" << denominator;
}


int main() {
	rational c, sum;
	rational a(3, 2);
	rational b(1, 2);
	sum = c.sum(a, b);
	sum.print();

	return 0;
}