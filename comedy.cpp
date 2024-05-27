#include "movie.h"

// Comedy class methods

Comedy::Comedy(const string& title, int stock, const string& director, int release_year)
    : release_year_(release_year) {
    this->title_ = title;
    this->stock_ = stock;
    this->current_stock_ = stock;
    this->director_ = director;
    this->genre_ = 'F';
}

bool Comedy::operator<(const Movie& other) const {
    const auto comedy = static_cast<const Comedy&>(other);
    if (title_ != comedy.title_) {
        return title_ < comedy.title_;
    }
    return release_year_ < comedy.release_year_;
}

bool Comedy::operator==(const Movie& other) const {
    const auto comedy = static_cast<const Comedy&>(other);
    return title_ == comedy.title_ && release_year_ == comedy.release_year_;
}

ostream& Comedy::Print(ostream& out) const {
    out << "Title: " << title_ << '\n';
    out << "Director: " <<director_ << '\n';
    out << "Release Year: " << release_year_<< '\n';
    out << "Borrowed: " << current_stock_ - stock_<< '\n';
    out << "Available in Stock: " << stock_<< '\n';
    //out << "Comedy: " << title_ << ", " << release_year_ << ", " << director_ <<  "\n" << "[Overall stock: ]" << current_stock_  << " , avaliable:  "<< stock_ << " ] \n";
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
    string director;
    string title;
    int release_year;

    ss >> stock;
    ss.ignore(2); 
    getline(ss, director, ',');
    ss.ignore(1); 
    getline(ss, title, ',');
    ss.ignore(1);
    ss >> release_year;

    return new Comedy(title, stock, director, release_year);
}
