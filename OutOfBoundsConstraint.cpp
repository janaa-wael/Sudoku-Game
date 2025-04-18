#include <iostream>
#include <exception>
#include "OutOfBoundsConstraint.hpp"

using namespace std;
const char* OutOfBoundsConstraint::what() const noexcept
{
    return "Out Of Bounds Contraint!\n";
}  
