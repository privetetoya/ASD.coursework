#pragma once
#include <fstream>
#include "queue.h"
#include "List.h"
#include "extraList.h"
using namespace std;

class algorithm
{
public:
	struct pair {
		int first;
		long second;
	};
	List<char> listOfVertex;
	extraList<List<int>> capacity;
	extraList<List<int>> adjacent;
	int inf = INT_MAX;

	int maxflow() {
		int maximum_flow = 0;
		List<int> parent(capacity.get_size(), 0);
		int new_flow;
		while (new_flow = bfs(0, listOfVertex.get_size() - 1, parent)) {
			maximum_flow += new_flow;
			int cur = listOfVertex.get_size() - 1;
			while (cur != 0) {
				int prev = parent.at(cur);
				capacity.at(prev).set(cur, capacity.at(prev).at(cur) - new_flow);
				capacity.at(cur).set(prev, capacity.at(cur).at(prev) + new_flow);
				cur = prev;
			}
		}
		return maximum_flow;
	}
	
	void input(string input) {
			ifstream file(input);
			if (!file.is_open())
				throw runtime_error("File was not found");
			int symb_num = 0;
			char symb;
			int cap;
			char firstVertex, secondVertex;
			//Reading the vertexes list
			while (!file.eof()) {
				file >> noskipws >> symb;
				if ((symb_num == 0 || symb_num == 2) && !listOfVertex.contains(symb))
					listOfVertex.push_back(symb);
				symb_num++;
				if (symb == '\n' || file.eof())
					symb_num = 0;
			}

			if (listOfVertex.at(0) != 'S' || listOfVertex.at(listOfVertex.get_size() - 1) != 'T')
				throw invalid_argument("Graph should start with S and ended with T");

			file.clear();
			file.seekg(0);
			List<int> temp;

			for (int i = 0; i < listOfVertex.get_size(); i++) {
				for (int j = 0; j < listOfVertex.get_size(); j++)
					temp.push_back(0);
				capacity.push_back(temp);
				temp.reset();
			}

			//Reading the avaliable capacity
			while (!file.eof())
			{
				if (symb_num != 4) {
					file >> noskipws >> symb;

					if (symb_num == 0)
						firstVertex = symb;

					else if (symb_num == 2)
						secondVertex = symb;
				}	

				else {
					file >> cap;
					capacity.at(listOfVertex.get_index((char)firstVertex)).set(listOfVertex.get_index((char)secondVertex), cap);
				}
				
				symb_num++;
				if (symb == '\n' || file.eof())
					symb_num = 0;
			
			}
			
			for (int i = 0; i < capacity.get_size(); i++) {
				temp.reset();
				for (int j = 0; j < capacity.at(i).get_size(); j++) {
					temp.push_back(capacity.at(i).at(j));
				}
				adjacent.push_back(temp);
			}

			for (int i = 0; i < adjacent.get_size(); i++) {
				for (int j = i; j < adjacent.at(i).get_size(); j++) {
					adjacent.at(j).set(i, adjacent.at(i).at(j));
				}
			}


			temp.reset();

			List<int> parent(capacity.get_size(), 0);

	}

	int bfs(int source, int sink, List<int>& parent) { //breadth-first search
		for (int i = 0; i < parent.get_size(); i++)
			parent.set(i, -1);
		parent.set(source, -2);
		queue_like <pair> queue;
		queue.enqueue({ source, inf });
		while (queue.get_size() != 0) {
			int cur = queue.peek().first;
			int flow = queue.peek().second;
			queue.dequeue();

			for (int next = 0; next < adjacent.at(cur).get_size(); next++) {
				if (parent.at(next) == -1 && capacity.at(cur).at(next)) {
					parent.set(next, cur);
					int new_flow;
					if (capacity.at(cur).at(next) < flow)
						new_flow = capacity.at(cur).at(next);
					else
						new_flow = flow;
					if (next == sink)
						return new_flow;
					queue.enqueue({ next, new_flow });
				}
			}
		}
		return 0;
	}
};