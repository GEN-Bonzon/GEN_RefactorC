#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Customer.h"
#include "MovieStateRegular.h"
#include "MovieStateNewRelease.h"
#include "MovieStateChildren.h"
#include "Rental.h"

class MMovieR : public Movie {
public:
    MMovieR() : Movie("Karate Kid", new MovieStateRegular()) {};
    MOCK_METHOD(std::string, getTitle, ());
    MOCK_METHOD(double, getPrice, ());
    MOCK_METHOD(unsigned, getMaxRentPeriodBeforePriceIncrease, ());
    MOCK_METHOD(double, getPriceIncrease, ());
    MOCK_METHOD(std::string, getMovieType, ());
};

class MMovieNR : public Movie {
public:
    MMovieNR() : Movie("Avengers: Endgame", new MovieStateNewRelease()) {};
    MOCK_METHOD(std::string, getTitle, ());
    MOCK_METHOD(double, getPrice, ());
    MOCK_METHOD(unsigned, getMaxRentPeriodBeforePriceIncrease, ());
    MOCK_METHOD(double, getPriceIncrease, ());
    MOCK_METHOD(std::string, getMovieType, ());
};

class MMovieC : public Movie {
public:
    MMovieC() : Movie("Snow White", new MovieStateChildren()) {};
    MOCK_METHOD(std::string, getTitle, ());
    MOCK_METHOD(double, getPrice, ());
    MOCK_METHOD(unsigned, getMaxRentPeriodBeforePriceIncrease, ());
    MOCK_METHOD(double, getPriceIncrease, ());
    MOCK_METHOD(std::string, getMovieType, ());
};

TEST(Customer, name) {
    std::string name = "Jimmy";
    Customer customer(name);

    ASSERT_EQ(name, customer.getName());
}

TEST(Customer, statement) {

    MMovieR movieR;
    MMovieNR movieNR;
    MMovieC movieC;

    EXPECT_CALL(movieR, getTitle()).WillRepeatedly(testing::Return("Karate Kid"));
    EXPECT_CALL(movieR, getPrice()).WillRepeatedly(testing::Return(2));
    EXPECT_CALL(movieR, getMaxRentPeriodBeforePriceIncrease()).WillRepeatedly(testing::Return(2));
    EXPECT_CALL(movieR, getPriceIncrease()).WillRepeatedly(testing::Return(1.5));
    EXPECT_CALL(movieR, getMovieType()).WillRepeatedly(testing::Return("Regular"));

    EXPECT_CALL(movieNR, getTitle()).WillRepeatedly(testing::Return("Avengers: Endgame"));
    EXPECT_CALL(movieNR, getPrice()).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(movieNR, getMaxRentPeriodBeforePriceIncrease()).WillRepeatedly(testing::Return(0));
    EXPECT_CALL(movieNR, getPriceIncrease()).WillRepeatedly(testing::Return(3));
    EXPECT_CALL(movieNR, getMovieType()).WillRepeatedly(testing::Return("NewRelease"));

    EXPECT_CALL(movieC, getTitle()).WillRepeatedly(testing::Return("Snow White"));
    EXPECT_CALL(movieC, getPrice()).WillRepeatedly(testing::Return(1.5));
    EXPECT_CALL(movieC, getMaxRentPeriodBeforePriceIncrease()).WillRepeatedly(testing::Return(3));
    EXPECT_CALL(movieC, getPriceIncrease()).WillRepeatedly(testing::Return(1.5));
    EXPECT_CALL(movieC, getMovieType()).WillRepeatedly(testing::Return("Children"));

    Customer customer("Olivier");
    customer.addRental( Rental( movieR, 7));
    customer.addRental( Rental( movieNR, 5));
    customer.addRental( Rental( movieC, 3 ));

    std::string expected = "Rental Record for Olivier\n"
                           "\tKarate Kid\t9.5\n"
                           "\tAvengers: Endgame\t15\n"
                           "\tSnow White\t1.5\n"
                           "Amount owed is 26\n"
                           "You earned 4 frequent renter points";

    ASSERT_EQ(expected, customer.statement());
}