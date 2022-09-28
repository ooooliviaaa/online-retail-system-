#ifndef MOVIE_H
#define MOVIE_H
#include "util.h"
#include "product.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Movie : public Product
{
public:
  //in public, I want all the variables to be here 
    Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;
    
protected: 
  //in private, I want all the functions to be here because they
  //can't be modified
    std::string genre_;
    std::string rating_;
};
#endif