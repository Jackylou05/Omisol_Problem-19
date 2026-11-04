#include <stdio.h>

int main()
{
	float balance = 10000.00;
	float amount;
	int choice;
	int successful_withdrawals = 0;

	do {
		printf("\n1. Withdraw money\n");
		printf("2. Check balance\n");
		printf("3. Exit\n");
		printf("Choose an option: ");

		if (scanf("%d", &choice) != 1) {
			printf("Invalid input. Please enter 1, 2, or 3.\n");
			return 1;
		}

		switch (choice) {
		case 1:
			printf("Enter withdrawal amount: ");
			if (scanf("%lf", &amount) != 1) {
				printf("Invalid amount.\n");
				return 1;
			}

			if (amount <= 0.0) {
				printf("Withdrawal amount must be greater than zero.\n");
			} else if (amount > balance) {
				printf("Insufficient balance.\n");
			} else {
				balance -= amount;
				successful_withdrawals++;
				printf("Withdrawal successful.\n");
			}
			break;
		case 2:
			printf("Current balance: $%.2f\n", balance);
			break;
		case 3:
			printf("Successful withdrawals: %d\n", successful_withdrawals);
			printf("Remaining balance: $%.2f\n", balance);
			break;
		default:
			printf("Invalid option. Please choose 1, 2, or 3.\n");
		}
	} while (choice != 3);

	return 0;
}
