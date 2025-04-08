#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
    private:
        std::string ideas[100];
        int idea_i;
    public:
        Brain();
        Brain &operator=(Brain &rhs);
        Brain(Brain &src);
        ~Brain();

        void setIdea(std::string idea);
        std::string getIdea(int index) const;
};

#endif
