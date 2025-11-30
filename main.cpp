#include <iostream>

using namespace std;

void inputData(float* p, int n)
{
    for (int i = 0; i < n; i++){
        cin >> *(p+i);
    }
}
float average(const float* p, int n)
{
    float summa;
    for (int i = 0; i < n; i++){
        summa += *(p+i);
    }
    float ave = summa/n;
    return ave;
}

float minValue(const float* p, int n){

    float minimum = *p;
    for (int i = 1; i < n; i++){
        if ((*(p+i)) < minimum){
            minimum = (*(p+i));
        }
    }
    return minimum;
}


float maxValue(const float* p, int n){
    float maximum = *p;
    for (int i = 1; i < n; i++){
        if ((*(p+i)) > maximum){
            maximum = *(p+i);
        }
    }
    return maximum;

}
float* filterAboveAverage(float* p, int n, int& newCount){

    float ave = average(p, n);
    float* data = new float[newCount];

    for (int i = 0; i < n; i++){
        if (*(p+i) > ave){
            *(data + newCount) = *(p+i);
            newCount++;

        }
    }
    return data;
}

int main()
{

    int n;

    cout << "=== Анализ сенсора ===" << endl;
    cout << "Введите количество измерений: ";
    cin >> n;

    float* data = new float[n];

    cout << "Введите значения: ";
    inputData(data, n);

    float ave = average(data, n);
    cout << "Среднее значение: " << ave << endl;

    float mini = minValue(data, n);
    cout << "Минимум: " << mini << endl;

    float maxi = maxValue(data, n);
    cout << "Максимум: " << maxi << endl;

    int newCount = 0;

    float* new_data = filterAboveAverage(data, n, newCount);

    cout << "Значения выше среднего: ";
    for (int i = 0; i < newCount; i++){
    cout << (*(new_data+i)) << " ";
    }

    delete[] data;
    delete[] new_data;

    return 0;
}
