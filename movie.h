#ifndef MOVIE_H_
#define MOVIE_H_
#include <ostream>
#include <vector>

using namespace std;


class Movie {
    friend ostream &operator<<(ostream &out, const Movie &movie);

public:
    virtual ~Movie() = default;

protected:

    int stock_;
    string title_;
    string director_;
    int release_year_;
    char genre_;
    char media_;

private:

};

class Comedy : public Movie {
public:

  Comedy();

  bool operator>(const Comedy &movie) const;
  bool operator==(const Comedy &movie) const;
};

class Drama : public Movie {
public:

  Drama();

  bool operator>(const Drama &movie) const;
  bool operator==(const Drama &movie) const;

};

class MovieFactory {

public:

    virtual Movie* create() const = 0;

};
#endif