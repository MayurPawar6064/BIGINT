#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Aadhar list
struct AadharNode {
    char name[50];
    char address[100];
    int aadharNumber;  
    struct AadharNode* next;
};

// Structure for PAN list
struct PANNode {
    char name[50];
    char address[100];
    char panNumber[10];
    int aadharNumber; 
    struct PANNode* next;
};

// Structure for bank accounts list
struct BankNode {
    char name[50];
    char panNumber[10];
    char bank[50];
    int accountNumber; 
    int aadharNumber;
    double depositedAmount;
    struct BankNode* next;
};

// Structure for LPG subsidy list
struct LPGNode {
    char name[50];
    int accountNumber;
	int aadharNumber;  
    char subsidy[3];    // "YES" or "NO"
    struct LPGNode* next;
};

// Function to insert data into Aadhar list
struct AadharNode* insertAadhar(struct AadharNode* head, char name[], char address[], int aadharNumber) {
    struct AadharNode* newNode = (struct AadharNode*)malloc(sizeof(struct AadharNode));
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    newNode->aadharNumber = aadharNumber;
    newNode->next = head;
    return newNode;
}

// Function to delete data from Aadhar list based on Aadhar number
struct AadharNode* deleteAadhar(struct AadharNode* head, int aadharNumber) {
    struct AadharNode *current = head, *prev = NULL;

    while (current != NULL) {
        if (current->aadharNumber == aadharNumber) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }

    printf("Aadhar number not found.\n");
    return head;
}

// Function to display Aadhar list
void displayAadhar(struct AadharNode* head) {
    printf("\nAadhar List:\n");
    while (head != NULL) {
        printf("Name: %s, Address: %s, Aadhar Number: %d\n", head->name, head->address, head->aadharNumber);
        head = head->next;
    }
}

// Function to insert data into PAN list
struct PANNode* insertPAN(struct PANNode* head, char name[], char address[], char panNumber[], int aadharNumber) {
    struct PANNode* newNode = (struct PANNode*)malloc(sizeof(struct PANNode));
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    strcpy(newNode->panNumber, panNumber);
    newNode->aadharNumber = aadharNumber;
    newNode->next = head;
    return newNode;
}
// Function to delete data from PAN list based on PAN number
struct PANNode* deletePAN(struct PANNode* head, char panNumber[]) {
    struct PANNode *current = head, *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->panNumber, panNumber) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }

    printf("PAN number not found.\n");
    return head;
}
// Function to display PAN list
void displayPAN(struct PANNode* head) {
    printf("\nPAN List:\n");
    while (head != NULL) {
        printf("Name: %s, Address: %s, PAN Number: %s, Aadhar Number: %d\n", head->name, head->address, head->panNumber, head->aadharNumber);
        head = head->next;
    }
}

// Function to insert data into bank accounts list
struct BankNode* insertBank(struct BankNode* head, char name[], char panNumber[], char bank[], int accountNumber, int aadharNumber, double depositedAmount) {
    struct BankNode* newNode = (struct BankNode*)malloc(sizeof(struct BankNode));
    strcpy(newNode->name, name);
    strcpy(newNode->panNumber, panNumber);
    strcpy(newNode->bank, bank);
    newNode->accountNumber = accountNumber;
    newNode->aadharNumber = aadharNumber;
    newNode->depositedAmount = depositedAmount;
    newNode->next = head;
    return newNode;
}
// Function to delete data from bank accounts list based on account number
struct BankNode* deleteBank(struct BankNode* head, int accountNumber) {
    struct BankNode *current = head, *prev = NULL;

    while (current != NULL) {
        if (current->accountNumber == accountNumber) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }

    printf("Account number not found.\n");
    return head;
}

