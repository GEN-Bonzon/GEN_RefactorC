//
// Created by tiffany on 6/20/20.
//

#include <gtest/gtest.h>

#include "Movie.h"
#include "MovieStateRegular.h"
#include "MovieStateChildren.h"
#include "MovieStateNewRelease.h"

TEST(Movie, title) {
    std::string regularName    = "Karate Kid",
                chlidrenName   = "Snow White",
                newReleaseName = "Avengers: Endgame";

    Movie regularMovie(regularName, new MovieStateRegular());
    Movie childrenMovie(chlidrenName, new MovieStateChildren());
    Movie newReleaseMovie(newReleaseName, new MovieStateNewRelease());

    ASSERT_EQ(regularName, regularMovie.getTitle());
    ASSERT_EQ(chlidrenName, childrenMovie.getTitle());
    ASSERT_EQ(newReleaseName, newReleaseMovie.getTitle());
}

TEST(Movie, price) {
    std::string regularName    = "Karate Kid",
                chlidrenName   = "Snow White",
                newReleaseName = "Avengers: Endgame";

    Movie regularMovie(regularName, new MovieStateRegular());
    Movie childrenMovie(chlidrenName, new MovieStateChildren());
    Movie newReleaseMovie(newReleaseName, new MovieStateNewRelease());

    double regularPrice    = 2,
           childrenPrice   = 1.5,
           newReleasePrice = 0;

    ASSERT_EQ(regularPrice, regularMovie.getPrice());
    ASSERT_EQ(childrenPrice, childrenMovie.getPrice());
    ASSERT_EQ(newReleasePrice, newReleaseMovie.getPrice());
}

TEST(Movie, maxRentPeriodBeforePriceIncrease) {
    std::string regularName    = "Karate Kid",
                chlidrenName   = "Snow White",
                newReleaseName = "Avengers: Endgame";

    Movie regularMovie(regularName, new MovieStateRegular());
    Movie childrenMovie(chlidrenName, new MovieStateChildren());
    Movie newReleaseMovie(newReleaseName, new MovieStateNewRelease());

    unsigned regularPeriod    = 2,
             childrenPeriod   = 3,
             newReleasePeriod = 0;

    ASSERT_EQ(regularPeriod, regularMovie.getMaxRentPeriodBeforePriceIncrease());
    ASSERT_EQ(childrenPeriod, childrenMovie.getMaxRentPeriodBeforePriceIncrease());
    ASSERT_EQ(newReleasePeriod, newReleaseMovie.getMaxRentPeriodBeforePriceIncrease());
}

TEST(Movie, priceIncrease) {
    std::string regularName    = "Karate Kid",
                chlidrenName   = "Snow White",
                newReleaseName = "Avengers: Endgame";

    Movie regularMovie(regularName, new MovieStateRegular());
    Movie childrenMovie(chlidrenName, new MovieStateChildren());
    Movie newReleaseMovie(newReleaseName, new MovieStateNewRelease());

    double regularPriceIncrease    = 1.5,
           childrenPriceIncrease   = 1.5,
           newReleasePriceIncrease = 3;

    ASSERT_EQ(regularPriceIncrease, regularMovie.getPriceIncrease());
    ASSERT_EQ(childrenPriceIncrease, childrenMovie.getPriceIncrease());
    ASSERT_EQ(newReleasePriceIncrease, newReleaseMovie.getPriceIncrease());
}

TEST(Movie, movieType) {
    std::string regularName    = "Karate Kid",
                chlidrenName   = "Snow White",
                newReleaseName = "Avengers: Endgame";

    Movie regularMovie(regularName, new MovieStateRegular());
    Movie childrenMovie(chlidrenName, new MovieStateChildren());
    Movie newReleaseMovie(newReleaseName, new MovieStateNewRelease());

    std::string regularType    = "Regular",
                childrenType   = "Children",
                newReleaseType = "NewRelease";

    ASSERT_EQ(regularType, regularMovie.getMovieType());
    ASSERT_EQ(childrenType, childrenMovie.getMovieType());
    ASSERT_EQ(newReleaseType, newReleaseMovie.getMovieType());
}