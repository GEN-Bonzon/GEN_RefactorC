//
// Created by tiffany on 6/20/20.
// FROM: https://sourcemaking.com/design_patterns/state/cpp/1
//

#ifndef GEN_REFACTORC_MOVIESTATECHILDREN_H
#define GEN_REFACTORC_MOVIESTATECHILDREN_H


class MovieStateChildren : public MovieState {
    double getPrice() override {
        return 1.5;
    }

    unsigned getMaxRentPeriodBeforePriceIncrease() override {
        return 3;
    }

    double getPriceIncrease() override {
        return 1.5;
    }

    std::string getMovieType() override {
        return "Children";
    }
};


#endif //GEN_REFACTORC_MOVIESTATECHILDREN_H
