#pragma once
#include "Celestial.hpp"

class Planet{
    Celestial m_satellite;
public:
    Planet(const Celestial& satellite) : m_satellite(satellite) {}
    Planet(const Planet& b) : Planet(b.m_satellite) {}
    
    Planet& operator=(const Planet& b){
        m_satellite = b.m_satellite;
        return *this;
    }
};