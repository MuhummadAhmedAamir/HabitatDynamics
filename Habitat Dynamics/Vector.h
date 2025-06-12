#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

template <class T>
class MyVector {
private:
	T* arr;
	int len;
	int cap;

	void double_capacity() {
		this->cap = (this->cap == 0) ? 1 : this->cap * 2;
		T* helper = new T[this->cap];

		for (int i = 0; i < this->len; i++) {
			helper[i] = this->arr[i];
		}

		delete[] this->arr;
		this->arr = helper;
	}
public:

	MyVector() : arr(nullptr), len(0), cap(1) {
		arr = new T[cap];
	}
	MyVector(int count, T value) : len(count), cap(count) {
		arr = new T[cap];
		for (int i = 0; i < count; i++) {
			arr[i] = value;
		}
	}
	MyVector(const MyVector& other) : len(other.len), cap(other.cap) {
		arr = new T[cap];
		for (int i = 0; i < len; i++) {
			arr[i] = other.arr[i];
		}
	}
	MyVector& operator=(const MyVector& other) {
		if (this != &other) {
			delete[] arr;
			len = other.len;
			cap = other.cap;
			arr = new T[cap];
			for (int i = 0; i < len; i++) {
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}
	void print() const {
		for (int i = 0; i < this->len; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void push(const T& value) {
		if (this->len == this->cap) {
			this->double_capacity();
		}
		this->arr[this->len] = value;
		this->len++;
	}
	void pop() {
		if (this->len > 0) {
			this->len--;
		}
	}
	int size() const {
		return this->len;
	}
	T& operator [](int index) {
		if (index < 0 || index >= len) {
			throw std::out_of_range("Index out of bound");
		}
		return this->arr[index];
	}
	const T& operator [] (int index) const {
		if (index < 0 || index >= len) {
			throw std::out_of_range("Index out of bound");
		}
		return this->arr[index];
	}
	void delete_element_by_index(int index) {
		if (index < 0 || index >= len) {
			throw std::out_of_range("Index out of bound");
		}
		for (int i = index; i < len - 1; i++) {
			this->arr[i] = this->arr[i + 1];
		}
		this->len--;
	}
	void delete_element_by_value(const T& value) {
		for (int i = 0; i < this->len; i++) {
			if (this->arr[i] == value) {
				delete_element_by_index(i);
				return;
			}
		}
		cout << "Value not found.\n";
	}
	~MyVector() {
		delete[] this->arr;
	}

};

#endif 