Program: To find the longest, second longest & total compound words


Steps to run the program:
g++ compoundWords.cpp -o compoundWords
./compoundWords


Approach:

1. The problem consisted of traversing strings chracter by character. This
   suggested the use of trie (prefix) tree. Trie tree gives a O(m) search-time
   for a word, where 'm' is word length. This program needs to keep track of
   all the valid words in a compound word, which can be done conveniently in trie.

2. To check if a word is a compound word, the program traverses the string
   character by character, till it finds a complete word from the trie. It then
   recursively checks whether the remaining part is also a word OR a compound word.

3. The worst-case time complexity to check whether a word is compound is O(m^2),
   where 'm' is word length. Hence, for 'n' words, the time complexity is O(n.m^2).
   The word length 'm' is very small for a large dataset.
