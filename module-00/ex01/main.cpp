#include "graph.hpp"

int main(void)
{
	Vector2 size = {10, 10};
	Graph graph(size);

	Vector2 point1 = { 2, 2 };
	Vector2 point3 = { 7, 7 };

	graph.addPoint(point3);
	graph.addPoint(point1);


	graph.printGraph();
	return (0);
}