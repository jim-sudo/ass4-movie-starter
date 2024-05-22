#include "movie.h"
// Drama class methods

Drama::Drama(const string& director, const string& title, int stock, int release_year)
    : release_year_(release_year) {
    this->title_ = title;
    this->stock_ = stock;
    this->current_stock_ = stock;
    this->director_ = director;
    this->genre_ = 'D';
}

bool Drama::operator<(const Movie& other) const {
    const Drama& drama = static_cast<const Drama&>(other);
    if (director_ != drama.director_) {
        return director_ < drama.director_;
    }
    return title_ < drama.title_;
}

bool Drama::operator==(const Movie& other) const {
    const Drama& drama = static_cast<const Drama&>(other);
    return director_ == drama.director_ && title_ == drama.title_;
}

ostream& Drama::Print(ostream& out) const {
    out << "Drama: " << director_ << ", " << title_ << ", " << release_year_ << ", " << current_stock_ << "/" << stock_;
    return out;
}

string Drama::ToString() const {
    return to_string(stock_) + ", " + director_ + ", " + title_ + ", " + to_string(release_year_);
}

int Drama::getReleaseYear() const {
    return release_year_;
}

void Drama::setReleaseYear(int year) {
    release_year_ = year;
}

string Drama::getDirector() const {
    return director_;
}

void Drama::setDirector(const string& director) {
    this->director_ = director;
}

Movie* DramaFactory::Create(const string& line) const {
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

    return new Drama(director, title, stock, releaseYear);
}
