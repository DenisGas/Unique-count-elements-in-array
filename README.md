# Unique count elements is array
Console app which counts the number of unique array elements.

! Only standard libres 

## Console output

```cmd
>>  Array size: 0
>>
>>  Size must be greater than 0
>>
>>  Array size: 8
>>
>>  Enter 8 elements:  1 2 3 2 3 4 2 5
>>
>>  1 2 3 2 3 4 2 5
>>  1 3 3 4 5
>>  1 4 5
>>
>>  Number of unique elements: 3
```


## Func printArr()

```cmd
>>  1 2 3 2 3 4 2 5
>>  1 3 3 4 5
>>  1 4 5
```

## Func uniqueCountElem()

```cpp
int uniqueCountElem(const int* array, int size) {
    if (size == 0) return 0;

    printArr(array, size);

    int uniqueElem = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[j] == array[i]) {
                int notUniqueElement = array[i];
                int index = 0;
                int* newArray = new int[size];

                for (int k = 0; k < size; k++) {
                    if (array[k] != notUniqueElement) {
                        newArray[index] = array[k];
                        index++;
                    }
                }

                delete[] array;

                return uniqueCountElem(newArray, index);
            }
        }
        uniqueElem++;
    }

    delete[] array;

    return uniqueElem;
}

```
