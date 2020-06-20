// Customer.cpp
#include <sstream>

#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for(Rental rental : _rentals) {

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        if ((rental.getMovie().getMovieType() == "NewRelease" )
            && rental.getDaysRented() > 1 ) frequentRenterPoints++;

        // show figures for this rental
        result << "\t" << rental.getMovie().getTitle() << "\t"
               << getRentalAmount(rental) << "\n";
        totalAmount += getRentalAmount(rental);
    }
    // add footer lines
    result << "Amount owed is " << getTotalAmountDue() << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

double Customer::getTotalAmountDue() {
    totalAmountDue = 0;// determine amounts for each line

    for (Rental rental : _rentals) {

        totalAmountDue += getRentalAmount(rental);
        /*
        totalAmountDue += rental.getMovie().getPrice();
        if (rental.getDaysRented() > rental.getMovie().getMaxRentPeriodBeforePriceIncrease())
            totalAmountDue += (rental.getDaysRented() - rental.getMovie().getMaxRentPeriodBeforePriceIncrease()) * rental.getMovie().getPriceIncrease();

        switch (rental.getMovie().getPriceCode()) {
            case Movie::REGULAR:
                totalAmountDue += 2;
                if (rental.getDaysRented() > 2)
                    totalAmountDue += (rental.getDaysRented() - 2) * 1.5;
                break;
            case Movie::NEW_RELEASE:
                totalAmountDue += rental.getDaysRented() * 3;
                break;
            case Movie::CHILDRENS:
                totalAmountDue += 1.5;
                if (rental.getDaysRented() > 3)
                    totalAmountDue += (rental.getDaysRented() - 3) * 1.5;
                break;
        }
         */
    }

    return totalAmountDue;
}

double Customer::getRentalAmount(const Rental& rental) {
    double price = 0;

    price += rental.getMovie().getPrice();
    if (rental.getDaysRented() > rental.getMovie().getMaxRentPeriodBeforePriceIncrease())
        price += (rental.getDaysRented() - rental.getMovie().getMaxRentPeriodBeforePriceIncrease()) * rental.getMovie().getPriceIncrease();
    /*
    switch (rental.getMovie().getPriceCode()) {
        case Movie::REGULAR:
            price += 2;
            if (rental.getDaysRented() > 2)
                price += (rental.getDaysRented() - 2) * 1.5;
            break;
        case Movie::NEW_RELEASE:
            price += rental.getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            price += 1.5;
            if (rental.getDaysRented() > 3)
                price += (rental.getDaysRented() - 3) * 1.5;
            break;
    }
     */

    return price;
}
