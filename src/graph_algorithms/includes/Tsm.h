#pragma once

#ifndef TSM_H
#define TSM_H

#include <set>

#define ALPHA 1            // вес феромона
#define BETA 1             // коэффициент эвристики
#define PH_EVAROPATION 0.8 // коэффициент испарения феромона после каждого цикла
#define Q_PH 100.0         // количество феромона

#define T_MAX 100    // время жизни колонии
#define CNT_ANTS 150 // количество муравьев в колонии

struct Ant {
  int distance;             // длина маршрута
  std::set<vertex_id> tabu; // посещенные муравьём вершины
  std::vector<vertex_id> path; // путь муравья (пройденные вершины)
};

struct TsmResult {
  // массив с искомым маршрутом (с порядком обхода вершин)
  std::vector<int> vertices;
  double distance; // длина маршрута
};

#endif
