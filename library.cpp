#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure definition for book information
struct Book {
    int id;
    string title;
    string author;
    string subject;
    string status;
};

// Array definition to hold books
vector<Book> library;

// Function to add a new book
void addBook() {
    Book newBook;
    newBook.id = rand(); // Generate a random ID
    cout << endl;
    cout << "Enter title: ";
    cin >> newBook.title;
    cout << "Enter author: ";
    cin >> newBook.author;
    cout << "Enter subject: ";
    cin >> newBook.subject;
    newBook.status = "Available";
    
    library.push_back(newBook);
    cout << endl << " [#] Book added successfully with ID: " << newBook.id << endl;
}

// Function to search and display book information by ID
void searchBookById(int id) {
    for (Book book : library) {
        if (book.id == id) {
            cout << endl << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Subject: " << book.subject << endl;
            cout << "Status: " << book.status << endl;
            return;
        }
    }
    cout << endl << " [!] Book not found with ID: " << id << endl;
}

// Function to delete a book by ID
void deleteBook(int id) {
    for (auto it = library.begin(); it != library.end(); ++it) {
        if (it->id == id) {
            library.erase(it);
            cout << endl << " [#] Book deleted successfully with ID: " << id << endl;
            return;
        }
    }
    cout << endl << " [!] Book not found with ID: " << id << endl;
}

// Function to display all books
void displayAllBooks() {
    for (Book book : library) {
        cout << endl << "ID: " << book.id << " | Title: " << book.title << " | Author: " << book.author << " | Subject: " << book.subject << " | Status: " << book.status << endl;
    }
}

// Function to search and display books by subject
void searchBooksBySubject(string subject) {
    for (Book book : library) {
        if (book.subject == subject) {
            cout << endl << "ID: " << book.id << " | Title: " << book.title << " | Author: " << book.author << " | Subject: " << book.subject << " | Status: " << book.status << endl;
        }
    }
}

// Function to count books by subject
int countBooksBySubject(string subject) {
    int count = 0;
    for (Book book : library) {
        if (book.subject == subject) {
            count++;
        }
    }
    return count;
}

int main() {
    string searchSubject;
    string countSubject;
    int choice;
    do {
        cout << endl << "------------------------------------------------------" << endl;
        cout << endl << " Library Management System :" << endl;
        cout << "  1. Add a new book" << endl;
        cout << "  2. Search and display book information by ID" << endl;
        cout << "  3. Delete a book by ID" << endl;
        cout << "  4. Display all books" << endl;
        cout << "  5. Search and display books by subject" << endl;
        cout << "  6. Count books by subject" << endl;
        cout << "  0. Exit" << endl;
        cout << endl << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                int searchId;
                cout << endl << "Enter ID to search: ";
                cin >> searchId;
                searchBookById(searchId);
                break;
            case 3:
                int deleteId;
                cout << endl << "Enter ID to delete: ";
                cin >> deleteId;
                deleteBook(deleteId);
                break;
            case 4:
                displayAllBooks();
                break;
            case 5:
                cout << endl << "Enter subject to search: ";
                cin >> searchSubject;
                searchBooksBySubject(searchSubject);
                break;
            case 6:
                cout << endl << "Enter subject to count: ";
                cin >> countSubject;
                cout << endl << "Number of books with subject " << countSubject << ": " << countBooksBySubject(countSubject) << endl;
                break;
            case 0:
                cout << endl << "  [*] Exiting program. Goodbye!" << endl << endl;
                break;
            default:
                cout << endl << "  [!] Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    return 0;
}