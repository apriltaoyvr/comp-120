// Lab 6: Arrays

// Objectives
//
// By the end of this lab, students will be able to:
//
// 1. Write functions that process arrays using parameters and lengths.
// 2. Loop over the elements of an integer array using an index.
// 3. Use the accumulator pattern and "tracking" variables (largest, counter) with arrays.
// 4. Modify an array in place inside a function.
// 5. Use early return inside a loop (true/false checks).
// 6. Use nested loops to compare pairs of elements.
// 7. Loop over a string until the null terminator '\0' (or using strlen()).
// 8. Use assert() to test functions with different inputs.

// Your task is to implement the following twelve functions.
//
// * Do not modify the function names, parameters, or return types.
// * Do not modify the tests or main() at the bottom of the file.
// * A function cannot tell how long an array is, so every array function
//   receives the array size as a parameter.
// * Compile and run the program to check your work. If all tests pass,
//   you should see: All tests passed!
//
// Finally, remember to complete your lab_quiz on e-Learn after the lab.

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ============================================================
// Function 1: double average(int nums[], int n)
//
// Return the average of the n numbers in nums.
//
// Examples:
//     {2, 4}       -> 3.0
//     {1, 2, 3, 4} -> 2.5
//
// Assume n > 0.
// ============================================================

double average(int nums[], int n) {
  int sum = 0;

  for (int i = 0; i < n; ++i) {
    sum += nums[i];
  }

  return (double)sum / n;
}

// ============================================================
// Function 2: void add_number(int nums[], int n, int k)
//
// Add k to every element in nums. Modify the array in place.
//
// Examples:
//     {1, 2, 3}, k = 5 -> {6, 7, 8}
//     {-2, 0}, k = 2   -> {0, 2}
// ============================================================

void add_number(int nums[], int n, int k) {
  for (int i = 0; i < n; ++i) {
    nums[i] += k;
  }
}

// ============================================================
// Function 3: bool is_increasing(int nums[], int n)
//
// Return true if every element is strictly greater than the
// element before it. Otherwise, return false.
//
// An array with one element is considered increasing.
// Assume n >= 1.
// ============================================================
bool is_increasing(int nums[], int n) {
  if (n == 1) return true;

  for (int i = 1; i < n; ++i) {
    if (nums[i] <= nums[i - 1]) return false;
  }

  return true;
}

// ============================================================
// Function 4: bool is_in_list(int nums[], int n, int k)
//
// Return true if the number k exists in the array, and false otherwise.
//
// Examples:
//     {1, 4, 5}, k = 4   -> true
//     {1, 4, 5}, k = 9   -> false
//     {7}, k = 7         -> true
//
// Do not use any built-in search function.
// ============================================================

bool is_in_list(int nums[], int n, int k) {
  for (int i = 0; i < n; ++i) {
    if (nums[i] == k) return true;
  }

  return false;
}

// ============================================================
// Function 5: bool all_even(int nums[], int n)
//
// Return true if all numbers in the array are even,
// and false otherwise. If the array is empty, return true.
//
// Examples:
//     {2, 4, 6}   -> true
//     {2, 3, 6}   -> false
//     {-2, 0}     -> true
//
// Hint: use the remainder operator %.
// ============================================================

bool all_even(int nums[], int n) {
  for (int i = 0; i < n; ++i) {
    if (nums[i] % 2 != 0) return false;
  }

  return true;
}

// ============================================================
// Function 6: int count_odd(int arr[], int size)
//
// Return how many numbers in the array are odd.
//
// Examples:
//     {1, 2, 3, 4, 5}  -> 3
//     {2, 4, 6}        -> 0
//     {-3, -2, -1}     -> 2
//
// ============================================================

int count_odd(int arr[], int size) {
	int count = 0;

  for (int i = 0; i < size; ++i) {
    if (arr[i] % 2 != 0) count++;
  }

  return count;
}

// ============================================================
// Function 7: int find_largest(int arr[], int size)
//
// Return the largest value in the array.
// Assume the array has at least one element.
//
// Examples:
//     {3, 9, 2}        -> 9
//     {-5, -2, -8}     -> -2
//     {7}              -> 7
//
// ============================================================

