#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const string eng_alphabet = "abcdefghijklmnopqrstuvwxyz"; // Массив букв английского алфавита
const int NUM_OF_CHAR = 1000; // Число размерности массива
char rundom_char_array[NUM_OF_CHAR] = ""; // Массив символов

void rundomCharGenerator();
void functionGuessTheWord();

int main()
{
    rundomCharGenerator();
    functionGuessTheWord();
    cout << rundom_char_array << endl;
    
}

/* Это функция для заполнения массива символов
размера N случайнми буквами английского алфавита. */
void rundomCharGenerator()
{
    srand(time(0)); // Функции необходимая для обновления выходных значений функции rand() 

    for (int i = 0; i < NUM_OF_CHAR; i++) {
        rundom_char_array[i] = eng_alphabet[rand() % eng_alphabet.size()];
    }
}

/*Функция рассчитывающая количество итераций необходимых
для игры "Угадай слово", а также максимальное количество попыток
для поиска одного символа. (Игра заключается в посимвольном поиске
символов внутри случайного массива символов) */
void functionGuessTheWord() 
{
    int i = 0; // Счетчик внешнего цикла, отвечает за индекс текущего символа массива
    int j = 0; // Счетчик внутреннего цикла, отвечает за индекс текущего символа массива английских букв
    int num_for_iteration = 0; // Счетчик количество итераций работы функции 
    int max_num_to_guess = 0; // Значение максимального количества попыток на поиск буквы в массиве символов

    while (i < NUM_OF_CHAR) {
        while (j < eng_alphabet.size()) {
            num_for_iteration++;
            if (rundom_char_array[i] == eng_alphabet[j]) {
                if (j > max_num_to_guess) {
                    max_num_to_guess = j+1;
                }
                break;
            }
            j++;
        }
        j = 0;
        i++;
    }

    cout << "Number for iteration = " << num_for_iteration << endl;
    cout << "Maximum number of attempts to guess the symbol  = " << max_num_to_guess << endl;
}