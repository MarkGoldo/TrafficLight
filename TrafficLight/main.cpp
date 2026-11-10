#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>
#include "TrafficLight.h"

using namespace std::chrono_literals;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    try
    {
        // Загружаем адреса трёх светофоров из JSON
        std::vector<TrafficLight> trafficLights;

        trafficLights.emplace_back(
            LoadTrafficLightAddress("traffic_light_1.json"));

        trafficLights.emplace_back(
            LoadTrafficLightAddress("traffic_light_2.json"));

        trafficLights.emplace_back(
            LoadTrafficLightAddress("traffic_light_3.json"));

        std::cout << "Загружено светофоров: "
            << trafficLights.size() << std::endl;

        std::cout << "Мониторинг запущен. Для завершения нажмите Ctrl + C."
            << std::endl;

        // Мониторинг всех светофоров
        while (true)
        {
            for (const auto& trafficLight : trafficLights)
            {
                trafficLight.GetInfo();
            }

            // Ожидание 23 секунды
            std::this_thread::sleep_for(23000ms);
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}