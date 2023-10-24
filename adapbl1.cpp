
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
 
#define EMPTY_STRING ""
 
void decode(Node* root, int &index, string str)
{
    if (root == nullptr) {
        return;
    }
 
    if (isLeaf(root))
    {
        cout << root->ch;
        return;
    }
 
    index++;
 
    if (str[index] == '0') {
        decode(root->left, index, str);
    }
    else {
        decode(root->right, index, str);
    }
}

void build(string text)
{
   
    if (text == EMPTY_STRING) {
        return;
    }

    unordered_map<char, int> freq;
    for (char ch: text) {
        freq[ch]++;
    }
 
    priority_queue<Node*, vector<Node*>, comp> pq;
 
    for (auto pair: freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
 
    while (pq.size() != 1)
    {
    
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top();    pq.pop();
 
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }
 
    Node* root = pq.top();
 
    
    unordered_map<char, string> huffmanCode;
    encode(root, EMPTY_STRING, huffmanCode);
 
    cout << "Huffman Codes are:\n" << endl;
    for (auto pair: huffmanCode) {
        cout << pair.first << " " << pair.second << endl;
    }
 
    cout << "\nThe original string is:\n" << text << endl;
 
    
    string str;
    for (char ch: text) {
        str += huffmanCode[ch];
    }
 
    cout << "\nThe encoded string is:\n" << str << endl;
    cout << "\nThe decoded string is:\n";
 
    if (isLeaf(root))
    {
       
        while (root->freq--) {
            cout << root->ch;
        }
    }
    else {
        
        int index = -1;
        while (index < (int)str.size() - 1) {
            decode(root, index, str);
        }
    }
} 
int main()
{
    char str[100];
    cout<< "Enter the string";
    cout<<"\n";
    cin>>str;

    build(str);
 
    return 0;
}
