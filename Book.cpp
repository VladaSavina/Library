#include "Book.h"

Book::Book(const std::string& title_ , const int& date_)
{
	title = title_;
	date = date_;
}


std::string Book::getTitle() const {
	return title;
}

int Book::getDate() const{
	return date;
}