// Function to display bank accounts list
void displayBank(struct BankNode* head) {
    printf("\nBank Accounts List:\n");
    while (head != NULL) {
        printf("Name: %s, PAN Number: %s, Bank: %s, Account Number: %d, Deposited Amount: %.2f\n",
               head->name, head->panNumber, head->bank, head->accountNumber, head->depositedAmount);
        head = head->next;
    }
}

// Function to insert data into LPG subsidy list
struct LPGNode* insertLPG(struct LPGNode* head, char name[], int accountNumber, char subsidy[], int aadharNumber) {
    struct LPGNode* newNode = (struct LPGNode*)malloc(sizeof(struct LPGNode));
    strcpy(newNode->name, name);
    newNode->accountNumber = accountNumber;
    strcpy(newNode->subsidy, subsidy);
    newNode->aadharNumber = aadharNumber; 
    newNode->next = head;
    return newNode;
}

// Function to display LPG subsidy list
void displayLPG(struct LPGNode* head) {
    printf("\nLPG Subsidy List:\n");
    while (head != NULL) {
        printf("Name: %s, Account Number: %d, Subsidy: %s\n", head->name, head->accountNumber, head->subsidy);
        head = head->next;
    }
}

// Function to delete data from LPG subsidy list based on account number
struct LPGNode* deleteLPG(struct LPGNode* head, int accountNumber) {
    struct LPGNode *current = head, *prev = NULL;

    while (current != NULL) {
        if (current->accountNumber == accountNumber) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }

    printf("Account number not found.\n");
    return head;
}

// Function to free memory of a linked list
void freeList(void* head) {
    void* current = head;
    while (current != NULL) {
        void* next = ((struct AadharNode*)current)->next;
        free(current);
        current = next;
    }
}
// Function to print details of individuals with Aadhar numbers but no PAN numbers
void AadharWithoutPAN(struct AadharNode* aadharList, struct PANNode* panList) {
    struct AadharNode* currentAadhar = aadharList;

    printf("\nIndividuals with Aadhar numbers but no PAN numbers:\n");
    int found = 0;

    while (currentAadhar != NULL) {
        // Check if the Aadhar number exists in the PAN list
        struct PANNode* currentPAN = panList;
        found = 0;

        while (currentPAN != NULL) {
            if (currentPAN->aadharNumber == currentAadhar->aadharNumber) {
                found = 1;
                break;
            }
            currentPAN = currentPAN->next;
        }

        // If not found, print details
        if (!found) {
            printf("Name: %s, Address: %s, Aadhar Number: %d\n",
                   currentAadhar->name, currentAadhar->address, currentAadhar->aadharNumber);
        }

        currentAadhar = currentAadhar->next;
    }

    // If no match found, print a message
    if (!found) {
        printf("No individuals found with Aadhar numbers but no PAN numbers.\n");
    }
}
int PeopleWithMultiplePAN(struct PANNode* panList) {
    struct PANNode* current = panList;
    struct PANNode* temp;
    int count;

    printf("\nPeople with multiple PAN numbers:\n");

    while (current != NULL) {
        // Check if the current person has multiple PAN numbers
        count = 0;
        temp = panList;

        while (temp != NULL) {
            if (strcmp(current->name, temp->name) == 0 && current->aadharNumber == temp->aadharNumber) {
                count++;
                if (count > 1) {
                    break; // Exit the loop once multiple PAN numbers are found
                }
            }
            temp = temp->next;
        }

        // If the person has multiple PAN numbers, print details
        if (count > 1) {
            printf("Name: %s, Address: %s, Aadhar Number: %d\n", current->name, current->address, current->aadharNumber);
            printf("PAN Numbers: ");

            // Print all PAN numbers for the person
            temp = panList;
            while (temp != NULL) {
                if (strcmp(current->name, temp->name) == 0 && current->aadharNumber == temp->aadharNumber) {
                    printf("%s ", temp->panNumber);
                }
                temp = temp->next;
            }

            printf("\n\n");
        }

        current = current->next;
    }

    // If no one has multiple PAN numbers, print a message
    if (count == 0) {
        printf("No one found with multiple PAN numbers.\n");
    }
    return count;
}
int countPANNodes(struct PANNode* panList, char name[], int aadharNumber) {
    struct PANNode* current = panList;
    int count = 0;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0 && current->aadharNumber == aadharNumber) {
            count++;
        }
        current = current->next;
    }

    return count;
}

