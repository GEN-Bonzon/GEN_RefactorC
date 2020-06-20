// Customer.cpp
#include <sstream>

#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    getRentalsFigures(result);

    // add footer lines
    result << "Amount owed is " << getTotalAmountDue() << "\n";
    result << "You earned " << getFrequentRenterPoint()
           << " frequent renter points";
    return result.str();
}

void Customer::getRentalsFigures(ostringstream &result) const {
    for(Rental rental : _rentals) {
        // show figures for this rental
        result << "\t" << rental.getTitle() << "\t"
               << rental.getPrice() << "\n";
    }
}

double Customer::getTotalAmountDue() {
    totalAmountDue = 0;

    for (Rental rental : _rentals)
        totalAmountDue += rental.getPrice();

    return totalAmountDue;
}

unsigned Customer::getFrequentRenterPoint() {
    frequentRenterPoints = 0;
    for(Rental rental : _rentals) {
        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        if ((rental.getType() == "NewRelease")
            && rental.getDaysRented() > 1)
            frequentRenterPoints++;
    }

    return frequentRenterPoints;
}

