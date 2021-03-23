#ifndef SHAPES_HPP
#define SHAPES_HPP
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <ctgmath>

struct Point2D
{
  float x;
  float y;
};

struct Point3D
{
  float x;
  float y;
  float z;
};

class Circle
{
private:
  float m_ratio;

public:
  Circle(float ratio) { m_ratio = ratio; };

  float getArea();
};

class Square
{
private:
  float m_edge;

public:
  Square(float edge) { m_edge = edge; };

  float getArea();
};

class Triangle
{
private:
  float m_l1 = 0, m_l2 = 0, m_l3 = 0;
  Point2D m_pA, m_pB, m_pC;
  
  bool m_isConstructedByPoints = false;

public:
  Triangle(float l1, float l2, float l3) { m_l1 = l1, m_l2 = l2, m_l3 = l3; };
  Triangle(Point2D p1, Point2D p2, Point2D p3)
  {
    m_pA = p1, m_pB = p2, m_pC = p3;
    m_isConstructedByPoints = true;
  };

  float getArea();
};

class Sphere
{
private:
  float m_ratio;

public:
  Sphere(float ratio) { m_ratio = ratio; };

  float getArea();
};

class Tetrahedron
{
private:
  Point3D m_pA, m_pB, m_pC, m_pD;

public:
  Tetrahedron(Point3D p1, Point3D p2, Point3D p3, Point3D p4)
  {
    m_pA = p1;
    m_pB = p2;
    m_pC = p3;
    m_pD = p4;
  };

  float getArea();
};

class Cube
{
private:
  float m_edge;

public:
  Cube(float edge) { m_edge = edge; };

  float getArea();
};

#endif