#include <iostream>
using namespace std;
#ifndef STRING_H
#define STRING_H

class String {
	char* c_string;
	int size;
	int capacity;

public:

	String();

	int length(const char* input);

	int length(String s);

	String(const char* input);

	String(const String& copy);

	String(const char ch, int number);

	bool is_greater(const String& M);

	void regrow(String& str);

	void insert_att(int idx, char ch);

	void insert_at(int idx, const String& sub);

	String& operator = (const String& s1);

	bool is_less(const String& M);

	bool is_equal(const String& M);

	int find_first(char ch);

	int find_last(char ch);

	void regrow(int*& arr, int& size);

	int* find_all(char ch, int& number_of_characters);

	void remove_at(int idx);

	void replace_first(char c);

	void remove_first(char ch);

	void remove_last(char ch);

	void remove_all(char ch);

	String concat(const String& s2);

	int* all_sub_strings(const char* ch, int& no_of_substrings);

	int find_first(const String& s1) const;

	int find_last(const String& s1);

	int stoi(const String s);

	String regrow_string(String s);

	String itos(int number);

	String trim(String s);

	String to_upper();

	String to_lower();

	String* split(char delim, int& count) const;

	char& operator[](int i) const;

	char& operator[](int i);

	bool operator == (const String& s);

	friend istream& operator >>(istream& os, String& s1); //can't use const here because i won't be able to modify it

	friend ostream& operator <<(ostream& os, const String& s1);

	~String();
};
String operator + (String ptr, String ptr2);

#endif 