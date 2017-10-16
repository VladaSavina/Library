#ifndef AUTHOR_H
#define AUTHOR_H

#include "Book.h" 
#include <vector>
#include <iostream>

class Author
{
private:
	std::vector <Book> books;
	std::string name;
public:
	Author(const std::string& name_);
	~Author() = default;
	std::string getNameOfAuthor() const;
	void deleteBook(const std::string&);
	void addBook(const std::string&, const int&);
	int numOfBooks() const;
	void getBookByTitle(const std::string&, const std::string&);
	void getBookByDate(const int&, const std::string&);
	void printBook(const std::string&);
};

#endif AUTHOR_H
