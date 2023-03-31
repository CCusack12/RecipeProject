#include "food.h"
#include <vector>
#include <string>

using namespace std;

vector<Ingredients> Food::ingredients; //static data member of food class

Food::Food(const string &name, const vector<Ingredients> &ingredients) //takes in food name and vector of ingredients
  : name(name), ingredients(ingredients) { //initialises the name and ingredients data members for Food object
}

Food::Food(const string &name) : name(name) { //only takes in name, used when ingredients list is not available straight away
}

const vector<Ingredients> &Food::getIngredients() const { //returns a const reference to the ingredienrs vector of the food object
  return ingredients;
}

Food::~Food() = default;




