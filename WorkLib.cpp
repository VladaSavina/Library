#include "WorkLib.h"

WorkLib::WorkLib()
{
}

void WorkLib::instruction() {

	std::cout << std::endl <<
		"If you want to add/delete the book press 1/2" << std::endl <<
		"If you want to add/delete author press 3/4" << std::endl <<
		"If you want to find the book press 5" << std::endl <<
		"To show lib press 6" << std::endl <<
		"To exit press 0" << std::endl;
}

void WorkLib::printBook (std::vector<Book> books, std::string name_) {
	for (int i = 0; i < books.size(); i++) {
		std::cout << "Title: " << books[i].getTitle() << std::endl;
	    std::cout << "Author: " << name_<< std::endl;
		std::cout << "Date: " << books[i].getDate() << std::endl << std::endl;
	}
}

void WorkLib::printLibrary( Library lib) {
	std::vector<Author> tmpAuthors = lib.getAllAuthors(lib);
	if (tmpAuthors.empty()) {
		std::cout << "Library is empty!" << std::endl;
	}
	else {
		std::cout << tmpAuthors.size() << std::endl;
		for (int a = 0; a < tmpAuthors.size(); a++) {
				printBook(tmpAuthors[a].getAllBooks(tmpAuthors[a]), tmpAuthors[a].getNameOfAuthor());
		}
	}
}

void WorkLib::menu(Library myLib) {
	bool f = false;
	while (!f) {
		instruction();
		int choice;
		std::cin >> choice;
	
		switch (choice) {
	case 1: {
		myLib=addBook(myLib);
		break;
	}
	case 2: {
		myLib=deleteBook(myLib);
		break;
	}
	case 3: {
		myLib=addAuthor(myLib);
		break;
	}
	case 4: {
		myLib = deleteAuthor(myLib);
		break;
	}
	case 5: {
		if (myLib.getAllAuthors(myLib).size() == 0) {
			std::cout << "Library is empty!" << std::endl;
		}
		else {

			int choice_;
			std::cin >> choice_;
			switch (choice_) {
			case 1: {
				printBookByTittle(myLib);
				break;
			}
			case 2: {
				myLib = printBookByDate(myLib);
				break;

			}
			case 3: {
				myLib = printBookByAuthor(myLib);
				break;
			}
			}
		}
		break;
	}
	case 6: {
		printLibrary(myLib);
		break;
	}
	case 0:
		f = true;
	}
}
}


Library WorkLib::addBook(Library myLib) {
	std::string title_;
	std::string name_;
	int date_;
	std::cout << "Enter title, author and date" << std::endl;
	std::getline(std::cin, title_);
	std::getline(std::cin, title_);
	std::getline(std::cin, name_);
	std::cin >> date_;
	myLib.addBook(Book(title_, date_), name_);

	return myLib;
}

Library WorkLib::deleteBook(Library myLib) {
	if (myLib.getAllAuthors(myLib).size() == 0) {
		std::cout << "Library is empty!" << std::endl;
	}
	else {
		std::cout << "Enter the book's title you want to delete:" << std::endl;
		std::string title_;
		std::getline(std::cin, title_);
		std::getline(std::cin, title_);
		myLib.deleteBookByTitle(title_);
	}
	return myLib;
}

Library WorkLib::addAuthor(Library myLib) {
	std::cout << "Enter name of the author:" << std::endl;
	std::string name_;
	std::cin >> name_;
	bool exA = false;
	if (!myLib.getAllAuthors(myLib).empty()) {
		try {
			for (Author author : myLib.getAllAuthors(myLib)) {
				if (author.getNameOfAuthor() == name_) {
					throw 123;
				}
				myLib.getAllAuthors(myLib).push_back(Author(name_));
			}
		}
		catch (int i) {
			std::cout << "Error #" << i << " :autor " << name_ << " already exists!";
		}

	}
	else {
		myLib.getAllAuthors(myLib).push_back(Author(name_));

	}
	return myLib;
}

Library WorkLib::deleteAuthor(Library myLib) {

	if (myLib.getAllAuthors(myLib).size() == 0) {
		std::cout << "Library is empty!" << std::endl;
	}

	else {
		std::cout << "Enter the name of the author you want to delete" << std::endl;
		std::string name;
		std::getline(std::cin, name);
		std::getline(std::cin, name);
		myLib.deleteAuthor(name);
	}
	return myLib;
}

Library WorkLib::printBookByTittle (Library myLib) {
	std::cout << "Enter a title to find:" << std::endl;
	std::string title_;
	std::getline(std::cin, title_);
	std::getline(std::cin, title_);
	std::cout << "Book(s) that you need: " << std::endl;
	for (int i = 0; i < myLib.getAllAuthors(myLib).size();i++) {
		std::vector<Book> foundBooks = myLib.searchBookByTitle(title_, myLib.getAllAuthors(myLib)[i]);
		printBook(foundBooks, myLib.getAllAuthors(myLib)[i].getNameOfAuthor());
	}
	return myLib;
}
Library WorkLib::printBookByAuthor(Library myLib) {
	std::cout << "Enter an author to find:" << std::endl;
	std::string name_;
	std::getline(std::cin, name_);
	std::getline(std::cin, name_);
	std::cout << "Book(s) that you need: " << std::endl;
	printBook(myLib.searchBookByAuthor(name_), name_);
	return myLib;
}

Library WorkLib::printBookByDate(Library myLib) {
	std::cout << "Enter a date to find:" << std::endl;
	std::string title_;
	int date_;
	std::cin >> date_;
	std::cout << "Book(s) that you need: " << std::endl;
	for (int i = 0; i < myLib.getAllAuthors(myLib).size();i++) {
		std::vector<Book> foundBooks = myLib.searchBookByDate(date_, myLib.getAllAuthors(myLib)[i]);
		printBook(foundBooks, myLib.getAllAuthors(myLib)[i].getNameOfAuthor());
	}
	return myLib;
}
