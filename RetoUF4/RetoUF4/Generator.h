#pragma once
#include <string>

struct Question
{
	int order;
	int amountOfAnswers;
	std::string text;
};

struct Answer
{
	int order;
	int relatedQuestion;
	int points;
	std::string text;
};

struct AnswerPoints
{
	int pointsGained;
	int relatedQuestion;
};

class Generator
{
public:
	Generator();
	~Generator();
	void loadDialog(std::string xml);

	int getQuestionsAmount() { return questionsAmount; };
	std::string getQuestiontext(int question) { return allQuestions[question].text; };

	int getAnswersAmountOfQuestion(int question) { return allQuestions[question].amountOfAnswers; };
	std::string getAnswersTextOfQuestion(int question, int answer);

	int getWinnedPointsOfQuestion(int question) { return pointsForQuestion[question].pointsGained; };
	void setAnswerPointsOfQuestion(int question, int answer);

	int getTotalPoints() { return totalpoints; };

private:
	int questionsAmount;
	Question *allQuestions;

	int globalAnswersAmount;
	Answer *allAnswers;

	int totalpoints;
	AnswerPoints *pointsForQuestion;
};

