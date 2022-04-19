# Data-Structures-and-Algorithms

## Introduction

Writing a C++ Console application which reads sgm files that consists of archieves of newspapers. The program must be able to processing individual words from sgm file.

After reading and processing is over, The 10 most repetitive words and the number of repetitions will be calculated in the texts.


## Methods
We used C++ as a programming language and the libraries that we used are C++ STL iostream, string, cstring, fstream, and ctime for calculating the runtime of the code. We did not use any third party library. We used the string matching method to split the words.


## Testing System
We have run the algorithm many times to calculate the average runtime of the algorithm. The CPU that we utilized is **AMD Ryzen™5 3500X 3.6GHz 32MB 65W 7nm (6CPUs)**.

## Testing

### inputs :
`Reuters-21578/stopwords.txt` and `Reuters-21578/*.sgm` files

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
