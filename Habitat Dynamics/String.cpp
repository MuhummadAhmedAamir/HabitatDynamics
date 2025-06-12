#include <iostream>
using namespace std;
#include "C:/Users/ahmed/OneDrive/Desktop/LAB 8 OOP/string.h"

String::String() {
	c_string = nullptr;
	size = capacity = 0;
}

int String::length(const char* input) {
	int count = 0;
	for (int i = 0; input[i] != '\0'; i++) count++; 	//null is not included
	return count;
}

int String::length(String s) { // Test Function
	int count = 0;
	for (int i = 0; s.c_string[i] != '\0'; i++) count++;
	return count;
}

String::String(const char* input) {
	this->size = length(input);
	this->capacity = this->size + 1;
	this->c_string = new char[this->capacity];

	for (int i = 0; i < this->capacity; i++) {
		this->c_string[i] = input[i];
	}
	this->c_string[this->size] = '\0';
}

String::String(const String& copy) {

	this->size = copy.size;
	this->capacity = copy.capacity;
	this->c_string = new char[this->capacity];

	for (int i = 0; i < this->size; i++) {
		this->c_string[i] = copy.c_string[i];
	}
	this->c_string[this->size] = '\0';
}

String::String(const char ch, int number) {
	this->size = number;
	this->c_string = new char[this->size];

	for (int i = 0; i < this->size; i++) {
		this->c_string[i] = ch;
	}
}

void String::regrow(String& str) {
	//str.size;

}

void String::insert_att(int idx, char ch) {

	char* input = new char[this->capacity + 1];

	for (int i = 0; i < idx; i++)
		input[i] = this->c_string[i];
	input[idx] = ch;

	for (int i = idx + 1; i < this->capacity; i++) {
		input[i] = this->c_string[i];
	}

	delete[]this->c_string;
	this->c_string = input;
	this->size++;
	this->capacity++;


}

void String::insert_at(int idx, const String& sub) {
	int newSize = this->size + sub.size;
	char* input = new char[newSize + 1];
	this->size = this->capacity = newSize + 1;

	int i;
	for (i = 0; i < idx; i++) {
		input[i] = this->c_string[i];
	}

	for (int j = 0; j < sub.size; j++, i++) {
		input[i] = sub.c_string[j];
	}

	for (int j = idx; (j < this->size && this->c_string[j] != '\0'); j++, i++) {
		input[i] = this->c_string[j];
	}
	input[newSize] = '\0';

	delete[] this->c_string;
	this->c_string = input;

}

String& String:: operator = (const String& s1) {
	if (this != &s1) {
		delete[]c_string;
		this->size = s1.size;
		this->capacity = s1.capacity;
		this->c_string = new char[this->capacity];

		for (int i = 0; i < this->size; i++) {
			this->c_string[i] = s1.c_string[i];
		}
		this->c_string[this->size] = '\0';
	}
	return *this;
}

bool String::is_greater(const String& M) {
	int smaller = this->size < M.size ? this->size : M.size;

	for (int i = 0; i < smaller; i++) {
		if (this->c_string[i] > M.c_string[i]) return true;
		if (this->c_string[i] < M.c_string[i]) return false;
	}

	return this->size > M.size;
}

bool String::is_less(const String& M) {
	int smaller = this->size < M.size ? this->size : M.size;

	for (int i = 0; i < smaller; i++) {
		if (this->c_string[i] > M.c_string[i]) return false;
		if (this->c_string[i] < M.c_string[i]) return true;
	}

	return this->size < M.size;
}

bool String::is_equal(const String& M) {
	if (this->size != M.size) return false;

	for (int i = 0; i < this->size; i++) {
		if (this->c_string[i] != M.c_string[i]) return false;
	}
	return true;
}

int String::find_first(char ch) {
	for (int i = 0; i < this->size; i++) {
		if (this->c_string[i] == ch) {
			return i;
		}
	}
}

int String::find_last(char ch) {
	for (int i = this->size; i >= 0; i--) {
		if (this->c_string[i] == ch) {
			return i;
		}
	}
}

void String::regrow(int*& arr, int& size) {
	int* helper = new int[size + 1];
	for (int i = 0; i < size; i++) {
		helper[i] = arr[i];
	}
	delete[]arr;
	arr = helper;
	size++;
}

int* String::find_all(char ch, int& number_of_characters)
{
	int* index_array = nullptr;
	number_of_characters = 0;
	int size = 0;

	for (int i = 0; i < this->size; i++) {
		if (this->c_string[i] == ch) {
			regrow(index_array, size);
			index_array[size - 1] = i;
			number_of_characters++;
		}
	}

	return index_array;
}

