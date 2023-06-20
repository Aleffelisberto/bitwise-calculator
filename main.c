/*
* Bitwise calculator.
*
* Program that performs bitwise operations on two inputs, irrespective of their format — binary, decimal, or hexadecimal.
*
* by: l00p1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define DECIMAL "dec"
#define HEXADECIMAL "hex"
#define BINARY "bin"

enum operators {
    AND,
    OR,
    XOR
};

static const char * const VALID_OPERATORS[] = {
    [AND] = "&",
    [OR] = "|",
    [XOR] = "^"
};

bool is_data_type_valid(char *data_type) {
    if (
        strcmp(data_type, DECIMAL) == 0
        || strcmp(data_type, HEXADECIMAL) == 0
        || strcmp(data_type, BINARY) == 0
    ) {
        return true;
    }
    printf("\033[0;31m[-] Invalid data type.\033[0m\n");

    return false;
}

bool is_decimal(char *input) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }

    return true;
}

bool is_valid_operator(char *input) {
    for (size_t i = 0; i < sizeof(VALID_OPERATORS) / sizeof(VALID_OPERATORS[0]); i++) {
        if (strcmp(VALID_OPERATORS[i], input) == 0) {
            return true;
        }
    }

    return false;
}

bool is_hexadecimal(char *input) {
    int i = 0;
    int input_length = strlen(input);
    if (input[0] == '0' && input[1] == 'x') {
        i = 2;
    }
    for (i; i < input_length; i++) {
        if (isxdigit(input[i]) == 0) {
            return false;
        }
    }

    return true;
}

bool is_binary(char *input) {
    int i = 0;
    int input_length = strlen(input);
    if (input[0] == '0' && input[1] == 'b') {
        i = 2;
    }
    for (i; i < input_length; i++) {
        if (input[i] != '1' && input[i] != '0') {
            return false;
        }
    }

    return true;
}

bool validate_decimal_inputs(char *operand1, char *operand2, char *operator) {
    int has_error = false;
    if (!is_decimal(operand1)) {
        printf("\033[0;31m[-] Entered operand1 (%s) is not a decimal.\033[0m\n", operand1);
        has_error = true;
    } else if (!is_decimal(operand2)) {
        printf("\033[0;31m[-] Entered operand2 (%s) is not a decimal.\033[0m\n", operand1);
        has_error = true;
    } else if (!is_valid_operator(operator)) {
        printf("\033[0;31m[-] Entered operator (%s) is not a valid.\033[0m\n", operator);
        has_error = true;
    }
    
    return !has_error;
}

bool validate_hexadecimal_inputs(char *operand1, char *operand2, char *operator) {
    int has_error = false;
    if (!is_hexadecimal(operand1)) {
        printf("[-] Entered operand1 (%s) is not a hexadecimal.\033[0m\n", operand1);
        has_error = true;
    } else if (!is_hexadecimal(operand2)) {
        printf("[-] Entered operand2 (%s) is not a hexadecimal.\033[0m\n", operand1);
        has_error = true;
    } else if (!is_valid_operator(operator)) {
        printf("[-] Entered operator (%s) is not a valid.\033[0m\n", operator);
        has_error = true;
    }
    
    return !has_error;
}

bool validate_binary_inputs(char *operand1, char *operand2, char *operator) {
    int has_error = false;
    if (!is_binary(operand1)) {
        printf("\033[0;31m[-] Entered operand1 (%s) is not a binary.\033[0m\n", operand1);
        has_error = true;
    } else if (!is_binary(operand2)) {
        printf("\033[0;31m[-] Entered operand2 (%s) is not a binary.\033[0m\n", operand1);
        has_error = true;
    } else if (!is_valid_operator(operator)) {
        printf("\033[0;31m[-] Entered operator (%s) is not a valid.\033[0m\n", operator);
        has_error = true;
    }
    
    return !has_error;
}

long long int decimal_to_binary(int input) {
    long long int bin_number = 0;
    int power = 0;
    
    while (input > 0) {
        int rem = input % 2;
        long long int temp = pow(10, power);
        bin_number += rem * temp;
        power++;
        input /= 2;
    }

    return bin_number;
}

void calculate(char *operand1, char *operand2, char *operator, char *data_type) {
    int int_op1, int_op2;
    if (strcmp(DECIMAL, data_type) == 0) {
        int_op1 = atoi(operand1);
        int_op2 = atoi(operand2);
        if (strcmp(VALID_OPERATORS[AND], operator) == 0) {
        printf("\033[0;36m[=] %d\033[0m\n", int_op1 & int_op2);
        } else if (strcmp(VALID_OPERATORS[OR], operator) == 0) {
            printf("\033[0;36m[=] %d\033[0m\n", int_op1 | int_op2);
        } else if (strcmp(VALID_OPERATORS[XOR], operator) == 0) {
            printf("\033[0;36m[=] %d\033[0m\n", int_op1 ^ int_op2);
        }
    } else if (strcmp(HEXADECIMAL, data_type) == 0) {
        int_op1 = (int)strtol(operand1, NULL, 16);
        int_op2 = (int)strtol(operand2, NULL, 16);
        if (strcmp(VALID_OPERATORS[AND], operator) == 0) {
        printf("\033[0;36m[=] 0x%x\033[0m\n", int_op1 & int_op2);
        } else if (strcmp(VALID_OPERATORS[OR], operator) == 0) {
            printf("\033[0;36m[=] 0x%x\033[0m\n", int_op1 | int_op2);
        } else if (strcmp(VALID_OPERATORS[XOR], operator) == 0) {
            printf("\033[0;36m[=] 0x%x\033[0m\n", int_op1 ^ int_op2);
        }
    } else if (strcmp(BINARY, data_type) == 0) {
        int_op1 = (int)strtol(operand1, NULL, 2);
        int_op2 = (int)strtol(operand2, NULL, 2);
        if (strcmp(VALID_OPERATORS[AND], operator) == 0) {
        printf("\033[0;36m[=] %lld\033[0m\n", decimal_to_binary(int_op1 & int_op2));
        } else if (strcmp(VALID_OPERATORS[OR], operator) == 0) {
            printf("\033[0;36m[=] %lld\033[0m\n", decimal_to_binary(int_op1 | int_op2));
        } else if (strcmp(VALID_OPERATORS[XOR], operator) == 0) {
            printf("\033[0;36m[=] %lld\033[0m\n", decimal_to_binary(int_op1 ^ int_op2));
        }
    }
}

int main(int argc, char **argv) {
    char data_type[4];
    system("clear");
    while (1) {
        do {
            printf("[+] Enter the data type (dec, hex or bin): ");
            scanf("%s", data_type);
        } while(!is_data_type_valid(data_type));


        bool valid_operation = false;
        char operand1[20], operand2[20], operator[3] = "";
        do {
            printf("[+] Enter your operation (like 0x4b & 0x3c): ");
            scanf("%s %s %s", operand1, operator, operand2);

            if (strcmp(data_type, "dec") == 0) {
                valid_operation = validate_decimal_inputs(operand1, operand2, operator);
            } else if (strcmp(data_type, "hex") == 0) {
                valid_operation = validate_hexadecimal_inputs(operand1, operand2, operator);
            } else if (strcmp(data_type, "bin") == 0) {
                valid_operation = validate_binary_inputs(operand1, operand2, operator);
            }
        } while (!valid_operation);

        calculate(operand1, operand2, operator, data_type);
    }

    return 0;
}