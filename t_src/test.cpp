#define CATCH_CONFIG_MAIN 
#include "../framework/catch.hpp"
#include "../include/domain.hpp"

// Total - 4 Tests - 1 pass - 3 failed
TEST_CASE("create agency", "[Agency]")
{
  SECTION( "common set" ) 
  {
   Agency* A = new Agency("12345");
   REQUIRE(A->get_value() == "12345");
  }

  // Size lesser than standard
  SECTION( "Error 1" ) 
  {
   Agency* Agency_test = new Agency("1234");
   REQUIRE(Agency_test->get_value() == "1234");
  }

  // Invalid digit entry
  SECTION( "Error 2" ) 
  {
   Agency* Agency_test = new Agency("123a5");
   REQUIRE(Agency_test->get_value() == "123a5");
  }

  // Size greater than standard
  SECTION( "Error 3" ) 
  {
   Agency* Agency_test = new Agency("123456");
   REQUIRE(Agency_test->get_value() == "123456");
  }

}

// Total - 8 Tests - 2 pass - 6 failed
TEST_CASE("create Bank", "[Bank]")
{
  SECTION( "common set" ) 
  {
   Bank* Bank_test = new Bank("123");
   REQUIRE(Bank_test->get_value() == "123");
  }

  // Size lesser than standard
  SECTION( "Error 1" ) 
  {
   Bank* Bank_test = new Bank("13");
   REQUIRE(Bank_test->get_value() == "13");
  }

  // Invalid digit entry
  SECTION( "Error 2" ) 
  {
   Bank* Bank_test = new Bank("1a");
   REQUIRE(Bank_test->get_value() == "1a");
  }

  // Size greater than standard
  SECTION( "Error 3" ) 
  {
   Bank* Bank_test = new Bank("123456");
   REQUIRE(Bank_test->get_value() == "123456");
  }

}

// Total - 13 Tests - 3 pass - 10 failed
TEST_CASE("create Accommodation Capacity", "[Accommodation Capacity]")
{
  SECTION( "common set" ) 
  {
   AccommodationCapacity* AccommodationCapacity_test = new AccommodationCapacity("1");
   REQUIRE(AccommodationCapacity_test->get_value() == "1");
  }

  // Size lesser than standard
  SECTION( "Error 1" ) 
  {
   AccommodationCapacity* AccommodationCapacity_test = new AccommodationCapacity("");
   REQUIRE(AccommodationCapacity_test->get_value() == "");
  }

  // Invalid digit entry
  SECTION( "Error 2" ) 
  {
   AccommodationCapacity* AccommodationCapacity_test = new AccommodationCapacity("a");
   REQUIRE(AccommodationCapacity_test->get_value() == "a");
  }

  // Invalid digit entry
  SECTION( "Error 3" ) 
  {
   AccommodationCapacity* AccommodationCapacity_test = new AccommodationCapacity("a");
   REQUIRE(AccommodationCapacity_test->get_value() == "A");
  }


  // Size greater than standard
  SECTION( "Error 4" ) 
  {
   AccommodationCapacity* AccommodationCapacity_test = new AccommodationCapacity("123456");
   REQUIRE(AccommodationCapacity_test->get_value() == "123456");
  }

}

// Total - 19 Tests - 4 pass - 15 failed
TEST_CASE("create Daily Value", "[Daily Value]")
{
  SECTION( "common set" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("20.00");
   REQUIRE(DailyValue_test->get_value() == "20.00");
  }

  // Size lesser than standard
  SECTION( "Error 1" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("0.02");
   REQUIRE(DailyValue_test->get_value() == "0.02");
  }

    // Size greater than standard
  SECTION( "Error 2" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("12300.00");
   REQUIRE(DailyValue_test->get_value() == "123000.00");
  }


  // Invalid digit entry
  SECTION( "Error 3" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("a");
   REQUIRE(DailyValue_test->get_value() == "a");
  }

  // Invalid digit entry
  SECTION( "Error 4" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("123as.00");
  }

  // Invalid digit entry
  SECTION( "Error 5" ) 
  {
   DailyValue* DailyValue_test = new DailyValue("1232.00 3334.00");
  }
}

