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

  virtual bool compare(const Movie &movie) const = 0;
  bool operator>(const Movie &movie) const;
  bool operator==(const Movie &movie) const;

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

class Classic : public Movie{

public:
  bool operator>(const Classic &movie) const;
  bool operator==(const Classic &movie) const;

private:

  string major_actor_;
  int month_;
};

class MovieFactory {

public:

  virtual Movie* create() const = 0;

};

class ComedyFactory : public MovieFactory {
public:

  ComedyFactory();

  Movie *create() const override;
};

class DramaFactory : public MovieFactory {
public:

  DramaFactory();

  Movie *create() const override;
};

class ClassicFactory : public MovieFactory {
public:

  ClassicFactory();

  Movie *create() const override;
};

#endif
