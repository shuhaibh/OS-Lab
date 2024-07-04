//Program to implement a 2 person chat environment
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SIZE 1024

typedef struct {
    char str[SIZE];
    char from_user[SIZE];
} MessageBlock;

typedef struct {
    MessageBlock messages[SIZE];
    int f; // first empty position
    int r; // first full position
} MessageBox;

void addMsg(MessageBox *mailbox, MessageBlock message) {
    mailbox->messages[mailbox->f] = message;
    mailbox->f = (mailbox->f + 1) % SIZE;
    if (mailbox->f == mailbox->r) {
        mailbox->r = (mailbox->r + 1) % SIZE;
    }
}

MessageBlock getMsg(MessageBox *mailbox) {
    MessageBlock message = mailbox->messages[mailbox->r];
    mailbox->r = (mailbox->r + 1) % SIZE;
    return message;
}

int main() {
    key_t key = ftok("shmfile", 66);
    int shmid = shmget(key, sizeof(MessageBox), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    MessageBox *mailbox = (MessageBox *)shmat(shmid, NULL, 0);
    if (mailbox == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    mailbox->f = -1;
    mailbox->r = -1;

    // Parent process
    pid_t p = fork();
    if (p == -1) {
        perror("FORK");
        exit(1);
    }

    // Parent fork (for sending the message)
    if (p > 0) {
        while (1) {
            char str[SIZE];
            MessageBlock message;

            // If messages are full, wait
            while (mailbox->f == (mailbox->r + 1) % SIZE);

            printf("Enter message: ");
            scanf(" %[^\n]", str);

            strcpy(message.str, str);
            strcpy(message.from_user, "user1");

            addMsg(mailbox, message);
            if (strcmp(str, "exit") == 0) {
                printf("Exiting...");
                break;
            }
        }
    } else {
        // Child process (for receiving the message)
        while (1) {
            char str[SIZE];
            MessageBlock message = getMsg(mailbox);

            // If messages are empty, wait
            while (mailbox->f == -1);

            if (strcmp() {
        while (1) {
            char str[SIZE];
            MessageBlock message;

            // If mailbox is fullmessage.from_user, "user1") != 0) {
                printf("\, wait for it to be empty
            while (mailbox->r == (mailbox->f + 1) % SIZE);

            printf("Enter message: ");
            scanf(" %[^\n]", str);

           nMessage: %s - from: %s\n", message.str, message.from_user);
                if (strcmp(message.str, "exit") == 0) {
                    break;
                }
            }
        } strcpy(message.str, str);
            strcpy
    }
    shmd(message.from_user, getenv("USER")t(mailbox);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
