#include <vector>

struct Vector2
{
	float	x;
	float	y;
};

class Graph
{
	private:
		Vector2 size;
		std::vector<Vector2> points;

	public:
		Graph(Vector2 size);
		void addPoint(Vector2 point);
		void printGraph();
};