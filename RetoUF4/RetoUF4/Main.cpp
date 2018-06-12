#pragma once

#include "pugixml.hpp"
#include <iostream>
#include <string>
#include "dialogo.h"
#include "questions.h"
#include <thread>
#include <vector>
typedef const pugi::char_t* pugiCharArray;


bool endGame = false;
int input;
int thread_function()
{
	while (!endGame)
	{
		std::cin >> input;
		return input;
	}
}

int main()
{
	std::cout << "Bienvenido jugador, pulse cualquier tecla para comenzar el questionario." << std::endl << "Solo tendras 5 segundos por pregunta, piensa rapido!" << std::endl;
	system("pause");
	std::string dialogo ="dialogo.xml"
	std::vector <ClassDialogo> questionario = LoadQuestionary("questionario.xml");

	for (int i = 0; i < question1.questionVector.size(); i++)
	{
		std::cout << questionVector[i].question << std::endl;
		std::thread t(thread_function);
		
		
	}
	



	return 0;
}

std::vector <ClassDialogo> LoadQuestionary(std::string path)
{
	std::vector <ClassDialogo> dialogueVector;
	questions question1;
	ClassDialogo d;

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(path.c_str());

	pugi::xml_node nodoQuestionario = doc.child("questionario");
	pugi::xml_node nodoQuestion = nodoQuestionario.child("preguntas");
	pugi::xml_node nodoAnswers = nodoQuestionario.child("respuestas");

	for (pugi::xml_node nodoQuestion = nodoQuestion.child("pregunta_tiempo"); nodoQuestion; nodoQuestion = nodoQuestion.next_sibling("pregunta_tiempo"))
	{
		pugiCharArray actualQuestion = nodoQuestion.attribute("pregunta").value();
		pugiCharArray actualIdQuestion = nodoQuestion.attribute("id_pregunta").value();

		question1.question = std::string(actualQuestion);
		question1.questionId = stoi(std::string(actualIdQuestion));
		question1.questionVector.push_back(question1);
	}

	for (pugi::xml_node nodoAnswer = nodoAnswers.child("respuesta"); nodoAnswer; nodoAnswer = nodoAnswer.next_sibling("respuesta"))
	{
		pugiCharArray playerAnswer = nodoAnswer.attribute("respuestaJugador").value();
		pugiCharArray answerId = nodoAnswer.attribute("id_pregunta").value();
		pugiCharArray scoreAnswer = nodoAnswer.attribute("puntos").value();

		d.answerId = stoi(std::string(answerId));
		d.score = stoi(std::string(scoreAnswer));
		d.answers = std::string(playerAnswer);

		dialogueVector.push_back(d);
	}


	return dialogueVector;
}