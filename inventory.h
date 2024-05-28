#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "movie.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <sstream>

class Inventory {
public:
    ~Inventory();
    void AddMovie(const Movie& movie, int count);
    bool BorrowMovie(const std::string& movie_info);
    bool ReturnMovie(const std::string& movie_info);
    void PrintInventory() const;

private:
    std::vector<Movie*> movies_;

    void AddMovieHelper(Movie* movie, int count);
};

#endif // INVENTORY_H_
