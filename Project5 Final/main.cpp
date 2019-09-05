#include <string>
#include <iostream>
#include <cassert>
#include "Project5Helper.h"
#include "BoxOffice.h"
#include "Ticket.h"
using namespace std;

int main() {
	const string ORCHESTRA = "Orchestra Row A";
	const string BALCONY = "Balcony Row B";
	const int SEAT = 7;
	const string EVENT = "EVENT NAME";
	const string ROYCE = "Royce Hall";
	const string DAY = "October 1, 7:30AM";
	const string NIGHT = "October 1, 7:30PM";
	BoxOffice b;

	Ticket empTicket = b.buyTicket("", 0, "", "", Ticket::KIND::CONCERT, ""); //tests empty string
	assert(empTicket.getRow() == "");
	assert(empTicket.getSeat() == 0);
	assert(empTicket.getEvent() == "");
	assert(empTicket.getVenue() == "");
	assert(to_string(empTicket.getPrice()) == "0.000000"); //checks if price is set to 0;
	assert(empTicket.getKind() == Ticket::KIND::CONCERT); //checks if getKind() works
	assert(empTicket.getDayTime() == ""); //checks if getDayTime() works

	//tests buyTicket(...)
	Ticket t1 = b.buyTicket("Floor", SEAT, "Lecture", "Powell", Ticket::KIND::ATHLETICGAME, DAY);
	assert(t1.getRow() == "Floor"); //checks if getRow() works
	assert(t1.getSeat() == 7); //checks if getSeat() works
	assert(t1.getEvent() == "Lecture"); //checks if getEvent() works
	assert(t1.getVenue() == "Powell"); //checks if getVenue() works
	assert(to_string(t1.getPrice()) == "0.000000"); //checks if price is set to 0;
	t1.setPrice(11.00);
	assert(to_string(t1.getPrice()) == "11.000000"); //checks if price set correctly
	assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
	assert(t1.getDayTime() == DAY); //checks if getDayTime() works
	
	{//Tests buyRoyceHallStudentTicket(...)
		t1 = b.buyRoyceHallStudentTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, DAY);
		assert(t1.getRow() == "Orchestra Row A"); //checks if getRow() works
		assert(t1.getSeat() == 7); //checks if getSeat() works
		assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
		assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
		assert(to_string(t1.getPrice()) == "120.000000"); //checks price for orchestra student athletic game day, 150-30
		t1.setPrice(11.00);
		assert(to_string(t1.getPrice()) == "11.000000"); //checks if price set correctly
		assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
		assert(t1.getDayTime() == "October 1, 7:30AM"); //checks if getDayTime() works}

		t1 = b.buyRoyceHallStudentTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, NIGHT);
		assert(t1.getRow() == "Orchestra Row A"); //checks if getRow() works
		assert(t1.getSeat() == 7); //checks if getSeat() works
		assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
		assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
		assert(to_string(t1.getPrice()) == "120.000000"); //checks price for orchestra student athletic game night, 150-30
		t1.setPrice(11.00);
		assert(to_string(t1.getPrice()) == "11.000000"); //checks if price set correctly
		assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
		assert(t1.getDayTime() == "October 1, 7:30PM"); //checks if getDayTime() works}

		t1 = b.buyRoyceHallStudentTicket(BALCONY, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, DAY);
		assert(t1.getRow() == "Balcony Row B"); //checks if getRow() works
		assert(t1.getSeat() == 7); //checks if getSeat() works
		assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
		assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
		assert(to_string(t1.getPrice()) == "45.000000"); //checks price for balcony student athletic game day, 75-30
		assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
		assert(t1.getDayTime() == "October 1, 7:30AM"); //checks if getDayTime() works}
		
		t1 = b.buyRoyceHallStudentTicket(BALCONY, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, NIGHT);
		assert(t1.getRow() == "Balcony Row B"); //checks if getRow() works
		assert(t1.getSeat() == 7); //checks if getSeat() works
		assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
		assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
		assert(to_string(t1.getPrice()) == "45.000000"); //checks price for balcony student athletic game night, 75-30
		assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
		assert(t1.getDayTime() == "October 1, 7:30PM"); //checks if getDayTime() works

		t1 = b.buyRoyceHallStudentTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::CONCERT, DAY);
		assert(to_string(t1.getPrice()) == "70.000000"); //checks price for orchestra, concert during day
		t1 = b.buyRoyceHallStudentTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::CONCERT, NIGHT);
		assert(to_string(t1.getPrice()) == "100.000000"); //checks price for orchestra, concert during night 
		t1 = b.buyRoyceHallStudentTicket(BALCONY, SEAT, EVENT, Ticket::KIND::CONCERT, DAY);
		assert(to_string(t1.getPrice()) == "20.000000"); //checks price for balcony, concert during day
		t1 = b.buyRoyceHallStudentTicket(BALCONY, SEAT, EVENT, Ticket::KIND::CONCERT, NIGHT);
		assert(to_string(t1.getPrice()) == "35.000000"); //checks price for balcony, concert during night

		t1 = b.buyRoyceHallStudentTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::MOVIE, DAY);
		assert(to_string(t1.getPrice()) == "20.000000");
		t1 = b.buyRoyceHallStudentTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::MOVIE, NIGHT);
		assert(to_string(t1.getPrice()) == "20.000000");
		t1 = b.buyRoyceHallStudentTicket(BALCONY, SEAT, EVENT, Ticket::KIND::MOVIE, DAY);
		assert(to_string(t1.getPrice()) == "10.000000");
		t1 = b.buyRoyceHallStudentTicket(BALCONY, SEAT, EVENT, Ticket::KIND::MOVIE, NIGHT);
		assert(to_string(t1.getPrice()) == "10.000000");

		t1 = b.buyRoyceHallStudentTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::OTHER, DAY);
		assert(to_string(t1.getPrice()) == "50.000000");
		t1 = b.buyRoyceHallStudentTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::OTHER, NIGHT);
		assert(to_string(t1.getPrice()) == "80.000000");
		t1 = b.buyRoyceHallStudentTicket(BALCONY, SEAT, EVENT, Ticket::KIND::OTHER, DAY);
		assert(to_string(t1.getPrice()) == "10.000000");
		t1 = b.buyRoyceHallStudentTicket(BALCONY, SEAT, EVENT, Ticket::KIND::OTHER, NIGHT);
		assert(to_string(t1.getPrice()) == "25.000000");
	}

	{//Tests buyRoyceHallSTAFFTicket(...)
		t1 = b.buyRoyceHallStaffTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, DAY);
		assert(t1.getRow() == "Orchestra Row A"); //checks if getRow() works
		assert(t1.getSeat() == 7); //checks if getSeat() works
		assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
		assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
		assert(to_string(t1.getPrice()) == "130.000000"); //checks price for orchestra staff athletic game day, 150-20
		t1.setPrice(11.00);
		assert(to_string(t1.getPrice()) == "11.000000"); //checks if price set correctly
		assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
		assert(t1.getDayTime() == "October 1, 7:30AM"); //checks if getDayTime() works}

		t1 = b.buyRoyceHallStaffTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, NIGHT);
		assert(t1.getRow() == "Orchestra Row A"); //checks if getRow() works
		assert(t1.getSeat() == 7); //checks if getSeat() works
		assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
		assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
		assert(to_string(t1.getPrice()) == "130.000000"); //checks price for orchestra staff athletic game night, 150-20
		t1.setPrice(11.00);
		assert(to_string(t1.getPrice()) == "11.000000"); //checks if price set correctly
		assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
		assert(t1.getDayTime() == "October 1, 7:30PM"); //checks if getDayTime() works}

		t1 = b.buyRoyceHallStaffTicket(BALCONY, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, DAY);
		assert(t1.getRow() == "Balcony Row B"); //checks if getRow() works
		assert(t1.getSeat() == 7); //checks if getSeat() works
		assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
		assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
		assert(to_string(t1.getPrice()) == "55.000000"); //checks price for balcony staff athletic game day, 75-20
		assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
		assert(t1.getDayTime() == "October 1, 7:30AM"); //checks if getDayTime() works}

		t1 = b.buyRoyceHallStaffTicket(BALCONY, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, NIGHT);
		assert(t1.getRow() == "Balcony Row B"); //checks if getRow() works
		assert(t1.getSeat() == 7); //checks if getSeat() works
		assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
		assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
		assert(to_string(t1.getPrice()) == "55.000000"); //checks price for balcony staff athletic game night, 75-20
		assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
		assert(t1.getDayTime() == "October 1, 7:30PM"); //checks if getDayTime() works

		t1 = b.buyRoyceHallStaffTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::CONCERT, DAY);
		assert(to_string(t1.getPrice()) == "80.000000"); //checks price for orchestra, concert during day
		t1 = b.buyRoyceHallStaffTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::CONCERT, NIGHT);
		assert(to_string(t1.getPrice()) == "110.000000"); //checks price for orchestra, concert during night 
		t1 = b.buyRoyceHallStaffTicket(BALCONY, SEAT, EVENT, Ticket::KIND::CONCERT, DAY);
		assert(to_string(t1.getPrice()) == "30.000000"); //checks price for balcony, concert during day
		t1 = b.buyRoyceHallStaffTicket(BALCONY, SEAT, EVENT, Ticket::KIND::CONCERT, NIGHT);
		assert(to_string(t1.getPrice()) == "45.000000"); //checks price for balcony, concert during night

		t1 = b.buyRoyceHallStaffTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::MOVIE, DAY);
		assert(to_string(t1.getPrice()) == "22.500000");
		t1 = b.buyRoyceHallStaffTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::MOVIE, NIGHT);
		assert(to_string(t1.getPrice()) == "22.500000");
		t1 = b.buyRoyceHallStaffTicket(BALCONY, SEAT, EVENT, Ticket::KIND::MOVIE, DAY);
		assert(to_string(t1.getPrice()) == "11.250000");
		t1 = b.buyRoyceHallStaffTicket(BALCONY, SEAT, EVENT, Ticket::KIND::MOVIE, NIGHT);
		assert(to_string(t1.getPrice()) == "11.250000");

		t1 = b.buyRoyceHallStaffTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::OTHER, DAY);
		assert(to_string(t1.getPrice()) == "60.000000");
		t1 = b.buyRoyceHallStaffTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::OTHER, NIGHT);
		assert(to_string(t1.getPrice()) == "90.000000");
		t1 = b.buyRoyceHallStaffTicket(BALCONY, SEAT, EVENT, Ticket::KIND::OTHER, DAY);
		assert(to_string(t1.getPrice()) == "20.000000");
		t1 = b.buyRoyceHallStaffTicket(BALCONY, SEAT, EVENT, Ticket::KIND::OTHER, NIGHT);
		assert(to_string(t1.getPrice()) == "35.000000");
	}

	//tests buyRoyceHallTicket
	{t1 = b.buyRoyceHallTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, DAY);
	assert(t1.getRow() == "Orchestra Row A"); //checks if getRow() works
	assert(t1.getSeat() == 7); //checks if getSeat() works
	assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
	assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
	assert(to_string(t1.getPrice()) == "150.000000"); //checks price for orchestra staff athletic game day, 150-20
	t1.setPrice(13.00);
	assert(to_string(t1.getPrice()) == "13.000000"); //checks if price set correctly
	assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
	assert(t1.getDayTime() == "October 1, 7:30AM"); //checks if getDayTime() works}

	t1 = b.buyRoyceHallTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, NIGHT);
	assert(t1.getRow() == "Orchestra Row A"); //checks if getRow() works
	assert(t1.getSeat() == 7); //checks if getSeat() works
	assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
	assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
	assert(to_string(t1.getPrice()) == "150.000000"); //checks price for orchestra staff athletic game night, 150-20
	t1.setPrice(15.00);
	assert(to_string(t1.getPrice()) == "15.000000"); //checks if price set correctly
	assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
	assert(t1.getDayTime() == "October 1, 7:30PM"); //checks if getDayTime() works}

	t1 = b.buyRoyceHallTicket(BALCONY, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, DAY);
	assert(t1.getRow() == "Balcony Row B"); //checks if getRow() works
	assert(t1.getSeat() == 7); //checks if getSeat() works
	assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
	assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
	assert(to_string(t1.getPrice()) == "75.000000"); //checks price for balcony staff athletic game day, 75-20
	assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
	assert(t1.getDayTime() == "October 1, 7:30AM"); //checks if getDayTime() works}

	t1 = b.buyRoyceHallTicket(BALCONY, SEAT, EVENT, Ticket::KIND::ATHLETICGAME, NIGHT);
	assert(t1.getRow() == "Balcony Row B"); //checks if getRow() works
	assert(t1.getSeat() == 7); //checks if getSeat() works
	assert(t1.getEvent() == "EVENT NAME"); //checks if getEvent() works
	assert(t1.getVenue() == "Royce Hall"); //checks if getVenue() works
	assert(to_string(t1.getPrice()) == "75.000000"); //checks price for balcony staff athletic game night, 75-20
	assert(t1.getKind() == Ticket::KIND::ATHLETICGAME); //checks if getKind() works
	assert(t1.getDayTime() == "October 1, 7:30PM"); //checks if getDayTime() works

	t1 = b.buyRoyceHallTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::CONCERT, DAY);
	assert(to_string(t1.getPrice()) == "100.000000"); //checks price for orchestra, concert during day
	t1 = b.buyRoyceHallTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::CONCERT, NIGHT);
	assert(to_string(t1.getPrice()) == "130.000000"); //checks price for orchestra, concert during night 
	t1 = b.buyRoyceHallTicket(BALCONY, SEAT, EVENT, Ticket::KIND::CONCERT, DAY);
	assert(to_string(t1.getPrice()) == "50.000000"); //checks price for balcony, concert during day
	t1 = b.buyRoyceHallTicket(BALCONY, SEAT, EVENT, Ticket::KIND::CONCERT, NIGHT);
	assert(to_string(t1.getPrice()) == "65.000000"); //checks price for balcony, concert during night

	t1 = b.buyRoyceHallTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::MOVIE, DAY);
	assert(to_string(t1.getPrice()) == "25.000000");
	t1 = b.buyRoyceHallTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::MOVIE, NIGHT);
	assert(to_string(t1.getPrice()) == "25.000000");
	t1 = b.buyRoyceHallTicket(BALCONY, SEAT, EVENT, Ticket::KIND::MOVIE, DAY);
	assert(to_string(t1.getPrice()) == "12.500000");
	t1 = b.buyRoyceHallTicket(BALCONY, SEAT, EVENT, Ticket::KIND::MOVIE, NIGHT);
	assert(to_string(t1.getPrice()) == "12.500000");

	t1 = b.buyRoyceHallTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::OTHER, DAY);
	assert(to_string(t1.getPrice()) == "80.000000");
	t1 = b.buyRoyceHallTicket(ORCHESTRA, SEAT, EVENT, Ticket::KIND::OTHER, NIGHT);
	assert(to_string(t1.getPrice()) == "110.000000");
	t1 = b.buyRoyceHallTicket(BALCONY, SEAT, EVENT, Ticket::KIND::OTHER, DAY);
	assert(to_string(t1.getPrice()) == "40.000000");
	t1 = b.buyRoyceHallTicket(BALCONY, SEAT, EVENT, Ticket::KIND::OTHER, NIGHT);
	assert(to_string(t1.getPrice()) == "55.000000");
	}

	//Stahl's test cases:
	Ticket t = b.buyTicket("Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", 
		Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM");
	t.setPrice(150.00);
	assert(t.getRow() == "Pavillion Row 13");
	assert(t.getSeat() == 45);
	assert(t.getEvent() == "Dodgers vs. Brewers");
	assert(t.getVenue() == "Dodger Stadium");
	assert(t.getKind() == Ticket::KIND::ATHLETICGAME);
	assert(t.getDayTime() == "August 1, 7:30PM");
	assert(to_string(t.getPrice()) == "150.000000"); //checks if price is set to 150;

	t = b.buyRoyceHallStudentTicket("Orchestra Row U", 20, "Episode VII: The Force Awakens", 
		 Ticket::KIND::MOVIE, "September 1, 7:30PM");
	assert(to_string(t.getPrice()) == "20.000000"); //checks if price is properly calculated
	assert(t.getRow() == "Orchestra Row U");
	assert(t.getSeat() == 20);
	assert(t.getEvent() == "Episode VII: The Force Awakens");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::KIND::MOVIE);
	assert(t.getDayTime() == "September 1, 7:30PM");

	t = b.buyRoyceHallStaffTicket("Balcony Row J", 120, "An Evening With David Sedaris", 
		 Ticket::KIND::OTHER, "October 1, 7:30PM");
	assert(to_string(t.getPrice()) == "35.000000"); //checks if price is properly calculated
	assert(t.getRow() == "Balcony Row J");
	assert(t.getSeat() == 120);
	assert(t.getEvent() == "An Evening With David Sedaris");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::KIND::OTHER);
	assert(t.getDayTime() == "October 1, 7:30PM");

	t = b.buyRoyceHallTicket("Orchestra Row A", 56, "Barry Manilow Live In Concert", 
		 Ticket::KIND::CONCERT, "November 1, 7:30PM");
	assert(to_string(t.getPrice()) == "130.000000"); //checks if price is properly calculated
	assert(t.getRow() == "Orchestra Row A");
	assert(t.getSeat() == 56);
	assert(t.getEvent() == "Barry Manilow Live In Concert");
	assert(t.getVenue() == "Royce Hall");
	assert(t.getKind() == Ticket::KIND::CONCERT);
	assert(t.getDayTime() == "November 1, 7:30PM");

	cerr << "All tests passed!" << endl;
	return 0;
}