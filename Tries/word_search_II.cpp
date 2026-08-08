#include <iostream>
#include <vector>
using namespace std;

vector<string> result;
int m, n;

struct trieNode{
  bool endOfWord;
  string word;
  trieNode* children[26];
};

trieNode* getNode(){
  trieNode* newNode = new trieNode();
  newNode->endOfWord = false;
  newNode->word = "";
  for(int i=0; i<26; i++){
    newNode->children[i] = NULL;
  }
  return newNode;
}

void insert(trieNode* root, string& word){
  trieNode* crawler = root;
  for(int i=0; i<word.length(); i++){
    char ch = word[i];
    if(crawler->children[ch - 'a'] == NULL){
      crawler->children[ch-'a'] = getNode();
    }
    crawler = crawler->children[ch - 'a'];
  }
  crawler->endOfWord = true;
  crawler->word = word;
}

vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void findTrieWord(vector<vector<char>>& board, int i, int j, trieNode* root){
  if(i<0 || i>=m || j<0 || j>=n){
    return;
  }
  if(board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL){
    return;
  }
  root = root->children[board[i][j]-'a'];
  if(root->endOfWord == true){
    result.push_back(root->word);
    root->endOfWord = false;
  }
  char temp = board[i][j];
  board[i][j] = '$';
  for(vector<int>& dir: directions){
    int new_i = i + dir[0];
    int new_j = j + dir[1];
    findTrieWord(board, new_i, new_j, root);
  }
  board[i][j] = temp;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  m = board.size();
  n = board[0].size();
  trieNode* root = getNode();
  for(string& word: words){
    insert(root, word);
  }

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      char ch = board[i][j];
      if(root->children[ch-'a'] != NULL){
        findTrieWord(board, i, j, root);
      }
    }
  }
  return result;
}


int main() {
  vector<vector<char>> board1 = {
    {'o','a','a','n'},
    {'e','t','a','e'},
    {'i','h','k','r'},
    {'i','f','l','v'}
  };
  vector<string> words1 = {"oath", "pea", "eat", "rain"};
  vector<string> result1 = findWords(board1, words1);
  cout << "Test 1 results:";
  for (auto& word : result1) {
    cout << " " << word;
  }
  cout << "\n";

  vector<vector<char>> board2 = {
    {'a','b'},
    {'c','d'}
  };
  vector<string> words2 = {"ab", "cb", "ad", "bd", "ac", "ca"};
  vector<string> result2 = findWords(board2, words2);
  cout << "Test 2 results:";
  for (auto& word : result2) {
    cout << " " << word;
  }
  cout << "\n";

  return 0;
}