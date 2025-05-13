// Баяк Александра, лабораторная №6, вариант номер 6, задание № 2.
#include "queue.h"
#include "utilis.h"

int main() {
    char ch;
    int choice;
    char input[100]; 

    initQueue(); 

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Element\n");
        printf("2. Display Queue\n");
        printf("3. Clear Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        
        if (inputNumber(&choice) != 0) {
            continue; 
        }

        switch (choice) {
        case 1:
            printf("Enter a character to add: ");
            fgets(input, sizeof(input), stdin);
            ch = input[0]; 

            
            if (currentSize % 2 == 0) {
                enqueueFront(ch); 
            }
            else {
                enqueueRear(ch); 
            }

            if (currentSize > 1) {
                if (currentSize % 2 == 0) {
                    dequeueFront(); 
                }
                else {
                    dequeueRear(); 
                }
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
