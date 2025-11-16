#include <stdio.h>
#include <string.h>

// Structure for Book
struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity;
};

// Function Prototypes
void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void updateBook();

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Update Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: updateBook(); break;
            case 6: return 0;
            default: printf("Invalid Choice!\n");
        }
    }
}

// Add Book Function
void addBook() {
    struct Book b;
    FILE *fp = fopen("library.dat", "ab");

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Title: ");
    getchar();
    fgets(b.title, 100, stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter Author: ");
    fgets(b.author, 100, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Book Added Successfully!\n");
}

// Display All Books
void displayBooks() {
    struct Book b;
    FILE *fp = fopen("library.dat", "rb");

    if (!fp) {
        printf("No books found!\n");
        return;
    }

    printf("\n----- All Books -----\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("\nID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n",
               b.id, b.title, b.author, b.quantity);
    }
    fclose(fp);
}

// Search Book by ID
void searchBook() {
    int id, found = 0;
    struct Book b;
    FILE *fp = fopen("library.dat", "rb");

    printf("Enter Book ID to Search: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n",
                   b.id, b.title, b.author, b.quantity);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book Not Found!\n");

    fclose(fp);
}

// Delete Book Function
void deleteBook() {
    int id, found = 0;
    struct Book b;
    FILE *fp = fopen("library.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    printf("Enter Book ID to Delete: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            found = 1;
        } else {
            fwrite(&b, sizeof(b), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("library.dat");
    rename("temp.dat", "library.dat");

    if (found)
        printf("Book Deleted Successfully!\n");
    else
        printf("Book Not Found!\n");
}

// Update Book Function
void updateBook() {
    int id, found = 0;
    struct Book b;
    FILE *fp = fopen("library.dat", "rb+");

    printf("Enter Book ID to Update: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            printf("Enter New Title: ");
            getchar();
            fgets(b.title, 100, stdin);
            b.title[strcspn(b.title, "\n")] = '\0';

            printf("Enter New Author: ");
            fgets(b.author, 100, stdin);
            b.author[strcspn(b.author, "\n")] = '\0';

            printf("Enter New Quantity: ");
            scanf("%d", &b.quantity);

            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found)
        printf("Book Updated Successfully!\n");
    else
        printf("Book Not Found!\n");
}
