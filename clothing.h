#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "util.h"
#include "product.h"

class Clothing : public Product {
public:
  //in public, I want all the variables to be here 
    Clothing(const std::string category, const std::string name, double price, int qty, std::string brand, std::string size);
    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;
    
protected: 
  //in private, I want all the functions to be here because they
  //can't be modified
    std::string brand_;
    std::string size_;

};
#endif