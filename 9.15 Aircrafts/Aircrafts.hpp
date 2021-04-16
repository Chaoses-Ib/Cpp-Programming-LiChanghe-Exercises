#pragma once

class Aircraft{

};

class JetAircraft : public Aircraft{
    FixedWings m_wings;
};

class Helicopter : public Aircraft{
    RotaryWings m_wings;
};

class Wings{

};

class FixedWings : public Wings{

};

class RotaryWings : public Wings{

};