//
// Created by tiffany on 6/20/20.
// FROM: https://sourcemaking.com/design_patterns/state/cpp/1
//

#ifndef GEN_REFACTORC_MOVIESTATE_H
#define GEN_REFACTORC_MOVIESTATE_H


class MovieState {
public:
    virtual double getPrice() = 0;
    virtual unsigned getMaxRentPeriodBeforePriceIncrease() = 0;
    virtual double getPriceIncrease() = 0;
    virtual std::string getMovieType() = 0;
};


#endif //GEN_REFACTORC_MOVIESTATE_H
