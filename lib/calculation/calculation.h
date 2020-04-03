#ifndef CALCULATION_H
#define CALCULATION_H

#include "calculation_global.h"
#include <QVector>

// sum
int CALCULATION_EXPORT sum_of_elements(const QVector<int> &);

// avg
float CALCULATION_EXPORT avg_of_elements(const QVector<int> &);

// random
int CALCULATION_EXPORT random_range(const int &begin, const int &end);

// maximum
int CALCULATION_EXPORT maximum_value(const QVector<int> &);

// minimum
int CALCULATION_EXPORT minimum_value(const QVector<int> &);

#endif // CALCULATION_H
