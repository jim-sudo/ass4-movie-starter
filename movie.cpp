#include "movie.h"
#include <sstream>
#include <iostream>

<<<<<<< HEAD

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
        // return *(this).compare(movie);

    } else {
        return this->genre_ > movie.genre_;
    }
=======
map<char, MovieFactory*>& Movie::getFactories() {
    static map<char, MovieFactory*> factories;
    return factories;
}

void Movie::RegisterType(char type, MovieFactory* factory) {
    getFactories()[type] = factory;
}

Movie* Movie::Create(char type, const string& line) {
    auto it = getFactories().find(type);
    if (it != getFactories().end()) {
        return it->second->Create(line);
    }
    throw std::invalid_argument("Invalid movie type");
}

string Movie::getTitle() const { 
    return title_;

}
void Movie::setTitle(const string& title) {
    this->title_ = title;
}

int Movie::getStock() const { return stock_; }
void Movie::setStock(int stock) { this->stock_ = stock; }

char Movie::getType() const {
    return genre_;
}

bool Movie::Borrow() {
    if (current_stock_ > 0) {
        current_stock_--;
        return true;
    }
    return false;
}

bool Movie::ReturnItem() {
    if (current_stock_ < stock_) {
        current_stock_++;
        return true;
    }
    return false;
>>>>>>> 81e3b0c82f54b050ebb0052181ae9ccc34f8cc4c
}
