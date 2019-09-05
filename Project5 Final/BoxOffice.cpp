#include "BoxOffice.h"
#include "Project5Helper.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

BoxOffice::BoxOffice() {}
Ticket BoxOffice::buyTicket(string row, int seat, string event, string venue,
	Ticket::KIND kind, string daytime) {
	Ticket temp = Ticket(row, seat, event, venue, 0, kind, daytime);
	return temp;
}
Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat, string event,
	Ticket::KIND kind, string daytime) {
	Ticket temp = Ticket(row, seat, event, "Royce Hall", 0, kind, daytime);
	Project5Helper help = Project5Helper();
	if (kind == Ticket::KIND::ATHLETICGAME) { //athletic game
		temp.setPrice(75.00);
	}
	else if (kind == Ticket::KIND::CONCERT && help.endsWithPM(daytime) == false) { //concert, daytime
		temp.setPrice(50.00);
	}
	else if (kind == Ticket::KIND::CONCERT && help.endsWithPM(daytime) == true) { //concert, night
		temp.setPrice(65.00);
	}
	else if (kind == Ticket::KIND::MOVIE) {
		temp.setPrice(12.50);
	}
	else if (kind == Ticket::KIND::OTHER && help.endsWithPM(daytime) == false) { //concert, daytime
		temp.setPrice(40.00);
	}
	else if (kind == Ticket::KIND::OTHER && help.endsWithPM(daytime) == true) { //concert, night
		temp.setPrice(55.00);
	}
	if (help.startsWithOrchestra(row) == true) { //2x for orchestra
		double oldPrice = temp.getPrice();
		oldPrice = 2.0 * oldPrice;
		temp.setPrice(oldPrice);
	}
	double oldPrice2 = temp.getPrice();
	if (oldPrice2 >= 40) { //student discount
		oldPrice2 = oldPrice2 - 30;
		temp.setPrice(oldPrice2);
	}
	else if (oldPrice2 < 40) {
		oldPrice2 = 0.8*oldPrice2;
		temp.setPrice(oldPrice2);
	}
	return temp;
}
Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat, string event,
	Ticket::KIND kind, string daytime) {
	Ticket temp = Ticket(row, seat, event, "Royce Hall", 0, kind, daytime);
	Project5Helper help = Project5Helper();
	if (kind == Ticket::KIND::ATHLETICGAME) { //athletic game
		temp.setPrice(75.00);
	}
	else if (kind == Ticket::KIND::CONCERT && help.endsWithPM(daytime) == false) { //concert, daytime
		temp.setPrice(50.00);
	}
	else if (kind == Ticket::KIND::CONCERT && help.endsWithPM(daytime) == true) { //concert, night
		temp.setPrice(65.00);
	}
	else if (kind == Ticket::KIND::MOVIE) {
		temp.setPrice(12.50);
	}
	else if (kind == Ticket::KIND::OTHER && help.endsWithPM(daytime) == false) { //concert, daytime
		temp.setPrice(40.00);
	}
	else if (kind == Ticket::KIND::OTHER && help.endsWithPM(daytime) == true) { //concert, night
		temp.setPrice(55.00);
	}
	if (help.startsWithOrchestra(row) == true) { //2x for orchestra
		double oldPrice = temp.getPrice();
		oldPrice = 2.0 * oldPrice;
		temp.setPrice(oldPrice);
	}
	double oldPrice2 = temp.getPrice();
	if (oldPrice2 >= 40) { //staff discount
		oldPrice2 = oldPrice2 - 20;
		temp.setPrice(oldPrice2);
	}
	else if (oldPrice2 < 40) {
		oldPrice2 = 0.9*oldPrice2;
		temp.setPrice(oldPrice2);
	}
	return temp;
}
Ticket BoxOffice::buyRoyceHallTicket(string row, int seat, string event,
	Ticket::KIND kind, string daytime) { //for general public
	Ticket temp = Ticket(row, seat, event, "Royce Hall", 0, kind, daytime);
	Project5Helper help = Project5Helper();
	if (kind == Ticket::KIND::ATHLETICGAME) { //athletic game
		temp.setPrice(75.00);
	}
	else if (kind == Ticket::KIND::CONCERT && help.endsWithPM(daytime) == false) { //concert, daytime
		temp.setPrice(50.00);
	}
	else if (kind == Ticket::KIND::CONCERT && help.endsWithPM(daytime) == true) { //concert, night
		temp.setPrice(65.00);
	}
	else if (kind == Ticket::KIND::MOVIE) {
		temp.setPrice(12.50);
	}
	else if (kind == Ticket::KIND::OTHER && help.endsWithPM(daytime) == false) { //concert, daytime
		temp.setPrice(40.00);
	}
	else if (kind == Ticket::KIND::OTHER && help.endsWithPM(daytime) == true) { //concert, night
		temp.setPrice(55.00);
	}
	if (help.startsWithOrchestra(row) == true) { //2x for orchestra
		double oldPrice = temp.getPrice();
		oldPrice = 2.0 * oldPrice;
		temp.setPrice(oldPrice);
	}
	return temp;
}
