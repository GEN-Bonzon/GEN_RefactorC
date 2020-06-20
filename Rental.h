// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include <sstream>
#include "Movie.h"


class Rental {
public:
    Rental(const Movie& movie, unsigned daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;
    double getPrice() const;

private:
    Movie _movie;
    int _daysRented;
};

inline Rental::
Rental(const Movie& movie, unsigned daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie& Rental::
getMovie() const { return _movie; }

inline double Rental::
getPrice() const {
    double price = _movie.getPrice();
    if (_daysRented > _movie.getMaxRentPeriodBeforePriceIncrease())
        price += (_daysRented - _movie.getMaxRentPeriodBeforePriceIncrease()) * _movie.getPriceIncrease();

    return price;
}

#endif // RENTAL_H