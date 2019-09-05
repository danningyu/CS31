//Danning Yu
//CS31 Project 4
#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;

//check boundary cases!! esp when size = 0
//check that string values are actually changed!
//implement test cases

bool hasDuplicates(const string array[], int size);
int  countAllDigits(const string array[], int size);
bool isInDecreasingOrder(const string array[], int size);
int  shiftRight(string array[], int size, int amount, string placeholder);
int  find(const string array[], int size, string match);
int  replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter);
bool isNumber(char testChar); //if character is 0-9, copied from my project 3



int main() {
	string test1[8] = {
		"samwell", "jon", "margaery", "daenerys",
		"tyrion", "sansa", "howard123", "jon" };
	string test2[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
	string test3[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
	string test4[3] = { "", "", "" };
	string test5[5] = { "123456", "&*(ABC", "foo" };
	string test6[12] = {
	"samwell", "jon", "margaery", "daenerys",
	"tyrion", "sansa", "howard123", "hello" };
	string test7[6] = { "hello","abc",  "Project 4", "CS31", "ABC", "!Bang" };
	string test8[3] = { "Hello", "Goodbye", "Goodbye" };

	{assert(hasDuplicates(test1, 3) == false);
	assert(hasDuplicates(test1, 6) == false);
	assert(hasDuplicates(test1, 8) == true);
	assert(hasDuplicates(test6, 10) == true);
	assert(hasDuplicates(test4, 3) == true);
	assert(hasDuplicates(test1, 0) == false);
	assert(hasDuplicates(test1, -1) == false); }

	{	assert(countAllDigits(test1, 8) == 3);
	assert(countAllDigits(test2, 6) == 0);
	assert(countAllDigits(test1, 6) == 0);
	assert(countAllDigits(test4, 3) == 0);
	assert(countAllDigits(test5, 3) == 6);
	assert(countAllDigits(test1, 0) == -1);
	assert(countAllDigits(test1, -2) == -1); }

	{assert(isInDecreasingOrder(test7, 5) == true);
	assert(isInDecreasingOrder(test1, 5) == false);
	assert(isInDecreasingOrder(test4, 3) == false);
	assert(isInDecreasingOrder(test2, 3) == false);
	assert(isInDecreasingOrder(test2, 6) == false);
	assert(isInDecreasingOrder(test5, 3) == false);
	assert(isInDecreasingOrder(test8, 2) == true);
	assert(isInDecreasingOrder(test8, 3) == false);
	assert(isInDecreasingOrder(test1, -1) == false);
	assert(isInDecreasingOrder(test1, 0) == true);
	assert(isInDecreasingOrder(test1, 1) == true);
	assert(isInDecreasingOrder(test6, 0) == true);
	assert(isInDecreasingOrder(test5, 1) == true); }

	{assert(find(test1, -500, "foo") == -1);
	assert(find(test1, 8, "jon") == 1);
	assert(find(test1, 8, "howard123") == 6);
	assert(find(test2, 6, "gamma") == 2);
	assert(find(test2, 6, "gamma") != 3);
	assert(find(test2, 6, "alpha") == 0);
	assert(find(test2, 6, "zeta") == -1);
	assert(find(test2, 0, "gamma") == -1);
	assert(find(test4, 3, "") == 0);
	assert(find(test5, 3, "foo") == 2);
	assert(find(test7, 2, "abc") == 1);
	assert(find(test7, 2, "CS31") == -1);
	assert(find(test8, 3, "Goodbye") == 1);
	assert(find(test8, 0, "Goodbye") == -1);
	assert(find(test8, -2, "Goodbye") == -1); }

	{
		
	assert(shiftRight(test1, 5, 3, "foo") == 3);
	assert(test1[0] == "foo");
	assert(test1[1] == "foo");
	assert(test1[2] == "foo");
	// cout << test1[3] << endl;
	assert(test1[3] == "samwell");
	assert(test1[4] == "jon");
	string test1A[8] = {
		"samwell", "jon", "margaery", "daenerys",
		"tyrion", "sansa", "howard123", "jon" };
	assert(shiftRight(test1A, 6, 5, "foo") == 5);
	assert(test1A[0] == "foo" && test1A[1] == "foo" && test1A[2] == "foo" && test1A[3] == "foo");
	assert(test1A[5] == "samwell");
	assert(shiftRight(test4, 3, 2, "Hello") == 2);
	assert(test4[0] == "Hello" && test4[1] == "Hello");
	assert(test4[2] == "");
	assert(shiftRight(test4, 0, 0, "Hello") == 0);
	assert(shiftRight(test4, -1, 0, "Hello") == -1);
	assert(shiftRight(test4, 0, -1, "Hello") == -1);
	assert(shiftRight(test4, 1, 1, "Test") == 1);
	assert(test4[0] == "Test");
	assert(test4[1] == "Hello");
	assert(test4[2] == "");
	assert(shiftRight(test8, 3, 1, "Goodbye") == 1);
	assert(test8[0] == "Goodbye");
	assert(test8[1] == "Hello");
	// cout <<"index 2 has " << test8[2] << endl;
	assert(test8[2] == "Goodbye");
	//do cases with test2
	assert(shiftRight(test2, 5, 1, "gamma") == 1);
	assert(test2[0] == "gamma");
	assert(test2[1] == "alpha");
	assert(test2[2] == "beta");
	assert(test2[3] == "gamma" && test2[4] == "gamma");
	assert(shiftRight(test2, 6, 2, "beta") == 2);
	assert(test2[0] == "beta" && test2[1] == "beta");
	assert(test2[2] == "gamma");
	assert(test2[3] == "alpha");
	assert(test2[4] == "beta");
	assert(test2[5] == "gamma"); }

	string test1B[8] = {
		"samwell", "jon", "margaery", "daenerys",
		"tyrion", "sansa", "howard123", "jon" };
	string test2B[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
	string test3B[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
	string test4B[3] = { "", "", "" };
	string test5B[5] = { "123456", "&*(ABC", "foo" };
	string test6B[12] = {
	"samwell", "jon", "margaery", "daenerys",
	"tyrion", "sansa", "howard123", "hello" };
	string test7B[6] = { "hello","abc",  "Project 4", "CS31", "ABC", "!Bang" };
	string test8B[3] = { "Hello", "Goodbye", "Goodbye" };

	assert(replaceAllCharacters(test1B, 5, 'z', 'a') == 0);
	assert(replaceAllCharacters(test1B, 8, 's', 'H') == 4);
	assert(replaceAllCharacters(test1B, -1, 'j', 'd') == -1);
	assert(replaceAllCharacters(test1B, 0, 'd', 'f') == -1);
	assert(replaceAllCharacters(test1B, -5, 'z', 'a') == -1);
	assert(test1B[0] == "Hamwell");
	assert(test1B[1] == "jon" && test1B[7] == "jon");
	assert(test1B[2] == "margaery");
	assert(test1B[3] == "daeneryH");
	assert(test1B[4] == "tyrion");
	assert(test1B[5] == "HanHa");
	assert(test1B[6] == "howard123");
	assert(replaceAllCharacters(test2B, 3, 'a', 'F') == 5);
	assert(replaceAllCharacters(test2B, 6, 'm', 'G') == 4);
	assert(test2B[0] == "FlphF");
		assert(test2B[5] == "delta");
	assert(test2B[1] == "betF" && test2B[4] == "beta");
	assert(test2B[2] == "gFGGF" && test2B[3] == "gaGGa");
	assert(replaceAllCharacters(test4B, 3, 'a', 'F') == 0);
	assert(replaceAllCharacters(test7B, 6, '3', '9') == 1);
	assert(test7B[3] == "CS91");
	assert(replaceAllCharacters(test8B, 3, 'o', '0') == 5);
	assert(test8B[0] == "Hell0" && test8B[1] == "G00dbye" && test8B[2] == "G00dbye");
	cerr << "All tests passed." << endl;
	return 0;
}
bool hasDuplicates(const string array[], int size) {
	if (size <= 0) {
		return false;
	}
	bool hasDuplicate = false; //flag
	for (int i = 0; i < size; i++) { //loop through array
		string temp = array[i];
		// cerr << "Temp is " << temp << endl;
		for(int j = i+1; j < size; j++) { //check all elements after the one in question
			// cerr  << "J is " << j << endl;
			if (array[j] == temp) {
				hasDuplicate = true;
			}
		}
	}
	return hasDuplicate;
}
int  countAllDigits(const string array[], int size) {
	if (size <= 0) {
		return -1;
	}
	int counter = 0;
	for (int i = 0; i < size; i++) { //loop through array elements
		string temp = array[i];
		for (size_t j = 0; j < temp.size(); j++) { //loop through each string
			//warning given if size_t replaced with int?
			if (isNumber(temp.at(j)) == true) { //check if each char is a digit
				counter = counter + 1;
			}
		}
	}
	return counter;
}
bool isInDecreasingOrder(const string array[], int size) {
	if (size < 0) {
		return false;
	}
	if (size == 0 || size == 1) {
		return true;
	}
	bool flag = true;
	for (int i = 0; i < size - 1; i++) { //loop through array
		if (array[i + 1] >= array[i]) { //compare current value to next value
			flag = false; //next value should be less, not more
		}
	}
	return flag;
}
int  shiftRight(string array[], int size, int amount, string placeholder) {
	if (size < 0 || amount < 0) {
		return -1;
	}
	if (amount == 0 || size == 0) { //don't shift anything
		return 0;
	}
	if (amount > size) {
		amount = size;
	}
	/* for (int i = 0; i < size-amount; i++) {
		array[i + amount] = array[i]; //0 to 0 + amount, 1 to 1 + amount, etc.
	} */
	for (int i = size - amount - 1; i > -1; i--) {
		array[i + amount] = array[i];
	}
	for (int i = 0; i < amount; i++) {
		array[i] = placeholder;
	}
	return amount;
}
int  find(const string array[], int size, string match) {
	if (size <= 0) {
		return -1;
	}
	int index = 0;
	bool matchFound = false;
	for (int i = 0; i < size; i++) {
		if (array[i] == match && matchFound == false) { //first instance found
			index = i;
			matchFound = true; //no longer need to find more matches
		}
	}
	if (matchFound == false) {
		return -1;
	}
	return index;
}
int  replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter) {
	if (size < 0) {
		return -1;
	}
	if (size == 0) {
		return -1;
	}
	int counter = 0;
	for (int i = 0; i < size; i++) {
		string temp = array[i];
		// cerr << "String of interest: " << temp << " at index " << i << endl;
		string newString = "";
		for (size_t j = 0; j < temp.size(); j++) {
			// cerr << "Index of J is " << j << endl;
			if (temp.at(j) == findLetter) {
				newString = newString + replaceLetter; //add the replacement letter
				counter = counter + 1;
			}
			else {
				newString = newString + temp.at(j); //add the original letter
			}
			array[i] = newString; //update value in array[i]
		}
	}
	// cerr << "Number of instances: " << counter << endl;
	return counter;
}
bool isNumber(char testChar) {
	char test = testChar;
	bool isNum = false;
	for (int i = 48; i <= 57; i++) { //48 is ASCII for 0, 57 is ASCII for 9
		if (i == test) {
			isNum = true;
		}
	}
	return isNum;
}

