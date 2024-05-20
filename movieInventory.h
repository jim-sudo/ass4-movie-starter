//
// Created by new on 5/17/24.
//

#ifndef ASS4_MOVIE_STARTERG_MOVIEINVENTORY_H
#define ASS4_MOVIE_STARTERG_MOVIEINVENTORY_H
#include "movie.h"
#include <vector>

using std::vector;

class MovieInventory {
private:
  std::vector<Movie> movies_;
  std::vector<int> count_;

public:
  MovieInventory();
  void addMovie(const Movie& movie, int count);
  bool borrowMovie(const std::string& title);
  bool returnMovie(const std::string& title);
  void printInventory() const;
};

#endif // ASS4_MOVIE_STARTERG_MOVIEINVENTORY_H
