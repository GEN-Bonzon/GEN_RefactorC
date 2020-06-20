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
        if ((rental.getType() == "NewRelease" )
            && rental.getDaysRented() > 1 ) frequentRenterPoints++;

        // show figures for this rental
        result << "\t" << rental.getTitle() << "\t"
               << rental.getPrice() << "\n";
        totalAmount += rental.getPrice();
    }
    // add footer lines

    // determine amounts for each line
    result << "Amount owed is " << getTotalAmountDue() << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

double Customer::getTotalAmountDue() {
    totalAmountDue = 0;

    for (Rental rental : _rentals)
        totalAmountDue += rental.getPrice();

    return totalAmountDue;
}

