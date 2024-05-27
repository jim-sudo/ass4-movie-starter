#include "movie.h"
// Drama class methods

Drama::Drama(const string &director, const string &title, int stock,
             int release_year)
    : release_year_(release_year) {
  this->title_ = title;
  this->stock_ = stock;
  this->current_stock_ = stock;
  this->director_ = director;
  this->release_year_ = release_year;
  this->genre_ = 'D';
}

bool Drama::operator<(const Movie &other) const {
  const auto drama = static_cast<const Drama &>(other);
  if (director_ != drama.director_) {
    return director_ < drama.director_;
  }
  return title_ < drama.title_;
}

bool Drama::operator==(const Movie &other) const {
  const auto drama = static_cast<const Drama &>(other);
  return director_ == drama.director_ && title_ == drama.title_;
}

ostream &Drama::Print(ostream &out) const {
  out << "Title: " << title_ << '\n';
  out << "Director: " << director_ << '\n';
  out << "Release Year: " << release_year_ << '\n';
  out << "Borrowed: " << current_stock_ - stock_ << '\n';
  out << "Available in Stock: " << stock_ << '\n';
  return out;
}

string Drama::ToString() const {
  return to_string(stock_) + ", " + director_ + ", " + title_ + ", " +
         to_string(release_year_);
}

int Drama::getReleaseYear() const { return release_year_; }

void Drama::setReleaseYear(int year) { release_year_ = year; }

string Drama::getDirector() const { return director_; }

void Drama::setDirector(const string &director) { this->director_ = director; }

Movie *DramaFactory::Create(const string &line) const {
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

  return new Drama(director, title, stock, release_year);
}