int find_largest(int arr[], int size) {
  int largest = arr[0];

	for (int i = 0; i < size; ++i) {
		if (arr[i] > largest) largest = arr[i];
	}

  return largest;
}

// ============================================================
// Function 8: void reverse_array(int arr[], int size)
//
// Reverse the array in place. The function returns nothing.
//
// Examples:
//     {1, 2, 3, 4}  -> array becomes {4, 3, 2, 1}
//     {5, 6, 7}     -> array becomes {7, 6, 5}
//     {9}           -> array becomes {9}
//
// Hint: swap arr[i] with arr[size - 1 - i].
// Only loop over the first half of the array, or you will
// swap everything back to where it started.
// ============================================================

void reverse_array(int arr[], int size) {
  for (int i = 0; i < size / 2; ++i) {
		int r = size - 1 - i;
		int tmp = arr[i];

		arr[i] = arr[r];
		arr[r] = tmp;
	}
}

// ============================================================
// Function 9: void fibonacci(int arr[], int n)
//
// Fill the first n elements of the array with the Fibonacci
// sequence, starting with 0 and 1. Each number after the first
// two is the sum of the previous two.
// If n is 0, the function does nothing.
//
// Assume n >= 0 and arr has room for n integers.
//
// Examples:
//     n = 1   -> array starts with {0}
//     n = 2   -> array starts with {0, 1}
//     n = 7   -> array starts with {0, 1, 1, 2, 3, 5, 8}
//
// Hint: the first two values are special cases. Only set
// arr[1] if n is at least 2. Then loop from i = 2 and use
// arr[i] = arr[i - 1] + arr[i - 2].
// Assume the array has room for at least n elements.
// ============================================================

void fibonacci(int arr[], int n) {
	if (n == 0) return;

	arr[0] = 0;
	if (n >= 2) arr[1] = 1;

  for (int i = 2; i < n; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}

// ============================================================
// Function 10: bool has_pair_sum(int arr[], int size, int target)
//
// Return true if two different elements (at different positions)
// add up to target, and false otherwise.
//
// Examples:
//     {2, 7, 11, 15}, target = 9   -> true   (2 + 7)
//     {1, 2, 3}, target = 7        -> false
//     {3, 3}, target = 6           -> true   (two different positions)
//     {5}, target = 10             -> false  (an element cannot pair with itself)
//
// Hint: use nested loops. Let j start at i + 1 so that you never
// pair an element with itself. Return true as soon as you find
// a pair, and false after both loops finish.
// ============================================================

bool has_pair_sum(int arr[], int size, int target) {
  for (int i = 0; i < size; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] + arr[j] == target) return true;
		}
	}

  return false;
}

// ============================================================
// Function 11: int is_palindrome(char str[])
//
// Return true if the string reads the same forward and backward,
// and false otherwise.
// Case matters ("Aba" is not a palindrome).
// An empty string or a single character counts as a palindrome.
//
// Examples:
//     is_palindrome("level")  -> true
//     is_palindrome("hello")  -> false
//     is_palindrome("Aba")    -> true
//     is_palindrome("")       -> false
//
// ============================================================

bool is_palindrome(char str[]) {
  if (strlen(str) == 0) return true;

	for (int i = 0; i < strlen(str) - 1; ++i) {
		if (str[i] != str[strlen(str) - 1 - i]) return false;
	}

  return true;
}

// ============================================================
// Function 12: void reverse_string(char str[])
//
// Reverse the string in place. The function returns nothing.
//
// Examples:
//     "hello"  -> string becomes "olleh"
//     "ab"     -> string becomes "ba"
//     "x"      -> string becomes "x"
//
// Hint: swap str[i] with str[len - 1 - i], looping over the
// first half only. Do not move the '\0' at the end of the string.
// ============================================================

