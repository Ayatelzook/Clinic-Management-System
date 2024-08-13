#include <stdio.h>
#include <string.h>

struct new_patient {
    char name[20];
    int age;
    char gender[10];
    int ID;
    int slot;
} patients[100];

int max_num = 0;
int max = 0;
int slot[5] = {0, 0, 0, 0, 0};


void add_new_patient() {
    struct new_patient patient={0};

    printf("Enter your name: ");
    scanf("%s", patient.name);

    printf("Enter your age: ");
    scanf("%d", &patient.age);

    printf("Enter your gender: ");
    scanf("%s", patient.gender);

    printf("Enter your ID: ");
    scanf("%d", &patient.ID);

    int i = 0;
    while (i < max_num) {
        if (patients[i].ID == patient.ID) {
            printf("Not correct ID, this ID is already in use.\n");
            break;
        }
        i++;
    }

    if (i == max_num) {
        patients[max_num] = patient;
        max_num++;
        printf("Successful addition.\n");
    }
    else {
        printf("Not successful addition.\n");
    }

    max = max_num;
}

void Edit_patient_record() {
    int id;
    int j;

    printf("Please, Enter the ID: ");
    scanf("%d", &id);

    int found = 0;
    for (j = 0; j < max; j++) {
        if (patients[j].ID == id) {
            found = 1;
            printf("Now, You can edit your information:\n");

            printf("Enter your name: ");
            gets(patients[j].name);
            gets(patients[j].name);

            printf("Enter your age: ");
            scanf("%d", &patients[j].age);

            printf("Enter your gender: ");
            scanf("%s", patients[j].gender);

            printf("Enter your ID: ");
            scanf("%d", &id);

            int isIDUnique = 1;
            for (int k = 0; k < max; k++) {
                if (k != j && patients[k].ID == id) {
                    isIDUnique = 0;
                    printf("Not successful ID, this ID is already in use.\n");
                    break;
                }
            }

            if (isIDUnique) {
                patients[j].ID = id;
                printf("Successful edition.\n");
            }
            break;
        }
    }

    if (found == 0) {
        printf("This ID does not exist in the system.\n");
    }
}

void reserve_slot() {
    int id;
    int k;
    int p;
    int slot_num;

    printf("Enter your ID: ");
    scanf("%d", &id);

    for (k = 0; k < max; k++) {
        if (id == patients[k].ID) {
            p = 1;
            break;
        }
        else {
            p = 0;
        }
    }

    if (p == 1) {
        printf("Successful ID\n");

        if (patients[k].slot != 0) {
            printf("You already have a reservation. You cannot reserve another.\n");
            return;
        }

        printf("Available slots are:\n");
        while (slot[0] && slot[1] && slot[2] && slot[3] && slot[4]) {
            printf("Not successful reservation. All slots are busy.\n");
            return;
        }

        if (slot[0] == 0)
            printf("       1. from 2pm to 2:30pm\n");
        if (slot[1] == 0)
            printf("       2. from 2:30pm to 3pm\n");
        if (slot[2] == 0)
            printf("       3. from 3pm to 3:30pm\n");
        if (slot[3] == 0)
            printf("       4. from 3:30pm to 4pm\n");
        if (slot[4] == 0)
            printf("       5. from 4pm to 4:30pm\n");

        printf("You can enter your available slot number: ");
        scanf("%d", &slot_num);

        switch (slot_num) {
            case 1:
                slot[0] = 1;
                printf("Successful Reservation\n");
                patients[k].slot = slot[0];
                break;
            case 2:
                slot[1] = 2;
                printf("Successful Reservation\n");
                patients[k].slot = slot[1];
                break;
            case 3:
                slot[2] = 3;
                printf("Successful Reservation\n");
                patients[k].slot = slot[2];
                break;
            case 4:
                slot[3] = 4;
                printf("Successful Reservation\n");
                patients[k].slot = slot[3];
                break;
            case 5:
                slot[4] = 5;
                printf("Successful Reservation\n");
                patients[k].slot = slot[4];
                break;
            default:
                printf("Invalid slot number. Please try again.\n");
                break;
        }
    }
    else {
        printf("Not Successful ID. You cannot reserve a slot.\n");
    }
}

