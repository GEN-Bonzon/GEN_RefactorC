// Customer.cpp
#include <sstream>
#include <vector>
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
        if ((rental.getMovie().getPriceCode() == Movie::NEW_RELEASE )
            && rental.getDaysRented() > 1 ) frequentRenterPoints++;

        // show figures for this rental
        result << "\t" << rental.getMovie().getTitle() << "\t"
               << getAmount(rental) << "\n";
        totalAmount += getAmount(rental);
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

double Customer::getAmount(const Rental& rental) const {
    double  thisAmount= 0;// determine amounts for each line
    switch ( rental.getMovie().getPriceCode() ) {
        case Movie::REGULAR:
            thisAmount += 2;
            if (rental.getDaysRented() > 2 )
                thisAmount += (rental.getDaysRented() - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            thisAmount += rental.getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            thisAmount += 1.5;
            if (rental.getDaysRented() > 3 )
                thisAmount += (rental.getDaysRented() - 3 ) * 1.5;
            break;
    }

    return thisAmount;
}
