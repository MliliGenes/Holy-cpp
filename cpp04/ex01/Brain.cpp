#include "Brain.hpp"

Brain::Brain( void ) {
    std::cout << "now i have a brain!" << std::endl;
    for (int index = 0; index < 100; index++)
        ideas[index] = "slak ajemi...";
}

Brain::~Brain() {
    std::cout << "brain gone!" << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int index = 0; index < 100; index++)
        ideas[index] = other.ideas[index];
    std::cout << "brain copied, with some positive ideas!" << std::endl;
}

Brain &Brain::operator=(const Brain& other) {
    if (this == &other)
        return *this;

    for (int index = 0; index < 100; index++)
        ideas[index] = other.ideas[index];
    std::cout << "brain assigned to another brain" << std::endl;

    return *this;
}

void Brain::setIdea(unsigned int index, const std::string& idea) {
    if (index > 99)
        return ;
    ideas[index] = idea;
}

const std::string& Brain::getIdea(unsigned int index) {
    return ideas[index];
}