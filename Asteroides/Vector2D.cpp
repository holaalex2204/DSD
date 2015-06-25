#include "Vector2D.h"
#include <math.h>
#include <stdio.h>
Vector2D::Vector2D(float x, float y )
{
	m_x = x;
	m_y = y;
}
Vector2D::Vector2D(void)
{
	m_x = 0 ;
	m_y = 0;
}
float Vector2D::getX()
{
	return m_x; 
}
float Vector2D::getY()
{
	return m_y;
}
void Vector2D::setX(float x)
{
	m_x = x;
}
void Vector2D::setY(float y)
{
	m_y = y;
}
float Vector2D::length()
{
	return sqrt((m_x*m_x+ m_y*m_y));
}
void Vector2D::normaliza()
{
	float l = length();
	m_x = m_x/l;
	m_y = m_y/l;
}