#pragma once

class Celestial{
    double m_mess;
    double m_radius;
public:
    Celestial() : Celestial(0,0) {}
    Celestial(double mess, double radius) : m_mess(mess), m_radius(radius) {}
    Celestial(const Celestial& b) : Celestial(b.m_mess, b.m_radius) {}
    
    Celestial& operator=(const Celestial& b){
        m_mess = b.m_mess;
        m_radius = b.m_radius;
        return *this;
    }
};