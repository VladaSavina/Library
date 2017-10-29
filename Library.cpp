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

std::vector<Book> Library::searchBookByTitle(const std::string& title_, Author author) {
	std::vector <Book> foundBooks;
	foundBooks = author.getBookByTitle(title_);

	return foundBooks;
}

std::vector<Book> Library::searchBookByDate(const int& date_, Author author) {
	std::vector <Book> foundBooks;
	foundBooks=author.getBookByDate(date_, author.getNameOfAuthor());

	return foundBooks;
}

std::vector<Book> Library::searchBookByAuthor(const std::string& name_) {
	std::vector <Book> books;
	for (int a = 0; a < authors.size(); a++) {
		if (authors[a].getNameOfAuthor() == name_) {
			books=authors[a].getAllBooks(authors[a]);
		}
	}
	return books;
}

std::vector<Author> Library::getAllAuthors(Library  lib) {
	return lib.authors;
}

