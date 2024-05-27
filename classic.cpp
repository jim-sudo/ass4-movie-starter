#include "movie.h"
// Classic class methods

Classic::Classic(const string &release_date, const string &major_actor,
                 const string &title, int stock, const string &director)
    : release_date_(release_date), major_actor_(major_actor) {
  this->title_ = title;
  this->stock_ = stock;
  this->current_stock_ = stock;
  this->director_ = director;
  this->genre_ = 'C';
}

bool Classic::operator<(const Movie &other) const {
  const Classic &classic = static_cast<const Classic &>(other);
  if (release_date_ != classic.release_date_) {
    istringstream ssa(release_date_);
    istringstream ssb(classic.release_date_);
    int month_a;
    int year_a;
    int month_b;
    int year_b;
    ssa >> month_a >> year_a;
    ssb >> month_b >> year_b;
    if (year_a != year_b) {
      return year_a < year_b;
    }
    if (month_a != month_b) {
      return month_a < month_b;
    }
  }
  return major_actor_ < classic.major_actor_;
}

bool Classic::operator==(const Movie &other) const {
  const Classic &classic = static_cast<const Classic &>(other);
  return release_date_ == classic.release_date_ &&
         major_actor_ == classic.major_actor_;
}

ostream &Classic::Print(ostream &out) const {
  out << "Title: " << title_ << '\n';
  out << "Director: " << director_ << '\n';
  out << "Major Actor: " << major_actor_ << '\n';
  out << "Release Date: " << release_date_ << '\n';
  out << "Borrowed: " << current_stock_ - stock_ << '\n';
  out << "Available in Stock: " << stock_ << '\n';
  return out;
}

string Classic::ToString() const {
  return std::to_string(stock_) + ", " + director_ + ", " + title_ + ", " +
         major_actor_ + " " + release_date_;
}

string Classic::getReleaseDate() const { return release_date_; }

void Classic::setReleaseDate(const string &date) { release_date_ = date; }

string Classic::getMajorActor() const { return major_actor_; }

void Classic::setMajorActor(const string &actor) { major_actor_ = actor; }

Movie *ClassicFactory::Create(const string &line) const {
  istringstream ss(line);
  int stock;
  string director;
  string title;
  string major_actor_first;
  string major_actor_last;
  int release_month;
  int release_year;
  ss >> stock;
  ss.ignore(2);
  getline(ss, director, ',');
  ss.ignore(1);
  getline(ss, title, ',');
  ss.ignore(1);
  ss >> major_actor_first >> major_actor_last >> release_month >> release_year;
  string major_actor = major_actor_first + " " + major_actor_last;
  string release_date =
      to_string(release_month) + " " + to_string(release_year);
  return new Classic(release_date, major_actor, title, stock, director);
}
