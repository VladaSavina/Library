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
	std::vector<Book> searchBookByTitle(const std::string&, Author);
	std::vector<Book> searchBookByDate(const int&, Author);
	std::vector<Book> searchBookByAuthor(const std::string&);
	void addBook(const Book&, const std::string&);
	void deleteBookByTitle(const std::string&);
	std::vector<Author> getAllAuthors(Library);
};
#endif LIBRARY_H