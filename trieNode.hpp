
namespace words
{


        class TrieNode
        {
        public:
                bool word_end;
                int no_of_children;
                std::vector<TrieNode *> children;
                TrieNode(int arity);
        };

}
