#ifndef RECIPEPROJECT_ERROR404_H
#define RECIPEPROJECT_ERROR404_H

#include <exception>
#include <string>

using namespace std;

class error404 : public exception { //error404 class publicly derives from exception
public:
explicit error404(const string&); //constructor takeing string arugement cant be used as a conversion constructor
~error404() override; //destructor overrides default destructor
};

#endif //RECIPEBOOK_ERROR404_H
