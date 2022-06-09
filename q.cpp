#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cmath>       // for the inverse of cosine function
using namespace std;

// class begins here
class Vector {
private:
	// Private data members
	double* x;
	double* y;
	double* z;
public:
	// Default Constructor
	Vector() {
		x = nullptr;
		y = nullptr;
		z = nullptr;
	}

	// Memory Allocate
	void Memory_Allocate() {
		x = new double;
		y = new double;
		z = new double;
	}

	// Parameterised Constructor
	Vector(double* a, double* b, double* c) {
		x = new double;
		x = a;
		y = new double;
		y = b;
		z = new double;
		z = c;
	}

	// Copy Constructor
	Vector(const Vector& Vect) {
		x = new double;
		x = Vect.x;
		y = new double;
		y = Vect.y;
		z = new double;
		z = Vect.z;
	}

	// Input from User (Non friend functions, means member functions)
	void Input() {
		x = new double;
		y = new double;
		z = new double;
		cout << "Enter the x component: ";
		cin >> *x;
		cout << "Enter the y component: ";
		cin >> *y;
		cout << "Enter the z component: ";
		cin >> *z;
	}

	// Display Function (Non friend functions, means member functions)
	void Display() {
		cout << *x << "i" << " " << *y << "j" << " " << *z << "k" << endl;
	}

	// Set first variable
	void setx(double x) {
		this->x = new double;
		*this->x = x;
	}

	// Set second variable
	void sety(double y) {
		this->y = new double;
		*this->y = y;
	}

	// Set third variable
	void setz(double z) {
		this->z = new double;
		*this->z = z;
	}

	// Get first variable
	double* getx() {
		return x;
	}

	// Get second variable
	double* gety() {
		return y;
	}

	// Get third variable
	double* getz() {
		return z;
	}

	// Assignment Operator
	Vector operator =(const Vector& Vect) {
		x = Vect.x;
		y = Vect.y;
		z = Vect.z;
		return *this;
	}

	// Post increment
	Vector operator++() {
		(*(x))++;
		(*(y))++;
		(*(z))++;
		return *this;
	}

	// Pre increment
	Vector operator++(int) {
		(*(x))++;
		(*(y))++;
		(*(z))++;
		return *this;
	}

	// Post decrement
	Vector operator --() {
		(*(x))--;
		(*(y))--;
		(*(z))--;
		return *this;
	}

	// Pre decrement
	Vector operator--(int) {
		(*(x))--;
		(*(y))--;
		(*(z))--;
		return *this;
	}

	// Addition Operator Overloaded
	Vector operator +(const Vector& Vect) {
		Vector vect;
		*(vect.x) = *(this->x) + *(Vect.x);
		*(vect.y) = *(this->y) + *(Vect.y);
		*(vect.z) = *(this->z) + *(Vect.z);
		return vect;
	}

	// Subtraction Operator Overloaded
	Vector operator -(const Vector& Vect) {
		Vector vect;
		*(vect.x) = *(this->x) - *(Vect.x);
		*(vect.y) = *(this->y) - *(Vect.y);
		*(vect.z) = *(this->z) - *(Vect.z);
		return vect;
	}

	// Dot Product of two vectors
	// Equation form is: U * V = (Ux * Vx) + (Uy * Vy) + (Uz * Vz);
	double Dot_Product(const Vector vect1) {
		double _Scalar_product; 
		_Scalar_product = (*(this->x) * *(vect1.x) + *(this->y) * *(vect1.y) + *(this->z) * *(vect1.z));
		return _Scalar_product;
	}

	// Vector Magnitude
	double Vector_Magnitude() {
		double _magnitude;
		_magnitude = sqrt((*(x)) * (*(x)) + (*(y)) * (*(y)) + (*(z)) * (*(z)));
		return _magnitude;
	}

	// Destructor
	~Vector() {
		if (x != nullptr) {
			delete[] x;
			x = nullptr;
		}
	
		if (y != nullptr) {
			delete[] y;
			y = nullptr;
		}
		
		if (z != nullptr) {
			delete[] z;
			z = nullptr;
		}
		
	}

	// Friend functions(non member functions)
	friend ostream & operator <<(ostream&, const Vector&);
	friend istream & operator >>(istream&, Vector&);
	friend bool operator ==(const Vector, const Vector);
	friend bool operator !=(const Vector, const Vector);
	friend double Cosine_Angle(Vector& , Vector&);
};

