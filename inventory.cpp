#include "inventory.h"

void Inventory::AddMovieHelper(Movie* movie, int count) {
    for (auto& m : movies_) {
        if (*m == *movie) {
            m->setStock(m->getStock() + count);
            return;
        }
    }
    movie->setStock(count);
    movies_.push_back(movie);
}

void Inventory::AddMovie(const Movie& movie, int count) {
    Movie* new_movie = Movie::Create(movie.getType(), movie.ToString());
    AddMovieHelper(new_movie, count);
}

void Inventory::PrintInventory() const {
    vector<Movie*> sorted_movies = movies_;

    // Sort Comedy movies by title, then by release year
    sort(sorted_movies.begin(), sorted_movies.end(), [](Movie* a, Movie* b) {
        if (a->getType() == 'F' && b->getType() == 'F') {
            const auto *const ca = static_cast<const Comedy*>(a);
            const auto *const cb = static_cast<const Comedy*>(b);
            if (ca->getTitle() != cb->getTitle()) {
                return ca->getTitle() < cb->getTitle();
            }
            return ca->getReleaseYear() < cb->getReleaseYear();
        }
        return a->getType() < b->getType();
    });
    cout << endl;
    cout << "=================Prinitng inventory=================="<< endl;
    cout << endl;
    // Print Comedy movies
    std::cout << "===== Comedy Movies =====" << std::endl;
    cout << endl;
    for (const auto& movie : sorted_movies) {
        if (movie->getType() == 'F') {
            cout << *movie << std::endl;
        }
    }
    cout << endl;

    // Sort Drama movies by director, then by title
    sort(sorted_movies.begin(), sorted_movies.end(), [](Movie* a, Movie* b) {
        if (a->getType() == 'D' && b->getType() == 'D') {
            const auto *const da = static_cast<const Drama*>(a);
            const auto *const db = static_cast<const Drama*>(b);
            if (da->getDirector() != db->getDirector()) {
                return da->getDirector() < db->getDirector();
            }
            return da->getTitle() < db->getTitle();
        }
        return a->getType() < b->getType();
    });

    // Print Drama movies
    cout << "===== Drama Movies =====" << endl;
    cout << endl;
    for (const auto& movie : sorted_movies) {
        if (movie->getType() == 'D') {
            std::cout << *movie << endl;
        }
    }
    cout << endl;

    // Sort Classic movies by release date (month and year), then by major actor
    sort(sorted_movies.begin(), sorted_movies.end(), [](Movie* a, Movie* b) {
    if (a->getType() == 'C' && b->getType() == 'C') {
        const auto *const ca = static_cast<const Classic*>(a);
        const auto *const cb = static_cast<const Classic*>(b);
        istringstream ssa(ca->getReleaseDate());
        istringstream ssb(cb->getReleaseDate());
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
        return ca->getMajorActor() < cb->getMajorActor();
    }
    return a->getType() < b->getType();
});

    // Print Classic movies
    std::cout << "===== Classic Movies =====" << std::endl;
    cout << endl;
    for (const auto& movie : sorted_movies) {
        if (movie->getType() == 'C') {
            std::cout << *movie << std::endl;
        }
    }
}

bool Inventory::BorrowMovie(const std::string& movie_info) {
  std::istringstream iss(movie_info);
  char movie_type;
  iss >> movie_type;

  switch (movie_type) {
  case 'F': {
    std::string title;
    int year;
    iss.ignore(1, ' '); // Skip the space after type
    std::getline(iss, title, ',');
    iss >> year;

    for (auto& movie : movies_) {
      if (movie->getType() == 'F') {
        auto* comedy = static_cast<Comedy*>(movie);
        if (comedy->getTitle() == title && comedy->getReleaseYear() == year) {
          if (comedy->getStock() > 0) {
            comedy->setStock(comedy->getStock() - 1);
            return true; // Successfully borrowed
          }
            return false; // No stock available
          
        }
      }
    }
    break;
  }
  case 'D': {
    std::string director;
    std::string title;
    iss.ignore(1, ' '); // Skip the space after type
    std::getline(iss, director, ',');
    std::getline(iss, title);

    for (auto& movie : movies_) {
      if (movie->getType() == 'D') {
        auto* drama = static_cast<Drama*>(movie);
        if (drama->getDirector() == director && drama->getTitle() == title) {
          if (drama->getStock() > 0) {
            drama->setStock(drama->getStock() - 1);
            return true; // Successfully borrowed
          }
            return false; // No stock available
          
        }
      }
    }
    break;
  }
  case 'C': {
    int month;
    int year;
    std::string actor_first_name;
    std::string actor_last_name;
    iss >> month >> year >> actor_first_name >> actor_last_name;
    std::string actor = actor_first_name + " " + actor_last_name;

    for (auto& movie : movies_) {
      if (movie->getType() == 'C') {
        auto*  classic = static_cast<Classic*>(movie);
        if (classic->getReleaseDate() == std::to_string(month) + " " + std::to_string(year) && classic->getMajorActor() == actor) {
          if (classic->getStock() > 0) {
            classic->setStock(classic->getStock() - 1);
            return true; // Successfully borrowed
          }
            return false; // No stock available
          
        }
      }
    }
    break;
  }
  default:
    std::cerr << "Invalid movie type: " << movie_type << std::endl;
    return false;
  }

  std::cerr << "Movie not found: " << movie_info << std::endl;
  return false;
}

bool Inventory::ReturnMovie(const std::string& movie_info) {
  std::istringstream iss(movie_info);
  char movie_type;
  iss >> movie_type;

  switch (movie_type) {
  case 'F': {
    std::string title;
    int year;
    iss.ignore(1, ' '); // Skip the space after type
    std::getline(iss, title, ',');
    iss >> year;

    for (auto& movie : movies_) {
      if (movie->getType() == 'F') {
        auto*  comedy = static_cast<Comedy*>(movie);
        if (comedy->getTitle() == title && comedy->getReleaseYear() == year) {
          comedy->setStock(comedy->getStock() + 1);
          return true; // Successfully returned
        }
      }
    }
    break;
  }
  case 'D': {
    std::string director;
    std::string title;
    iss.ignore(1, ' '); // Skip the space after type
    std::getline(iss, director, ',');
    std::getline(iss, title);

    for (auto& movie : movies_) {
      if (movie->getType() == 'D') {
        auto* drama = static_cast<Drama*>(movie);
        if (drama->getDirector() == director && drama->getTitle() == title) {
          drama->setStock(drama->getStock() + 1);
          return true; // Successfully returned
        }
      }
    }
    break;
  }
  case 'C': {
    int month;
    int year;
    std::string actor_first_name;
    std::string actor_last_name;
    iss >> month >> year >> actor_first_name >> actor_last_name;
    std::string actor = actor_first_name + " " + actor_last_name;

    for (auto& movie : movies_) {
      if (movie->getType() == 'C') {
        auto* classic = static_cast<Classic*>(movie);
        if (classic->getReleaseDate() == std::to_string(month) + " " + std::to_string(year) && classic->getMajorActor() == actor) {
          classic->setStock(classic->getStock() + 1);
          return true; // Successfully returned
        }
      }
    }
    break;
  }
  default:
    std::cerr << "Invalid movie type: " << movie_type << std::endl;
    return false;
  }

  std::cerr << "Movie not found: " << movie_info << std::endl;
  return false;
}
