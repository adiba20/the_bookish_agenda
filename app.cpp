#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReadingList {
private:
    vector<string> wishlist;
    vector<bool> isRead;

public:
    void updatewishlist(const string& bookname) {
        
        for (const string& book : wishlist) {
            if (book == bookname) {
                cout << "The book is already in the wishlist.\n";
                return;
            }
        }

        wishlist.push_back(bookname);
        isRead.push_back(false);
        cout << "Yay! New Book added to the wishlist.\n";
    }

    void markRead(int index) {
        if (index >= 0 && index < wishlist.size()) {
            isRead[index] = true;
        } else {
            cout << "Invalid index. Please try again.\n";
        }
    }

    void showUnreadBooks() {
        bool unreadFound = false;
        for (size_t i = 0; i < wishlist.size(); ++i) {
            if (!isRead[i]) {
                cout << i << ". " << wishlist[i] << endl;
                unreadFound = true;
            }
        }
        if (!unreadFound) {
            cout << "No unread books in the wishlist.\n";
        }
    }

    void showWishlist() {
        if (wishlist.empty()) {
            cout << "List is empty.\n";
            return;
        }

        cout << "Books in the wishlist:\n";
        for (size_t i = 0; i < wishlist.size(); ++i) {
            cout << i << ". " << wishlist[i] << " (" << (isRead[i] ? "Read" : "Unread") << ")" << endl;
        }
    }

    void removeFromWishlist(int index) {
        if (index >= 0 && index < wishlist.size()) {
            wishlist.erase(wishlist.begin() + index);
            isRead.erase(isRead.begin() + index);
            cout << "Book removed from the wishlist.\n";
        } else {
            cout << "Invalid index. Please try again.\n";
        }
    }
};

int main() {
    ReadingList tracker;
    int choice;

    do {
        cout << "----------------Welcome To The Bookish Agenda------------------------\n "
             << "----------------------------------------------------------------------\n"
             << "1. Add a new book to the wishlist\n"
             << "2. Mark as read\n"
             << "3. Which books are still unread?\n"
             << "4. Display wishlist\n"
             << "5. Remove from wishlist\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string bookname;
                cout << "Enter the name of the book to add to the wishlist: ";
                cin.ignore();
                getline(cin, bookname);
                tracker.updatewishlist(bookname);
                break;
            }
            case 2: {
                int index;
                cout << "Enter the index of the book to mark as read: ";
                cin >> index;
                tracker.markRead(index);
                break;
            }
            case 3:
                cout << "Unread books in the wishlist:\n";
                tracker.showUnreadBooks();
                break;
            case 4:
                tracker.showWishlist();
                break;
            case 5: {
                int index;
                cout << "Enter the index of the book to remove from the wishlist: ";
                cin >> index;
                tracker.removeFromWishlist(index);
                break;
            }
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

