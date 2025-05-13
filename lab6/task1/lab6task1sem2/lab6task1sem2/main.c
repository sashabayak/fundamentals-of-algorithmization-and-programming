// лабораторная работа №6, задание номер 1, вариант №6, Баяк Александра
#include "queue.h"
#include "utilis.h"

int main() {
    char ch;
    int count = 0;
    int choice;
    char input[100]; 

    initQueue(); 

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue (Add symbol)\n");
        printf("2. Display queue\n");
        printf("3. Clear queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (inputNumber(&choice) != 0) {
            continue; 
        }

        switch (choice) {
        case 1:
            printf("Enter a character: ");
            fgets(input, sizeof(input), stdin);
            ch = input[0]; 
            if (ch == '\n') {
                printf("No character entered!\n");
                break;
            }
            enqueue(ch);
            if (currentSize >= 3) {
                showLeftSymbol(count);
                count++;
            }
            break;
        case 2:
            displayQueue();
            break;
        case 3:
            clearQueue();
            break;
        case 4:
            clearQueue();
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
