#include "GenericShape.hpp"

std::vector<std::string> dataTypesStr{"circle", "square", "triangle", "sphere", "tetrahedron", "cube"};

GenericShape::GenericShape(Circle v)
{
  m_shape = new Circle(v);
  m_dataType = tcircle;
}

GenericShape::GenericShape(Square v)
{
  m_shape = new Square(v);
  m_dataType = tsquare;
}

GenericShape::GenericShape(Sphere v)
{
  m_shape = new Sphere(v);
  m_dataType = tsphere;
}

GenericShape::GenericShape(Tetrahedron v)
{
  m_shape = new Tetrahedron(v);
  m_dataType = ttetra;
}

GenericShape::GenericShape(Triangle v)
{
  m_shape = new Triangle(v);
  m_dataType = ttriangle;
}

GenericShape::GenericShape(Cube v)
{
  m_shape = new Cube(v);
  m_dataType = tcube;
}

float GenericShape::getArea()
{
  switch (m_dataType)
  {
  case tcircle:
    return ((Circle *)m_shape)->getArea();
    break;
  case tsquare:
    return ((Square *)m_shape)->getArea();
    break;
  case ttriangle:
    return ((Triangle *)m_shape)->getArea();
    break;
  case tsphere:
    return ((Sphere *)m_shape)->getArea();
    break;
  case tcube:
    return ((Cube *)m_shape)->getArea();
    break;
  case ttetra:
    return ((Tetrahedron *)m_shape)->getArea();
    break;
  }
}

std::string GenericShape::getType()
{
  return dataTypesStr.at(m_dataType);
}

GenericShape::~GenericShape()
{
  switch (m_dataType)
  {
  case tcircle:
    delete (Circle *)m_shape;
    break;
  case tsquare:
    delete (Square *)m_shape;
    break;
  case ttriangle:
    delete (Triangle *)m_shape;
    break;
  case tsphere:
    delete (Sphere *)m_shape;
    break;
  case tcube:
    delete (Cube *)m_shape;
    break;
  case ttetra:
    delete (Tetrahedron *)m_shape;
    break;
  }
}