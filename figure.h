#pragma once
#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>

class Figure {
public:
  Figure(const std::string& type);

  virtual std::string Name() = 0;
  virtual double Perimeter() = 0;
  virtual double Area() = 0;

  virtual ~Figure() = default;

  const std::string Type;
};


#endif // FIGURE_H
