#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "GenericShape.hpp"
#include "Shapes.hpp"

using namespace std;

int main()
{
  vector<GenericShape *> shapes;

  string path;
  cin >> path;

  ifstream input(path);
  if (!input.is_open())
  {
    cout << "Erro, arquivo não foi encontrado" << endl;
    return 1;
  }

  string str;
  while (getline(input, str))
  {
    if (str == "circle")
    {
      getline(input, str);

      float radius = stod(str);
      shapes.push_back(new GenericShape(Circle(radius)));
    }
    else if (str == "square")
    {
      getline(input, str);

      float side = stod(str);
      shapes.push_back(new GenericShape(Square(side)));
    }
    else if (str == "triangle")
    {
      vector<Point2D> points;
      vector<float> sides;

      for (size_t i = 0; i < 3; i++)
      {
        getline(input, str);

        if (str.find(",") != string::npos)
        {
          Point2D point;
          stringstream ss(str);

          getline(ss, str, ',');

          point.x = stod(str);

          getline(ss, str, ',');

          point.y = stod(str);

          points.push_back(point);
        }
        else
        {
          sides.push_back(stod(str));
        }
      }

      if (points.size() == 0)
      {
        shapes.push_back(new GenericShape(Triangle(sides.at(0), sides.at(1), sides.at(2))));
      }
      else
      {
        shapes.push_back(new GenericShape(Triangle(points.at(0), points.at(1), points.at(2))));
      }
    }
    else if (str == "sphere")
    {
      getline(input, str);

      float radius = stod(str);
      shapes.push_back(new GenericShape(Sphere(radius)));
    }
    else if (str == "cube")
    {
      getline(input, str);

      float side = stod(str);
      shapes.push_back(new GenericShape(Cube(side)));
    }
    else if (str == "tetrahedron")
    {
      vector<Point3D> points;

      for (size_t i = 0; i < 4; i++)
      {
        getline(input, str);

        stringstream ss(str);
        Point3D point;

        getline(ss, str, ',');
        point.x = stod(str);

        getline(ss, str, ',');
        point.y = stod(str);

        getline(ss, str, ',');
        point.z = stod(str);

        points.push_back(point);
      }

      shapes.push_back(new GenericShape(Tetrahedron(points.at(0), points.at(1), points.at(2), points.at(3))));
    }
  }

  for (size_t i = 0; i < shapes.size(); i++)
  {
    string type(shapes.at(i)->getType());

    if (shapes.at(i)->getArea() == 0)
      cout << "Object #" << i << " is " << type << " -> "
           << "nan" << endl;
    else
      cout << "Object #" << i << " is " << type << " -> " << fixed << setprecision(2) << shapes.at(i)->getArea() << endl;

    delete shapes.at(i);
  }

  return 0;
}