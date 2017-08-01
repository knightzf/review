#include <iostream>
#include <vector>
#include <deque>

const int ALPHABETSIZE = 26;

struct Trie
{
	Trie():
		children{0},
		weight(-1),
		maxWeight(-1)
	{
	}
	
	Trie* children[ALPHABETSIZE];
	int weight;
	int maxWeight;
};

Trie* ROOT = new Trie();

void buildDict(const std::string& word, int weight)
{
	Trie* root = ROOT;
	
	for(size_t i = 0, sz = word.size(); i < sz; ++i)
	{
		char c = word[i];
		if(!root->children[c - 'a'])
		{
			root->children[c - 'a'] = new Trie();
		}
		
		root->maxWeight = std::max(root->maxWeight, weight);
	
		root = root->children[c - 'a'];
		
		if(i == sz - 1)
		{
			root->weight = weight;
		}
	}
}

int maxWeight(Trie* children[ALPHABETSIZE])
{
	int max = -1;
	for(int i = 0; i < ALPHABETSIZE; ++i)
	{
		if(children[i])
		{
			max = std::max(max, std::max(children[i]->weight, maxWeight(children[i]->children)));
		}
	}
	
	return max;
}

int maxWeight(Trie* node)
{
	int result = -1;
	
	std::deque<Trie*> queue;
	queue.push_back(node);
	
	while(!queue.empty())
	{
		Trie* front = queue.front();
		result = std::max(result, front->weight);
		for(int i = 0; i < ALPHABETSIZE; ++i)
		{
			if(front->children[i])
			{
				queue.push_back(front->children[i]);
			}
		}
		
		queue.pop_front();		
	}
	
	return result;
}

void getResult(const std::string& input, std::vector<int>& resultVec)
{
	int result = -1;
	
	Trie* root = ROOT;
	
	for(size_t i = 0, sz = input.size(); i < sz; ++i)
	{
		char c = input[i];
		if(!root->children[c - 'a'])
		{
			break;
		}
		
		root = root->children[c - 'a'];
		
		//look for max weight
		if(i == sz -1)
		{
			//result = std::max(root->weight, maxWeight(root->children));
			//result = maxWeight(root);
			result = root->maxWeight;
			break;
		}		
	}
	
	resultVec.push_back(result);
}

int main()
{
	int numEntries = 0;
	int numInputs = 0;
	
	std::cin >> numEntries >> numInputs;
	
	for(int i = 0; i < numEntries; ++i)
	{
		std::string word;
		int weight = 0;
		std::cin >> word >> weight;
		buildDict(word, weight);
	}
		
	std::vector<int> resultVec;
	
	for(int i = 0; i < numInputs; ++i)
	{
		std::string input;
		std::cin >> input;
		getResult(input, resultVec);
	}
	
	for(auto result : resultVec)
	{
		std::cout<<result<<std::endl;
	}
}