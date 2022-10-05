#include <iomanip>
#include <string>
#include <set>
#include "clothing.h"
#include "product.h"
#include <sstream> 

using namespace std;

//constructor 
Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string brand, std::string size) :
  Product(category, name, price, qty){
    brand_ = brand;
    size_ = size;
  }



std::set<std::string> Clothing::keywords() const{
//parse the author and the getname first because we need to parse them into sets 
  std::set<std::string> keywrds1 = parseStringToWords(brand_);
  std::set<std::string> keywrds2 = parseStringToWords(Product::getName());
  //create two different sets to store author and name 
  keywrds1.insert(keywrds2.begin(),keywrds2.end());
  //now insert the ISBN as well
  keywrds1.insert(convToLower(size_));
  return keywrds1;
}

std::string Clothing::displayString() const{
  //declare a string called contains 
  string contains = "";
  // add all the info about clothing
  //convert price to a string 
  std::stringstream ss;
  ss << std::fixed << std::setprecision(2) << price_;
  string p = ss.str();
  // convert qty to string too 
  std::stringstream sd;
  sd << qty_;
  string q = sd.str();
  // price has to be two decimals 
  contains=name_+"\n"+"Size: "+size_+" "+ "Brand: "+brand_+"\n"+p+" "+q+ " left.";
  return contains;
}

void Clothing::dump(std::ostream& os) const{
  //calls products and dumps the general stuff for products 
  Product::dump(os);
  //dump the additional stuff for books
  os << brand_ << endl;
  os << size_ << endl;
}


