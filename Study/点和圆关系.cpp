#include<iostream>
using namespace std;
//点和圆关系
class Point
{
public:
	void setX(int x)
	{
		m_X = x;
	}
	int getX()
	{
		return m_X;
	}
	void setY(int y)
	{
		m_Y = y;
	}
	int getY()
	{
		return m_Y;
	}
private:
	int m_X;
	int m_Y;
};
class Circle
{
public:
	void setR(int r)
	{
		m_R = r;
	}
	int getR()
	{
		return m_R;
	}
	void setCenter(Point center)
	{
		m_Center = center;
	}
	Point getCenter()
	{
		return m_Center;
	}
private:
	int m_R;
	//在类中可以让另一个类作为本来中的成员
	Point m_Center;
};
void isInCircle(Circle& c, Point& p)
{
	//计算两点之间距离的平方
	int distance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDistance = c.getR() * c.getR();
	if (distance == rDistance)
	{
		cout << "在圆上" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "在圆外" << endl;
	}
	else
	{
		cout << "在圆内" << endl;
	}
}
int main()
{
	//创建圆
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);
	//创建点
	Point p;
	p.setX(10);
	p.setY(10);
	isInCircle(c, p);
}
