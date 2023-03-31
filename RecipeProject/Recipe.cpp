#include "Recipe.h"
#include <algorithm>
#include <sstream>

using namespace std;

Recipe r;

vector<string> Recipe::recipeList;
vector<Recipe> Recipe::recipeVector;
ostringstream returnRecipe;
string Recipe::instructionsGlobal;

Recipe::Recipe(const string& name, const Food& food, const string& difficulty, const int& n, const string& instructions) //initializes all member variables of recipe class
    : name(name), food(food), difficulty(difficulty), instructionsSteps(n), instructions(instructions)
{
    appendInstructions(instructions, n);
}

void Recipe::addToList(const Recipe& recipe) //adds given object to list of all recipes
{
    recipeList.push_back(recipe.getName());
    recipeVector.push_back(recipe);
}

const string& Recipe::getName() const //returns name of recipe
{
    return name;
}

string Recipe::getRecipeNameList() //returns string list of all recipe names
{
    ostringstream returnRecipe;
    for (const string& str : recipeList)
    {
        returnRecipe << str << endl;
    }
    return returnRecipe.str();
}

const vector<string>& Recipe::getRecipeList() //returns a vector of all recipe names
{
    return recipeList;
}

const string Recipe::getDifficultyFromList(const int& i) //returns a string with all recipes and their difficulty
{
    ostringstream returnDifficulty;
    for (Recipe& r : recipeVector)
    {
        if (r.getDifficulty() == "Hard" && i == 1)
        {
            returnDifficulty << r.getName() << endl;
        }
        else if (r.getDifficulty() == "Medium" && i == 2)
        {
            returnDifficulty << r.getName() << endl;
        }
        else if (r.getDifficulty() == "Easy" && i == 3)
        {
            returnDifficulty << r.getName() << endl;
        }
    }
    return returnDifficulty.str();
}

const vector<Recipe>& Recipe::getRecipeDifficulty() //returns vector of all recipes and their difficulty
{
    return recipeVector;
}

const string& Recipe::getDifficulty() const //returns difficulty level of recipe
{
    return difficulty;
}

const Food& Recipe::getFood() //returns an instance of the food class representing ingredients used
{
    return food;
}

const string& Recipe::getIngredients() const //returns string with names of all ingredients used in recipe
{
    ostringstream returnIngredient;
    for (const Ingredients& i : Food::getIngredients())
    {
        returnIngredient << i.getIngredName() << endl;
    }
    return returnIngredient.str();
}

void Recipe::appendInstructions(const string& input, int n) //private method - used to append the cooking instructions for recipe
{
    string output;
    string::size_type pos = 0;
    for (int i = 0; i < n; ++i)
    {
        output += "Step " + to_string(i + 1) + ": ";
        while (pos < input.length())
        {
            output += input[pos];
            if (input[pos] == '.')
            {
                output += "\n";
                ++pos;
                break;
            }
            ++pos;
        }
        if (pos == input.length())
        {
            pos = 0;
        }
        output += "\n";
    }
    instructionsGlobal = output;
}

int Recipe::getInstructions() const //returns number of steps used in recipe
{
    return instructionsSteps;
}

const string& Recipe::getInstructionString() //returns string with all cooking instructions for recipe
{
    return instructionsGlobal;
}

Recipe::~Recipe() = default; //destructor
