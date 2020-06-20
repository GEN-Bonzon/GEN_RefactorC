//
// Created by tiffany on 6/20/20.
// FROM: https://sourcemaking.com/design_patterns/state/cpp/1
//

#ifndef GEN_REFACTORC_MOVIESTATENEWRELEASE_H
#define GEN_REFACTORC_MOVIESTATENEWRELEASE_H


class MovieStateNewRelease : public MovieState {
    double getPrice() {
        return 0;
    }

    unsigned getMaxRentPeriodBeforePriceIncrease() {
        return 0;
    }

    double getPriceIncrease() {
        return 3;
    }

    std::string getMovieType() {
        return "NewRelease";
    }
};


#endif //GEN_REFACTORC_MOVIESTATENEWRELEASE_H
