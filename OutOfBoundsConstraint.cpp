#include <iostream>
#include <exception>
#include "OutOfBoundsConstraint.hpp"

using namespace std;
const char* OutOfBoundsConstraint::what() const noexcept
{
    return "Invalid number, Out Of Bounds Contraint!\n";
}  