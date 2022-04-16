#include <iostream>
#include <ctime> 
#include <fstream>
#include <string>

using namespace std;

class words {
public:
    string word = "";
    int count = 0;

    void setword(string a) {
        this->word = a;
        this->count = 1;
    }
    void setcount(int a) {
        this->count = a;
    }
    void countpp() {
        this->count++;
    }

};

string pick(string s) {
    char p[60];
    string text = "";
    int i;
    for (i = 0; i < s.length(); i++) {
        p[i] = s[i];
        if (60 < p[i] && p[i] < 91) { //if it has bigger uppercase letter then return lower case
            p[i] = p[i] + 32;
        }
        if ((32 < p[i] && p[i] < 48) || (57 < p[i] && p[i] < 65)) { //if it has symbol then return nothing
        }
        else {
            text = text + p[i];
        }
        if (47 < p[i] && p[i] < 58) { //if it has number then return x
            text = "x";
            break;
        }
    }
    return text;
}

words top10[10];

void swipeandadd(int x, int y, string a) {
    int member1 = top10[x].count;
    string member1a = top10[x].word;
    int member2 = top10[x + 1].count;
    string member2a = top10[x + 1].word;
    int i = x;
    for (i = x; i < 9; i++) {
        member2 = top10[i + 1].count;
        member2a = top10[i + 1].word;
        top10[i + 1].count = member1;
        top10[i + 1].word = member1a;
        member1 = member2;
        member1a = member2a;
    }
    top10[x].count = y;
    top10[x].word = a;
}

int limit = -1;
int altlimit = 0;
int countofword = 0;
string stopwords[572];
words arr[25000];
void addword(string x) {
    x = pick(x);
    if (x != "x") { //if x has a number
        bool istherestop = false;
        for (int s = 0; s < 572; s++) {
            if (stopwords[s] == x) {
                istherestop = true;
                break;
            }
        }
        if (istherestop) {
        }
        else if (x != "") {
            bool found = false;
            altlimit = countofword;
            for (int i = 0; i < countofword; i++) {
                if (arr[i].count < limit) {
                    altlimit = i;
                }
                if (arr[i].word == x) {
                    arr[i].countpp();
                    found = true;
                    break;
                }
            }
            if (!found) {
                arr[altlimit].setword(x);
                if (altlimit == countofword) {
                    countofword++;
                }
            }
        }
    }
}

int main() {
    clock_t baslangic = clock(), bitis;
    string x;
    bool key = false;
    string bodyin = "<BODY>";
    string bodyout = "</BODY>";
    ifstream inputFile2;
    inputFile2.open("Reuters-21578/stopwords.txt");
    int stopi = 0;
    while (inputFile2) {
        inputFile2 >> x;
        stopwords[stopi] = pick(x);
        stopi++;
    }
    ifstream inputFile;

    for (int d =21; d >-1; d--) {
        string dosya;
        altlimit = 0;
        if (d < 10) {
            dosya = "0" + to_string(d);
        }
        else {
            dosya = to_string(d);
        }
        inputFile.open("Reuters-21578/reut2-0" + dosya + ".sgm");
        while (inputFile) {
            inputFile >> x;
            if (strstr(x.c_str(), bodyout.c_str()))
            {
                key = false;
                addword(pick(x.substr(0, (x.find("</BODY>") + 6))));
            }
            if (key) {
                if (d < 21) {
                    limit = 50;
                }
                    if (strstr(x.c_str(), "/")) {

                        while (strstr(x.c_str(), "/")) {
                            addword(x.substr(0, x.find("/")));
                            x = x.substr(x.find("/") + 1, x.length());
                        }
                        addword(x);

                    }
                    else if (strstr(x.c_str(), "-")) {
                        while (strstr(x.c_str(), "-")) {
                            addword(x.substr(0, x.find("-")));
                            x = x.substr(x.find("-") + 1, x.length());
                        }
                        addword(x);

                    }
                    else {
                        addword(x);
                    }
            }
            if (strstr(x.c_str(), bodyin.c_str()))
            {
                key = true;
                addword(pick(x.substr((x.find("<BODY>") + 6), x.length()))); //substr(a,b)
            }
        }
        inputFile.close();
    }

    for (int i = countofword - 1; i > -1; i--) {
        for (int j = 0; j < 10; j++) {
            if (int(arr[i].count) > int(top10[j].count)) {
                swipeandadd(j, arr[i].count, arr[i].word);
                break;
            }
        }
    }

    cout << "Top 10 List :" << endl << endl;
    for (int i = 0; i < 10; i++) {
        cout << i+1 << "- " << top10[i].word << " - " << top10[i].count << endl;
    }
    bitis = clock();
    std::cout << endl << "Total Elapsed Time: " << (float)(bitis - baslangic) / CLOCKS_PER_SEC << "s\n";
}