void PeopleWithMultiplePANAndBankAccounts(struct BankNode* bankList, struct PANNode* panList) {
    struct PANNode* currentPAN = panList;

    printf("\nPeople with multiple PAN numbers and multiple bank accounts:\n");
    int found = 0;

    while (currentPAN != NULL) {
        // Check if the current person has multiple PAN numbers
        int countPAN = countPANNodes(panList, currentPAN->name, currentPAN->aadharNumber);

        // If the person has multiple PAN numbers, check for multiple bank accounts
        if (countPAN > 1) {
            // Find the corresponding bank details
            struct BankNode* currentBank = bankList;

            while (currentBank != NULL) {
                if (strcmp(currentPAN->name, currentBank->name) == 0 && strcmp(currentPAN->panNumber, currentBank->panNumber) == 0) {
                    found = 1;
                    printf("Name: %s, Address: %s, Aadhar Number: %d\n", currentPAN->name, currentPAN->address, currentPAN->aadharNumber);
                    printf("PAN Number: %s\n", currentPAN->panNumber);
                    printf("Bank Accounts: ");

                    // Print all bank accounts for the person under different PAN numbers
                    struct BankNode* tempBank = bankList;
                    while (tempBank != NULL) {
                        if (strcmp(currentPAN->name, tempBank->name) == 0 && strcmp(currentPAN->panNumber, tempBank->panNumber) != 0) {
                            printf("%s, ", tempBank->bank);
                        }
                        tempBank = tempBank->next;
                    }

                    printf("\n\n");
                }

                currentBank = currentBank->next;
            }
        }

        currentPAN = currentPAN->next;
    }

    // If no one has multiple PAN numbers and multiple bank accounts, print a message
    if (!found) {
        printf("No one found with multiple PAN numbers and multiple bank accounts.\n");
    }
}

