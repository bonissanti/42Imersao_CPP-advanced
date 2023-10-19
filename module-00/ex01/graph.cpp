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
	for (int i = this->size.y - 1; i >= 0; i--)
	{
		std::cout << i << " ";
		for (int j = 0; j < this->size.x; j++)
		{
			bool found = false;
			for (std::vector<Vector2>::iterator it = this->points.begin(); it != this->points.end(); ++it)
			{
				if (it->x == j && it->y == i)
				{
					std::cout << " X ";
					found = true;
					break;
				}
			}
			if (!found)
				std::cout << " . ";
		}
		std::cout << std::endl;
	}
	std::cout << " ";
	for (int i = 0; i < this->size.x; i++)
		std::cout << "  " << i;
	std::cout << std::endl;
}
