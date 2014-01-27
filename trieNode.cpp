#include "trieNode.h"

namespace words
{

        TrieNode :: TrieNode(int arity) {
                word_end = false;
                no_of_children = arity;
                for (int i = 0; i < no_of_children; i++) {
                        children.push_back(NULL);
                }
        }

}