// Function to print details (Aaadhar, PAN, all bank-account details) of a person who has availed LPG subsidy
void PersonWithLPGSubsidy(struct AadharNode* aadharList, struct PANNode* panList, struct BankNode* bankList, struct LPGNode* lpgList) {
    int found = 0;

    struct LPGNode* currentLPG = lpgList;

    while (currentLPG != NULL) {
        if (strcmp(currentLPG->subsidy, "YES") == 0) {
            // Check if the account number exists in the Bank list
            struct BankNode* currentBank = bankList;
            found = 0;

            while (currentBank != NULL) {
                if (currentBank->accountNumber == currentLPG->accountNumber) {
                    found = 1;
                    break;
                }
                currentBank = currentBank->next;
            }

            if (found) {
                // Find Aadhar details
                struct AadharNode* currentAadhar = aadharList;
                while (currentAadhar != NULL) {
                    if (currentAadhar->aadharNumber == currentBank->aadharNumber) {
                        printf("\nDetails of person with LPG subsidy:\n");
                        printf("Name: %s, Address: %s, Aadhar Number: %d\n",
                               currentAadhar->name, currentAadhar->address, currentAadhar->aadharNumber);

                        // Find PAN details
                        struct PANNode* currentPAN = panList;
                        while (currentPAN != NULL) {
                            if (currentPAN->aadharNumber == currentBank->aadharNumber) {
                                printf("PAN Number: %s\n", currentPAN->panNumber);
                                break;
                            }
                            currentPAN = currentPAN->next;
                        }

                        // Print all bank account details
                        printf("Bank Accounts:\n");
                        while (currentBank != NULL && currentBank->aadharNumber == currentAadhar->aadharNumber) {
                            printf("Bank: %s, Account Number: %d, Deposited Amount: %.2f\n",
                                   currentBank->bank, currentBank->accountNumber, currentBank->depositedAmount);
                            currentBank = currentBank->next;
                        }

                        found = 1;
                        break;
                    }
                    currentAadhar = currentAadhar->next;
                }
            }
        }

        currentLPG = currentLPG->next;
    }

    // If no match found, print a message
    if (!found) {
        printf("No person found with LPG subsidy or they have not availed the subsidy.\n");
    }
}
// Function to print details of people with total savings greater than amount X and LPG subsidy
void PeopleWithSavingsAndLPGSubsidy(struct AadharNode* aadharList, struct PANNode* panList,
                                         struct BankNode* bankList, struct LPGNode* lpgList, double amountX) {
    struct LPGNode* currentLPG = lpgList;

    while (currentLPG != NULL) {
        if (strcmp(currentLPG->subsidy, "YES") == 0) {
            // Check if the account number exists in the Bank list
            struct BankNode* currentBank = bankList;
            double totalSavings = 0;

            while (currentBank != NULL) {
                if (currentBank->accountNumber == currentLPG->accountNumber) {
                    totalSavings += currentBank->depositedAmount;
                }
                currentBank = currentBank->next;
            }

            // If total savings are greater than amount X, print details
            if (totalSavings > amountX) {
                // Find Aadhar details
                struct AadharNode* currentAadhar = aadharList;
                while (currentAadhar != NULL) {
                    if (currentAadhar->aadharNumber == currentLPG->aadharNumber) {
                        printf("\nDetails of person with savings > %.2f and LPG subsidy:\n", amountX);
                        printf("Name: %s, Address: %s, Aadhar Number: %d\n",
                               currentAadhar->name, currentAadhar->address, currentAadhar->aadharNumber);

                        // Find PAN details
                        struct PANNode* currentPAN = panList;
                        while (currentPAN != NULL) {
                            if (currentPAN->aadharNumber == currentLPG->aadharNumber) {
                                printf("PAN Number: %s\n", currentPAN->panNumber);
                                break;
                            }
                            currentPAN = currentPAN->next;
                        }

                        printf("Total Savings: %.2f\n", totalSavings);
                        break;
                    }
                    currentAadhar = currentAadhar->next;
                }
            }
        }

        currentLPG = currentLPG->next;
    }
}
// Function to print details of people with inconsistent names
void InconsistentData(struct AadharNode* aadharList, struct PANNode* panList,
                            struct BankNode* bankList, struct LPGNode* lpgList) {
    struct AadharNode* currentAadhar = aadharList;

    while (currentAadhar != NULL) {
        // Check PAN list for inconsistent names
        struct PANNode* currentPAN = panList;
        while (currentPAN != NULL) {
            if (currentAadhar->aadharNumber == currentPAN->aadharNumber &&
                strcmp(currentAadhar->name, currentPAN->name) != 0) {
                printf("\nInconsistent Data Found:\n");
                printf("Aadhar Name: %s, PAN Name: %s, Aadhar Number: %d\n",
                       currentAadhar->name, currentPAN->name, currentAadhar->aadharNumber);
                break;
            }
            currentPAN = currentPAN->next;
        }

        // Check Bank list for inconsistent names
        struct BankNode* currentBank = bankList;
        while (currentBank != NULL) {
            if (currentAadhar->aadharNumber == currentBank->accountNumber &&
                strcmp(currentAadhar->name, currentBank->name) != 0) {
                printf("\nInconsistent Data Found:\n");
                printf("Aadhar Name: %s, Bank Name: %s, Aadhar Number: %d\n",
                       currentAadhar->name, currentBank->name, currentAadhar->aadharNumber);
                break;
            }
            currentBank = currentBank->next;
        }

        // Check LPG list for inconsistent names
        struct LPGNode* currentLPG = lpgList;
        while (currentLPG != NULL) {
            if (currentAadhar->aadharNumber == currentLPG->aadharNumber &&
                strcmp(currentAadhar->name, currentLPG->name) != 0) {
                printf("\nInconsistent Data Found:\n");
                printf("Aadhar Name: %s, LPG Name: %s, Aadhar Number: %d\n",
                       currentAadhar->name, currentLPG->name, currentAadhar->aadharNumber);
                break;
            }
            currentLPG = currentLPG->next;
        }

        currentAadhar = currentAadhar->next;
    }
}
// Function to merge two bank account lists and display the result
struct BankNode* mergeAndDisplayLists(struct BankNode* list1, struct BankNode* list2) {
    // If the first list is empty, return the second list
    if (list1 == NULL) {
        return list2;
    }

