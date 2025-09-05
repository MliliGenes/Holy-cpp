#pragma once

#include <string>
#include <iostream>

class Brain {

    private :
        std::string ideas[100];

    public :
        Brain(void);
        ~Brain(void);

        Brain(const Brain &other);
        Brain& operator=(const Brain& other);

        void setIdea(unsigned int index, const std::string& idea);
        const std::string& getIdea(unsigned int index);
};