void String::remove_at(int idx) {
	char* new_Array = new char[this->size];

	for (int i = 0, j = 0; i < this->size; i++) {
		if (i != idx) {
			new_Array[j++] = this->c_string[i];
		}
	}
	new_Array[this->size - 1] = '\0';

	delete[]this->c_string;
	this->c_string = new_Array;
	this->size--;
	this->capacity--;
}

void String::replace_first(char c)
{
	this->c_string[0] = c;
}

void String::remove_first(char ch)
{
	int index = find_first(ch);
	char* new_String = new char[this->size];

	for (int i = 0, j = 0; i < this->size; i++) {
		if (i != index) {
			new_String[j++] = this->c_string[i];
		}
	}
	new_String[this->size - 1] = '\0';

	delete[]this->c_string;
	this->c_string = new_String;
	this->size--;
	this->capacity--;

}

void String::remove_last(char ch) {
	int index = find_last(ch);
	char* new_String = new char[this->size];

	for (int i = 0, j = 0; i < this->size; i++) {
		if (i != index) {
			new_String[j++] = this->c_string[i];
		}
	}
	new_String[this->size - 1] = '\0';

	delete[] this->c_string;
	this->c_string = new_String;
	this->capacity--;
	this->size--;
}

void String::remove_all(char ch) {
	int no_of_occurrences = 0;
	int* index = find_all(ch, no_of_occurrences);

	int newSize = this->size - no_of_occurrences;
	char* new_Array = new char[newSize + 1];

	for (int i = 0, j = 0, idx = 0; i < this->size; i++) {
		if (j < no_of_occurrences && i == index[j]) {
			j++;
		}
		else {
			new_Array[idx++] = this->c_string[i];
		}
	}
	new_Array[newSize] = '\0';

	delete[] this->c_string;
	delete[] index;
	this->c_string = new_Array;
	this->size = newSize;
	this->capacity = newSize + 1;
}

String String::concat(const String& s2) {
	String resultant;
	resultant.size = this->size + s2.size;
	resultant.capacity = this->capacity + s2.capacity;
	resultant.c_string = new char[resultant.capacity];

	int i = 0;
	for (; i < this->size; i++) {
		resultant.c_string[i] = this->c_string[i];
	}
	for (int j = 0; j < s2.size; j++) {
		resultant.c_string[i++] = s2.c_string[j];
	}

	resultant.c_string[resultant.size] = '\0';
	return resultant;
}

int* String::all_sub_strings(const char* ch, int& no_of_substrings) {
	int len = length(ch);
	bool found = false;
	int* index = nullptr;
	int size_of_index = 0;
	int k = 0;

	for (int i = 0; i < this->size; i++) {
		found = false;
		if (this->c_string[i] == ch[0]) {
			k = i + 1;
			for (int j = 1; j < len; j++) {
				if (this->c_string[k] == ' ') k++;
				if (this->c_string[k] != ch[j]) {
					found = true;
					break;
				}
				k++;
			}
			if (!found) {
				regrow(index, size_of_index);
				index[size_of_index - 1] = i;
				no_of_substrings++;
			}
		}
	}
	return index;
}

int String::find_first(const String& s1) const {
	int size = 0;
	bool found = false;

	int k = 0;

	for (int i = 0; i < this->size; i++) {
		found = false;
		if (this->c_string[i] == s1.c_string[0]) {
			k = i + 1;
			for (int j = 1; j < s1.size; j++) {
				if (this->c_string[k] == ' ') k++;
				if (this->c_string[k] != s1.c_string[j]) {
					found = true;
					break;
				}
				k++;
			}
			if (!found) {
				return i;
			}
		}
	}
}

int String::find_last(const String& s1) {
	bool found = false;
	int* index = nullptr;
	int size_of_index = 0;
	int k = 0;

	for (int i = 0; i < this->size; i++) {
		found = false;
		if (this->c_string[i] == s1.c_string[0]) {
			k = i + 1;
			for (int j = 1; j < s1.size; j++) {
				if (this->c_string[k] == ' ') k++;
				if (this->c_string[k] != s1.c_string[j]) {
					found = true;
					break;
				}
				k++;
			}
			if (!found) {
				regrow(index, size_of_index);
				index[size_of_index - 1] = i;
			}
		}
	}
	return index[size_of_index - 1];   //returning last occurence
}

int String::stoi(const String s) {
	int digit = 0, num = 0, i = 0;

	while (s.c_string[i] != '\0') {
		digit = s.c_string[i] - '0';
		num = num * 10 + digit;
		i++;
	}
	return num;
}

String String::regrow_string(String s) { //test function
	String helper;
	helper.size = s.size + 1;
	helper.capacity = s.capacity + 1;
	helper.c_string = new char[helper.capacity];

	for (int i = 0; i < s.size; i++) {
		helper.c_string[i] = s.c_string[i];
	}
	helper.c_string[helper.size] = '\0';
	delete[]s.c_string;
	return helper;
}

