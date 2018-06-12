#include "Generator.h"



Generator::Generator()
{
}

void Generator::loadDialog(std::string xml) {

	int questionsCount = 0;
	int questionOrder = 0;

	int answersAmount = 0;
	int answersCount = 0;
	int answerOrder = 0;
	int answerPoints = 0;

	totalpoints = 0;

	typedef const pugi::char_t* pugiCharArray;

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(xml.c_str());

	std::cout << "Resultado carga para dialogos --> " << result.description() << "\n" << std::endl;

	pugi::xml_node nodeQuestions = doc.child("preguntas");

	pugiCharArray arrayQuestionsAmount = nodeQuestions.attribute("cantidad").value();
	pugiCharArray arrayGlobalAnswersAmount = nodeQuestions.attribute("respuestasTotales").value();

	std::string stringQuestionsAmount(arrayQuestionsAmount);
	std::string stringGlobalAnswersAmount(arrayGlobalAnswersAmount);

	questionsAmount = stoi(stringQuestionsAmount);
	globalAnswersAmount = stoi(stringGlobalAnswersAmount);

	allQuestions = new Question[questionsAmount];
	pointsForQuestion = new AnswerPoints[questionsAmount];
	allAnswers = new Answer[globalAnswersAmount];

	for (pugi::xml_node nodeQuestion = nodeQuestions.child("pregunta");
		nodeQuestion;
		nodeQuestion = nodeQuestion.next_sibling("pregunta"))
	{

		pugiCharArray arrayQuestionOrder = nodeQuestion.attribute("orden").value();
		pugiCharArray arrayQuestionText = nodeQuestion.attribute("texto").value();

		std::string stringQuestionOrder(arrayQuestionOrder);
		std::string stringQuestionText(arrayQuestionText);

		questionOrder = stoi(stringQuestionOrder);

		allQuestions[questionsCount].order = questionOrder;
		allQuestions[questionsCount].text = stringQuestionText;
		questionsCount++;

		for (pugi::xml_node nodeAnswers = nodeQuestion.child("respuestas");
			nodeAnswers;
			nodeAnswers = nodeAnswers.next_sibling("respuestas"))
		{
			pugiCharArray arrayAnswersAmount = nodeAnswers.attribute("cantidad").value();

			std::string stringAnswersAmount(arrayAnswersAmount);

			answersAmount = stoi(stringAnswersAmount);
			allQuestions[questionsCount - 1].amountOfAnswers = answersAmount;

			for (pugi::xml_node nodeAnswer = nodeAnswers.child("respuesta");
				nodeAnswer;
				nodeAnswer = nodeAnswer.next_sibling("respuesta"))
			{
				pugiCharArray arrayAnswerOrder = nodeAnswer.attribute("orden").value();
				pugiCharArray arrayAnswerPoints = nodeAnswer.attribute("puntos").value();
				pugiCharArray arrayAnswerText = nodeAnswer.attribute("texto").value();

				std::string stringAnswerOrder(arrayAnswerOrder);
				std::string stringAnswerPoints(arrayAnswerPoints);
				std::string stringAnswerText(arrayAnswerText);

				answerOrder = stoi(stringAnswerOrder);
				answerPoints = stoi(stringAnswerPoints);

				allAnswers[answersCount].order = answerOrder;
				allAnswers[answersCount].relatedQuestion = questionsCount - 1;
				allAnswers[answersCount].points = answerPoints;
				allAnswers[answersCount].text = stringAnswerText;
				answersCount++;
			}
		}
	}
}

Generator::~Generator()
{
}
