#include "mcq_quiz.h"

bool enterMCQ() {

    MCQQuiz quiz;

    Question questions[] = {

            {
                    "What is the output of the following code snippet?\n#include <iostream>\nint main() {\nint num = 10;\nint* ptr = #\nstd::cout << *ptr << std::endl;\n*ptr = 20;\nstd::cout << num << std::endl;\nreturn 0;\n}\na) 10 10\nb) 10 20  \nc) 20 10\nd) 20 20",
                    { "a", "b", "c", "d"},
                    'b'
            },
            {
                    "What is the purpose of the \"static\" keyword when used with a class member in C++?\na) It specifies that the member can only be accessed by the class itself.\nb) It specifies that the member is shared among all objects of the class.  \nc) It specifies that the member cannot be modified.\nd) It specifies that the member is a constant.",
                    {"a", "b", "c", "d"},
                    'b'
            },
            {
                    "Which of the following is true about function templates in C++?\na) Function templates allow the creation of generic functions that can operate on different data types.  \nb) Function templates are used to define functions with variable numbers of arguments.\nc) Function templates are used to define functions with default arguments.\nd) Function templates can only be used with member functions of a class.",
                    {"a", "b", "c", "d"},
                    'a'
            },
            {
                    "What is the correct way to define a constant pointer to a constant integer in C++?\na) const int* ptr;\nb) int* const ptr;\nc) const int* const ptr;  \nd) int const* const ptr;",
                    {"a", "b", "c", "d"},
                    'c'
            },
            {
                    "Which of the following is true about the \"virtual\" keyword in C++?\na) It specifies that a function cannot be overridden by a derived class.\nb) It specifies that a function can only be accessed by the class itself.\nc) It specifies that a function can be overridden by a derived class.  \nd) It specifies that a function can be declared in multiple classes.",
                    {"a", "b", "c", "d"},
                    'c'
            },
            {
                    "What is the output of the following code snippet in C++?\n#include <iostream>\nint main() {\nint x = 5;\nstd::cout << (++x)++ << std::endl;\nreturn 0;\n}\na) 5\nb) 6\nc) Compilation error  \nd) Runtime error",
                    {"a", "b", "c", "d"},
                    'c'
            },
            {
                    "What is the purpose of the \"namespace\" keyword in C++?\na) It specifies the scope of a variable.\nb) It specifies the access level of a class member.\nc) It specifies a named scope for a set of identifiers.  \nd) It specifies the visibility of a function.",
                    {"a", "b", "c", "d"},
                    'c'
            },
            {
                    "Which of the following is true about the \"this\" pointer in C++?\na) It points to the current object within a member function.  \nb) It points to the previous object within a member function.\nc) It points to the base object within a derived class.\nd) It points to the derived object within a base class.",
                    {"a", "b", "c", "d"},
                    'a'
            },
            {
                    "What is the correct way to read a string with spaces from the user in C++?\na) std::cin >> str;\nb) std::cin.getline(str, size);\nc) std::getline(std::cin, str);  \nd) std::cin.ignore();",
                    {"a", "b", "c", "d"},
                    'c'
            },
            {
                    "What is the output of the following code snippet in C++?\n#include <iostream>\nint main() {\nint a = 5;\nint b = 2;\nstd::cout << a / b << std::endl;\nstd::cout << static_cast<double>(a) / b << std::endl;\nreturn 0;\n}\na) 2 2.5\nb) 2 2\nc) 2.5 2.5\nd) 2 2.5  ",
                    {"a", "b", "c", "d"},
                    'd'
            },
            {
                "What is the purpose of the \"namespace\" keyword in C++?\na) It specifies the scope of a variable.\nb) It specifies the access level of a class member.\nc) It specifies a named scope for a set of identifiers.  \nd) It specifies the visibility of a function.",
                        {"a", "b", "c", "d"},
                        'c'
            },
            {
                "Which of the following is true about the \"this\" pointer in C++?\na) It points to the current object within a member function.  \nb) It points to the previous object within a member function.\nc) It points to the base object within a derived class.\nd) It points to the derived object within a base class.",
                        {"a", "b", "c", "d"},
                        'a'
            },
            {
                "What is the correct way to read a string with spaces from the user in C++?\na) std::cin >> str;\nb) std::cin.getline(str, size);\nc) std::getline(std::cin, str);  \nd) std::cin.ignore();",
                        {"a", "b", "c", "d"},
                        'c'
            },
            {
                "What is the output of the following code snippet in C++?\n#include <iostream>\nint main() {\n int a = 5;\n int b = 2;\n std::cout << a / b << std::endl;\n std::cout << static_cast<double>(a) / b << std::endl;\n return 0;\n}",
                        {"a) 2 2.5", "b) 2 2", "c) 2.5 2.5", "d) 2 2.5  "},
                        'd'
            },
            {
                "What is the purpose of the \"sizeof\" operator in C++?\na) It returns the size of a variable in bytes.  \nb) It returns the address of a variable.\nc) It returns the data type of a variable.\nd) It returns the number of elements in an array.",
                        {"a", "b", "c", "d"},
                        'a'
            },
            {
                "Which of the following is true about the \"const\" keyword when used with a member function in C++?\na) It specifies that the member function cannot modify the object's data members.\nb) It specifies that the member function can only be called on const objects.  \nc) It specifies that the member function can only be called on non-const objects.\nd) It specifies that the member function cannot have any parameters.",
                        {"a", "b", "c", "d"},
                        'b'
            },
            {
                "What is the output of the following code snippet in C++?\n#include <iostream>\nint main() {\n int x = 10;\n int y = 5;\n int z = (++x) + (y++);\n std::cout << z << std::endl;\n return 0;\n}",
                        {"a) 16", "b) 17", "c) 15  ", "d) 14"},
                        'c'
            },
            {
                "What is the purpose of the \"default\" keyword in C++11?\na) It specifies the default value for a function parameter.\nb) It allows the default constructor to be explicitly defined for a class.\nc) It defines the default behavior for special member functions, such as the default constructor, copy constructor, and assignment operator.  \nd) It specifies the default access level for class members.",
                        {"a", "b", "c", "d"},
                        'c'
            },
            {
                "What is the output of the following code snippet in C++?\n#include <iostream>\nint main() {\n int x = 10;\n int y = 5;\n int z = (x++) - (--y);\n std::cout << z << std::endl;\n return 0;\n}",
                        {"a) 6", "b) 5", "c) 4", "d) 9  "},
                        'd'
            },
            {
                "Which famous scientist developed the theory of general relativity?\na) Isaac Newton\nb) Albert Einstein  \nc) Nikola Tesla\nd) Marie Curie",
                        {"a", "b", "c", "d"},
                        'b'
            },
            {
                "Who wrote the novel \"To Kill a Mockingbird\"?\na) J.R.R. Tolkien\nb) Harper Lee  \nc) George Orwell\nd) Jane Austen",
                        {"a", "b", "c", "d"},
                        'b'
            },
            {
                "What is the largest organ in the human body?\na) Heart \nb) Liver \nc) Skin \nd) Brain ",
                        {"a", "b", "c", "d"},
                        'c'
            },
            {
                "What is the tallest mountain in the world?\na) Mount Kilimanjaro\nb) Mount Everest  \nc) Mount McKinley\nd) Mount Fuji",
                        {"a", "b", "c", "d"},
                        'b'
            },
            {
                "Which musical instrument has pedals, keys, and strings?\na) Violin\nb) Piano  \nc) Trumpet\nd) Guitar",
                        {"a", "b", "c", "d"},
                        'b'
            },
            {
                "Who wrote the play 'Romeo and Juliet'?",
                        {"a) William Shakespeare", "b) Arthur Miller", "c) Tennessee Williams", "d) Oscar Wilde"},
                        'a'
            },
            {
                "Which country is famous for its tulips and windmills?",
                        {"a) Italy", "b) France", "c) Netherlands", "d) Brazil"},
                        'c'
            },
            {
                "What is the chemical symbol for gold?",
                        {"a) Au", "b) Ag", "c) Fe", "d) Cu"},
                        'a'
            },
            {
                "Who painted the ceiling of the Sistine Chapel?",
                        {"a) Vincent van Gogh", "b) Leonardo da Vinci", "c) Pablo Picasso", "d) Michelangelo"},
                        'd'
            },
            {
                "Which continent is home to the largest desert in the world, the Sahara?",
                        {"a) Asia", "b) Africa", "c) South America", "d) Australia"},
                        'b'
            },
            {
                "Who is the author of the Harry Potter book series?",
                        {"a) J.K. Rowling", "b) Stephen King", "c) Dan Brown", "d) George R.R. Martin"},
                        'a'
            },
            {
                "What is the largest ocean on Earth?",
                        {"a) Atlantic Ocean", "b) Indian Ocean", "c) Pacific Ocean", "d) Arctic Ocean"},
                        'c'
            },
            {
                "Which famous scientist developed the theory of evolution by natural selection?",
                        {"a) Isaac Newton", "b) Marie Curie", "c) Charles Darwin", "d) Nikola Tesla"},
                        'c'
            },
            {
                "Who painted the famous artwork 'The Starry Night'?",
                        {"a) Salvador Dalí", "b) Vincent van Gogh", "c) Pablo Picasso", "d) Claude Monet"},
                        'b'
            },
            {
                "What is the capital city of Canada?",
                        {"a) Toronto", "b) Ottawa", "c) Vancouver", "d) Montreal"},
                        'b'
            },
            {
                "Which country is home to the ancient pyramids of Giza?",
                        {"a) Greece", "b) Egypt", "c) Mexico", "d) China"},
                        'b'
            },
            {
                "Who wrote the novel '1984'?",
                        {"a) George Orwell", "b) Aldous Huxley", "c) F. Scott Fitzgerald", "d) Ernest Hemingway"},
                        'a'
            },
            {
                "What is the chemical symbol for oxygen?",
                        {"a) O", "b) H", "c) C", "d) N"},
                        'a'
            },
            {
                "Which planet is known as the 'Giant of our Solar System'?",
                        {"a) Saturn", "b) Neptune", "c) Jupiter", "d) Uranus"},
                        'c'
            },
            {
                "Who is the artist behind the famous painting 'The Last Supper'?",
                        {"a) Pablo Picasso", "b) Leonardo da Vinci", "c) Michelangelo", "d) Rembrandt"},
                        'b'
            },
            {
                "What is the official language of Brazil?",
                        {"a) Portuguese", "b) Spanish", "c) French", "d) English"},
                        'a'
            },
            {
                "Which famous scientist discovered the law of gravity?",
                        {"a) Isaac Newton", "b) Albert Einstein", "c) Galileo Galilei", "d) Nikola Tesla"},
                        'a'
            },
            {
                "Which city hosted the 2016 Summer Olympics?",
                        {"a) Rio de Janeiro", "b) London", "c) Beijing", "d) Sydney"},
                        'a'
            },
            {
                "What is the largest planet in our solar system?",
                        {"a) Mercury", "b) Venus", "c) Jupiter", "d) Mars"},
                        'c'
            },
            {
                "Who wrote the play 'Hamlet'?",
                        {"a) William Shakespeare", "b) Arthur Miller", "c) Tennessee Williams", "d) Oscar Wilde"},
                        'a'
            },
            {
                "What is the output of the following code snippet?\n\n#include <iostream>\nint main() {\n int x = 5;\n int y = x++ + ++x;\n std::cout << y;\n return 0;\n}\n\na) 10\nb) 11\nc) 12  \nd) 13",
                        {"a) 10", "b) 11", "c) 12  ", "d) 13"},
                        'c'
            },
            {
                "What is the purpose of the 'const' keyword in C++?\n\na) Specifies that a variable cannot be modified  \nb) Allocates memory for a variable at compile-time\nc) Defines a variable that is shared among all instances of a class\nd) Specifies that a variable's value cannot be changed",
                        {"a) Specifies that a variable cannot be modified  ", "b) Allocates memory for a variable at compile-time", "c) Defines a variable that is shared among all instances of a class", "d) Specifies that a variable's value cannot be changed"},
                        'a'
            },
            {
                "Which of the following is true about function overriding in C++?\n\na) Functions with the same name but different return types can be overridden\nb) Functions with the same name and same parameter types can be overridden  \nc) Functions with different names but the same parameter types cannot be overridden\nd) Functions with the same name and parameters but different access specifiers can be overridden",
                        {"a) Functions with the same name but different return types can be overridden", "b) Functions with the same name and same parameter types can be overridden  ", "c) Functions with different names but the same parameter types cannot be overridden", "d) Functions with the same name and parameters but different access specifiers can be overridden"},
                        'b'
            },
            {
                "What is the correct syntax for declaring a reference variable in C++?\n\na) int* ref;\nb) int& ref;  \nc) int ref*;\nd) ref int;",
                        {"a) int* ref;", "b) int& ref;  ", "c) int ref*;", "d) ref int;"},
                        'b'
            },
            {
                "What is the purpose of the 'delete' keyword in C++?\n\na) Deallocates memory for a variable\nb) Deletes a variable from memory\nc) Releases system resources held by an object\nd) Dynamically deallocates memory for an object  ",
                        {"a) Deallocates memory for a variable", "b) Deletes a variable from memory", "c) Releases system resources held by an object", "d) Dynamically deallocates memory for an object  "},
                        'd'
            },
            {
                "Which header file is required to use the string class in C++?\n\na) <string.h>\nb) <cstring>\nc) <string>  \nd) <iostream>",
                        {"a) <string.h>", "b) <cstring>", "c) <string>  ", "d) <iostream>"},
                        'c'
            },
            {
                "What is the correct way to write a comment in C++?\n\na) // This is a comment  \nb) /* This is a comment /\nc) # This is a comment\nd) <!-- This is a comment -->",
                        {"a) // This is a comment  ", "b) / This is a comment */", "c) # This is a comment", "d) <!-- This is a comment -->"},
                        'a'
            },
            {
                "Which operator is used for dynamic memory allocation in C++?\n\na) *\nb) ::\nc) ->\nd) new  ",
                        {"a) ", "b) ::", "c) ->", "d) new  "},
                        'd'
            },
            {
                "What is the purpose of the 'friend' keyword in C++?\n\na) Specifies a function that is a member of a class\nb) Specifies a function that can access private and protected members of a class  \nc) Specifies a class that inherits from another class\nd) Specifies a variable that cannot be modified",
                        {"a) Specifies a function that is a member of a class", "b) Specifies a function that can access private and protected members of a class  ", "c) Specifies a class that inherits from another class", "d) Specifies a variable that cannot be modified"},
                        'b'
            },
            {
                "What is the correct way to open a file for writing in C++?\n\na) file.open(\"filename.txt\", std::ios::out)  \nb) file.open(\"filename.txt\", std::ios::in)\nc) file.open(\"filename.txt\", std::ios::app)\nd) file.open(\"filename.txt\", std::ios::binary)",
                        {"a) file.open(\"filename.txt\", std::ios::out)  ", "b) file.open(\"filename.txt\", std::ios::in)", "c) file.open(\"filename.txt\", std::ios::app)", "d) file.open(\"filename.txt\", std::ios::binary)"},
                        'a'
            },
            {
                "What is the output of the following code snippet in C++?\n\n#include <iostream>\nint main() {\n int arr{} = {1, 2, 3, 4, 5};\n int ptr = arr;\n std::cout << *(ptr + 2);\n return 0;\n}\n\na) 1\nb) 2\nc) 3  \nd) 4",
                        {"a) 1", "b) 2", "c) 3  ", "d) 4"},
                        'c'
            },
            {
                "Which of the following is true about static member variables in C++?\n\na) They belong to a specific object of a class.\nb) They are accessible only within the class.\nc) They are initialized when an object of the class is created.\nd) They are shared among all objects of the class.  ",
                        {"a) They belong to a specific object of a class.", "b) They are accessible only within the class.", "c) They are initialized when an object of the class is created.", "d) They are shared among all objects of the class.  "},
                        'd'
            },
            {
                "What does the 'sizeof' operator return in C++?\n\na) The number of elements in an array.\nb) The size of the variable in bytes.  \nc) The address of a variable.\nd) The data type of a variable.",
                        {"a) The number of elements in an array.", "b) The size of the variable in bytes.  ", "c) The address of a variable.", "d) The data type of a variable."},
                        'b'
            },
            {
                "Which of the following is a valid way to initialize a string variable in C++?\n\na) std::string str = \"Hello\";  \nb) std::string str(\"Hello\");\nc) std::string str; str = \"Hello\";\nd) std::string str; str(\"Hello\");",
                        {"a) std::string str = \"Hello\";  ", "b) std::string str(\"Hello\");", "c) std::string str; str = \"Hello\";", "d) std::string str; str(\"Hello\");"},
                        'a'
            },
            {
                "What is the purpose of the 'try-catch' block in C++?\n\na) To define a block of code that may throw an exception.\nb) To handle exceptions thrown by a block of code.  \nc) To specify the type of exception that can be thrown.\nd) To define a block of code that is always executed.",
                        {"a) To define a block of code that may throw an exception.", "b) To handle exceptions thrown by a block of code.  ", "c) To specify the type of exception that can be thrown.", "d) To define a block of code that is always executed."},
                        'b'
            }

    };

    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        quiz.addQuestion(questions[i]);
    }

    //return true if question is answered
    if (quiz.askRandomQuestion()){
        return true;
    }
    else {
        return false;
    }

}
