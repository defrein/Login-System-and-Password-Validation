#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

char username[50];
char password[50];

char usnLogin[50];
char pwLogin[50];

char noArr[] = "0123456789";
char charArr[] = ".,?!@#$^&*()-_\%";

int lengthUsername;
int lengthPass;

int space;
int numbers;
int specialChar;

int usernameSuccess;
int passwordSuccess;

//--------------- Validation -----------------
void containSpace()
{
    for (int i = 0; i < lengthUsername; i++)
    {
        if (username[i] == ' ')
        {
            space = 1;
            break;
        }
        else
        {
            space = 0;
        }
    }
}

void containNumbers()
{
    for (int i = 0; password[i] != '\0' || noArr[i] != '\0'; i++)
    {
        if (strchr(password, noArr[i]) != NULL)
        {
            numbers = 1;
            break;
        }
        else
        {
            numbers = 0;
        }
    }
}

void containSpecialChar()
{
    for (int i = 0; password[i] != '\0' || charArr[i] != '\0'; i++)
    {
        if (strchr(password, charArr[i]) != NULL)
        {
            specialChar = 1;
            break;
        }
        else
        {
            specialChar = 0;
        }
    }
}

//--------------- SIGN UP -------------------
void signup()
{

    system("cls");
    printf("Buat Username dan Password Baru\n\n");
    printf("----username----\n");
    printf("Info: buat username baru dengan minimal 5 karakter tanpa spasi\n");

    do
    {
        printf("\nUsername baru: ");
        gets(username);

        lengthUsername = strlen(username);
        containSpace();

        if (lengthUsername >= 5 && space == 0)
        {
            printf("Username telah berhasil dibuat!");
            usernameSuccess = 1;
        }
        else
        {
            printf("Username gagal dibuat, coba untuk memenuhi syarat.\n");
        }
    } while (usernameSuccess != 1);

    printf("\n\n----password----\n");
    printf("Info: \n");
    printf("- Buat password baru dengan kombinasi huruf, angka, dan karakter\n");
    printf("- password minimal 6 karakter\n");
    printf("- password maksimal 12 karakter\n");

    do
    {
        printf("\nPassword baru: ");
        gets(password);
        lengthPass = strlen(password);
        containNumbers();
        containSpecialChar();

        // printf("%d\n", numbers);
        // printf("%d\n", specialChar);
        // printf("%d\n", lengthPass);

        if (lengthPass >= 6 && lengthPass <= 12 &&
            numbers == 1 && specialChar == 1)
        {
            printf("Password telah berhasil dibuat!\n");
            passwordSuccess = 1;
        }
        else if (lengthPass >= 6 && lengthPass <= 12 &&
                 numbers == 0 &&
                 specialChar == 0)
        {
            printf("Password terlalu lemah, coba kombinasikan dengan angka dan karakter\n");
        }
        else if (lengthPass >= 6 && lengthPass <= 12 &&
                 numbers == 1 &&
                 specialChar == 0)
        {
            printf("Password terlalu lemah, coba kombinasikan dengan karakter khusus\n");
        }
        else if (lengthPass >= 6 && lengthPass <= 12 &&
                 numbers == 0 && specialChar == 1)
        {
            printf("Password terlalu lemah, coba kombinasikan dengan angka\n");
        }
        else
        {
            printf("Password minimal 6 karakter dan maksimal 12 karakter\n");
        }
    } while (passwordSuccess != 1);

    getch();
}

//---------------- LOG IN --------------------
void login()
{
    system("cls");
    printf("---------LOGIN--------\n\n");
    printf("Masukkan username: ");
    gets(usnLogin);
    printf("Masukkan password: ");
    gets(pwLogin);

    if (strcmp(username, usnLogin) == 0 && strcmp(password, pwLogin) == 0 && lengthUsername != 0 && lengthPass != 0)
    {
        printf("\nLogin berhasil!\n");
    }
    else if (lengthUsername == 0 && lengthPass == 0)
    {
        printf("\nField tidak boleh kosong!\n");
        printf("Silakan Sign Up terlebih dahulu.\n");
    }
    else
    {
        printf("\nUsername dan password tidak sesuai!\n");
    }
    getch();
}

//---------------- Menu ----------------------
void menu()
{
    system("cls");
    printf("Selamat Datang, Tamu\n");
    printf("Silakan Login atau Sign up untuk Melanjutkan\n\n");
    printf("1. Log in\n");
    printf("2. Sign up\n");
    printf("3. Exit\n");
}

void menu0()
{
    system("cls");
    printf("pilihan tidak ada dalam daftar.");
    getch();
}

void menuExit()
{
    system("cls");
    printf("program berakhir.");
}

int main()
{
    char key = '1';
    do
    {
        menu();
        printf("\nMasukkan Nomor Pilihan : ");
        key = getch();
        if (key == '1')
        {
            login();
        }
        else if (key == '2')
        {
            signup();
        }
        else if (key == '3')
        {
            menuExit();
        }
        else
        {
            menu0();
        }
    } while (key != '3');
    getch();
    return 0;

    getch();
}
