#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include "TrafficLight.h"

using namespace std::chrono_literals;

int main()
{
    // Настройка кодировки консоли
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Создание адреса светофора
    TrafficLightAddress address
    {
        "Россия",
        "Москва",
        "Тверская улица",
        55.758494,
        37.613198
    };

    // Создание объекта светофора
    TrafficLight trafficLight(address);

    std::cout << "Программа TrafficLight запущена!" << std::endl;
    std::cout << "Для завершения нажмите Ctrl + C." << std::endl;

    // Бесконечный цикл
    while (true)
    {
        trafficLight.GetInfo();

        // Ожидание 23 секунды
        std::this_thread::sleep_for(23000ms);
    }

    return 0;
}