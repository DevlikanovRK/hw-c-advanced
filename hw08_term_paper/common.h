#ifndef COMMON_H
#define COMMON_H

typedef float(*function)(float);

// Функции
float f1(float); // Прямая
float f2(float); // Кубическая парабола
float f3(float); // Гипербола
// Разности функций
float f1_f2(float);
float f1_f3(float);
float f2_f3(float);
// Производные функций
float df1(float);
float df2(float);
float df3(float);
float ddf1(float);
float ddf2(float);
float ddf3(float);

#endif
