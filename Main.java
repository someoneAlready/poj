abstract class GeometricObject{
	public abstract double len();
	public abstract double area();
}

class Point{
	int x, y;
	Point (int _x, int _y){
		x=_x;
		y=_y;
	}
}

class Line{
	Point A, B;
	Line (Point _A, Point _B){
		A = _A;
		B = _B;
	}
	Line (int x1, int y1, int x2, int y2){
		A = new Point(x1, y1);
		B = new Point(x2, y2);
	}
}

class Rectangle extends GeometricObject{
	Point A, B;
	int a, b;
	Rectangle (Point _A, Point _B){
		A = _A;
		B = _B;
		a = Math.abs(B.x-A.x);
		b = Math.abs(B.y-A.y);
	}
	public double len(){
		return 2*(a+b);
	}
	public double area(){
		return a*b;
	}
}

class Circle extends GeometricObject{
	Point C; 
	int r;
	Circle(Point _C, int _r){
		C = _C;
		r = _r;
	}
	public double len(){
		return 3.14*2*r;
	}
	public double area(){
		return 3.14*r*r;
	}
}

class Triangle extends GeometricObject{
	public double len(){
	}
	public double area(){
	}
}

class Main{
	public static void main(String args[]){
		return;
	}
}
