#include <iostream>
#include <exception>

using namespace std;

class OutOfBoundsConstraint : public exception{
public:
    const char* what() const noexcept override;
};  