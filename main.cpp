#include<iostream>

using namespace words, std;

int main(int argc, char *argv[]) {
        Trie T(26);
        string word, longest_word, second_longest_word;
        ifstream myfile, myfile1;
        int cnt = 0, cnt1 = 0, max_length = 0, second_max_length = 0;
        myfile.open("words.txt");
        for (string word; getline(myfile, word);) {
                T.insert_in_trie(word);
        }
        myfile.close();

        myfile1.open("words.txt");
        for (string word; getline(myfile1, word);) {
                cnt1++;
                if (*word.rbegin() == '\r') {
                        word.erase(word.length() - 1);
                }
                if (T.traverse1(word, word.length())) {
                        cnt++;
                        if (max_length < word.length()) {
                                second_max_length = max_length;
                                second_longest_word = longest_word;

                                max_length = word.length();
                                longest_word = word;
                        }
                        else {
                                if (second_max_length <= word.length()) {
                                        second_max_length = word.length();
                                        second_longest_word = word;
                                }
                        }
                }
        }
        cout << "Total words: " << cnt1 << endl;
        cout << "Total composite words: " << cnt << endl << endl;
        cout << "1st Longest word: " << longest_word << " Length: " << max_length << endl;
        cout << "2nd Longest word: " << second_longest_word << " Length: " << second_max_length << endl;
        return 0;
}
