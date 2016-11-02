#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
	Shape(int x, int y) : x(x), y(y)
	{
	}
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
	int getSize() {
		return size;
	}
	void setX(int x){
		this->x = x;
	}
	void setY(int y){
		this->y = y;
	}
	
	virtual void setSize(int width, int height) = 0; // 가상 함수로 하위 클래스에서 작성
	void print(string n)
	{
		cout << n << " 의 위치는" << getX() << ", " << getY()
			<< " 이고 면적(넓이)은 " << getSize() << "입니다." << endl;
	}
protected:
	int x, y, size;
};

class Rectangle : public Shape {
public:
	Rectangle(int x, int y, int width, int height) : Shape(x, y)
	{
		setSize(width, height);
		print("Rectangle");
	}
	void setSize(int width, int height)
	{
		size = width * height;
	}
};
class Triangle : public Shape {
public:
	Triangle(int x, int y, int width, int height) : Shape(x, y)
	{
		setSize(width, height);
		print("Triangle");
	}
	void setSize(int width, int height)
	{
		size = width * height / 2;
	}
};
int main()
{
	Rectangle r(3, 4, 5, 2);
	Triangle t(4, 5, 2, 5);
	return 0;
}