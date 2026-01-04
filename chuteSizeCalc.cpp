// chuteSizeCalc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cmath>
int main()
{
  using namespace std;
  /* code */
  float tcelcius; /*temperature in Celcius*/
  float mass; /*nosecone mass*/
  float phpa; /*pressure in hPa*/
  std::cout << "Input temperature in degrees Celcius" << '\n';
  std::cin >> tcelcius;
  std::cout << "Input mass of nosecone in grams" << '\n';
  std::cin >> mass;
  std::cout << "Input pressure in hectopascals" << '\n';
  std::cin >> phpa;
  float R = 287.058; /*ideal gas constant*/
  float tkelvin = tcelcius + 275.13; /*temperature in K*/
  float p = phpa * 100; /*pressure in Pa*/
  float rho = p / (tkelvin * R);
  std::cout << '\n' << "The air density is " << rho << " kg/cu m" << '\n';
  float height;
  std::cout << "Input height the rocket flew to in feet" << '\n';
  std::cin >> height;
  float heightm = height / 3.281;
  float masskg = mass / 1000;
  float deceleration = 9.81 * heightm;
  float F = masskg * deceleration /*force on impact no chute in Newtons*/ ;
  if (F > 25) {
    std::cout << '\n' << "Because the force is " << F << " N Impact will
    break the egg, parachute required" << '\n';
    float diameter;
    std::cout << "Input diameter of parachute in cm" << '\n';
    std::cin >> diameter;
    float diameterm = diameter / 100;
    float pi = atan(1) * 4;
    float area = pi * diameterm * diameterm;
    float doublemass = masskg * 2;
    std::cout << "The area of the parachute is " << area << " sq m" << '\n';
    float velocity = sqrt((doublemass) / (1.175 * area * rho));
    std::cout << "The impact velocity will be " << velocity << " m/s" << '\n';
    deceleration = velocity;
    float F = masskg * deceleration /*force on impact no chute in Newtons*/;
    if (F > 25) {
      std::cout << '\n' << "Because the force is " << F << " N Impact will break the egg, a larger parachute required" << '\n';
      while (F > 25){
        std::cout << "Input diameter of parachute in cm" << '\n';
        std::cin >> diameter;
        float diameterm = diameter / 100;
        float pi = atan(1) * 4;
        float area = pi * diameterm * diameterm;
        std::cout << "The area of the parachute is " << area << " sq m" << '\n';
        float velocity = sqrt((2 * masskg) / (1.175 * area * rho));
        std::cout << "The impact velocity will be " << velocity << "m/s" << '\n';
        deceleration = velocity;
        float F = masskg * deceleration /*force on impact no chute in Newtons*/;
        std::cout << '\n' << "Because the force is " << F << " N Impact will break the egg, a larger parachute required" << '\n';
        }
        std::cout << "Force below 25 N, egg will not break" ;
      }
    else {
      std::cout << '\n' << "Impact will not break egg, no parachute
        required";
    }
  }
  else {
    std::cout << '\n' << "Impact will not break egg, no parachute required";
  }
}
