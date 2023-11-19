#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <Windows.h>

using namespace std;


//task 1
void Task1(FILE* file)
{
    char line[1024];
    int max_length = 0;

    while (fgets(line, sizeof(line), file)) {
        int length = strlen(line);
        if (length > max_length) {
            max_length = length;
        }
    }

    fclose(file);

    printf("Length of the longest line: %d\n", max_length);
}

//Task 2
void Task2(FILE* file)
{
    char word[1024];
    char searchWord[1024];
    cout << "Enter a word: ";
    cin >> searchWord;

    int count = 0;

    while (fscanf(file, "%1023s", word) == 1) {
        if (strcmp(word, searchWord) == 0) {
            ++count;
        }
    }

    fclose(file);
    printf("Word '%s' meets %d time(s).\n", searchWord, count);
}

int main()
{
    FILE* file = fopen("file_task.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    Task1(file);

    FILE* file2 = fopen("input_task.txt", "r");
    if (!file)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    Task2(file2);
    return 0;
}