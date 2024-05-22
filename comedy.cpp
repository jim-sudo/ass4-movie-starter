#include "movie.h"

// Comedy class methods

Comedy::Comedy(const string& title, int stock, const string& director, int releaseYear)
    : release_year_(releaseYear) {
    this->title_ = title;
    this->stock_ = stock;
    this->current_stock_ = stock;
    this->director_ = director;
    this->genre_ = 'F';
}

bool Comedy::operator<(const Movie& other) const {
    const Comedy& comedy = static_cast<const Comedy&>(other);
    if (title_ != comedy.title_) {
        return title_ < comedy.title_;
    }
    return release_year_ < comedy.release_year_;
}

bool Comedy::operator==(const Movie& other) const {
    const Comedy& comedy = static_cast<const Comedy&>(other);
    return title_ == comedy.title_ && release_year_ == comedy.release_year_;
}

ostream& Comedy::Print(ostream& out) const {
    out << "Comedy: " << title_ << ", " << release_year_ << ", " << director_ << ", " << current_stock_ << "/" << stock_;
    return out;
}

string Comedy::ToString() const {
    return std::to_string(stock_) + ", " + director_ + ", " + title_ + ", " + std::to_string(release_year_);
}

int Comedy::getReleaseYear() const {
    return release_year_;
}

void Comedy::setReleaseYear(int year) {
    release_year_ = year;
}

string Comedy::getDirector() const {
    return director_;
}

void Comedy::setDirector(const string& director) {
    this->director_ = director;
}

Movie* ComedyFactory::Create(const string& line) const {
    istringstream ss(line);
    int stock;
    string director, title;
    int releaseYear;

    ss >> stock;
    ss.ignore(2); 
    getline(ss, director, ',');
    ss.ignore(1); 
    getline(ss, title, ',');
    ss.ignore(1);
    ss >> releaseYear;

    return new Comedy(title, stock, director, releaseYear);
}