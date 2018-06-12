#pragma once
#include <string>
#include <vector>
#include "dialogo.h"

class questions : ClassDialogo
{
public:
	questions();
	~questions();
	std::string question;
	int questionId;
	std::vector <questions> questionVector;
};