void reverse_string(char str[]) {
  for (int i = 0; i < strlen(str) / 2; ++i) {
		int r = strlen(str) - 1 - i;
		int tmp = str[i];

		str[i] = str[r];
		str[r] = tmp;
	}
}

// ============================================================
// Do not modify the tests below.
// ============================================================

void test_average(void) {
  int a[] = {2, 4, 6};
  int b[] = {1, 2};
  int c[] = {5};
  int d[] = {-2, 2};
  int e[] = {1, 2, 3, 4};
  int empty[1] = {0};

  assert(fabs(average(a, 3) - 4.0) < 0.000001);  // fabs() from math.h
  assert(fabs(average(b, 2) - 1.5) < 0.000001);
  assert(fabs(average(c, 1) - 5.0) < 0.000001);
  assert(fabs(average(d, 2) - 0.0) < 0.000001);
  assert(fabs(average(e, 4) - 2.5) < 0.000001);
}

// Helper for the tests: returns true if two int arrays are equal.
bool arrays_equal(int a[], int b[], int size) {
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

void test_add_number(void) {
  int a[] = {1, 2, 3};
  int b[] = {10, 20};
  int c[] = {4, 4};
  int d[] = {-1, 0, 1};

  add_number(a, 3, 5);
  add_number(b, 2, -5);
  add_number(c, 2, 0);
  add_number(d, 3, 1);

  int exp_a[] = {6, 7, 8};
  int exp_b[] = {5, 15};
  int exp_c[] = {4, 4};
  int exp_d[] = {0, 1, 2};

  assert(arrays_equal(a, exp_a, 3));
  assert(arrays_equal(b, exp_b, 2));
  assert(arrays_equal(c, exp_c, 2));
  assert(arrays_equal(d, exp_d, 3));
}

void test_is_increasing(void) {
  int a[] = {1, 3, 7};
  int b[] = {1, 5, 2};
  int c[] = {4};
  int d[] = {2, 2, 3};
  int e[] = {-5, -2, 0, 10};
  int f[] = {5, 4, 3};
  int g[] = {1, 2, 3, 4, 5, 4};

  assert(is_increasing(a, 3) == true);
  assert(is_increasing(b, 3) == false);
  assert(is_increasing(c, 1) == true);
  assert(is_increasing(d, 3) == false);
  assert(is_increasing(e, 4) == true);
  assert(is_increasing(f, 3) == false);
  assert(is_increasing(g, 6) == false);
}

void test_is_in_list(void) {
  int a[] = {1, 4, 5};
  int b[] = {7};
  int c[] = {-3, 0, 3};
  int empty[1] = {0};

  assert(is_in_list(a, 3, 4) == true);
  assert(is_in_list(a, 3, 9) == false);
  assert(is_in_list(b, 1, 7) == true);
  assert(is_in_list(c, 3, -3) == true);
  assert(is_in_list(c, 3, 2) == false);
  assert(is_in_list(empty, 0, 0) == false);
}

void test_all_even(void) {
  int a[] = {2, 4, 6};
  int b[] = {2, 3, 6};
  int c[] = {0};
  int d[] = {-2, -4};
  int e[] = {1};
  int empty[1] = {0};

  assert(all_even(a, 3) == true);
  assert(all_even(b, 3) == false);
  assert(all_even(c, 1) == true);
  assert(all_even(d, 2) == true);
  assert(all_even(e, 1) == false);
  assert(all_even(empty, 0) == true);
}

void test_count_odd(void) {
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {2, 4, 6};
  int c[] = {-3, -2, -1};
  int d[] = {7};
  int e[] = {0};
  int f[] = {1, 3, 5, 7};

  assert(count_odd(a, 5) == 3);
  assert(count_odd(b, 3) == 0);
  assert(count_odd(c, 3) == 2);
  assert(count_odd(d, 1) == 1);
  assert(count_odd(e, 1) == 0);
  assert(count_odd(f, 4) == 4);
}

void test_find_largest(void) {
  int a[] = {3, 9, 2};
  int b[] = {-5, -2, -8};
  int c[] = {7};
  int d[] = {1, 2, 3, 4, 5};
  int e[] = {5, 4, 3};
  int f[] = {-1, -1};

  assert(find_largest(a, 3) == 9);
  assert(find_largest(b, 3) == -2);
  assert(find_largest(c, 1) == 7);
  assert(find_largest(d, 5) == 5);
  assert(find_largest(e, 3) == 5);
  assert(find_largest(f, 2) == -1);
}

void test_reverse_array(void) {
  int a[] = {1, 2, 3, 4};
  int b[] = {5, 6, 7};
  int c[] = {9};
  int d[] = {1, 2};

  reverse_array(a, 4);
  reverse_array(b, 3);
  reverse_array(c, 1);
  reverse_array(d, 2);

  int exp_a[] = {4, 3, 2, 1};
  int exp_b[] = {7, 6, 5};
  int exp_c[] = {9};
  int exp_d[] = {2, 1};

  assert(arrays_equal(a, exp_a, 4));
  assert(arrays_equal(b, exp_b, 3));
  assert(arrays_equal(c, exp_c, 1));
  assert(arrays_equal(d, exp_d, 2));
}

void test_fibonacci(void) {
  int a[10];
  int b[2];
  int c[7];
  int one[1] = {99};
  int zero[1] = {99};

  fibonacci(a, 10);
  fibonacci(b, 2);
  fibonacci(c, 7);
  fibonacci(one, 1);
  fibonacci(zero, 0);

  int exp_a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
  int exp_b[] = {0, 1};
  int exp_c[] = {0, 1, 1, 2, 3, 5, 8};

  assert(arrays_equal(a, exp_a, 10));
  assert(arrays_equal(b, exp_b, 2));
  assert(arrays_equal(c, exp_c, 7));
  assert(one[0] == 0);
  assert(zero[0] == 99);  // n = 0 must not change the array
}

void test_has_pair_sum(void) {
  int a[] = {2, 7, 11, 15};
  int b[] = {1, 2, 3};
  int c[] = {3, 3};
  int d[] = {5};
  int e[] = {-1, 4, 6};
  int empty[1] = {0};

  assert(has_pair_sum(a, 4, 9) == true);
  assert(has_pair_sum(b, 3, 7) == false);
  assert(has_pair_sum(c, 2, 6) == true);
  assert(has_pair_sum(d, 1, 10) == false);
  assert(has_pair_sum(e, 3, 5) == true);
  assert(has_pair_sum(b, 3, 6) == false);  // 3 + 3 is not allowed: only one 3
  assert(has_pair_sum(empty, 0, 0) == false);
}

void test_is_palindrome(void) {
  assert(is_palindrome("level") == 1);
  assert(is_palindrome("hello") == 0);
  assert(is_palindrome("abba") == 1);
  assert(is_palindrome("Aba") == 0);
  assert(is_palindrome("x") == 1);
  assert(is_palindrome("") == 1);
  assert(is_palindrome("racecar") == 1);
  assert(is_palindrome("ab") == 0);
}

void test_reverse_string(void) {
  char a[] = "hello";
  char b[] = "ab";
  char c[] = "x";
  char d[] = "";
  char e[] = "abcd";
  char f[] = "racecar";

  reverse_string(a);
  reverse_string(b);
  reverse_string(c);
  reverse_string(d);
  reverse_string(e);
  reverse_string(f);

  assert(strcmp(a, "olleh") == 0);
  assert(strcmp(b, "ba") == 0);
  assert(strcmp(c, "x") == 0);
  assert(strcmp(d, "") == 0);
  assert(strcmp(e, "dcba") == 0);
  assert(strcmp(f, "racecar") == 0);
}

// ============================================================
// Do not modify the main() below.
// ============================================================

int main(void) {
  test_average();
  test_add_number();
  test_is_increasing();
  test_is_in_list();
  test_all_even();
  test_count_odd();
  test_find_largest();
  test_reverse_array();
  test_fibonacci();
  test_has_pair_sum();
  test_is_palindrome();
  test_reverse_string();

  printf("All tests passed!\n");

  return 0;
}