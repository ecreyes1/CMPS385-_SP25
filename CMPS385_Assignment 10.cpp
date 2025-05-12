#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<set>
using namespace std;
class Graph {
private:
	map<char, list<char>>adjList;
public:
	void addEdge(char src, char dest) {
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);

	}
	void bfs(char start)
	{
		set <char> visited;
		queue<char>q;
		cout << "Breath first traversal : ";
		visited.insert(start);
		q.push(start);

		while (!q.empty()) {
			char current = q.front();
			q.pop();
			cout << current << " ";
				for (char neighbor : adjList[current]) {
					if (visited.find(neighbor) == visited.end()) {

						visited.insert(neighbor);
						q.push(neighbor);
					
					}
					
			}
				

		}
		
		cout << endl;
	}
	void dfs(char start)
	{
		set<char>visited;
		stack<char>s;
		cout << "Depth  first traversal:";
		visited.insert(start);
		s.push(start);
		while (!s.empty()) {
			char current = s.top();
			cout << current << " ";
			bool foundUnvisited = false;
			for (char neighbor : adjList[current])
			{
				if (visited.find(neighbor) == visited.end())
				{
					visited.insert(neighbor);
					s.push(neighbor);
					foundUnvisited = true;
					break;
				}

			}
			if (!foundUnvisited)
			{
				s.pop();

			}
		}
		cout << endl;



		}

	
};
int main() {
	Graph g;
	g.addEdge('E', 'C');
	g.addEdge('E', 'R');
	g.addEdge('J', 'M');
	g.addEdge('A', 'L');
	g.bfs('E');
	g.dfs('E');
	system("pause");
	return 0;
}