    // Traverse the first list to the last node
    struct BankNode* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }

    // Attach the second list to the end of the first list
    current->next = list2;

    // Display the merged list
    displayBank(list1);

    return list1;
}


int main() {
    struct AadharNode* aadharList = NULL;
    struct PANNode* panList = NULL;
    struct BankNode* bankList = NULL;
    struct LPGNode* lpgList = NULL;

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Aadhar data\n");
        printf("2. Delete Aadhar data\n");
        printf("3. Display Aadhar data\n");
        printf("4. Insert PAN data\n");
        printf("5. Delete PAN data\n");
        printf("6. Display PAN data\n");
        printf("7. Insert Bank data\n");
        printf("8. Delete Bank data\n");
        printf("9. Display Bank data\n");
        printf("10. Insert LPG subsidy data\n");
        printf("11. Display LPG subsidy data\n");
        printf("12. Delete data from LPG subsidy list\n");
        printf("13(1). Print individuals with Aadhar but no PAN\n");
        printf("14(2). print individuals data with multiple pan numbers\n");
        printf("15(3). print individuals data with multiple bank accounts under multiple pan numbers\n");
        printf("16(4). print individuals data who has taken LPG subsidy\n");
        printf("17(5). print individuals data of by comparing their savings by the given amount X\n");
        printf("18(6). print individuals data whose data is inconsistent\n");
        printf("19(7). merge two banklits\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50], address[100];
                int aadharNumber;
                printf("Enter Aadhar data (Name Address AadharNumber): ");
                scanf("%s %s %d", name, address, &aadharNumber);
                aadharList = insertAadhar(aadharList, name, address, aadharNumber);
                break;
            }
            case 2: {
                int aadharNumber;
                printf("Enter Aadhar number to delete: ");
                scanf("%d", &aadharNumber);
                aadharList = deleteAadhar(aadharList, aadharNumber);
                break;
            }
            case 3:
                displayAadhar(aadharList);
                break;
            case 4: {
                char name[50], address[100], panNumber[10];
                int aadharNumber;
                printf("Enter PAN data (Name Address PANNumber AadharNumber): ");
                scanf("%s %s %s %d", name, address, panNumber, &aadharNumber);
                panList = insertPAN(panList, name, address, panNumber, aadharNumber);
                break;
            }
            case 5: {
                char panNumber[10];
                printf("Enter PAN number to delete: ");
                scanf("%s", panNumber);
                panList = deletePAN(panList, panNumber);
           }
            case 6:
                displayPAN(panList);
                break;
            case 7: {
                char name[50], panNumber[10], bank[50];
                int accountNumber;
                int aadharNumber;
                double depositedAmount;
                printf("Enter Bank data (Name PANNumber Bank AccountNumber aadharNumber DepositedAmount): ");
                scanf("%s %s %s %d %d %lf", name, panNumber, bank, &accountNumber, &aadharNumber, &depositedAmount);
                bankList = insertBank(bankList, name, panNumber, bank, accountNumber, aadharNumber, depositedAmount);
                break;
            }
            case 8: {
                 int deleteAccountNumber;
                 printf("Enter account number to delete from Bank list: ");
                 scanf("%d", &deleteAccountNumber);
                 bankList = deleteBank(bankList, deleteAccountNumber);
                 break;
                }
            case 9:
                displayBank(bankList);
                break;
            case 10: {
                char name[50], subsidy[3];
                int accountNumber;
                int aadharNumber;
                printf("Enter LPG data (Name AccountNumber Subsidy): ");
                scanf("%s %d %s %d", name, &accountNumber, subsidy, &aadharNumber);
                lpgList = insertLPG(lpgList, name, accountNumber, subsidy, aadharNumber);
                break;
            }
            case 11:
                displayLPG(lpgList);
                break;
            case 12: {
                int deleteAccountNumber;
                printf("Enter account number to delete from LPG list: ");
                scanf("%d", &deleteAccountNumber);
                lpgList = deleteLPG(lpgList, deleteAccountNumber);
                break;
            }
            case 13:{
                AadharWithoutPAN(aadharList, panList);
                break;
            }
			case 14:
            {
		     	PeopleWithMultiplePAN(panList);
            	break;
            }
			case 15:
            {
					PeopleWithMultiplePANAndBankAccounts( bankList, panList);
                break;
			}
			case 16:
			{
			    PersonWithLPGSubsidy(aadharList, panList, bankList, lpgList);      
		         break;
		    }
			case 17:
	        {
		        double amountX;
                printf("Enter amount X: ");
                scanf("%lf", &amountX);

               // Print details of people with savings greater than amount X and LPG subsidy
                PeopleWithSavingsAndLPGSubsidy(aadharList, panList, bankList, lpgList, amountX);
               break;
			}
            case 18:
            	{
            		InconsistentData( aadharList,  panList, bankList,  lpgList); 
            		break;
				}
			case 19:
			{
				struct BankNode* bankList1 = NULL;
                struct BankNode* bankList2 = NULL;

                // Input for the first bank list
                int numAccounts1;
                printf("Enter the number of accounts for the first list: ");
                scanf("%d", &numAccounts1);

                for (int i = 0; i < numAccounts1; i++) 
				{
                char name[50], panNumber[10], bank[50];
                int accountNumber;
                int aadharNumber;
                double depositedAmount;

                printf("Enter Bank data (Name PANNumber Bank AccountNumber aadharNumber DepositedAmount) for account %d: ", i + 1);
                scanf("%s %s %s %d %d %lf", name, panNumber, bank, &accountNumber, &aadharNumber, &depositedAmount);

                bankList1 = insertBank(bankList1, name, panNumber, bank, accountNumber, aadharNumber, depositedAmount);
                } 

               // Input for the second bank list
               int numAccounts2;
               printf("\nEnter the number of accounts for the second list: ");
               scanf("%d", &numAccounts2);

               for (int i = 0; i < numAccounts2; i++) {
               char name[50], panNumber[10], bank[50];
               int accountNumber;
               int aadharNumber;
               double depositedAmount;

               printf("Enter Bank data (Name PANNumber Bank AccountNumber aadharNumber, DepositedAmount) for account %d: ", i + 1);
               scanf("%s %s %s %d %d %lf", name, panNumber, bank, &accountNumber, &aadharNumber, &depositedAmount);

               bankList2 = insertBank(bankList2, name, panNumber, bank, accountNumber, aadharNumber, depositedAmount);
              }

              // Display the first bank list
            printf("\nFirst Bank List:\n");
            displayBank(bankList1);

            // Display the second bank list
            printf("\nSecond Bank List:\n");
            displayBank(bankList2);

           // Merge and display the lists
           printf("\nMerged Bank List:\n");
           struct BankNode* mergedList = mergeAndDisplayLists(bankList1, bankList2);
     
	        break;
	}
			  
 
			case 0:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    // Free memory
    freeList(aadharList);
    freeList(panList);
    freeList(bankList);
    freeList(lpgList);

    return 0;
}

