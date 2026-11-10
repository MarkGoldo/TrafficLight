#pragma once
#include <string>
#include <fstream>
#include <stdexcept>
#include <nlohmann/json.hpp>

// Адрес светофора
struct TrafficLightAddress
{
    std::string country;
    std::string city;
    std::string street;

    double latitude;
    double longitude;
};

// Загрузка адреса светофора из JSON-файла
inline TrafficLightAddress LoadTrafficLightAddress(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось открыть JSON-файл: " + filename);
    }

    nlohmann::json data;
    file >> data;

    TrafficLightAddress address;

    address.country = data.at("country").get<std::string>();
    address.city = data.at("city").get<std::string>();
    address.street = data.at("street").get<std::string>();
    address.latitude = data.at("latitude").get<double>();
    address.longitude = data.at("longitude").get<double>();

    return address;
}