#ifndef MOVIE_H_
#define MOVIE_H_
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Movie;

class MovieFactory {
public:
    virtual Movie* Create(const string& line) const = 0;
    virtual ~MovieFactory() = default;
};

class Movie {
    friend ostream& operator<<(ostream& out, const Movie& movie);
    virtual ostream& Print(ostream& out) const = 0;

public:
    virtual ~Movie() = default;

    static void RegisterType(char type, MovieFactory* factory);
    static Movie* Create(char type, const string& line);

    virtual bool operator<(const Movie& other) const = 0;
    virtual bool operator==(const Movie& other) const = 0;
    virtual bool Borrow();
    virtual bool ReturnItem();

    string getTitle() const;
    void setTitle(const string& title);

    int getStock() const;
    void setStock(int stock);

    char getType() const;
    virtual string ToString() const = 0;

protected:
    string title_;
    string director_;
    int stock_;
    int current_stock_;
    char genre_;

private:
    static map<char, MovieFactory*>& getFactories();
};

inline ostream& operator<<(ostream& out, const Movie& movie) {
    return movie.Print(out);
}

class Comedy : public Movie {
public:
    Comedy(const string& title, int stock, const string& director, int releaseYear);

    int getReleaseYear() const;
    void setReleaseYear(int year);

    string getDirector() const;
    void setDirector(const string& director);

    bool operator<(const Movie& other) const override;
    bool operator==(const Movie& other) const override;
    ostream& Print(ostream& out) const override;
    string ToString() const override;

private:
    int release_year_;
    string director_;
};

class Drama : public Movie {
public:
    Drama(const string& director, const string& title, int stock, int releaseYear);

    int getReleaseYear() const;
    void setReleaseYear(int year);

    string getDirector() const;
    void setDirector(const string& director);

    bool operator<(const Movie& other) const override;
    bool operator==(const Movie& other) const override;
    ostream& Print(ostream& out) const override;
    string ToString() const override;

private:
    int release_year_;
    string director_;
};

class Classic : public Movie {
public:
    Classic(const string& release_date, const string& major_actor, const string& title, int stock, const string& director);

    string getReleaseDate() const;
    void setReleaseDate(const string& date);

    string getMajorActor() const;
    void setMajorActor(const string& actor);

    bool operator<(const Movie& other) const override;
    bool operator==(const Movie& other) const override;
    ostream& Print(ostream& out) const override;
    string ToString() const override;

private:
    string release_date_;
    string major_actor_;
};

class ComedyFactory : public MovieFactory {
public:
    Movie* Create(const string& line) const override;
};

class DramaFactory : public MovieFactory {
public:
    Movie* Create(const string& line) const override;
};

class ClassicFactory : public MovieFactory {
public:
    Movie* Create(const string& line) const override;
};

#endif // MOVIE_H_