#pragma once
#include "TrafficLightAddress.h"

// Состояния цветов светофора
enum TrafficLightsState
{
    RED,
    YELLOW,
    GREEN
};

// Класс для моделирования работы светофора
class TrafficLight
{
private:
    TrafficLightAddress address;

public:
    TrafficLight(const TrafficLightAddress& address);

    TrafficLightsState GetCurrentState() const;

    void GetInfo() const;
};