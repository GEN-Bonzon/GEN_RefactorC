//
// Created by tiffany on 6/20/20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Rental.h"
#include "MovieStateRegular.h"

class MMovie : public Movie {
    public:
        MMovie() : Movie("Karate Kid", new MovieStateRegular()) {};
        MOCK_METHOD(std::string, getTitle, ());
        MOCK_METHOD(double, getPrice, ());
        MOCK_METHOD(unsigned, getMaxRentPeriodBeforePriceIncrease, ());
        MOCK_METHOD(double, getPriceIncrease, ());
        MOCK_METHOD(std::string, getMovieType, ());
};

MMovie movie;
Rental rental(movie, 42);


TEST(Rental, movie) {
    EXPECT_CALL(movie, getTitle()).WillRepeatedly(testing::Return("Karate Kid"));
    EXPECT_CALL(movie, getPrice()).WillRepeatedly(testing::Return(2));
    EXPECT_CALL(movie, getMaxRentPeriodBeforePriceIncrease()).WillRepeatedly(testing::Return(2));
    EXPECT_CALL(movie, getPriceIncrease()).WillRepeatedly(testing::Return(1.5));
    EXPECT_CALL(movie, getMovieType()).WillRepeatedly(testing::Return("Regular"));

    ASSERT_EQ(movie.getTitle(), rental.getMovie().getTitle());
    ASSERT_EQ(movie.getPrice(), rental.getMovie().getPrice());
    ASSERT_EQ(movie.getMaxRentPeriodBeforePriceIncrease(), rental.getMovie().getMaxRentPeriodBeforePriceIncrease());
    ASSERT_EQ(movie.getPriceIncrease(), rental.getMovie().getPriceIncrease());
    ASSERT_EQ(movie.getMovieType(), rental.getMovie().getMovieType());
}

TEST(Rental, daysRented) {
    ASSERT_EQ(42, rental.getDaysRented());
}

TEST(Rental, price) {
    ASSERT_EQ(62, rental.getPrice());
}

TEST(Rental, title) {
    ASSERT_EQ("Karate Kid", rental.getTitle());
}

