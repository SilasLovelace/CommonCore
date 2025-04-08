#include   "Brain.hpp"

Brain::Brain() {
    idea_i = 0;
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain &src) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = src.ideas[i];
    }
    this->idea_i = src.idea_i;
    std::cout << "Brain copy constructor called" << std::endl;
}
Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}
Brain &Brain::operator=(Brain &rhs) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}
void Brain::setIdea(std::string idea) {
    this->ideas[this->idea_i] = idea;
    if (this->idea_i < 99) {
        this->idea_i++;
    } else {
        std::cout << "Brain is full, future ideas will remove old ones!" << std::endl;
        this->idea_i = 0;
    }
}
std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        if (this->ideas[index].empty()) {
            return "This idea is empty!\n";
        }
        return this->ideas[index];
    }
    return "This idea does not exist!\n";
}