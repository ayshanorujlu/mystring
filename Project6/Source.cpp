#include<iostream>
#include<assert.h>
using namespace std;


class MyString {
	char* text;
	size_t length;

	void SetLength(int len) {
		this->length = len;
	}
public:
	MyString() {
		text = NULL;
		length = NULL;
	};
	MyString(const char* text) {
		SetText(text);
	}
	MyString(const MyString& other) {
		SetText(other.text);
	}
	MyString& operator=(const MyString& other) {
		SetText(other.text);

		return*this;
	}

	void SetText(const char* text) {
		assert(text != nullptr && "Text should be different than null.");
		int l = strlen(text);
		this->text = new char[l + 1] {};
		strcpy_s(this->text, l + 1, text);
		SetLength(l);
	}

	size_t GetLength()const {
		return length;
	};
	char* GetText()const {
		return text;
	}

	char First() {
		assert(text != nullptr && "Text Null");
		return text[0];
	}
	char Last() {
		assert(text != nullptr && "Text Null");
		return text[strlen(text) - 1];
	}


	void Append(const char* newtext) {
		int newlen = strlen(newtext) + 10;
		if (newtext != nullptr && newlen > 0) {
			size_t new_length = GetLength() + newlen;
			char* new_data = new char[new_length + 1] {};

			strcat_s(new_data, GetLength() + 1, text);
			strcat_s(new_data, newlen + 1, newtext);

			delete[]this->text;
			this->text = new_data;
			new_data = nullptr;

			SetLength(new_length);
		}
		else {
			cout << "Text is null or empty:ERROR" << endl;
		}
	}

	void Clear() {
		delete[]text;
		text = nullptr;
		SetLength(0);
	}

	~MyString()
	{
		delete[]text;
	}

};

void main() {
	MyString text = "salam";
	cout << text.First() << endl;
	cout << text.Last() << endl;

}