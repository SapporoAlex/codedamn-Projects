#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
    string description;

public:
    // Setters
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setISBN(const string& i) { isbn = i; }
    void setAvailable(bool avail) { available = avail; }
    void setDescription(const string& d) { description = d; }

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    string getAvailable() const { return available ? "Available" : "Checked out"; }
    string getDescription() const { return description; }

    // Borrow and return functions
    void borrowBook() {
        if (available) {
            available = false;
            cout << "Book checked out successfully.\n";
        } else {
            cout << "Error: Book is already checked out.\n";
        }
    }

    void returnBook() {
        if (!available) {
            available = true;
            cout << "Book returned successfully.\n";
        } else {
            cout << "Error: Book is already available.\n";
        }
    }

    ~Book() {
        cout << "Book '" << title << "' by " << author << " has been destroyed.\n";
    }
    
};

// Maximum capacity of the library
const int MAX_CAPACITY = 100;

int main() {
    vector<Book> library;  // Dynamic array for library

    cout << "Welcome to the library management system!\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add book\n";
        cout << "2. Remove book\n";
        cout << "3. Search for book\n";
        cout << "4. Exit\n";
        cout << "5. Borrow book\n";
        cout << "6. Return book\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();  // Ignore newline left in buffer

        if (choice == 1) {
            if (library.size() >= MAX_CAPACITY) {
                cout << "Library is at maximum capacity.\n";
                continue;
            }

            string title, author, isbn, description;

            cout << "Enter book title: ";
            getline(cin, title);

            cout << "Enter book author: ";
            getline(cin, author);

            cout << "Enter book ISBN: ";
            getline(cin, isbn);

            cout << "Enter book description: ";
            getline(cin, description);

            // Adding book directly to the vector
            library.push_back(Book());
            library.back().setTitle(title);
            library.back().setAuthor(author);
            library.back().setISBN(isbn);
            library.back().setDescription(description);
            library.back().setAvailable(true);

            cout << "Book added to library.\n";
        } else if (choice == 2) {
            string isbn;
            cout << "Enter book ISBN to remove: ";
            cin >> isbn;

            bool found = false;
            for (auto it = library.begin(); it != library.end(); ++it) {
                if (it->getISBN() == isbn) {
                    library.erase(it);
                    cout << "Book removed from library.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Error: Book not found.\n";
            }
        } else if (choice == 3) {
            cout << "Choose a search method:\n";
            cout << "1. ISBN\n";
            cout << "2. Author name\n";
            cout << "3. Book title\n";

            int searchMethod;
            cin >> searchMethod;
            cin.ignore();

            if (searchMethod == 1) {
                string isbn;
                cout << "Enter book ISBN: ";
                cin >> isbn;

                bool found = false;
                for (const auto& book : library) {
                    if (book.getISBN() == isbn) {
                        cout << "\nBook Information:\n";
                        cout << "Title: " << book.getTitle() << "\n";
                        cout << "Author: " << book.getAuthor() << "\n";
                        cout << "ISBN: " << book.getISBN() << "\n";
                        cout << "Description: " << book.getDescription() << "\n";
                        cout << "Availability: " << book.getAvailable() << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Error: Book not found.\n";
                }
            } else if (searchMethod == 2) {
                string author;
                cout << "Enter author name: ";
                cin >> author;

                bool found = false;
                for (const auto& book : library) {
                    if (book.getAuthor() == author) {
                        cout << "\nBook Information:\n";
                        cout << "Title: " << book.getTitle() << "\n";
                        cout << "Author: " << book.getAuthor() << "\n";
                        cout << "ISBN: " << book.getISBN() << "\n";
                        cout << "Description: " << book.getDescription() << "\n";
                        cout << "Availability: " << book.getAvailable() << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Error: Book not found.\n";
                }
            } else if (searchMethod == 3) {
                string title;
                cout << "Enter book title: ";
                cin >> title;

                bool found = false;
                for (const auto& book : library) {
                    if (book.getTitle() == title) {
                        cout << "\nBook Information:\n";
                        cout << "Title: " << book.getTitle() << "\n";
                        cout << "Author: " << book.getAuthor() << "\n";
                        cout << "ISBN: " << book.getISBN() << "\n";
                        cout << "Description: " << book.getDescription() << "\n";
                        cout << "Availability: " << book.getAvailable() << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Error: Book not found.\n";
                }
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        } else if (choice == 4) {
            cout << "Thank you for using the library management system!\n";
            break;
        } else if (choice == 5) {
            string isbn;
            cout << "Enter book ISBN to borrow: ";
            cin >> isbn;

            bool found = false;
            for (auto& book : library) {
              if (book.getISBN() == isbn) {
                cout << book.getTitle() << " borrowed.\n";
                found = true;
                book.borrowBook();
                break;
                } else if (book.getISBN() == isbn) {
                cout << "Sorry, " << book.getTitle() << " is currently unavailable.\n";
                found = true;
                break;
                }
                }
                if (!found) {
                    cout << "Error: book not found.\n";
                }
                } else if (choice == 6) {
            string isbn;
            cout << "Enter book ISBN to return: ";
            cin >> isbn;

            bool found = false;
            for (auto& book : library) {
              if (book.getISBN() == isbn) {
                cout << book.getTitle() << " returned.\n";
                book.returnBook();
                found = true;
                break;
                } else if (book.getISBN() == isbn) {
                cout << "Sorry, " << book.getTitle() << " is already returned.\n";
                found = true;
                break;
                }
                
            }
            if (!found) {
            cout << "Error: book not found.\n";
            }
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
