#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "mydatastore.h"
#include "book.h"
#include "product.h"
#include "util.h"
#include "product.h"
#include "db_parser.h"
#include "user.h"
#include "datastore.h"

using namespace std;
//constructor and destructor for the program 
MyDataStore::MyDataStore(){

}

MyDataStore::~MyDataStore(){

}

// add product into the product list 
void MyDataStore::addProduct(Product* p){
  //insert in productlist 
  // add the keywords by accessng the keywords that associate with the product 
  // to do that: iterate through the existing keyword map check if the keyword already exist 
  //if the keyword exists, just insert
  //if not then create keywords and then insert 
  productlist.insert(p);
  set<string> keys = p->keywords();
  set<string>::iterator it;
  for(it = keys.begin(); it != keys.end(); ++it){
    if(productmap.find(*it) == productmap.end()){
      //make a pair of keyword + product 
      //createt a new set that contains all the added products 
      set<Product*> set_of_p;
      //insert the products into the set 
      set_of_p.insert(p);
      // productmap.insert(make_pair(*it,set_of_p));
      productmap[*it] = set_of_p;
    }
    // if the key exists, then I just need to insert the value that 
    // corelate to that keyword 
    else{
      // i used to write the insert function using productmap[], but it didn't work 
      productmap[*it].insert(p);
    }
  }
}

//add user into the userlist 
void MyDataStore::addUser(User* u){
  // makea pair of userid and user 
  // and just push into it
  if(user.find(u->getName())== user.end()){
     user.insert(make_pair(u->getName(),u));
  }
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type){
// go through the map, and then find and create 
//basically it gives me all the product that is associated with my keywords 
//depends on if its and or or 
// type 0 is AND; type 1 is OR 
  vector<Product*> result;
  //if its AND, then I find intersection  
  // find intersections of keywords 
  // set intersection (s1, s2);
  //found the keyword we need 
  //find the vectors of products that contain those keywords !!
  vector<set<Product *>> productSetPerTerm;
  for(unsigned int i = 0; i < terms.size(); i++){
    if (productmap.find(terms[i]) != productmap.end()) {
      productSetPerTerm.push_back(productmap[terms[i]]);
    }
  }
    if (productSetPerTerm.size() == 0) {
    return result;
  }

  set<Product*> finalSet = productSetPerTerm[0];

  for(unsigned int i = 1; i < productSetPerTerm.size(); i++){
    if (type == 0){
        finalSet = setIntersection(finalSet, productSetPerTerm[i]);
    } 
    else {
        finalSet = setUnion(finalSet, productSetPerTerm[i]);
    }
  }
  for(Product* p: finalSet){
    result.push_back(p);
  }
  return result;
}



void MyDataStore::dump(ostream& ofile){
//spit this file into a new file 
  ofile << "<products>" << endl;
  for(set<Product*>::iterator it = productlist.begin(); it!=productlist.end(); ++it){
    (*it)->dump(ofile);
  }
  ofile << "</products>" << endl;
  ofile << "<users>" << endl;
  for(map<string, User*>::iterator it=user.begin(); it != user.end(); ++it){
    (*it).second->dump(ofile);
  }
  ofile << "</users>" << endl;
}



// add to cart 
void MyDataStore::addtocart(std::string username, Product* p){
  if (p->getQty() == 0) {
    return;
  }
  if(user.find(username) != user.end()){
    if(cart.find(username) != cart.end()){
      cart[username].push_back(p);
    }
    else{
      vector<Product*> newproduct;
      newproduct.push_back(p);
      cart.insert(make_pair(username,newproduct));
    }
  }
  else{
    cout << "Invalid username" << endl;
  }
}



// buy from cart 
void MyDataStore::buycart(std:: string username){
  if(user.find(username) != user.end()){
    if(cart.find(username) != cart.end()){
      vector<Product*> newcart;
      vector<Product*> userproduct = cart[username];
      for(unsigned int i = 0; i < userproduct.size(); i++){
        double finalprice = (userproduct[i])->getPrice() * (userproduct[i])->getQty();
        if(finalprice <= user[username]->getBalance()){
          user[username]->deductAmount(finalprice);
          (userproduct[i])->subtractQty(1);
        }
        else{
          cout << "Not enough balance to purchase" << endl;
          newcart.push_back(userproduct[i]);
        }
      }
      if(newcart.size() > 0){
        cart[username] = newcart;
      }
      else{
        cart.erase(username);
      }
    }
  }
  else{
    cout << "Invalid username" << endl;
  }
}


// view cart 
void MyDataStore::viewcart(std::string username){
  // to check if the program got here
  //cout << "here" <<endl;
  //check the size
  //cout << cart[username].size() << endl;
  if(user.find(username) != user.end()){
    if(cart.find(username) != cart.end()){
      vector<Product*> userproduct = cart[username];
      //loop through vector 
      for(unsigned int i = 0; i < userproduct.size(); i++){
        cout << (userproduct[i])->displayString() << endl;
      }
    }
  }
  else{
    cout << "Invalid username" << endl;
  }
}
