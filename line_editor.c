
#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

void insertLine(void) {
    int position;
    char text[MAX_LENGTH];

    if (lineCount >= MAX_LINES) {
        printf("Document is full.\n");
        return;
    }

    printf("Enter position (1 to %d): ", lineCount + 1);

    if (scanf("%d", &position) != 1) {
        printf("Invalid input.\n");
        return;
    }
    getchar();

    if (position < 1 || position > lineCount + 1) {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter text: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Unable to read text.\n");
        return;
    }

    text[strcspn(text, "\n")] = '\0';

    for (int i = lineCount; i >= position; i--) {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[position - 1], text);
    lineCount++;

    printf("Line inserted successfully.\n");
}

void deleteLine(void) {
    int position;

    if (lineCount == 0) {
        printf("Document is empty.\n");
        return;
    }

    printf("Enter line number to delete (1 to %d): ", lineCount);

    if (scanf("%d", &position) != 1) {
        printf("Invalid input.\n");
        return;
    }
    getchar();

    if (position < 1 || position > lineCount) {
        printf("Invalid line number.\n");
        return;
    }

    for (int i = position - 1; i < lineCount - 1; i++) {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;
    printf("Line deleted successfully.\n");
}

void displayDocument(void) {
    if (lineCount == 0) {
        printf("Document is empty.\n");
        return;
    }

    printf("\n--- Document ---\n");

    for (int i = 0; i < lineCount; i++) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

int main(void) {
    int choice;

    do {
        printf("\n=== Simple Line Editor ===\n");
        printf("1. Insert a line\n");
        printf("2. Delete a line\n");
        printf("3. Display document\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        getchar();

        switch (choice) {
            case 1:
                insertLine();
                break;
            case 2:
                deleteLine();
                break;
            case 3:
                displayDocument();
                break;
            case 4:
                printf("Exiting Line Editor.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
