#include <iostream>
#include <vector>
#include "movie.h"
using namespace std;


// virtual bool Movie::compare(const Movie &movie) const {
//     if (movie.genre_ != this->genre_) {
//         return this->genre_ > movie.genre_;
//     } else {
//         return operator>(movie);
//     }
// }

bool Movie::operator>(const Movie &movie) const {
    if (movie.genre_ == this->genre_) {
        // do the individual genre's sorting
        return (this)*.compare(movie);

    } else {
        return this->genre_ > movie.genre_;
    }
}