void cancel() {
    int id;
    int p;
    int k;

    printf("Enter your ID: ");
    scanf("%d", &id);

    for (k = 0; k < max; k++) {
        if (id == patients[k].ID) {
            p = 1;
            break;
        }
        else {
            p = 0;
        }
    }

    if (p == 1) {
        printf("Successful ID\n");

        switch (patients[k].slot) {
            case 1:
                slot[0] = 0;
                break;
            case 2:
                slot[1] = 0;
                break;
            case 3:
                slot[2] = 0;
                break;
            case 4:
                slot[3] = 0;
                break;
            case 5:
                slot[4] = 0;
                break;
        }

        printf("Successful Cancelation\n");
        patients[k].slot = 0;
    }
    else {
        printf("Not Successful ID, You are not in the system.\n");
    }
}

void serve(int n) {
    switch (n) {
        case 1:
            add_new_patient();
            break;
        case 2:
            reserve_slot();
            break;
        case 3:
            cancel();
            break;
        case 4:
            Edit_patient_record();
            break;
    }
}

void view_patient_record(int id, int j) {
    printf("Name: %s\n", patients[j].name);
    printf("Age: %d\n", patients[j].age);
    printf("Gender: %s\n", patients[j].gender);
    printf("slot: %d\n", patients[j].slot);

    if (patients[j].slot == 0)
        printf("You do not have a reservation.\n");
    else
        printf("You have a reservation in slot .\n");
}

void view_today_reservation() {
    if (slot[0] && slot[1] && slot[2] && slot[3] && slot[4])
        printf("No reservation for today.\n");
    else {
        if (slot[0])
            printf("       1. from 2pm to 2:30pm\n");
        if (slot[1])
            printf("       2. from 2:30pm to 3pm\n");
        if (slot[2])
            printf("       3. from 3pm to 3:30pm\n");
        if (slot[3])
            printf("       4. from 3:30pm to 4pm\n");
        if (slot[4])
            printf("       5. from 4pm to 4:30pm\n");
    }
}

int main() {
    int num;
    int pass;
    int i;
    int num_serve;
    int choice;
    int k, p;
    int id;

    while (1) {
        printf("Please choose from that:\n");
        printf("                            1. Admin mode\n");
        printf("                            2. User mode\n");
        printf("                            3. Exit\n");
        scanf("%d", &num);

        if (num == 1) {
            printf("Please enter the password: ");
            scanf("%d", &pass);
            for (i = 1; ((i < 3) && (pass != 1234)); i++) {
                printf("Now, You have %d trials, please enter the password: ", 3 - i);
                scanf("%d", &pass);
            }
            if (i == 3 || pass != 1234) {
                printf("Not correct password, you don't have any trial ever\n");
                continue;
            }

            printf("You can choose which service you need:\n");
            printf("          1. Add new patient\n");
            printf("          2. Reserve slot\n");
            printf("          3. Cancel reservation\n");
            printf("          4. Edit record\n");
            printf("Now, Enter your choice number: ");
            scanf("%d", &num_serve);
            serve(num_serve);

            while (num_serve) {
                printf("Enter number of service, if you need another servation\n");
                printf("If you need to exit, enter 0\n");
                scanf("%d", &num_serve);
                while (num_serve == 0) {
                    break;
                }
                if (num_serve) {
                    serve(num_serve);
                }
            }
        }
        else if (num == 2) {
            printf("Enter your ID: ");
            scanf("%d", &id);
            for (k = 0; k < max; k++) {
                if (id == patients[k].ID) {
                    p = 1;
                    break;
                }
                else {
                    p = 0;
                }
            }
            if (p == 1) {
                printf("Successful ID\n");
                printf("There are two options:\n");
                printf("            1. View patient record\n");
                printf("            2. View today's reservation\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        view_patient_record(id, k);
                        break;
                    case 2:
                        view_today_reservation();
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
            }
            else {
                printf("Not Successful ID\n");
            }
        }
        else if (num == 3) {
            printf("Exiting the program...\n");
            return 0;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}