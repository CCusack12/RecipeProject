#ifndef FOOD_H
#define FOOD_H

#include <vector>
#include <string>
#include "Ingredients.h"

class Food {
public:
    Food(const std::string& name, const std::vector<Ingredients>& ingredients); //constructor for name and vector of ingredients as parameters
    Food(const std::string& name);//constructor for name

    const std::vector<Ingredients>& getIngredients() const; //allows other code to access list of ingredients associated with particular food

    ~Food();

private:
    std::string name;
    std::vector<Ingredients> ingredients;
};

#endif // FOOD_H - destructor
