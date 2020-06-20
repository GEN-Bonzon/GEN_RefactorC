#include <iostream>

#include "Customer.h"
#include "MovieStateRegular.h"
#include "MovieStateNewRelease.h"
#include "MovieStateChildren.h"

int main() {

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid", new MovieStateRegular()), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", new MovieStateNewRelease() ), 5));
    customer.addRental( Rental( Movie("Snow White", new MovieStateChildren), 3 ));

    std::cout << customer.statement() << std::endl;

    return 0;
}