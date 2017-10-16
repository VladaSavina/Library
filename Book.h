#ifndef BOOK_H
#define BOOK_H


#include <string> 

class Book
{
public:
		Book(const std::string&, const int&);
		~Book()=default;

		std::string getTitle() const;
		int getDate() const;

private:
		std::string title;
		int date;
};

#endif BOOK_H
