#ifndef GENERICSHAPE_HPP
#define GENERICSHAPE_HPP

#include "Shapes.hpp"

enum DataTypes
{
  tcircle,
  tsquare,
  ttriangle,
  tsphere,
  ttetra,
  tcube
};

class GenericShape
{
private:
  void *m_shape;
  DataTypes m_dataType;

public:
  GenericShape(Circle v);
  GenericShape(Square v);
  GenericShape(Sphere v);
  GenericShape(Tetrahedron v);
  GenericShape(Triangle v);
  GenericShape(Cube v);

  float getArea();
  std::string getType();

  ~GenericShape();
};

#endif // GENERICSHAPE_HPP