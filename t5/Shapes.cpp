#include "Shapes.hpp"

float triangleArea(float a, float b, float c)
{
  float p = (a + b + c) / 2;

  return (float)sqrt(p * (p - a) * (p - b) * (p - c));
}

float distanceBetweenTwoPoints3D(Point3D a, Point3D b)
{
  return ((float)sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2)));
}

float Circle::getArea()
{
  return (M_PI * float(pow(m_ratio, 2)));
}

float Square::getArea()
{
  return (pow(m_edge, 2));
}

float Triangle::getArea()
{

  float lAB, lBC, lCA, area, p;

  if (m_isConstructedByPoints)
  {

    lAB = (float)sqrt(pow((m_pA.x - m_pB.x), 2) + pow((m_pA.y - m_pB.y), 2));
    lBC = (float)sqrt(pow((m_pB.x - m_pC.x), 2) + pow((m_pB.y - m_pC.y), 2));
    lCA = (float)sqrt(pow((m_pC.x - m_pA.x), 2) + pow((m_pC.y - m_pA.y), 2));
  }
  else
  {
    lAB = m_l1;
    lBC = m_l2;
    lCA = m_l3;
  }

  p = (lAB + lBC + lCA) / 2;

  area = (float)sqrt(p * (p - lAB) * (p - lBC) * (p - lCA));

  // Com os lados
  // p=(a + b + c) /2
  // area do triangulo = raizquadrada(p(p-a)(p-b)(p-c))

  // Com os pontos geometricos
  // Calcular lados L = raizquadrada((Xa-Xb)^2 + (Ya-Yb)^2);
  // p=(a + b + c) /2
  // area do triangulo = raizquadrada(p(p-a)(p-b)(p-c))

  return triangleArea(lAB, lBC, lCA);
}

float Sphere::getArea()
{
  return (4 * M_PI * float(pow(m_ratio, 2)));
}

float Tetrahedron::getArea()
{
  float lAB, lAD, lAC, lBC, lBD, lDC;

  lAB = distanceBetweenTwoPoints3D(m_pA, m_pB);

  lAD = distanceBetweenTwoPoints3D(m_pA, m_pD);

  lAC = distanceBetweenTwoPoints3D(m_pA, m_pC);

  lBC = distanceBetweenTwoPoints3D(m_pB, m_pC);

  lBD = distanceBetweenTwoPoints3D(m_pB, m_pD);

  lDC = distanceBetweenTwoPoints3D(m_pD, m_pC);

  return (triangleArea(lAB, lAD, lBD) +
          triangleArea(lAC, lAD, lDC) +
          triangleArea(lAB, lAC, lBC) +
          triangleArea(lBC, lDC, lBD));
}

float Cube::getArea()
{
  return 6 * (pow(m_edge, 2));
}
