#include <iomanip>
#include <string>
#include <set>
#include "book.h"
#include "product.h"
#include <sstream> 

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string ISBN) :
  Product(category, name, price, qty){
    ISBN_ = ISBN;
    author_ = author;
  }



std::set<std::string> Book::keywords() const{
//parse the author and the getname first because we need to parse them into sets 
  std::set<std::string> keywrds1 = parseStringToWords(author_);
  std::set<std::string> keywrds2 = parseStringToWords(Product::getName());
  //create two different sets to store author and name 
  keywrds1.insert(keywrds2.begin(),keywrds2.end());
  //now insert the ISBN as well
  keywrds1.insert(ISBN_);
  return keywrds1;
}

std::string Book::displayString() const{
  //declare a string called contains 
  string contains = "";
  // add all the info about book
  //convert price to a string 
  std::stringstream ss;
  ss << std::fixed << std::setprecision(2) << price_;
  string p = ss.str();

  std::stringstream sd;
  sd << qty_;
  string q = sd.str();

  // price has to be two decimals 
  contains=name_+"\n"+"Author: "+author_+" "+"ISBN: "+" "+ISBN_+"\n"+p+" "+q+ " left.";
  return contains;
}

void Book::dump(std::ostream& os) const{
  //calls products and dumps the general stuff for products 
  Product::dump(os);
  //dump the additional stuff for books
  //changed order for author and isbn 
  os << ISBN_ << "\n" << author_ << endl;
}

