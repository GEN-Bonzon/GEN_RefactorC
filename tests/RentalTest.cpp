//
// Created by tiffany on 6/20/20.
//

#include <gtest/gtest.h>

#include "Rental.h"
#include "Movie.h"
#include "MovieStateRegular.h"

Movie movie("Karate Kid", new MovieStateRegular());
Rental rental(movie, 42);

TEST(Rental, movie) {
    ASSERT_TRUE(movie.getTitle() == rental.getMovie().getTitle());
    ASSERT_TRUE(movie.getPrice() == rental.getMovie().getPrice());
    ASSERT_TRUE(movie.getMaxRentPeriodBeforePriceIncrease() == rental.getMovie().getMaxRentPeriodBeforePriceIncrease());
    ASSERT_TRUE(movie.getPriceIncrease() == rental.getMovie().getPriceIncrease());
    ASSERT_TRUE(movie.getMovieType() == rental.getMovie().getMovieType());
}

TEST(Rental, daysRented) {
    ASSERT_EQ(42, rental.getDaysRented());
}

