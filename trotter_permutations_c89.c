/*Алгоритм Джонсона Троттера для перестановок
 * Размеры всех массивов должны быть n. Не забыть установить
 * размер массива temp на строке 23*/
#include <stdio.h>


			int main () {

	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int s[10]={1,1,1,1,1,1,1,1,1,1}; /*1 - стрелка влево, 0 - стрелка вправо*/
	int n=10;
	int k, i, max, current, swap;
	int fact=3628800;


while (fact--) {
			/*Печать*/
			for (i=0; i< n; i++)
			printf("%d", a[i]);
			printf("\n");

			/*Временный массив для хранения подвижных элементов*/
			int temp[10]={};

			/*Поиск подвижных элементов*/
			for (k=0; k < n; k++) {
				if (k-1 !=-1  && a[k-1] < a[k] && s[k]==1)
				temp[k]=a[k];
				if (k+1 != n  && a[k+1] < a[k] && s[k]==0)
				temp[k]=a[k];
			}


			/*Максимально подвижный элемент*/
			max=temp[0];
			for (k=0; k < n; k++) {
					if (temp[k] > max)
					max=temp[k];
			}
			/*Ключ максимально подвижного элемента*/
			for (k=0; a[k] != max; k++);
				 max=k;


			/*Обмен, если стрелка влево*/
			  if (s[max]==1) {
				  swap=a[max];
				  a[max]=a[max-1];
				  a[max-1]=swap;
				  /*Текущий элемент*/
				  current=max-1;
				  /*Обернем стрелки*/
				  swap=s[max];
				  s[max]=s[max-1];
				  s[max-1]=swap;
			  }
			  else
			   {
			/*Обмен, если стрелка вправо*/
				  swap=a[max];
				  a[max]=a[max+1];
				  a[max+1]=swap;
				  /*Текущий элемент*/
				  current=max+1;
				  /*Обернем стрелки*/
				  swap=s[max];
				  s[max]=s[max+1];
				  s[max+1]=swap;
			  }
			/*Обернем стрелки у всех элементов больше текущего*/
				for (k=0; k < n; k++) {
					if (a[k] > a[current]) {
						if (s[k]==1) {
							s[k]=0;
						continue;
						}
						else {
						s[k]=1;
						continue;
						}
					}
				}
			}
		}
