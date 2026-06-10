#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
        Node* links[26];
        bool flag = false;


        Node(){
            for(auto& ptr: links){
                ptr = nullptr;
            }
        }


        bool containsCh(char ch){
            return (links[ch-'a']!= NULL);
        }


        void insertCh(char ch, Node* node){
            links[ch-'a'] = node;
        }


        Node* get(char ch){
            return links[ch-'a'];
        }


        void setEnd(){
            flag = true;
        }


        bool isEnd(){
            return flag;
        }
};


class Trie{
    private:
        Node* root;

    public:
     
        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node* node = root;
            for(int i=0; i<word.length(); i++){
                if(!node->containsCh(word[i])){
                    node->insertCh(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }

        vector<string> sort(){
            string name = "";
            vector<string> sorted;
            preOrder(root, name, sorted);
            return sorted;
        }


    
    private:
        void preOrder(Node* node, string& currName, vector<string>& sortedNames){
            if(node->isEnd()){
                sortedNames.emplace_back(currName);
            }

            for(int i=0; i<26; i++){
                if(node->links[i]!= nullptr){
                    char ch = i + 'a';
                    currName.push_back(ch);

                    preOrder(node->links[i], currName, sortedNames);

                    currName.pop_back();
                }
            }
            
        }


};



int main() {
    
    Trie myTrie;

    string names[] = {"dipankar", "amlan", "gitartha", "tuniba", "tonmoy", "raimalu", "abishek", "jutikha", "tuljit", "rima"};

    for(auto& name: names){
        myTrie.insert(name);
    }

    vector<string> sortedNames = myTrie.sort();

    for(auto& name: sortedNames){
        cout<<name<<endl;
    }
    

    return 0;
}