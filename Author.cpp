#pragma once 

#include "Author.h"

Author::Author(const std::string& name_): name(name_) {}

std::string Author::getNameOfAuthor() const {
	return name;
}

void Author::addBook(const std::string& title_, const int& date_) {
	bool exB = false;
	if (!books.empty()) {
		for (Book book : books) {
			if (book.getTitle() == title_ && book.getDate() == date_) {
				exB = true;
				break;
			}
		}
		if (exB == false) {
			books.push_back(Book(title_, date_));
			exB = true;
		}	
	}
	else {
		books.push_back(Book(title_, date_));
		exB = true;
	}	
}

void Author::deleteBook(const std::string& title_) {
	
	if (books.empty()) {
		std::cout << "Library is empty!" << std::endl;
	}

	else {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].getTitle() == title_) {
				books.erase(books.begin() + i);
			}
		}
	}
}

int Author::numOfBooks() const {
	return books.size();
}

void Author::getBookByTitle(const std::string& title_, const std::string& name_)  {

	for (int i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title_) {
			printBook(name_);
		}
	}
}

void Author::getBookByDate (const int& date_, const std::string& name_) {

	for (int i = 0; i < books.size(); i++) {
		if (books[i].getDate() == date_) {
			printBook(name_);
		}
	}
}

void Author::printBook(const std::string& name_) {
	for (int i = 0; i < books.size(); i++) {
		std::cout << "Title: " << books[i].getTitle() << std::endl;
		std::cout << "Author: " << name_ << std::endl;
		std::cout << "Date: " << books[i].getDate() << std::endl << std::endl;
	}
}