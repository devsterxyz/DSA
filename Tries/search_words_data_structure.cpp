#include <iostream>
#include <string>
using namespace std;


struct trieNode{
  trieNode* children[26];
  bool isEndOfWord;
};

trieNode* getNode(){
  trieNode* newNode = new trieNode();
  newNode->isEndOfWord = false;
  for(int i=0; i<26; i++){
    newNode->children[i] = NULL;
  }
  return newNode;
}

trieNode* root;

void WordDictionary() {
  root = getNode();
}
    
void addWord(string word) {
  trieNode* crawler = root;
  for(int i=0; i<word.length(); i++){
    int index = word[i] - 'a';
    if(!crawler->children[index]){
      crawler->children[index] = getNode();
    }
    crawler = crawler->children[index];
  }
  crawler->isEndOfWord = true;
}

bool searchUtil(trieNode* root, string word){
  trieNode* crawler = root;
  for(int i=0; i<word.length(); i++){
    char ch = word[i];
    if(ch == '.'){
      for(int j=0; j<26; j++){
        if(crawler->children[j] != NULL){
          if(searchUtil(crawler->children[j], word.substr(i+1))){
            return true;
          }
        }
      }
      return false;
    }
    else if(crawler->children[ch - 'a'] == NULL){
      return false;
    }
    crawler = crawler->children[ch - 'a'];
  }
  return (crawler != NULL && crawler->isEndOfWord == true);
}
    
bool search(string word) {
  return searchUtil(root, word);
}




int main() {


  WordDictionary();

  addWord("bad");
  addWord("dad");
  addWord("mad");

  cout << boolalpha;
  cout << "search(\"pad\"): " << search("pad") << endl;
  cout << "search(\"bad\"): " << search("bad") << endl;
  cout << "search(\".ad\"): " << search(".ad") << endl;
  cout << "search(\"b..\"): " << search("b..") << endl;

  return 0;
}