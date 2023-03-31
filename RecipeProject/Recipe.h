#ifndef RECIPE_H
#define RECIPE_H

#include "Food.h"
#include <string>
#include <vector>

class Recipe {
public:
    // Constructors
    Recipe(const std::string& name, const Food& food, const std::string& difficulty,
           const int& n, const std::string& instructions);
    Recipe();

    // Destructor
    virtual ~Recipe();

    // Accessor methods
    const std::string& getName() const;
    const Food& getFood();
    const std::string& getDifficulty() const;
    static const std::vector<std::string>& getRecipeList();
    static const std::string getDifficultyFromList(const int& i);
    static const std::vector<Recipe>& getRecipeDifficulty();
    static std::string getRecipeNameList();
    std::string getIngredients();
    int getInstructions() const;
    static const std::string& getInstructionString();

    // Mutator methods
    void addToList(const Recipe& recipe);

private:
    // Private member variables
    std::string name;
    Food food;
    std::string difficulty;
    int instructionsSteps;
    std::string instructions;

    // Static member variables
    static std::vector<std::string> recipeList;
    static std::vector<Recipe> recipeVector;
    static std::ostringstream returnRecipe;
    static std::string instructionsGlobal;

    // Private methods
    void appendInstructions(const std::string& input, int n);
};

#endif  // RECIPE_H

