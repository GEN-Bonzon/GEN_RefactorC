//
// Created by tiffany on 6/20/20.
// FROM: https://sourcemaking.com/design_patterns/state/cpp/1
//

#ifndef GEN_REFACTORC_MOVIESTATEREGULAR_H
#define GEN_REFACTORC_MOVIESTATEREGULAR_H


class MovieStateRegular : public MovieState {
    double getPrice() {
        return 2;
    }

    unsigned getMaxRentPeriodBeforePriceIncrease() {
        return 2;
    }

    double getPriceIncrease() {
        return 1.5;
    }

    std::string getMovieType() {
        return "Regular";
    }
};


#endif //GEN_REFACTORC_MOVIESTATEREGULAR_H
