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

        // checks if the char already exist in the array
        bool containsCh(char ch){
            return (links[ch-'a']!= NULL);
        }

        // inserting nodes(of char) to array
        void insertCh(char ch, Node* node){
            links[ch-'a'] = node;
        }


        // moving to the next reference node
        Node* get(char ch){
            return links[ch-'a'];
        }

        // set the ending node
        void setEnd(){
            flag = true;
        }


        // getting the node's flag value
        bool isEnd(){
            return flag;
        }
};


class Trie{
    private:
        Node* root;

    public:
        // creating the trie node
        Trie(){
            root = new Node();
        }


        // inserting in the trie
        void insert(string word){

            // starting from the root
            Node* node = root;

            for(int i=0; i<word.length(); i++){
                if(!node->containsCh(word[i])){

                    // if the character doesn't exist in the array, insert it in ch-'a' index.
                    node->insertCh(word[i], new Node());

                }
                // moving on to the referenced node
                node = node->get(word[i]);
            }
            // setting an end to the node
            node->setEnd();
        }

        // Searching for element in the trie
        bool search(string word){

            Node* node = root;

            for(int i=0; i<word.length(); i++){
                if(!node->containsCh(word[i])){
                    return false;
                }
                node = node->get(word[i]);
            }
            return node->isEnd();
        }

        // checking if there is a prefix
        bool prefix(string word){

            Node* node = root;

            for(int i=0; i<word.length(); i++){
                if(!node->containsCh(word[i])){
                    return false;
                }
                node = node->get(word[i]);
            }
            return true;
        }


};



int main() {
    
    Trie myTrie;

    
    // insert to the trie
    myTrie.insert("apple");
    myTrie.insert("apps");
    myTrie.insert("apxl");
    myTrie.insert("bac");
    myTrie.insert("bat");


    // searching elem in the trie
    myTrie.search("apple")? cout<<"True"<<endl : cout<<"False"<<endl;
    myTrie.search("bax")? cout<<"True"<<endl : cout<<"False"<<endl;
    myTrie.search("apples")? cout<<"True"<<endl : cout<<"False"<<endl;
    myTrie.search("aple")? cout<<"True"<<endl : cout<<"False"<<endl;
    myTrie.search("apxl")? cout<<"True"<<endl : cout<<"False"<<endl;


    // searching fro prefix
    myTrie.prefix("app")? cout<<"True"<<endl : cout<<"False"<<endl;
    myTrie.prefix("apps")? cout<<"True"<<endl : cout<<"False"<<endl;
    myTrie.prefix("apl")? cout<<"True"<<endl : cout<<"False"<<endl;
    myTrie.prefix("ba")? cout<<"True"<<endl : cout<<"False"<<endl;
    myTrie.prefix("ax")? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}