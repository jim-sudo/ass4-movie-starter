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
            const Comedy* ca = static_cast<const Comedy*>(a);
            const Comedy* cb = static_cast<const Comedy*>(b);
            if (ca->getTitle() != cb->getTitle()) {
                return ca->getTitle() < cb->getTitle();
            }
            return ca->getReleaseYear() < cb->getReleaseYear();
        }
        return a->getType() < b->getType();
    });

    // Print Comedy movies
    std::cout << "Comedy Movies:" << std::endl;
    for (const auto& movie : sorted_movies) {
        if (movie->getType() == 'F') {
            cout << *movie << std::endl;
        }
    }
    cout << endl;

    // Sort Drama movies by director, then by title
    sort(sorted_movies.begin(), sorted_movies.end(), [](Movie* a, Movie* b) {
        if (a->getType() == 'D' && b->getType() == 'D') {
            const Drama* da = static_cast<const Drama*>(a);
            const Drama* db = static_cast<const Drama*>(b);
            if (da->getDirector() != db->getDirector()) {
                return da->getDirector() < db->getDirector();
            }
            return da->getTitle() < db->getTitle();
        }
        return a->getType() < b->getType();
    });

    // Print Drama movies
    cout << "Drama Movies:" << endl;
    for (const auto& movie : sorted_movies) {
        if (movie->getType() == 'D') {
            std::cout << *movie << endl;
        }
    }
    cout << endl;

    // Sort Classic movies by release date (month and year), then by major actor
    sort(sorted_movies.begin(), sorted_movies.end(), [](Movie* a, Movie* b) {
    if (a->getType() == 'C' && b->getType() == 'C') {
        const Classic* ca = static_cast<const Classic*>(a);
        const Classic* cb = static_cast<const Classic*>(b);
        
        // Split the releaseDate into month and year for comparison
        istringstream ssa(ca->getReleaseDate());
        istringstream ssb(cb->getReleaseDate());
        int month_a, year_a, month_b, year_b;
        ssa >> month_a >> year_a;
        ssb >> month_a >> year_b;
        
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
    std::cout << "Classic Movies:" << std::endl;
    for (const auto& movie : sorted_movies) {
        if (movie->getType() == 'C') {
            std::cout << *movie << std::endl;
        }
    }
}