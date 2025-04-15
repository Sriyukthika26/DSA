#include<bits/stdc++.h>
using namespace std;

class node{
public:
	char ch;
	int freq;
	node *left; node* right;	
	node(char ch, int freq, node* l , node* r){
		this->ch = ch;
		this->freq = freq;
		left = l; right = r;
	}
};

class comp{
public:
	bool operator()(node* n1, node* n2){
		return (n1->freq > n2->freq);
	}
};

void encode(node* root, string str, unordered_map<char, string>& huffman){
	if(root==NULL) return;
	
	if(!root->left && !root->right){
		huffman[root->ch] = str;
	}
	
	encode(root->left, str+'0', huffman);
	encode(root->right, str+'1', huffman);
	
}
void decode(node* root, int& topidx, string code){
	if(root==NULL) return;
	if(!root->left && !root->right){
		cout<<root->ch;
		return;
	}
	topidx++;
	if(code[topidx]=='0'){
		decode(root->left, topidx,code);
	}
	else{
		decode(root->right, topidx, code);
	}
}
void Huffman(string s){
	unordered_map<char, int>freq;
	for(auto ch: s){
		freq[ch]++;
	}
	priority_queue<node*, vector<node*> , comp>minheap;
	for(auto it: freq){
		node* temp = new node(it.first, it.second, NULL, NULL);
		minheap.push(temp);
	}
	
	while(minheap.size()!= 1){
		node* left = minheap.top();
		minheap.pop();
		node* right = minheap.top();
		minheap.pop();
		int sum = left->freq + right->freq;
		node* top = new node('\0', sum, left, right);
		minheap.push(top);
	}
	node* root = minheap.top();
	
	unordered_map<char, string>huffman;
	encode(root, "", huffman);
	cout<<"huffman codes : "<<"\n";
	for(auto it: huffman){
		cout<<it.first<<" "<<it.second<<"\n";
	}
	cout<<"Original text: "<<"\n";
	
	for(auto it: s){
		cout<<it;
	}
	cout<<"\n";
	string code  ="";
	for(auto it:s){
		code+= huffman[it];
	}
	cout<<"Compressed encoding"<<"\n";
	cout<<code<<"\n";
	int topidx = -1;
	cout<<"Decoding string: "<<"\n";
	while(topidx < (int)code.size()-2){
		decode(root, topidx, code);
	}
	cout<<"\n";
	cout<<"compressed ratio: "<<"\n";
	int input = s.size()*8;
	int output=0;
	for(auto it:freq){
		string temp = huffman[it.first];
		int sz = temp.size();
		output+=(it.second*sz);
		output+=8;
		output+=sz;		
	}
	cout<<input<<" "<<output<<"\n";
	cout<<ceil(input/output)<<"\n";
}

int main(){
	string s = "AABCDSGFGHDYTFGIUHIL";
	Huffman(s);
	
	
}
