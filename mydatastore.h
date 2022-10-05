#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "util.h"
#include "product.h"
#include "db_parser.h"
#include "user.h"
#include "datastore.h"
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

//implement searching/add product and users 
// start with datastore.h 

class MyDataStore : public DataStore
{
public:
     MyDataStore();
    ~MyDataStore();
    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);
    /**
     * Adds a user to the data store
     */
    void addUser(User* u);
    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);
    
    // add to cart 
    void addtocart(std::string username, Product* p);

    // view cart 
    void viewcart(std::string username);

    // buy from cart 
    void buycart(std:: string username);

private: 
  //create new set called product 
  std::set<Product*> productlist;
  // map : user map 
  std::map<std::string,User*> user;
  // cart map 
  std::map<std::string,std::vector<Product*>> cart;
  // search: keywords -> product map 
  //std::set<Product*> 改成vector
  std::map<std::string,std::set<Product*>> productmap;
};
#endif