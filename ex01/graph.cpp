#include "graph.hpp"

Graph::Graph(Vector2 size) : size(size)
{
}

void Graph::addPoint(Vector2 point)
{
	this->points.push_back(point);
}

void Graph::printGraph()
{
	char **graph = new char *[size.y];
	for (int i = 0; i < size.y; i++)
	{
		graph[i] = new char[size.x];
		for (int j = 0; j < size.x; j++)
			graph[i][j] = '.';
	}
	for (Vector2 point : points)
	{
		int x = point.x;
		int y = point.y;
		if (x >= 0 && x < size.x && y >= 0 && y < size.y)
			graph[y][x] = 'X';
	}
	for (int i = 0; i < size.y; i++)
	{
		for (int j = 0; j < size.x; j++)
			std::cout << graph[i][j];
		std::cout << std::endl;
	}
}