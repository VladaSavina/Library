#ifndef LIBRARY_H
#define LIBRARY_H

#include "Author.h" 

class Library
{
private:
	std::vector<Author> authors;

public:
	Library();
	~Library()=default;

	void deleteAuthor(const std::string&);
	void addAuthor(const std::string&);
	void searchBookByTitle(const std::string&);
	void searchBookByDate(const int&);
	void searchBookByAuthor(const std::string&);
	void addBook(const Book&, const std::string&);
	void deleteBookByTitle(const std::string&);
	bool emptyLib();
	void printLibrary();
};
#endif LIBRARY_H