// Total -  44 Tests - 20 pass - 24 failed
TEST_CASE("create Date", "[Date]")
{
  SECTION("common set 1")
  {
    Date *Date_test = new Date("02/jan/2023");
    REQUIRE(Date_test->get_value() == "02/jan/2023");
    REQUIRE(Date_test->get_day() == 2);
    REQUIRE(Date_test->get_month() == 1);
    REQUIRE(Date_test->get_year() == 2023);
  }

  SECTION("common set 2")
  {
    Date *Date_test = new Date("27/jun/2005");
    REQUIRE(Date_test->get_value() == "27/jun/2005");
    REQUIRE(Date_test->get_day() == 27);
    REQUIRE(Date_test->get_month() == 06);
    REQUIRE(Date_test->get_year() == 2005);
  }

  // Size error
  SECTION("Error 1")
  {
    Date *Date_test = new Date("1/jun/2005");
  }

  // '/' error
  SECTION("Error 2")
  {
    Date *Date_test = new Date("012jun/2005");
  }

  // '/' error 
  SECTION("Error 3")
  {
    Date *Date_test = new Date("01/junn2005");
  }

  // Digit error
  SECTION("Error 4")
  {
    Date *Date_test = new Date("0a/jun/2000");
  }

  // Digit error
  SECTION("Error 5")
  {
    Date *Date_test = new Date("01/jun/200a");
  }

  // Month value error
  SECTION("Error 6")
  {
    Date *Date_test = new Date("01/feb/2010");
  }

  // Year value error
  SECTION("Error 7")
  {
    Date *Date_test = new Date("01/jun/1999");
  }

  // Year value error
  SECTION("Error 8")
  {
    Date *Date_test = new Date("01/jun/2100");
  }

  // Day value error(Not a leap year)
  SECTION("Error 9")
  {
    Date *Date_test = new Date("29/fev/2018");
  }

  SECTION("Leap year 1")
  {
    Date *Date_test = new Date("29/fev/2020");
    REQUIRE(Date_test->get_value() == "29/fev/2020");
    REQUIRE(Date_test->get_day() == 29);
    REQUIRE(Date_test->get_month() == 02);
    REQUIRE(Date_test->get_year() == 2020);
  }

  SECTION("Leap year 2")
  {
    Date *Date_test = new Date("29/fev/2000");
    REQUIRE(Date_test->get_value() == "29/fev/2000");
    REQUIRE(Date_test->get_day() == 29);
    REQUIRE(Date_test->get_month() == 02);
    REQUIRE(Date_test->get_year() == 2000);
  }
}

// Total -  52 Tests - 22 pass - 30 failed 
TEST_CASE("create Expiration date", "[Expiration date]")
{
  SECTION("common set")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("03/18");
    REQUIRE(ExpirationDate_test->get_month() == 3);
    REQUIRE(ExpirationDate_test->get_year() == 2018);
  }

  // Size error
  SECTION("Error 1")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("03/1");
  }

  // '/' error
  SECTION("Error 2")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("1/008");
  }

  // Digits error 
  SECTION("Error 3")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("0a/08");
  }

  // Digits error 
  SECTION("Error 4")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("02//8");
  }

  // Month value error 
  SECTION("Error 5")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("13/08");
  }

  // Month value error 
  SECTION("Error 6")
  {
    ExpirationDate* ExpirationDate_test = new ExpirationDate("00/08");
  }
}

// Total -  58 Tests - 26 pass - 32 failed 
TEST_CASE("create State", "[State]")
{
  SECTION("common set 1")
  {
    State* State_test = new State("AC");
    REQUIRE(State_test->get_value() == "AC");
    REQUIRE(State_test->get_state() == StateName::AC);
  }

    SECTION("common set 2")
  {
    State* State_test = new State("DF");
    REQUIRE(State_test->get_value() == "DF");
    REQUIRE(State_test->get_state() == StateName::DF);
  }

  SECTION("Error 1")
  {
    State* State_test = new State("df");
    REQUIRE(State_test->get_value() == "DF");
    REQUIRE(State_test->get_state() == StateName::AC);
  }

  SECTION("Error 2")
  {
    State* State_test = new State("EF");
  }
}

// Total -  62 Tests - 28 pass - 34 failed 
TEST_CASE("create Identifier", "[Identifier]")
{
  SECTION("common set 1")
  {
    Identifier *Identifier_test = new Identifier("ahyef");
    REQUIRE(Identifier_test->get_value() == "ahyef");
  }

  SECTION("common set 2")
  {
    Identifier *Identifier_test = new Identifier("aaaaa");
    REQUIRE(Identifier_test->get_value() == "aaaaa");
  }

  SECTION("Error 1")
  {
    Identifier *Identifier_test = new Identifier("Ahyef");
  }

  SECTION("Error 2")
  {
    Identifier *Identifier_test = new Identifier("a_yer");
  }
}
