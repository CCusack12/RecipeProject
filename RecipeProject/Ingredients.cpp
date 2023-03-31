#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <string>

using namespace std;

class Ingredients {
public:
    Ingredients(const string &name);
    const string &getIngredName() const; //function returns ingredName data member
    virtual ~Ingredients() = default;

private:
    string ingredName;
};

#endif /* INGREDIENTS_H */
