#pragma once

#include "Library.h" 

Library::Library()
{
}

void Library::deleteAuthor(const std::string& name) {

	for (int i = 0; i < authors.size(); i++) {
		if (authors[i].getNameOfAuthor() == name) {
			authors.erase(authors.begin() + i);
		}
	}
}

void Library::addBook(const Book& book, const std::string& name_) {
	bool exA = false;

	if (!authors.empty()) {
		for (int i = 0; i < authors.size(); i++) {
			if (authors[i].getNameOfAuthor() == name_) {
				authors[i].addBook(book.getTitle(), book.getDate());
				exA = true;
			}
		}
		if (exA == false) {
			authors.push_back(name_);
			authors[authors.size() - 1].addBook(book.getTitle(), book.getDate());
		}

	}
	else {
		authors.push_back(name_);
		authors[authors.size()-1].addBook(book.getTitle(), book.getDate());
	}
}
	
void Library::deleteBookByTitle(const std::string& title_) {
	
	for (int a = 0; a < authors.size(); a++) {
		authors[a].deleteBook(title_);
		if (authors[a].numOfBooks() == 0)
			authors.erase(authors.begin() + a);
	}
}	


void Library::addAuthor(const std::string& name_) {

	bool exA = false;
	if (!authors.empty()) {
		for (Author author : authors) {
			if (author.getNameOfAuthor() == name_) {
				exA = true;
				break;
			}
		}
		if (exA == false) {
			authors.push_back(Author(name_));
			exA = true;
		}
	}
	else {
		authors.push_back(Author(name_));
		exA = true;
	}	
}

void Library::searchBookByTitle(const std::string& title_) {

	for (int a = 0; a < authors.size(); a++) {
		authors[a].getBookByTitle(title_, authors[a].getNameOfAuthor());
			/*std::cout << "Title: " << authors[a].getBookByTitle(title_).getTitle() << std::endl;
			std::cout << "Author: " << authors[a].getNameOfAuthor() << std::endl;
			std::cout << "Date: " << authors[a].getBookByTitle(title_).getDate() << std::endl << std::endl;*/
	}	
}
void Library::searchBookByDate(const int& date_) {

		for (int a = 0; a < authors.size(); a++) {
			authors[a].getBookByDate(date_, authors[a].getNameOfAuthor());
			/*std::cout << "Title: " << authors[a].getBookByTitle(title_).getTitle() << std::endl;
			std::cout << "Author: " << authors[a].getNameOfAuthor() << std::endl;
			std::cout << "Date: " << authors[a].getBookByTitle(title_).getDate() << std::endl << std::endl;*/
		}
	}

void Library::searchBookByAuthor(const std::string& name_) {

	for (int a = 0; a < authors.size(); a++) {
		if (authors[a].getNameOfAuthor() == name_) {
			authors[a].printBook(name_);
		}
	}
}

void Library::printLibrary() {
	if (authors.empty()) {
		std::cout << "Library is empty!" << std::endl;
	}
	else {
		for (int a = 0; a < authors.size(); a++) {
			for (int b = 0; b < authors[a].numOfBooks(); b++) {
				authors[a].printBook(authors[a].getNameOfAuthor());
			}
		}
	}
}


bool Library::emptyLib() {
	if (authors.empty())
		return false;
	else
		return true;
}