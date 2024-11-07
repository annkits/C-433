#include <stdio.h>
#include <string.h>
#include <ctype.h> //библиотека позволяет нормализовать регистр текста перед обработкой

#define max_len 1000
#define max_words 1000

int main(){

    char sentence[max_len], word [max_len];
    char max_word[max_words][max_len];
    int max_count = 0, max_word_count = 0;

    printf("Введите предложение: ");
    fgets(sentence, max_len, stdin);

    int i = 0, j = 0, current_count = 0;

    while (1){
        if (sentence[i] != ' ' && sentence[i] != '\0' && sentence[i] != '\n'){
            word[j++] = sentence[i]; //собираем слово
            if (tolower(sentence[i]) == 'a'){ //понижаем регистр
                current_count++; //считаем букву 'a' в текущем слове
            }
        }
        else {
            word[j] = '\0'; //завершение слова
            if (current_count > max_count){ //если новое максимальное кол-во 'a'
                max_count = current_count;
                max_word_count = 0; //обнуляем счетчик с максимумом
                strcpy(max_word[max_word_count++], word); //добавляем новое слово в массив
            }
            else if (current_count == max_count && current_count > 0){ //если кол-во 'a' такое же
                strcpy(max_word[max_word_count++], word); //добавляем слово в массив
            }
            j = 0; //обнуление индекса для нового слова
            current_count = 0; //обнуление счётчика для нового слова
        }
        if (sentence[i] == '\0')
            break;
        i++;
    }
    
if (max_count > 0){
    printf("Слова с максимальным количеством 'a' (%d): \n", max_count);
    for (int k = 0; k < max_word_count; k++){
        printf("%s\n", max_word[k]);
    }
}
else {
    printf("В предложении нет слов с буквой 'a'.\n");
}
}
