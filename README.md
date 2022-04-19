# Data-Structures-and-Algorithms

## Introduction

Writing a C++ Console application which reads sgm files that consists of archieves of newspapers. The program must be able to processing individual words from sgm file.

After reading and processing is over, The 10 most repetitive words and the number of repetitions will be calculated in the texts.

In this project we construct a simple question answering system. We implement a program which displays an answer for any question such as in the given text questions. Two input files used in our algorithm. First one which includes a text, and second one containing questions. While our program is executed, it automatically generates an answer for each question in the questions.txt file using the the_truman_show_script.txt file as main text. Our program outputs to the console in this way, first giving the question with the number of that and then the answer below the question.

## Methods
We used C++ as a programming language and the libraries that we used are C++ STL iostream,string, unordered_map, fstream, and ctime for calculating the runtime of the code. We did not use any third party library. For the searching part we used Horspool's Algorithm method. We used the string matching method to split the words.

### Algorthim’s step by step implementation is shown below:
- Read one by one by splitting the sentences in the_truman_show_script.txt" by dot.
- Read one by one by splitting the questions in questions.txt" by question mark.
- Keep questions and sentences in global arrays for use in oops and functions.
- Split question by question pattern (Wh- array).
- Scan with Horspool’s Algorithm the parts of the divided uestion by decrementing the words until you find them in he sentences.
- Also, for a better search, the horspool algorithm we use ompares the parameters it receives by reducing them to owercase.
- Give the answer by finding and parsing in the sentence he words in the question and the extra words (in arrays).
- Skip to the next question.


## Time Complexity
First of all, we processed the 'the_truman_show_script.txt' file. To complete this, we loop through the text, dividing the sentences in the script between dots. If we say that there are 'm' sentences between two points, the time complexity will be O(m). After that, we processed the questions. We also divided the questions according to question marks. If we take the
average total number of characters in a question as 'q' and the number of question marks as 'n', we get the time complexity of O(n*q). Then we divide the question according to the question pattern. Let's call the number of new characters in the script 'l'. We used Horspool's Algorithm for each question. The average time complexity of the Horspool Algorithm for a question is O(1). The time complexity of each of our questions separated by question marks is O(n*l). As a result, if we consider the time complexity; O(m) + O(n*q) + O(n*l)'. It would be O(n*l). Our time complexity is O(n*l).

## Average Speed and Correctness of Algorithm
We have run the algorithm 5 times to calculate the average runtime of the algorithm. The CPU that we utilized is **AMD Ryzen™5 3500X 3.6GHz 32MB 65W 7nm (6CPUs)**. In calculating the average speed part we have just answered the given question by project and the algorithm’s runtimes are 0.054s , 0.06s , 0.055s , 0.056s , 0.054s. Then the average is 0,0558 seconds. In the test step, we tried 15 different questions, including the questions of the project and all the question answers were correct. (15/15)

## Testing

### inputs :
`stopwords.txt` and `Reuters-21578/*.sgm` files

### outputs :

in Visual Studio

![image](https://user-images.githubusercontent.com/54783062/163690487-437ed044-b1ce-4113-98e4-eafd2b8e7685.png)

***

in Visual Studio Code (with MinGW x64)
```
Top 10 List :

1- mln - 25564
2- dlrs - 20562
3- reuter - 18914
4- pct - 17067
5- year - 11879
6- billion - 10256
7- cts - 8857
8- company - 8234
9- bank - 6656
10- net - 6063

Total Elapsed Time: 39.7s
```
