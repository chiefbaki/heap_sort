#include <iostream>
void iswap (int &n1, int &n2) 
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main () 
{
    const int n = 100;
    int a[n];

    // Для наглядности заполняем массив числами от n до 0.
    for (int i = 0; i < n; i++) {
        a[i] = n - i;
        std::cout << a[i] << ' ';
    }

	// ----------- Сортировка ------------
	// Сортирует по возрастанию. Чтобы получить сортировку по убыванию,
	// поменяйте знаки сравнения в строчках, помеченных /*(знак)*/
    int sh = 0; // Смещение
    bool b;
    do 
    {
	    b = false;
	    for (int i = 0; i < n; i++) 
        {
	        if (i * 2 + 2 + sh < n) 
            {
		        if ((a[i + sh] > /*<*/ a[i * 2 + 1 + sh]) || (a[i + sh] > /*<*/ a[i * 2 + 2 + sh])) 
                {
		            if (a[i * 2 + 1 + sh] < /*>*/ a[i * 2 + 2 + sh]) 
                    {
			            iswap(a[i + sh], a[i * 2 + 1 + sh]);
			            b = true;
		            } 
                    else if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) 
                    {
		                iswap(a[i + sh], a[i * 2 + 2 + sh]);
		                b = true;
		            }
		        }
		        // Дополнительная проверка для последних двух элементов;
                // с её помощью можно отсортировать пирамиду
                // состоящую всего лишь из трёх элементов
		        if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) 
                {
			        iswap(a[i * 2 + 1 + sh], a[i * 2 + 2 + sh]);
                    b = true;
			    }
	        } 
            else if (i * 2 + 1 + sh < n) 
            {
	            if (a[i + sh] > /*<*/ a[ i * 2 + 1 + sh]) 
                {
	                iswap(a[i + sh], a[i * 2 + 1 + sh]);
	                b = true;
	            }
	        }
	    }
	    if (!b)
            ++sh; // Смещение увеличивается, когда на текущем этапе сортировать больше нечего
    } while (sh + 2 < n); // Конец сортировки

    std::cout << std::endl << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';

    return 0;
}
