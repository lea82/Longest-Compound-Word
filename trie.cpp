#include "trie.h"

namespace words
{
        Trie :: Trie(int n) {
                arity = n;
                root = new TrieNode(arity);
        }

        void
        Trie :: insert_in_trie(string word) {
                TrieNode *r = root;
                if (*word.rbegin() == '\r') {
                        word.erase(word.length() - 1);
                }
                string :: iterator i = word.begin();
                for (;i != word.end(); ++i) {
                        char c = *i;
                        int index = c - 'a';

                        if (r -> children[index] == NULL) {
                                r -> children[index] = new TrieNode(arity);
                        }
                        r = (TrieNode *)r -> children[index];
                }
                if (!r -> word_end)
                        r -> word_end = true;
        }

        bool
        Trie :: traverse1(string word, int word_length) {
                TrieNode *r = root;
                int cnt = 0;
                if (word.empty())
                        return true;
                if (*word.rbegin() == '\r') {
                        word.erase(word.length() - 1);
                }

                string :: iterator i = word.begin();
                while (i != word.end()) {
                        char chr = *i;
                        int index = chr - 'a';
                        r = r -> children[index];
                        if (r != NULL) {
                                if (r -> word_end) {
                                        string suffix = string(word, cnt + 1);
                                        if (traverse1(suffix, word_length)) {
                                                if (word.length() != word_length) {
                                                        return true;
                                                } else if (suffix.length() == 0) {
                                                        return false;
                                                } else {
                                                        return true;
                                                }
                                        }
                                }
                        }
                        else {
                                return false;
                        }
                        i++;
                        cnt++;
                }
                if (!(r -> word_end)) {
                        return false;
                }
        }
}
