#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <string>

using namespace std;

class Ingredients {
public:
    Ingredients(const string &name);
    const string &getIngredName() const; //returns const reference to the private member variable ingredName
    virtual ~Ingredients() = default;

private:
    string ingredName;
};

#endif //INGREDIENTS_H
