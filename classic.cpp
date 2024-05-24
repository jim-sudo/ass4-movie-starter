#include "movie.h"
// Classic class methods

Classic::Classic(const string& release_date, const string& major_actor, const string& title, int stock, const string& director)
    : release_date_(release_date), major_actor_(major_actor) {
    this->title_ = title;
    this->stock_ = stock;
    this->current_stock_ = stock;
    this->director_ = director;
    this->genre_ = 'C';
}

bool Classic::operator<(const Movie& other) const {
    const Classic& classic = static_cast<const Classic&>(other);
    if (release_date_ != classic.release_date_) {
        istringstream ssa(release_date_);
        istringstream ssb(classic.release_date_);
        int month_a, year_a, month_b, year_b;
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

bool Classic::operator==(const Movie& other) const {
    const Classic& classic = static_cast<const Classic&>(other);
    return release_date_ == classic.release_date_ && major_actor_ == classic.major_actor_;
}

ostream& Classic::Print(ostream& out) const {
    out << "Classic: " << release_date_ << ", " << major_actor_ << ", " << title_ << ", " << director_ << ", " << current_stock_ << "/" << stock_;
    return out;
}

string Classic::ToString() const {
    return std::to_string(stock_) + ", " + director_ + ", " + title_ + ", " + major_actor_ + " " + release_date_;
}

string Classic::getReleaseDate() const {
    return release_date_;
}

void Classic::setReleaseDate(const string& date) {
    release_date_ = date;
}

string Classic::getMajorActor() const {
    return major_actor_;
}

void Classic::setMajorActor(const string& actor) {
    major_actor_ = actor;
}

Movie* ClassicFactory::Create(const string& line) const {
    istringstream ss(line);
    int stock;
    string director, title, majorActorFirst, majorActorLast;
    int releaseMonth, releaseYear;

    ss >> stock;
    ss.ignore(2);
    getline(ss, director, ',');
    ss.ignore(1); 
    getline(ss, title, ',');
    ss.ignore(1); 
    ss >> majorActorFirst >> majorActorLast >> releaseMonth >> releaseYear;

    string majorActor = majorActorFirst + " " + majorActorLast;
    string releaseDate = to_string(releaseMonth) + " " + to_string(releaseYear);

    return new Classic(releaseDate, majorActor, title, stock, director);
}