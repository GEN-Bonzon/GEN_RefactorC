// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

#include "MovieState.h"

class Movie {
public:
    Movie( const std::string& title, MovieState *state);

    std::string getTitle() const;

    double getPrice() const;
    unsigned getMaxRentPeriodBeforePriceIncrease() const;
    double getPriceIncrease() const;
    std::string getMovieType() const;

private:
    std::string _title;
    MovieState* _state;
};

inline Movie::
Movie( const std::string& title, MovieState *state )
        : _title( title )
        , _state( state )
{}

inline double Movie::
getPrice() const { return _state->getPrice(); }

inline unsigned Movie::
getMaxRentPeriodBeforePriceIncrease() const { return _state->getMaxRentPeriodBeforePriceIncrease(); }

inline double Movie::
getPriceIncrease() const { return _state->getPriceIncrease(); }

inline std::string Movie::
getMovieType() const { return _state->getMovieType(); }

inline std::string Movie::
getTitle() const { return _title; }

#endif // MOVIE_H