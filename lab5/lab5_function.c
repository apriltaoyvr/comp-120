// Lab 5: Functions

// Objectives

// By the end of this lab, students will be able to:

// 1. Define and implement functions with parameters and return values.
// 2. Identify the accumulator pattern - initialize, update, and return.
// 3. Use functions to process characters and strings.
// 4. Use `if` / `else if` / `else` statements to make decisions inside functions.
// 5. Call one function from another function.
// 6. Use `assert()` to test functions with different inputs.

// Your task is to implement the following eight functions.

// * Do not modify the function names, parameters, or return types.
// * Do not modify the tests or main() at the bottom of the file.
// * Compile and run the program to check your work. If all tests pass, you should see:
// All tests passed!
 

// Finally, remember to complete your **lab_quiz** on e-Learn after all your function implementations pass the tests.

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// ============================================================
// Function 1: int sum_integers(int num)
//
// Return the sum of all integers from 0 to num, inclusive.
//
// Examples:
//     sum_integers(0)  -> 0
//     sum_integers(1)  -> 1
//     sum_integers(5)  -> 15
//     sum_integers(10) -> 55
//
// Assume the input num is a non-negative integer.
// ============================================================

int sum_integers(int num) {
    int sum = 0;

    for (int i = 0; i <= num; ++i) {
        sum += i;
    }

    return sum;
}

// ============================================================
// Function 2: int sum_chars(char str[])
//
// Return the sum of the decimal values of all characters
// in the string.
//
// Examples:
//     sum_chars("")   -> 0
//     sum_chars("A")  -> 65
//     sum_chars("AB") -> 131
//
// Do not include the value of '\0'.
// ============================================================

int sum_chars(char str[]) {
    int sum = 0;

    for (int i = 0; i <= strlen(str); ++i) {
        sum += (int) str[i];
    }

    return sum;
}


// ============================================================
// Function 3: int running_total(int num)
//
// Return the square of num by adding |num| to a running total |num| times.
//
// Examples:
//     running_total(0)  -> 0
//     running_total(2)  -> 4
//     running_total(8) -> 64
//     running_total(-4) -> 16
//
// Hint: you may want to use abs() from <stdlib.h>,
// or multiply num by -1 if it is negative.   
// ============================================================

int running_total(int num) {
    int prod = 0;
    int absolute = abs(num);

    for (int i = 0; i < absolute; ++i) {
        prod += absolute;
    }

    return prod;
}


// ============================================================
// Function 4: char score_to_grade(int test_score)
//
// Return the matching letter grade for the test_score.
// If the score is not in the range of 0 - 100, return 'X';
// If the score is in the range of 90 - 100, return 'A';
// If the score is in the range of 80 - 89, return 'B';
// If the score is in the range of 70 - 79, return 'C';
// If the score is in the range of 60 - 69, return 'D';
// If the score is in the range of 50 - 59, return 'E';
// If the score is in the range of 0 - 49, return 'F';
//
// Examples:
//     score_to_grade(-1)  -> 'X'
//     score_to_grade(120)  -> 'X'
//     score_to_grade(91)  -> 'A'
//     score_to_grade(89)  -> 'B'
//     score_to_grade(45)  -> 'F'
//
// Assume the input test_score can be any integer
// ============================================================

char score_to_grade(int test_score) {
    if (test_score > 100 || test_score < 0)
        return 'X';
    else if (test_score >= 90)
        return 'A';
    else if (test_score >= 80)
        return 'B';
    else if (test_score >= 70)
        return 'C';
    else if (test_score >= 60)
        return 'D';
    else if (test_score >= 50)
        return 'E';
    else
        return 'F';
}


// ============================================================
// Function 5: int sum_range(int start, int end)
//
// Return the sum of all integers from start to end, inclusive.
//
// Examples:
//     sum_range(1, 5)   -> 15
//     sum_range(3, 6)   -> 18
//     sum_range(10, 10) -> 10
//
// Assume start is a non-negative integer, and start <= end.
// ============================================================

int sum_range(int start, int end) {
    int sum = 0;

    for (int i = start; i <= end; ++i) {
        sum += i;
    }

    return sum;
}

// ============================================================
// Function 5.1: double average_range(int start, int end)
//
// Return the average (2 decimal digits) of all integers from start to end, inclusive.
//
// Examples:
//     average_range(1, 3)   -> 2.00
//     average_range(2, 6)   -> 4.00
//     average_range(4, 5)   -> 4.50
//
// Assume start is a non-negative integer, and start <= end.
// Requirement: must call sum_range()
// ============================================================

double average_range(int start, int end) {
    double avg = 0.00;
    double size = (float) end - start + 1;

    if (size == 0) return 0;

    avg = sum_range(start, end);

    return avg / size;
}


