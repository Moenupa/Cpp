#include <iostream>
using namespace std;

double max(double arr[], int size)
{
    if (size == 0)
        return 0;
    double max = arr[0];
    for (int i = 1; i < size; i++)
    {
        max = (arr[i] > max) ? arr[i] : max;
    }
    return max;
}
double min(double *aPtr, int size)
{
    if (size == 0)
        return 0;
    double *min = aPtr;
    for (int i = 1; i < size; i++)
    {
        min = (aPtr + i < min) ? aPtr + i : min;
    }
    return *min;
}
int main() {
    double data[] = {1, 2, 3, 4, 5};
    cout << "max: " << max(data, 5) << endl;
    cout << "min: " << min(data, 5) << endl;

    return 0;
}