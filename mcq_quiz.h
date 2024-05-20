//MCQ_QUIZ_H

#ifndef MCQ_QUIZ_H
#define MCQ_QUIZ_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Question {
    string question;
    string choices[4];
    char correctChoice;
};

class MCQQuiz {
private:
    struct Node {
        Question data;
        Node* next;
    };

    Node* head;
    int count;

public:
    MCQQuiz() : head(nullptr), count(0) {
        srand(static_cast<unsigned>(time(nullptr)));
    }

    ~MCQQuiz() {
        clear();
    }

    void addQuestion(const Question& question) {
        Node* newNode = new Node;
        newNode->data = question;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        count++;
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        count = 0;
    }

    bool askRandomQuestion() {
        if (head == nullptr) {
            cout << "No questions available." << endl;
            return true;
        }

        int randomIndex = rand() % count;

        Node* current = head;
        for (int i = 0; i < randomIndex; i++) {
            current = current->next;
        }

        Question question = current->data;
        cout << question.question << endl;
        for (int i = 0; i < 4; i++) {
            cout << static_cast<char>('A' + i) << ") " << question.choices[i] << endl;
        }

        char userChoice;
        cout << "Enter your choice (A, B, C, or D): ";
        cin >> userChoice;

        if (tolower(userChoice) == question.correctChoice) {
            cout << "Correct!" << endl;
            return true;
        } else {
            cout << "Incorrect." << endl;
            return false;
        }
    }
};

#endif // MCQ_QUIZ_H

