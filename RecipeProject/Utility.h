#ifndef RECIPEBOOK_UTILITY_H
#define RECIPEBOOK_UTILITY_H

#include <vector>

template<typename T> //type T not specified until class is instaniated
class Utility {
public:
    virtual ~Utility() = default;

    virtual T searchList(const T& t, const std::vector<T>& vectorT) const = 0; //element of type T is being searched for, second is vector of type T being searched
};

#endif //RECIPEBOOK_UTILITY_H
