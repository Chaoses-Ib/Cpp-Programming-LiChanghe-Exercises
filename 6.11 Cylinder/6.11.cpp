#include <iostream>

using namespace std;

class Cylinder{
    double m_radius, m_height;
public:
    double volume() const{
        return 3.14 * m_radius * m_radius * m_height;
    }
    Cylinder(double i = 0, double h = 0) : m_radius(i), m_height(h) {}


    void zoom(double scale){
        m_radius *= scale;
        m_height *= scale;
    }
    double surface_area() const{
        return 2 * 3.14 * m_radius * (m_radius + m_height);
    }
    void radius(double radius){
        m_radius = radius;
    }
    void height(double height){
        m_height = height;
    }
};

int main(){
    Cylinder object(1.0, 1.0);
    double vol = object.volume();
    cout << vol << endl;

    object.radius(0.5);
    object.height(0.5);
    object.zoom(2);
    cout << "V: " << object.volume() << endl;
    cout << "S: " << object.surface_area() << endl;
}