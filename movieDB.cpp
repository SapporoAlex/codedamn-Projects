#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Movie {
    std::string title;
    int releaseYear;
    std::string director;
    std::string genre;
};

// Function to save movies to a file
void saveToFile(const std::vector<Movie>& movies, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& movie : movies) {
        file << movie.title << "|" << movie.releaseYear << "|" 
             << movie.director << "|" << movie.genre << "\n";
    }
    file.close();
}

// Function to load movies from a file
std::vector<Movie> loadFromFile(const std::string& filename) {
    std::vector<Movie> movies;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        Movie movie;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);

        movie.title = line.substr(0, pos1);
        movie.releaseYear = std::stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        movie.director = line.substr(pos2 + 1, pos3 - pos2 - 1);
        movie.genre = line.substr(pos3 + 1);

        movies.push_back(movie);
    }

    file.close();
    return movies;
}

// Function to add a new movie
void addMovie(std::vector<Movie>& movies) {
    Movie movie;
    std::cout << "Enter movie title: ";
    std::cin.ignore();
    std::getline(std::cin, movie.title);
    std::cout << "Enter release year: ";
    std::cin >> movie.releaseYear;
    std::cin.ignore();
    std::cout << "Enter director: ";
    std::getline(std::cin, movie.director);
    std::cout << "Enter genre: ";
    std::getline(std::cin, movie.genre);
    movies.push_back(movie);
    std::cout << "Movie added successfully!\n";
}

// Function to display all movies
void displayMovies(const std::vector<Movie>& movies) {
    if (movies.empty()) {
        std::cout << "No movies in the database.\n";
        return;
    }
    for (const auto& movie : movies) {
        std::cout << "Title: " << movie.title << "\n"
                  << "Release Year: " << movie.releaseYear << "\n"
                  << "Director: " << movie.director << "\n"
                  << "Genre: " << movie.genre << "\n"
                  << "---------------------------\n";
    }
}

// Function to search for a movie
void searchMovie(const std::vector<Movie>& movies) {
    std::string query;
    std::cout << "Enter a keyword to search (title/director/genre): ";
    std::cin.ignore();
    std::getline(std::cin, query);
    bool found = false;

    for (const auto& movie : movies) {
        if (movie.title.find(query) != std::string::npos ||
            movie.director.find(query) != std::string::npos ||
            movie.genre.find(query) != std::string::npos) {
            std::cout << "Title: " << movie.title << "\n"
                      << "Release Year: " << movie.releaseYear << "\n"
                      << "Director: " << movie.director << "\n"
                      << "Genre: " << movie.genre << "\n"
                      << "---------------------------\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No movies found with the given keyword.\n";
    }
}

// Function to delete a movie
void deleteMovie(std::vector<Movie>& movies) {
    std::string title;
    std::cout << "Enter the title of the movie to delete: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    auto it = std::remove_if(movies.begin(), movies.end(),
                             [&title](const Movie& movie) {
                                 return movie.title == title;
                             });

    if (it != movies.end()) {
        movies.erase(it, movies.end());
        std::cout << "Movie deleted successfully!\n";
    } else {
        std::cout << "Movie not found.\n";
    }
}

// Main menu
int main() {
    const std::string filename = "movies.txt";
    std::vector<Movie> movies = loadFromFile(filename);

    while (true) {
        std::cout << "\nMovie Database\n";
        std::cout << "1. Add a movie\n";
        std::cout << "2. Display all movies\n";
        std::cout << "3. Search for a movie\n";
        std::cout << "4. Delete a movie\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addMovie(movies);
                break;
            case 2:
                displayMovies(movies);
                break;
            case 3:
                searchMovie(movies);
                break;
            case 4:
                deleteMovie(movies);
                break;
            case 5:
                saveToFile(movies, filename);
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
