#ifndef WORKLIB_H
#define WORKLIB_H

#include "Library.h"
#include <iostream>

class WorkLib
{
public:
	WorkLib();
	~WorkLib() = default;
	void printBook(std::vector <Book>, std::string);
	void printLibrary(Library);
	void menu(Library);
	void instruction();
	Library addAuthor(Library);

private:
	Library addBook(Library);
	Library deleteBook(Library);
	
	Library deleteAuthor(Library);
	Library printBookByTittle(Library);
	Library printBookByAuthor(Library);
	Library printBookByDate(Library);
};
#endif WORKLIB_H

