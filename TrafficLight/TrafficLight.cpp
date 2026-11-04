#include "TrafficLight.h"
#include <iostream>
#include <chrono>

// Конструктор светофора
TrafficLight::TrafficLight(const TrafficLightAddress& address)
    : address(address)
{
}

// Получение текущего состояния светофора
TrafficLightsState TrafficLight::GetCurrentState() const
{
    // Фиксируем текущее время
    auto now = std::chrono::system_clock::now();

    // Приводим время к секундам
    auto now_sec =
        std::chrono::floor<std::chrono::seconds>(now).time_since_epoch();

    // Получаем секунды текущей минуты
    int seconds = (now_sec % 60).count();

    // Определяем цвет светофора
    if (seconds >= 0 && seconds <= 5)
    {
        return TrafficLightsState::YELLOW;
    }
    else if (seconds >= 6 && seconds <= 29)
    {
        return TrafficLightsState::RED;
    }
    else if (seconds >= 30 && seconds <= 53)
    {
        return TrafficLightsState::GREEN;
    }
    else
    {
        return TrafficLightsState::YELLOW;
    }
}

// Вывод информации о светофоре
void TrafficLight::GetInfo() const
{
    TrafficLightsState currentState = GetCurrentState();

    std::cout << "\n========== TRAFFIC LIGHT ==========" << std::endl;

    std::cout << "Страна: " << address.country << std::endl;
    std::cout << "Город: " << address.city << std::endl;
    std::cout << "Улица: " << address.street << std::endl;

    std::cout << "Широта: " << address.latitude << std::endl;
    std::cout << "Долгота: " << address.longitude << std::endl;

    std::cout << "Текущее состояние: ";

    switch (currentState)
    {
    case TrafficLightsState::RED:
        std::cout << "КРАСНЫЙ" << std::endl;
        break;

    case TrafficLightsState::YELLOW:
        std::cout << "ЖЁЛТЫЙ" << std::endl;
        break;

    case TrafficLightsState::GREEN:
        std::cout << "ЗЕЛЁНЫЙ" << std::endl;
        break;
    }

    std::cout << "===================================" << std::endl;
}