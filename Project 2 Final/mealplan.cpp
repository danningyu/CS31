//Danning Yu 305-087-992
//Project 2 - Bruin Meal Plan Calculator
//TO DO: Check logic and timely program termination
#include <iostream>
#include <string>
using namespace std;
int main() {
	string ticketOrCard = "";
	string whatMeal = "";
	string studentStaff = "";
	string resident = "";
	cout << "Ticket or BruinCard?";
	getline(cin, ticketOrCard);
	if (ticketOrCard != "Ticket" && ticketOrCard != "BruinCard") {
		cout << "The kind value must either be Ticket or BruinCard." << endl;
		return(-1);
	}
	cout << "Breakfast, Lunch, or Dinner?";
	getline(cin, whatMeal);
	if (whatMeal != "Breakfast" && whatMeal != "Lunch" && whatMeal != "Dinner") {
		cout << "The meal value must either be Breakfast, Lunch or Dinner." << endl;
		return(-2);
	}
	if (ticketOrCard == "Ticket" && whatMeal == "Breakfast") { //ticket and breakfast
		cout << "Thank you for eating at UCLA today.  Your meal cost is $12.50." << endl;
		return (1);
	}
	else if (ticketOrCard == "Ticket" && whatMeal == "Lunch") { //ticket and lunch
		cout << "Thank you for eating at UCLA today.  Your meal cost is $14.50." << endl;
		return (2);
	}
	else if (ticketOrCard == "Ticket" && whatMeal == "Dinner") { //ticket and dinner
		cout << "Thank you for eating at UCLA today.  Your meal cost is $17.00." << endl;
		return (3);
	}
	cout << "Student or Staff?";
	getline(cin, studentStaff);
	if (studentStaff != "Student" && studentStaff != "Staff") {
		cout << "The type value must either be Student or Staff." << endl;
		return(-2);
	}
	if (ticketOrCard == "BruinCard" && studentStaff == "Staff") {
		if (whatMeal == "Breakfast") {
			cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25." << endl;
			return(6);
		}
		else if (whatMeal == "Lunch") {
			cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75." << endl;
			return(9);
		}
		else if (whatMeal == "Dinner") {
			cout << "Thank you for eating at UCLA today.  Your meal cost is $14.75." << endl;
			return(12);
		}
	}
	cout << "Resident?";
	getline(cin, resident);
	if (resident != "Yes" && resident != "No") {
		cout << "The resident value must either be Yes or No." << endl;
		return(-3);
	}
	if (ticketOrCard == "BruinCard") {
		if (whatMeal == "Breakfast") {
			if (studentStaff == "Student") {
				if (resident == "Yes") {
					cout << "Thank you for eating at UCLA today.  Your meal cost is $9.75." << endl;
					return(4);
				}
				else if (resident == "No") {
					cout << "Thank you for eating at UCLA today.  Your meal cost is $10.00." << endl;
					return(5);
				}
			}
		}
		else if (whatMeal == "Lunch") {
			if (studentStaff == "Student") {
				if (resident == "Yes") {
					cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25." << endl;
					return(7);
				}
				else if (resident == "No") {
					cout << "Thank you for eating at UCLA today.  Your meal cost is $11.75." << endl;
					return(8);
				}
			}
		}
		else if (whatMeal == "Dinner") {
			if (studentStaff == "Student") {
				if (resident == "Yes") {
					cout << "Thank you for eating at UCLA today.  Your meal cost is $12.25." << endl;
					return(10);
				}
				else if (resident == "No") {
					cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75." << endl;
					return(11);
				}
			}
		}
	}
	return(0);
}