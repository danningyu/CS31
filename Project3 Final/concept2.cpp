//Danning Yu
//CS31 Project 3
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

//Implement other 5 functions and do project 3 report
//false = 0, true is nonzero
//ALWAYS TREAT CHARACTERS AS NUMBERS
//REMEMBER TO TAKE OUT ALL // cerr WHEN FINISHED

bool isValidRowerString(string rowerString);
int totalDistance(string rowerString);
int heartRate(string rowerString);
int strokesPerMinute(string rowerString);
int elapsedMinutes(string rowerString);
int elapsedSeconds(string rowerString);
bool isNonzeroNumber(char testChar); //if character is 1-9
bool isNumber(char testChar); //if character is 0-9
bool isWhiteSpace(string testString); //checks if string is all whitespace

int main() {
	string test1 = "";
	/* assert(isValidRowerString("   5:00 500 s/m    500 m  600") == true);
	assert(isValidRowerString("   5:5 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   05:50 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   5: 50 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   000005:50 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   :50 500 s/m    500 m  600") == true);
	assert(isValidRowerString("   :60 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   5 :59 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   59: 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   0:50 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   50:0 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   555:50 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   a60:50 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   5:a50 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   ::50 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   5:050 500 s/m    500 m  600") == false);
	assert(isValidRowerString("   5:05 500     s/m    500 m  600") == false);
	assert(isValidRowerString("   5:05 500 00 s/m    500 m  600") == false);
	assert(isValidRowerString("   5:05 50s/m    500 m  600") == false);
	assert(isValidRowerString("   5:05     500 s/m    500 m  600") == true);
	assert(isValidRowerString("   5:05 1000 s/m    500 m  600") == false);
	assert(isValidRowerString("   5:05 0500 s/m    500 m  600") == false);
	assert(isValidRowerString("   5:05 499 s/m    500 m  600") == true);
	assert(isValidRowerString("   5:05 500 ssm    500 m  600") == false);
	assert(isValidRowerString("   5:05 500 s /m    500 m  600") == false);
	assert(isValidRowerString("   5:05 100 s/ m    500 m  600") == false);
	assert(isValidRowerString("   5:05 100 s    500 m  600") == false);
	assert(isValidRowerString("   5:00 500 s/m    0 m  600") == false);
	assert(isValidRowerString("   5:00 500 s/m    50m  600") == false);
	assert(isValidRowerString("   5:00 500 s/m    -50 m  600") == false);
	assert(isValidRowerString("   5:00 500 s/m    50  m  600") == false);
	assert(isValidRowerString("   5:00 500 s/m    50 s  600") == false);
	assert(isValidRowerString("   5:00 500 s/m    1000 m  600") == true);
	assert(isValidRowerString("       5:00 500 s/m 50 m  600") == true);
	assert(isValidRowerString("   5:00 500 s/m    50 00 m  600") == false);
	assert(isValidRowerString("   5:00 500 s/m    500 m  1000") == false);
	assert(isValidRowerString("   5:00 500 s/m    500 m  0") == false);
	assert(isValidRowerString("   5:00 500 s/m    500 m  -500") == false);
	assert(isValidRowerString("   5:00 500 s/m    500 m  50 50") == false);
	assert(isValidRowerString("   5:00 500 s/m    500 m  a50") == false);
	assert(isValidRowerString("   5:00 500 s/m    500 m  50abc") == false);
	assert(elapsedSeconds("       5:00    400 s/m 50 m  1999") == -1);
	assert(elapsedMinutes("       50:00    400 s/m 70 m  199") == 50);
	assert(elapsedSeconds("       50:00    400 s/m 70 m  199") == 0);
	assert(strokesPerMinute("       50:00    400 s/m 70 m  199") == 400);
	assert(totalDistance("       50:00    400 s/m 70 m  199") == 70);
	assert(heartRate("       50:00    400 s/m 70 m  199") == 199);
	assert(isValidRowerString("") == false);
	assert(isValidRowerString("00:14 11 s/m 22 m 33") == false);
	assert(isValidRowerString(":2 11 s/m 22 m 33") == false);
	assert(isValidRowerString("01:14 11 s/m 22 m 33") == false);
	assert(isValidRowerString("60:14 11 s/m 22 m 33") == false);
	assert(isValidRowerString("44:60 11 s/m 22 m 33") == false);
	assert(isValidRowerString("44: 14 11 s/m 22 m 33") == false);
	assert(isValidRowerString("44 :14 11 s/m 22 m 33") == false);
	assert(isValidRowerString("-01:14 11 s/m 22 m 33") == false);
	assert(isValidRowerString("44:14 asdf11 s/m 22 m 33") == false);
	assert(isValidRowerString("44:14 011 s/m 22 m 33") == false);
	assert(isValidRowerString("44:14 0 s/m 22 m 33") == false);
	assert(isValidRowerString("44:14 1000 s/m 22 m 33") == false);
	assert(isValidRowerString("44:14 11s/m 22 m 33") == false);
	assert(isValidRowerString("44:14 11  s/m 22 m 33") == false);
	assert(isValidRowerString("44:14 11 22 m 33") == false);
	assert(isValidRowerString("44:14 11 m/s 22 m 33") == false);
	assert(isValidRowerString("44:14 11 s/m 02 m 33") == false);
	assert(isValidRowerString("44:14 11 s/m asdf02 m 33") == false);
	assert(isValidRowerString("44:14 11 s/m 22.2 m 33") == false);
	assert(isValidRowerString("44:14 11 s/m 22m 33") == false);
	assert(isValidRowerString("44:14 11 s/m 22   m 33") == false);
	assert(isValidRowerString("44:14 11 s/m 0 m 33") == false);
	assert(isValidRowerString("44:14 11 s/m -100 m 33") == false);
	assert(isValidRowerString("44:14 11 s/m 22 m 0") == false);
	assert(isValidRowerString("44:14 11 s/m 22 m 1000") == false);
	assert(isValidRowerString("44:14 11 s/m 22 m 33 ") == false);
	assert(isValidRowerString("44:14 11 s/m 22 m 33 asdf") == false);
	assert(isValidRowerString("44:14") == false);
	assert(isValidRowerString("44:14 11 s/m") == false);
	assert(isValidRowerString("44:14 22 m") == false);
	assert(isValidRowerString("44:14 11 s/m 22 m") == false);
	assert(isValidRowerString("44:14 22 m 33") == false);
	assert(isValidRowerString("       44:14 11 s/m 22 m 33") == true);
	assert(isValidRowerString("  44:14      11 s/m    22 m 33") == true);
	assert(isValidRowerString(":14 11 s/m 22 m 33") == true);
	assert(isValidRowerString(":04 11 s/m 22 m 33") == true);
	assert(isValidRowerString(":00 11 s/m 22 m 33") == true);
	assert(isValidRowerString("44:00 11 s/m 22 m 33") == true);
	assert(isValidRowerString("44:59 11 s/m 22 m 33") == true);
	assert(isValidRowerString("59:59 11 s/m 22 m 33") == true);
	assert(isValidRowerString("44:14 1 s/m 22 m 33") == true);
	assert(isValidRowerString("44:14 999 s/m 22 m 33") == true);
	assert(isValidRowerString("44:14 11 s/m 1 m 33") == true);
	assert(isValidRowerString("44:14 11 s/m 1234567890 m 33") == true);
	assert(isValidRowerString("44:14 11 s/m 22 m 1") == true);
	assert(isValidRowerString("44:14 11 s/m 22 m 999") == true);
	assert(isValidRowerString("44:14    11 s/m  22 m 999") == true); */
	// cout << "All test cases passed!" << endl;
	while (test1 != "exit") {
		cout << "Enter a test case or \"exit\" to exit" << endl;
		getline(cin, test1);
		cout << isValidRowerString(test1) << "\t" 
			<< "Minutes: " << elapsedMinutes(test1) << "\t"
			<< "Seconds: " << elapsedSeconds(test1) << "\t"
			<< "Strokes Per Minute: " << strokesPerMinute(test1) << "\t"
			<< "Distance: " << totalDistance(test1) << "\t"
			<< "Heart Rate: " << heartRate(test1) << endl;		
	}
	return 0;
}
//MAKE SURE LENGTH IS UPDATED!
bool isValidRowerString(string rowerString) {
	// cerr << "THE PROGRAM RAN" << endl;
	string str = rowerString;
	int length = str.length();
	int index = 0;
	bool minutesFlag = true;
	int minutesRowed = 0;
	int secondsRowed = 0;
	int strokeRate = 0;
	int distRowed = 0;
	bool nonZeroDist = true;
	int heartRate = 0;
	// cerr << length << endl;
	if (str == "") { //empty string is not well formed
		// cerr << "Bad string, must not be empty" << endl;
		return false;
	}
	if (str.length() < 15) {
		// cerr << "Bad string, is too short, must be missing data" << endl;
		return false;
	}
	if (isWhiteSpace(str) == true) {
		// cerr << "Bad string, it only has whitespace" << endl;
		return false;
	}
	//handle leading whitespace
	while (str.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	string str1 = str.substr(index, length - index);
	// cerr << "Whitespaced removed:" << str1 << endl;
	length = str1.length(); //updates length
	//ONLY USE STR1 BELOW THIS POINT!!
	if (isNonzeroNumber(str1.at(0)) == false && str1.at(0) != 58) { //first character must be number or :
		// cerr << "Bad string, must start with nonzero num or :" << endl;
		return false;
	}
	else {
		// cerr << "Good string, starts with nonzero num or :" << endl;
	}
	//handle first two numbers (minutes)
	if (str1.at(0) == 58) {
		minutesFlag = false;
		minutesRowed = 0;
		// cerr << "Rowed for less than a minute" << endl;
	}
	//handle if minutes not between 1 and 99 (it's 100 or higher) 
	if (minutesFlag == true) {
		if (str1.at(1) != 58 && str1.at(2) != 58) {
			// cerr << "Bad string, Minutes must be between 1 and 99! Outside range or bad input" << endl;
			return false;
		}
	}
	if (minutesFlag == true) { //we have minutes data to process, convert to int
		if (isNumber(str1.at(1)) == true) { //2 digit number
			minutesRowed = 10 * (str1.at(0) - 48) + (str1.at(1) - 48); //tens digit then units digit
			// cerr << "Good string, minutes rowed was (two digits) " << minutesRowed << endl;
		}
		if (isNumber(str1.at(1)) == false) { //1 digit number
			minutesRowed = str1.at(0) - 48;
			// cerr << "Good string, minutes rowed was (one digit) " << minutesRowed << endl;
		}
	}
	if (minutesRowed > 59) { //handle if minutes is 60 or greater
		// cerr << "Bad string, minutes must be less than 60" << endl;
		return false;
	}
	//get rid of minutes data (if present) in string
	if (minutesRowed > 0 && minutesRowed < 10) { //minutes was only 1 digit
		str1 = str1.substr(1, length - 1);
	}
	if (minutesRowed >= 10 && minutesRowed < 100) {
		str1 = str1.substr(2, length - 2);
	}
	//else, it means minutes is 0, do not reupdate str1
	length = str1.length(); //update length if str1 got shorter
	// cerr << "After removing minutes:" << str1 << endl;
	if (str1.at(0) != 58) { //makes sure a : comes next
		// cerr << "Bad string, the next character should be a \":\"" << endl;
		return false;
	}
	str1 = str1.substr(1, length - 1); //get rid of :
	// cerr << "After removing colon:" << str1 << endl;
	if (isNumber(str1.at(0)) == false || isNumber(str1.at(1)) == false) { //checks if next two digits are numbers
		// cerr << "Bad string, the next two characters should be numbers" << endl;
		return false;
	}
	secondsRowed = 10 * (str1.at(0) - 48) + (str1.at(1) - 48); //convert next two digits to numbers
	if (secondsRowed > 59 || secondsRowed < 0) { //<0 case shouldn't happen
		// cerr << "Bad string, seconds must be between 0 and 59" << endl;
		return false;
	}
	// cerr << "Seconds rowed: " << secondsRowed << endl;
	str1 = str1.substr(2, length - 2); //remove the seconds value from the string
	// cerr << "After removing seconds:" << str1 << endl;
	if (isWhiteSpace(str1) == true) {
		// cerr << "Bad string, it only has whitespace" << endl;
		return false;
	}
	if (str1.at(0) != 32) {
		// cerr << "Bad string, needs space between seconds and stroke rate" << endl;
		return false;
	}
	if (isWhiteSpace(str1) == true) {
		// cerr << "Bad string, it only has whitespace" << endl;
		return false;
	}
	index = 0; //reset index
	//remove any whitespace before stroke length
	while (str1.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	str1 = str1.substr(index, length - index);
	// cerr << "Whitespaced removed:" << str1 << endl;
	length = str1.length(); //updates length

	if (isNonzeroNumber(str1.at(0)) == false) { //first character must be nonzeronumber
		// cerr << "Bad string, first digit of stroke rate must be nonzero number" << endl;
		return false;
	}
	//what if multiple leading 0's? okay, first one gets discovered and function returns false
	if (isNonzeroNumber(str1.at(0)) == false || isNumber(str1.at(3)) == true) { //if stroke rate is 0 or >999
		// cerr << "Bad string, stroke rate must be between 1 and 999" << endl;
		return false;
	}	//can't use this for heartrate because you can get an out of bounds error

	//transform next up to 3 digits into an int for strokeRate
	if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == true && isNumber(str1.at(2)) == true) { //stroke rate is 3 digits
		strokeRate = 100 * (str1.at(0) - 48) + 10 * (str1.at(1) - 48) + 1 * (str1.at(2) - 48);
		// cerr << "Good string, 3 digits, the stroke rate is " << strokeRate << endl;
	}
	else if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == true && isNumber(str1.at(2)) == false) { //stroke rate is 2 digits
		strokeRate = 10 * (str1.at(0) - 48) + 1 * (str1.at(1) - 48);
		// cerr << "Good string, 2 digits, the stroke rate is " << strokeRate << endl;
	}
	else if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == false && isNumber(str1.at(2)) == false) { //stroke rate is 1 digit
		strokeRate = 1 * (str1.at(0) - 48);
		// cerr << "Good string, 1 digit, the stroke rate is " << strokeRate << endl;
	}
	else {
		// cerr << "Bad string, stroke rate must be 1, 2, or 3 digit number" << endl;
		return false;
	}
	//remove strokeRate number from string
	if (strokeRate >= 100 && strokeRate < 1000) {
		str1 = str1.substr(3, length - 3);
	}
	else if (strokeRate <= 99 && strokeRate >= 10) {
		str1 = str1.substr(2, length - 2);
	}
	else if (strokeRate <= 9 && strokeRate >= 1) {
		str1 = str1.substr(1, length - 1);
	}
	length = str1.length();
	// cerr << "After removing strokeRate:" << str1 << endl;
	if (str1.at(0) == 32 && str1.substr(1, 3) == "s/m") { //strokeRate must be followed by space and then s/m
		// cerr << "Good string, stroke rate followed by space and s/m" << endl;
	}
	else {
		// cerr << "Bad string, stroke rate must be followed by space and s/m" << endl;
		return false;
	}
	str1 = str1.substr(4, length - 4); //remove " s/m" from the string
	length = str1.length(); //update length
	if (isWhiteSpace(str1) == true) {
		// cerr << "Bad string, it only has whitespace" << endl;
		return false;
	}
	index = 0; //reset index
	//remove any whitespace before distanced rowed
	while (str1.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	str1 = str1.substr(index, length - index);
	// cerr << "Whitespaced removed:" << str1 << endl;
	length = str1.length(); //updates length
	//str1 now has no leading whitespace, only total meters and heartrate
	if (str1.at(0) == 48) { //special case if meters rowed is 0
		
		// cerr << "Bad string, distance rowed cannot be 0." << endl;
		return false;
	}
	if (isNonzeroNumber(str1.at(0)) == false) { //if it does not start with 1-9
		// cerr << "Bad string, meters rowed must start with a number" << endl;
		return false;
	}
	index = 0; //reset index
	if (nonZeroDist == true) {
		while (isNumber(str1.at(index)) == true) { //keep looping until something is hit that's not a number
			index = index + 1; //this determines how many digits the dist rowed is
		}
		// cerr << "Good string, the distance rowed has " << index << " digits in it." << endl;
		//then convert those digits to an int
		for (int i = 0; i < index; i++) {
			distRowed = static_cast<int>(distRowed + pow(10, index - i - 1)*(str1.at(i) - 48));
		}
	}
	// cerr << "Good string, the distance rowed (zero or nonzero) is " << distRowed << endl;
	str1 = str1.substr(index, length - index); //take out the dist rowed from the string
	// cerr << "Distanced rowed removed:" << str1 << endl;
	if (str1.substr(0, 2) != " m") { //distance value should be followed by " m"
		// cerr << "Bad string, distance rowed must be followed by units" << endl;
		return false;
	}
	if (str1.substr(0, 2) == " m") {
		// cerr << "Good string, distanced rowed was followed by \" m\"" << endl;
	}
	str1 = str1.substr(2, length - 2); //remove " m" from the string
	length = str1.length(); //update length
	if (isWhiteSpace(str1) == true) {
		// cerr << "Bad string, it only has whitespace left" << endl;
		return false;
	}
	index = 0; //reset index
	//remove any whitespace before heart rate
	while (str1.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	str1 = str1.substr(index, length - index);
	// cerr << "Whitespaced removed:" << str1 << endl;
	length = str1.length(); //updates length

	//str1 now has no leading whitespace, only heart rate
	if (isNumber(str1.at(0)) == false) { //heart rate must be number starting with 1-9
		// cerr << "Bad string, heart rate must start with number from 1-9" << endl;
		return false;
	}
	index = 0; //reset index
	while (index < length && isNumber(str1.at(index)) == true) { //keep looping until something is hit that's not a number
		index = index + 1; //this determines how many digits the heart rate is
	}
	// cerr << "Good string, the heart rate has " << index << " digits in it." << endl;
	//then convert those digits to an int
	for (int i = 0; i < index; i++) {
		heartRate = static_cast<int>(heartRate + pow(10, index - i - 1)*(str1.at(i) - 48));
	}
	if (heartRate < 1 || heartRate >999) {
		// cerr << "Bad string, heart rate must be between 1 and 999" << endl;
		return false;
	}
	// cerr << "Good string, heart rate is " << heartRate << endl;
	str1 = str1.substr(index, length - index); //take out the heartrate from the string
	// cerr << "Heart rate removed: " << str1 << endl;
	if (str1 == "") { //there should be nothing left
		// cerr << "Good string, nothing left" << endl;
		return true;
	}
	//if this point reached, means there's still stuff left that shouldn't be there, including whitespace
	// cerr << "Bad string, extra characters in string" << endl;
	return false;
}
int totalDistance(string rowerString) {
	if (isValidRowerString(rowerString) == false) {
		return -1;
	}
	string str = rowerString;
	int length = str.length();
	int index = 0;
	bool minutesFlag = true;
	int minutesRowed = 0;
	int secondsRowed = 0;
	int strokeRate = 0;
	int distRowed = 0;
	bool nonZeroDist = true;
	// // cerr << length << endl;
	if (str == "") { //empty string is not well formed
		return false;
	}
	if (str.length() < 15) {
		return false;
	}
	if (isWhiteSpace(str) == true) {
		return false;
	}
	//handle leading whitespace
	while (str.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	string str1 = str.substr(index, length - index);
	length = str1.length(); //updates length
	//ONLY USE STR1 BELOW THIS POINT!!
	if (isNonzeroNumber(str1.at(0)) == false && str1.at(0) != 58) { //first character must be number or :
		return false;
	}
	else {
	}
	//handle first two numbers (minutes)
	if (str1.at(0) == 58) {
		minutesFlag = false;
		minutesRowed = 0;
	}
	//handle if minutes not between 1 and 99 (it's 100 or higher) 
	if (minutesFlag == true) {
		if (str1.at(1) != 58 && str1.at(2) != 58) {
			return false;
		}
	}
	if (minutesFlag == true) { //we have minutes data to process, convert to int
		if (isNumber(str1.at(1)) == true) { //2 digit number
			minutesRowed = 10 * (str1.at(0) - 48) + (str1.at(1) - 48); //tens digit then units digit
		}
		if (isNumber(str1.at(1)) == false) { //1 digit number
			minutesRowed = str1.at(0) - 48;
		}
	}
	//get rid of minutes data (if present) in string
	if (minutesRowed > 0 && minutesRowed < 10) { //minutes was only 1 digit
		str1 = str1.substr(1, length - 1);
	}
	if (minutesRowed >= 10 && minutesRowed < 100) {
		str1 = str1.substr(2, length - 2);
	}
	//else, it means minutes is 0, do not reupdate str1
	length = str1.length(); //update length if str1 got shorter
	if (str1.at(0) != 58) { //makes sure a : comes next
		return false;
	}
	str1 = str1.substr(1, length - 1); //get rid of :
	if (isNumber(str1.at(0)) == false || isNumber(str1.at(1)) == false) { //checks if next two digits are numbers
		return false;
	}
	secondsRowed = 10 * (str1.at(0) - 48) + (str1.at(1) - 48); //convert next two digits to numbers
	if (secondsRowed > 59 || secondsRowed < 0) { //<0 case shouldn't happen
		return false;
	}
	str1 = str1.substr(2, length - 2); //remove the seconds value from the string
	if (isWhiteSpace(str1) == true) {
		return false;
	}
	if (str1.at(0) != 32) {
		return false;
	}
	if (isWhiteSpace(str1) == true) {
		return false;
	}
	index = 0; //reset index
	//remove any whitespace before stroke length
	while (str1.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	str1 = str1.substr(index, length - index);
	length = str1.length(); //updates length

	if (isNonzeroNumber(str1.at(0)) == false) { //first character must be nonzeronumber
		return false;
	}
	//what if multiple leading 0's? okay, first one gets discovered and function returns false
	if (isNonzeroNumber(str1.at(0)) == false || isNumber(str1.at(3)) == true) { //if stroke rate is 0 or >999
	}	//can't use this for heartrate because you can get an out of bounds error

	//transform next up to 3 digits into an int for strokeRate
	if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == true && isNumber(str1.at(2)) == true) { //stroke rate is 3 digits
		strokeRate = 100 * (str1.at(0) - 48) + 10 * (str1.at(1) - 48) + 1 * (str1.at(2) - 48);
	}
	else if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == true && isNumber(str1.at(2)) == false) { //stroke rate is 2 digits
		strokeRate = 10 * (str1.at(0) - 48) + 1 * (str1.at(1) - 48);
	}
	else if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == false && isNumber(str1.at(2)) == false) { //stroke rate is 1 digit
		strokeRate = 1 * (str1.at(0) - 48);
	}
	else {
		return false;
	}
	//remove strokeRate number from string
	if (strokeRate >= 100 && strokeRate < 1000) {
		str1 = str1.substr(3, length - 3);
	}
	else if (strokeRate <= 99 && strokeRate >= 10) {
		str1 = str1.substr(2, length - 2);
	}
	else if (strokeRate <= 9 && strokeRate >= 1) {
		str1 = str1.substr(1, length - 1);
	}
	length = str1.length();
	if (str1.at(0) == 32 && str1.substr(1, 3) == "s/m") { //strokeRate must be followed by space and then s/m
	}
	else {
		return false;
	}
	str1 = str1.substr(4, length - 4); //remove " s/m" from the string
	length = str1.length(); //update length
	if (isWhiteSpace(str1) == true) {
		return false;
	}
	index = 0; //reset index
	//remove any whitespace before distanced rowed
	while (str1.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	str1 = str1.substr(index, length - index);
	length = str1.length(); //updates length
	//str1 now has no leading whitespace, only total meters and heartrate
	if (str1.at(0) == 48) { //special case if meters rowed is 0
		return false;
	}
	if (isNonzeroNumber(str1.at(0)) == false) { //if it does not start with 1-9
		return false;
	}
	index = 0; //reset index
	if (nonZeroDist == true) {
		while (isNumber(str1.at(index)) == true) { //keep looping until something is hit that's not a number
			index = index + 1; //this determines how many digits the dist rowed is
		}
		//then convert those digits to an int
		for (int i = 0; i < index; i++) {
			distRowed = static_cast<int>(distRowed + pow(10, index - i - 1)*(str1.at(i) - 48));
		}
	}
	return distRowed;
}
int heartRate(string rowerString) {
	if (isValidRowerString(rowerString) == false) {
		return -1;
	}
	string str = rowerString;
	int length = str.length();
	int index = 0;
	bool minutesFlag = true;
	int minutesRowed = 0;
	int secondsRowed = 0;
	int strokeRate = 0;
	int distRowed = 0;
	bool nonZeroDist = true;
	int heartRate = 0;
	// // cerr << length << endl;
	if (str == "") { //empty string is not well formed
		return false;
	}
	if (str.length() < 15) {
		return false;
	}
	if (isWhiteSpace(str) == true) {
		return false;
	}
	//handle leading whitespace
	while (str.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	string str1 = str.substr(index, length - index);
	length = str1.length(); //updates length
	//ONLY USE STR1 BELOW THIS POINT!!
	if (isNonzeroNumber(str1.at(0)) == false && str1.at(0) != 58) { //first character must be number or :
		return false;
	}
	else {
	}
	//handle first two numbers (minutes)
	if (str1.at(0) == 58) {
		minutesFlag = false;
		minutesRowed = 0;
	}
	//handle if minutes not between 1 and 99 (it's 100 or higher) 
	if (minutesFlag == true) {
		if (str1.at(1) != 58 && str1.at(2) != 58) {
			return false;
		}
	}
	if (minutesFlag == true) { //we have minutes data to process, convert to int
		if (isNumber(str1.at(1)) == true) { //2 digit number
			minutesRowed = 10 * (str1.at(0) - 48) + (str1.at(1) - 48); //tens digit then units digit
		}
		if (isNumber(str1.at(1)) == false) { //1 digit number
			minutesRowed = str1.at(0) - 48;
		}
	}
	//get rid of minutes data (if present) in string
	if (minutesRowed > 0 && minutesRowed < 10) { //minutes was only 1 digit
		str1 = str1.substr(1, length - 1);
	}
	if (minutesRowed >= 10 && minutesRowed < 100) {
		str1 = str1.substr(2, length - 2);
	}
	//else, it means minutes is 0, do not reupdate str1
	length = str1.length(); //update length if str1 got shorter
	if (str1.at(0) != 58) { //makes sure a : comes next
		return false;
	}
	str1 = str1.substr(1, length - 1); //get rid of :
	if (isNumber(str1.at(0)) == false || isNumber(str1.at(1)) == false) { //checks if next two digits are numbers
		return false;
	}
	secondsRowed = 10 * (str1.at(0) - 48) + (str1.at(1) - 48); //convert next two digits to numbers
	if (secondsRowed > 59 || secondsRowed < 0) { //<0 case shouldn't happen
		return false;
	}
	str1 = str1.substr(2, length - 2); //remove the seconds value from the string
	if (isWhiteSpace(str1) == true) {
		return false;
	}
	if (str1.at(0) != 32) {
		return false;
	}
	if (isWhiteSpace(str1) == true) {
		return false;
	}
	index = 0; //reset index
	//remove any whitespace before stroke length
	while (str1.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	str1 = str1.substr(index, length - index);
	length = str1.length(); //updates length

	if (isNonzeroNumber(str1.at(0)) == false) { //first character must be nonzeronumber
		return false;
	}
	//what if multiple leading 0's? okay, first one gets discovered and function returns false
	if (isNonzeroNumber(str1.at(0)) == false || isNumber(str1.at(3)) == true) { //if stroke rate is 0 or >999
	}	//can't use this for heartrate because you can get an out of bounds error

	//transform next up to 3 digits into an int for strokeRate
	if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == true && isNumber(str1.at(2)) == true) { //stroke rate is 3 digits
		strokeRate = 100 * (str1.at(0) - 48) + 10 * (str1.at(1) - 48) + 1 * (str1.at(2) - 48);
	}
	else if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == true && isNumber(str1.at(2)) == false) { //stroke rate is 2 digits
		strokeRate = 10 * (str1.at(0) - 48) + 1 * (str1.at(1) - 48);
	}
	else if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == false && isNumber(str1.at(2)) == false) { //stroke rate is 1 digit
		strokeRate = 1 * (str1.at(0) - 48);
	}
	else {
		return false;
	}
	//remove strokeRate number from string
	if (strokeRate >= 100 && strokeRate < 1000) {
		str1 = str1.substr(3, length - 3);
	}
	else if (strokeRate <= 99 && strokeRate >= 10) {
		str1 = str1.substr(2, length - 2);
	}
	else if (strokeRate <= 9 && strokeRate >= 1) {
		str1 = str1.substr(1, length - 1);
	}
	length = str1.length();
	if (str1.at(0) == 32 && str1.substr(1, 3) == "s/m") { //strokeRate must be followed by space and then s/m
	}
	else {
		return false;
	}
	str1 = str1.substr(4, length - 4); //remove " s/m" from the string
	length = str1.length(); //update length
	if (isWhiteSpace(str1) == true) {
		return false;
	}
	index = 0; //reset index
	//remove any whitespace before distanced rowed
	while (str1.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	str1 = str1.substr(index, length - index);
	length = str1.length(); //updates length
	//str1 now has no leading whitespace, only total meters and heartrate
	if (str1.at(0) == 48) { //special case if meters rowed is 0
		return false;
	}
	if (isNonzeroNumber(str1.at(0)) == false) { //if it does not start with 1-9
		return false;
	}
	index = 0; //reset index
	if (nonZeroDist == true) {
		while (isNumber(str1.at(index)) == true) { //keep looping until something is hit that's not a number
			index = index + 1; //this determines how many digits the dist rowed is
		}
		//then convert those digits to an int
		for (int i = 0; i < index; i++) {
			distRowed = static_cast<int>(distRowed + pow(10, index - i - 1)*(str1.at(i) - 48));
		}
	}
	str1 = str1.substr(index, length - index); //take out the dist rowed from the string
	if (str1.substr(0, 2) != " m") { //distance value should be followed by " m"
		return false;
	}
	if (str1.substr(0, 2) == " m") {
	}
	str1 = str1.substr(2, length - 2); //remove " m" from the string
	length = str1.length(); //update length
	if (isWhiteSpace(str1) == true) {
		return false;
	}
	index = 0; //reset index
	//remove any whitespace before heart rate
	while (str1.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	str1 = str1.substr(index, length - index);
	length = str1.length(); //updates length

	//str1 now has no leading whitespace, only heart rate
	if (isNumber(str1.at(0)) == false) { //heart rate must be number starting with 1-9
		return false;
	}
	index = 0; //reset index
	while (index < length && isNumber(str1.at(index)) == true) { //keep looping until something is hit that's not a number
		index = index + 1; //this determines how many digits the heart rate is
	}
	//then convert those digits to an int
	for (int i = 0; i < index; i++) {
		heartRate = static_cast<int>(heartRate + pow(10, index - i - 1)*(str1.at(i) - 48));
	}
	return heartRate;
}
int strokesPerMinute(string rowerString) {
	if (isValidRowerString(rowerString) == false) {
		return -1;
	}
	string str = rowerString;
	int length = str.length();
	int index = 0;
	bool minutesFlag = true;
	int minutesRowed = 0;
	int secondsRowed = 0;
	int strokeRate = 0;
	// // cerr << length << endl;
	if (str == "") { //empty string is not well formed
		return false;
	}
	if (str.length() < 15) {
		return false;
	}
	if (isWhiteSpace(str) == true) {
		return false;
	}
	//handle leading whitespace
	while (str.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	string str1 = str.substr(index, length - index);
	length = str1.length(); //updates length
	//ONLY USE STR1 BELOW THIS POINT!!
	if (isNonzeroNumber(str1.at(0)) == false && str1.at(0) != 58) { //first character must be number or :
		return false;
	}
	else {
	}
	//handle first two numbers (minutes)
	if (str1.at(0) == 58) {
		minutesFlag = false;
		minutesRowed = 0;
	}
	//handle if minutes not between 1 and 99 (it's 100 or higher) 
	if (minutesFlag == true) {
		if (str1.at(1) != 58 && str1.at(2) != 58) {
			return false;
		}
	}
	if (minutesFlag == true) { //we have minutes data to process, convert to int
		if (isNumber(str1.at(1)) == true) { //2 digit number
			minutesRowed = 10 * (str1.at(0) - 48) + (str1.at(1) - 48); //tens digit then units digit
		}
		if (isNumber(str1.at(1)) == false) { //1 digit number
			minutesRowed = str1.at(0) - 48;
		}
	}
	//get rid of minutes data (if present) in string
	if (minutesRowed > 0 && minutesRowed < 10) { //minutes was only 1 digit
		str1 = str1.substr(1, length - 1);
	}
	if (minutesRowed >= 10 && minutesRowed < 100) {
		str1 = str1.substr(2, length - 2);
	}
	//else, it means minutes is 0, do not reupdate str1
	length = str1.length(); //update length if str1 got shorter
	if (str1.at(0) != 58) { //makes sure a : comes next
		return false;
	}
	str1 = str1.substr(1, length - 1); //get rid of :
	if (isNumber(str1.at(0)) == false || isNumber(str1.at(1)) == false) { //checks if next two digits are numbers
		return false;
	}
	secondsRowed = 10 * (str1.at(0) - 48) + (str1.at(1) - 48); //convert next two digits to numbers
	if (secondsRowed > 59 || secondsRowed < 0) { //<0 case shouldn't happen
		return false;
	}
	str1 = str1.substr(2, length - 2); //remove the seconds value from the string
	if (isWhiteSpace(str1) == true) {
		return false;
	}
	if (str1.at(0) != 32) {
		return false;
	}
	if (isWhiteSpace(str1) == true) {
		return false;
	}
	index = 0; //reset index
	//remove any whitespace before stroke length
	while (str1.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	str1 = str1.substr(index, length - index);
	length = str1.length(); //updates length

	if (isNonzeroNumber(str1.at(0)) == false) { //first character must be nonzeronumber
		return false;
	}
	//what if multiple leading 0's? okay, first one gets discovered and function returns false
	if (isNonzeroNumber(str1.at(0)) == false || isNumber(str1.at(3)) == true) { //if stroke rate is 0 or >999
	}	//can't use this for heartrate because you can get an out of bounds error

	//transform next up to 3 digits into an int for strokeRate
	if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == true && isNumber(str1.at(2)) == true) { //stroke rate is 3 digits
		strokeRate = 100 * (str1.at(0) - 48) + 10 * (str1.at(1) - 48) + 1 * (str1.at(2) - 48);
	}
	else if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == true && isNumber(str1.at(2)) == false) { //stroke rate is 2 digits
		strokeRate = 10 * (str1.at(0) - 48) + 1 * (str1.at(1) - 48);
	}
	else if (isNonzeroNumber(str1.at(0)) == true && isNumber(str1.at(1)) == false && isNumber(str1.at(2)) == false) { //stroke rate is 1 digit
		strokeRate = 1 * (str1.at(0) - 48);
	}
	else {
		return false;
	}
	return strokeRate;
}
int elapsedMinutes(string rowerString) {
	if (isValidRowerString(rowerString) == false) {
		return -1;
	}
	string str = rowerString;
	int length = str.length();
	int index = 0;
	bool minutesFlag = true;
	int minutesRowed = 0;
	// // cerr << length << endl;
	if (str == "") { //empty string is not well formed
		return false;
	}
	if (str.length() < 15) {
		return false;
	}
	if (isWhiteSpace(str) == true) {
		return false;
	}
	//handle leading whitespace
	while (str.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	string str1 = str.substr(index, length - index);
	length = str1.length(); //updates length
	//ONLY USE STR1 BELOW THIS POINT!!
	if (isNonzeroNumber(str1.at(0)) == false && str1.at(0) != 58) { //first character must be number or :
		return false;
	}
	else {
	}
	//handle first two numbers (minutes)
	if (str1.at(0) == 58) {
		minutesFlag = false;
		minutesRowed = 0;
	}
	//handle if minutes not between 1 and 99 (it's 100 or higher) 
	if (minutesFlag == true) {
		if (str1.at(1) != 58 && str1.at(2) != 58) {
			return false;
		}
	}
	if (minutesFlag == true) { //we have minutes data to process, convert to int
		if (isNumber(str1.at(1)) == true) { //2 digit number
			minutesRowed = 10 * (str1.at(0) - 48) + (str1.at(1) - 48); //tens digit then units digit
		}
		if (isNumber(str1.at(1)) == false) { //1 digit number
			minutesRowed = str1.at(0) - 48;
		}
	}
	return minutesRowed;
}
int elapsedSeconds(string rowerString) {
	if (isValidRowerString(rowerString) == false) {
		return -1;
	}
	string str = rowerString;
	int length = str.length();
	int index = 0;
	bool minutesFlag = true;
	int minutesRowed = 0;
	int secondsRowed = 0;
	// // cerr << length << endl;
	if (str == "") { //empty string is not well formed
		return false;
	}
	if (str.length() < 15) {
		return false;
	}
	if (isWhiteSpace(str) == true) {
		return false;
	}
	//handle leading whitespace
	while (str.at(index) == 32) { //32 is a space
		index = index + 1;
	}
	string str1 = str.substr(index, length - index);
	length = str1.length(); //updates length
	//ONLY USE STR1 BELOW THIS POINT!!
	if (isNonzeroNumber(str1.at(0)) == false && str1.at(0) != 58) { //first character must be number or :
		return false;
	}
	else {
	}
	//handle first two numbers (minutes)
	if (str1.at(0) == 58) {
		minutesFlag = false;
		minutesRowed = 0;
	}
	//handle if minutes not between 1 and 99 (it's 100 or higher) 
	if (minutesFlag == true) {
		if (str1.at(1) != 58 && str1.at(2) != 58) {
			return false;
		}
	}
	if (minutesFlag == true) { //we have minutes data to process, convert to int
		if (isNumber(str1.at(1)) == true) { //2 digit number
			minutesRowed = 10 * (str1.at(0) - 48) + (str1.at(1) - 48); //tens digit then units digit
		}
		if (isNumber(str1.at(1)) == false) { //1 digit number
			minutesRowed = str1.at(0) - 48;
		}
	}
	//get rid of minutes data (if present) in string
	if (minutesRowed > 0 && minutesRowed < 10) { //minutes was only 1 digit
		str1 = str1.substr(1, length - 1);
	}
	if (minutesRowed >= 10 && minutesRowed < 100) {
		str1 = str1.substr(2, length - 2);
	}
	//else, it means minutes is 0, do not reupdate str1
	length = str1.length(); //update length if str1 got shorter
	if (str1.at(0) != 58) { //makes sure a : comes next
		return false;
	}
	str1 = str1.substr(1, length - 1); //get rid of :
	if (isNumber(str1.at(0)) == false || isNumber(str1.at(1)) == false) { //checks if next two digits are numbers
		return false;
	}
	secondsRowed = 10 * (str1.at(0) - 48) + (str1.at(1) - 48); //convert next two digits to numbers
	if (secondsRowed > 59 || secondsRowed < 0) { //<0 case shouldn't happen
		return false;
	}
	return secondsRowed;
}
bool isNonzeroNumber(char testChar) {
	char test = testChar;
	bool isNum = false;
	for (int i = 49; i <= 57; i++) { //49 is ASCII for 1, 57 is ASCII for 9
		if (i == test) {
			isNum = true;
		}
	}
	return isNum;
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
bool isWhiteSpace(string testString) {
	string str = testString;
	int length = str.length();
	bool isEmpty = true;
	for (int i = 0; i < length; i++) {
		if (str.at(i) != 32 && str.at(i) != 9 && str.at(i) != 10 && str.at(i) != 13) {
			//32 is space, 9 is tab, 10 is newline, 13 is carriage return
			isEmpty = false;
		}
	}
	return isEmpty;
}