// Friend function to take input from the user
istream& operator >>(istream& in, Vector& vect) {

	vect.Memory_Allocate();
	double a = *vect.x;
	double b = *vect.y;
	double c = *vect.z;
	cout << "Enter the x component: ";
	in >> a;
	cout << "Enter the y component: ";
	in >> b;
	cout << "Enter the z component: ";
	in >> c;
	vect.setx(a);
	vect.sety(b);
	vect.setz(c);

	return in;
}

// Friend function to output the given data on the screen
ostream & operator <<(ostream& out, const Vector& vect) {
	out << *(vect.x) << "i" << " " << *(vect.y) << "j" << " " << *(vect.z) << "k" << endl;
	return out;
}

// Friend Function to determine whether two vectors are equal
bool operator==(const Vector vect1, const Vector vect2) {
	bool flag;
	if (*(vect1.x) == *(vect2.x) && *(vect1.y) == *(vect2.y) && *(vect1.z) == *(vect2.z)) {
		flag = true;
		cout << "Both vectors are equal." << endl;
	}
	else {
		flag = false;
		cout << "Vectors are not equal." << endl;
	}
	return flag;
}

// Friend function to determine whether two vectors are not equal
bool operator!=(const Vector vect1, const Vector vect2) {
	bool flag;
	if (*(vect1.x) == *(vect2.x) || *(vect1.y) == *(vect2.y) || *(vect1.z) == *(vect2.z)) {
		flag = true;
		cout << "Vectors are not equal.";
	}
	else {
		flag = false;
		cout << "Vectors are equal.";
	}
	return flag;
}

// Friend function to calculate the angle between the two vectors
double Cosine_Angle(Vector& vect1, Vector& vect2) {
	double Theeta, cos_prod, magnitude_product_of_two_vectors;     

	cos_prod = vect1.Dot_Product(vect2);
	magnitude_product_of_two_vectors = (vect1.Vector_Magnitude()) * (vect2.Vector_Magnitude());
	Theeta = acos(cos_prod / magnitude_product_of_two_vectors);      // acos means arc of cosine, meaning inverse of cosine
	return Theeta;
}

// Main Driver
int main() {
	system("Color 44");       // Background and text color for console

	cout << "\t\t\tA Programme on Vectors" << endl;

	Vector U, V;      // two class objects

	cout << "First Vector: " << endl;
	cin >> U;
	cout << "Vector u is: " << U << endl;
	cout << "Magnitude of vector U is: " << U.Vector_Magnitude() << endl;

	cout << "-------------------------------------------------------------------" << endl;
	
	cout << "Second Vector: " << endl;
	cin >> V;
	cout << "Vector v is: " << V << endl;
	cout << "Magnitude of vector V is: " << V.Vector_Magnitude() << endl;

	cout << "-------------------------------------------------------------------" << endl;
	
	cout << "The dot product of vector U and V is: " << U.Dot_Product(V) << endl;

	cout << "The angle between the vector U and V is: " << Cosine_Angle(U, V) << endl;
	
	Vector p = U;
	cout << p << endl;
	cout << "-------------------------------------------------------------------" << endl;

	if (U == V) {
		cout << "The two vectors are equal." << endl;
	}
	else {
		cout << "The vectors are not equal." << endl;
	}

	cout << "-------------------------------------------------------------------" << endl;

	if (U != V) {
		cout << "The vectors are not equal." << endl;
	}
	else {
		cout << "The two vectors are equal." << endl;
	}

	cout << "-------------------------------------------------------------------" << endl;

	Vector q = U++;
	cout << q << endl;
	//q.Display();       // member function for display
	cout << "-------------------------------------------------------------------" << endl;

	Vector r = U--;
	cout << r << endl; 
	// r.Display();

	cout << "-------------------------------------------------------------------" << endl;

	Vector s = ++U;
	cout << s << endl;
	//s.Display();

	cout << "-------------------------------------------------------------------" << endl;

	Vector t = --U;
	cout << t << endl;
	//t.Display();

	cout << "-------------------------------------------------------------------" << endl;

	cout << "\t\t\t**************************THANK YOU********************************" << endl;
	system("Pause");
	return 0;
}
