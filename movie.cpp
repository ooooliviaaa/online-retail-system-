#include <iomanip>
#include <string>
#include <set>
#include "movie.h"
#include <sstream> 

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) :
  Product(category, name, price, qty){
    genre_ = genre;
    rating_ = rating;
  }



std::set<std::string> Movie::keywords() const{
//parse the strings to set 
  std::set<std::string> keywrds1 = parseStringToWords(genre_);
  std::set<std::string> keywrds2 = parseStringToWords(Product::getName());
  std::set<std::string> keywrds3 = parseStringToWords(rating_);
 
  keywrds1.insert(keywrds2.begin(),keywrds2.end());
  keywrds1.insert(keywrds3.begin(),keywrds3.end());
  return keywrds1;
}

std::string Movie::displayString() const{
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
  contains=name_+"/n"+"Genre: "+genre_+" "+ "Rating: "+" "+rating_+"/n"+p+" "+q+ " left.";
  return contains;
}

void Movie::dump(std::ostream& os) const{
  //calls products and dumps the general stuff for products 
  Product::dump(os);
  //dump the additional stuff for books
  os << genre_ << "\n" << rating_ << endl;
}

