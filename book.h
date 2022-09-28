#ifndef BOOK_H
#define BOOK_H
#include "util.h"
#include "product.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Book : public Product
{
public:
  //in public, I want all the variables to be here 
    Book(const std::string category, const std::string name, double price, int qty,  std::string ISBN, std::string author);
    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;
    
protected: 
  //in private, I want all the functions to be here because they
  //can't be modified
    std::string ISBN_;
    std::string author_;
};
#endif