//incomplete itos
String String::itos(int number) {
	int digit = 0, actual_number = number;
	int size = 0, idx = 0;
	String s;

	while (number >= 0) {
		number /= 10;
		size++;
	}
	s.c_string = new char[size + 1];
	while (actual_number != 0 && idx < size) {
		digit = actual_number % 10;
		digit = digit + '0'; //doing opposite of what i did in stoi
		s.c_string[idx] = digit;
		idx++;
		actual_number = actual_number / 10;
	}

	s.c_string[size] = '\0';
	s.size = size;
	s.capacity = capacity;

	return s;
}

String String::trim(String s) {
	int starting_index = 0, ending_index = s.size - 1;

	while (starting_index < s.size && (s.c_string[starting_index] == ' ' || s.c_string[starting_index] == '\t' || s.c_string[starting_index] == '\n')) {
		starting_index++;
	}

	while (ending_index > starting_index && (s.c_string[ending_index] == ' ' || s.c_string[ending_index] == '\t' || s.c_string[ending_index] == '\n')) {
		ending_index--;
	}

	int new_size = ending_index - starting_index + 1;
	String trimmed_string;
	trimmed_string.size = new_size;
	trimmed_string.capacity = new_size + 1;
	trimmed_string.c_string = new char[trimmed_string.capacity];

	for (int i = 0; i < new_size; i++) {
		trimmed_string.c_string[i] = s.c_string[starting_index + i];
	}

	trimmed_string.c_string[new_size] = '\0';

	return trimmed_string;
}

String String::to_upper() {
	String uppercase;
	uppercase.size = this->size;
	uppercase.capacity = this->capacity;
	uppercase.c_string = new char[uppercase.capacity];

	for (int i = 0; i < this->size; i++) {
		if (this->c_string[i] >= 'a' && this->c_string[i] <= 'z') {
			uppercase.c_string[i] = this->c_string[i] - 32;
		}
		else {
			uppercase.c_string[i] = this->c_string[i];
		}
	}
	uppercase.c_string[uppercase.size] = '\0';

	return uppercase;
}

String String::to_lower() {
	String lowercase;
	lowercase.size = this->size;
	lowercase.capacity = this->capacity;
	lowercase.c_string = new char[lowercase.capacity];

	for (int i = 0; i < this->size; i++) {
		if (this->c_string[i] >= 'A' && this->c_string[i] <= 'Z') {
			lowercase.c_string[i] = this->c_string[i] + 32;
		}
		else {
			lowercase.c_string[i] = this->c_string[i];
		}
	}
	lowercase.c_string[lowercase.size] = '\0';

	return lowercase;
}

String* String::split(char delim, int& count) const {
	count = 1;
	for (int i = 0; i < this->size; i++) {
		if (this->c_string[i] == delim) count++;
	}

	String* parts = new String[count];
	int start = 0, parts_index = 0;

	for (int i = 0; i <= this->size; i++) {
		if (this->c_string[i] == '\0' || this->c_string[i] == delim) {
			int length = i - start;  //length of substring which i wanna extract
			parts[parts_index].size = length;
			parts[parts_index].capacity = length + 1;
			parts[parts_index].c_string = new char[length + 1];

			for (int j = 0; j < length; j++) {
				parts[parts_index].c_string[j] = this->c_string[start + j];
			}
			parts[parts_index].c_string[length] = '\0';
			parts_index++;
			start = i + 1;
		}
	}

	return parts;
}


char& String::  operator[](int i) const {
	return this->c_string[i];
}
char& String::  operator[](int i) {      //returning a reference.
	return this->c_string[i];
}

bool String:: operator == (const String& s) {
	//	if (s.size != this->size) return false;
	for (int i = 0; i < this->size; i++) {
		if (this->c_string[i] != s.c_string[i]) return false;
	}
	return true;
}

ostream& operator <<(ostream& os, const String& s1) {
	for (int i = 0; i < s1.size; i++) {
		os << s1.c_string[i];
	}

	return os;
}


istream& operator >>(istream& os, String& s1) {
	char temp[256];
	os.getline(temp, 256, ',');

	delete[] s1.c_string;
	int len = s1.length(temp);
	s1.size = len;
	s1.capacity = len + 1;
	s1.c_string = new char[s1.capacity] {};

	for (int i = 0; i < s1.size; i++) {
		s1.c_string[i] = temp[i];
	}

	return os;

}
String:: ~String() {
	delete[]c_string;
}

String operator + (String ptr, String ptr2) {
	String result;
	result = ptr.concat(ptr2);
	return result;
}
//int main() {
//
//
//	String s1("Hello");
//	const String s2("Ahmed");
//
//	s2[0] = 'N';
//	s2.print();
//
//	s1[0] = 'A';
//	s1.print();
//
//	String s3 = "Hello" + s2;
//	s3.print();
//
//
//	return 0;
//}



