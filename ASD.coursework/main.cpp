#include "EdmondsKarp.h"
#include "reader.h"

int main()
{
	algorithm graph;
	string text = read();
	cout << text << endl << endl;
	graph.input("input.txt");
	cout << "For this graph maximum flow is: ";
	cout << graph.maxflow() << endl;
	return 0;
}