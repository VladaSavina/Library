#include "Book.h" 
#include "Author.h" 
#include "Library.h" 



void instruction() {

	std::cout << std::endl << "If you want to add/delete the book press 1/2" << std::endl <<
		"If you want to add/delete author press 3/4" << std::endl <<
		"If you want to find the book press 5" << std::endl <<
		"To show lib press 6" << std::endl<<
		"To exit press 0" << std::endl;
}

int main() {
	Library myLib;

	bool f=false;
	while (!f) {
		instruction();
		int choise;
		std::cin >> choise;

		switch (choise) {
		case 1: {
			std::string title_;
			std::string name_;
			int date_;
			std::cout << "Enter title, author and date" << std::endl;
			std::getline(std::cin, title_);
			std::getline(std::cin, title_);
			std::getline(std::cin, name_);
			std::cin >> date_;
			myLib.addBook(Book(title_, date_), name_);
			break;
		}
		case 2: {
			if (!myLib.emptyLib()) {
				std::cout << "Library is empty!" << std::endl;
			}
			else {
				std::cout << myLib.emptyLib() << std::endl;
				std::cout << "Enter the book's title you want to delete:" << std::endl;
				std::string title_;
				std::getline(std::cin, title_);
				std::getline(std::cin, title_);
				myLib.deleteBookByTitle(title_);
			}
			break;
		}
		case 3: {
			std::cout << "Enter name of the author:" << std::endl;
			std::string name_;
			std::cin >> name_;
			myLib.addAuthor(name_);
			break;
		}
		case 4: {

			if (!myLib.emptyLib()) {
				std::cout << "Library is empty!" << std::endl;
			}

			else {
				std::cout << "Enter the name of the author you want to delete" << std::endl;
				std::string name;
				std::getline(std::cin, name);
				std::getline(std::cin, name);
				myLib.deleteAuthor(name);
			}
			break;
		}
		case 5: {
			if (!myLib.emptyLib()) {
				std::cout << "Library is empty!" << std::endl;
			}
			else {
				int choise_;
				std::cin >> choise_;
				switch (choise_) {
				case 1: {
					std::cout << "Enter a title to find:" << std::endl;
					std::string title_;
					std::getline(std::cin, title_);
					std::getline(std::cin, title_);
					std::cout << "Book(s) that you need: " << std::endl;
					myLib.searchBookByTitle(title_);
				}
				case 2: {
					std::cout << "Enter a date to find:" << std::endl;
					std::string title_;
					int date_;
					std::cin >> date_;
					std::cout << "Book(s) that you need: " << std::endl;
					myLib.searchBookByDate(date_);

				}
				case 3: {
					std::cout << "Enter an author to find:" << std::endl;
					std::string name_;
					std::getline(std::cin, name_);
					std::getline(std::cin, name_);
					std::cout << "Book(s) that you need: " << std::endl;
					myLib.searchBookByAuthor(name_);

				}
				}

			}
			break;
		}
		case 6: {
			myLib.printLibrary();
			break;
		}
		case 0:
			f = true;
		}
	}
	std::system("pause");
}