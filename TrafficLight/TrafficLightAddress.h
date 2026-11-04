#pragma once
#include <string>

struct TrafficLightAddress
{
    std::string country;
    std::string city;
    std::string street;

    double latitude;
    double longitude;
};