// ============================================================
// Function 6: bool is_digit(char ch)
//
// Return true if the input char is a digit, false otherwise.
//
// Examples:
//     is_digit('a')  -> false
//     is_digit('1')  -> true
//     is_digit('0')  -> true
//
// ============================================================

bool is_digit(char ch) {
    if (ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}

// ============================================================
// Function 6.1: int count_digits(char str[])
//
// Return the number of digits in a string.
//
// Examples:
//     count_digits("abc")  -> 0
//     count_digits("01a")  -> 2
//     count_digits("Mc9nd")  -> 1
//
// Requirement: must call is_digit()
// ============================================================

int count_digits(char str[]) {
    int count = 0;

    for (int i = 0; i <= strlen(str); i++) {
        if (is_digit(str[i])) count++;
    }

    return count;
}


// ============================================================
// Do not modify the tests below.
// ============================================================

void test_sum_integers(void) {
    assert(sum_integers(0) == 0);
    assert(sum_integers(1) == 1);
    assert(sum_integers(2) == 3);
    assert(sum_integers(5) == 15);
    assert(sum_integers(10) == 55);
}

void test_sum_chars(void) {
    assert(sum_chars("") == 0);
    assert(sum_chars("A") == 65);
    assert(sum_chars("AB") == 131);
    assert(sum_chars("abc") == 294);
    assert(sum_chars("Hello") == 500);
}

void test_running_total(void) {
    assert(running_total(0) == 0);
    assert(running_total(1) == 1);
    assert(running_total(2) == 4);
    assert(running_total(5) == 25);
    assert(running_total(8) == 64);
    assert(running_total(-4) == 16);
}

void test_score_to_grade(void) {
    // Invalid scores
    assert(score_to_grade(-1) == 'X');
    assert(score_to_grade(-100) == 'X');
    assert(score_to_grade(101) == 'X');
    assert(score_to_grade(120) == 'X');

    // A: 90 - 100
    assert(score_to_grade(90) == 'A');
    assert(score_to_grade(100) == 'A');

    // B: 80 - 89
    assert(score_to_grade(80) == 'B');
    assert(score_to_grade(89) == 'B');

    // C: 70 - 79
    assert(score_to_grade(70) == 'C');
    assert(score_to_grade(79) == 'C');

    // D: 60 - 69
    assert(score_to_grade(60) == 'D');
    assert(score_to_grade(69) == 'D');

    // E: 50 - 59
    assert(score_to_grade(50) == 'E');
    assert(score_to_grade(59) == 'E');

    // F: 40 - 49
    assert(score_to_grade(40) == 'F');
    assert(score_to_grade(45) == 'F');

    // Scores below 40 but still in the valid range
    assert(score_to_grade(0) == 'F');
    assert(score_to_grade(39) == 'F');
}

void test_sum_range(void) {
    assert(sum_range(0, 0) == 0);
    assert(sum_range(1, 1) == 1);
    assert(sum_range(1, 5) == 15);
    assert(sum_range(3, 6) == 18);
    assert(sum_range(10, 10) == 10);
    assert(sum_range(10, 15) == 75);
}

void test_average_range(void) {
    assert(fabs(average_range(0, 0) - 0.00) < 0.000001); // fabs() from math.h
    assert(fabs(average_range(1, 3) - 2.00) < 0.000001);
    assert(fabs(average_range(2, 6) - 4.00) < 0.000001);
    assert(fabs(average_range(4, 5) - 4.50) < 0.000001);
    assert(fabs(average_range(1, 10) - 5.50) < 0.000001);
}

void test_is_digit(void) {
    // Digits
    assert(is_digit('0') == true);
    assert(is_digit('1') == true);
    assert(is_digit('5') == true);
    assert(is_digit('9') == true);

    // Non-digits
    assert(is_digit('a') == false);
    assert(is_digit('z') == false);
    assert(is_digit('A') == false);
    assert(is_digit(' ') == false);
    assert(is_digit('-') == false);
}

void test_count_digits(void) {
    assert(count_digits("") == 0);
    assert(count_digits("abc") == 0);
    assert(count_digits("01a") == 2);
    assert(count_digits("Mc9nd") == 1);
    assert(count_digits("12345") == 5);
    assert(count_digits("a1b2c3") == 3);
    assert(count_digits("Hello2026") == 4);
}


// ============================================================
// Do not modify the main() below.
// ============================================================

int main(void) {
    
    test_sum_integers();
    test_sum_chars();
    test_running_total();
    test_score_to_grade();
    test_sum_range();
    test_average_range();
    test_is_digit();
    test_count_digits();

    printf("All tests passed!\n");

    return 0;
}
