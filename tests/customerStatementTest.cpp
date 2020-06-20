#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Customer.h"
#include "MovieStateRegular.h"
#include "MovieStateNewRelease.h"
#include "MovieStateChildren.h"

TEST(Customer, statement) {

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid", new MovieStateRegular()), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", new MovieStateNewRelease() ), 5));
    customer.addRental( Rental( Movie("Snow White", new MovieStateChildren), 3 ));

    std::string expected = "Rental Record for Olivier\n"
                           "\tKarate Kid\t9.5\n"
                           "\tAvengers: Endgame\t15\n"
                           "\tSnow White\t1.5\n"
                           "Amount owed is 26\n"
                           "You earned 4 frequent renter points";

    ASSERT_EQ(expected, customer.statement());
}