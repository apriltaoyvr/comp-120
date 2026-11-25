#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// Part 1
int binary_search(int nums[], int size, int target) {
  int high = size - 1;
  int low = 0;

  while (high >= low) {
    int mid = low + (high - low) / 2;
    if (target == nums[mid])
      return mid;
    else if (target < nums[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  return -1;
}

int binary_search_recursive(int nums[], int target, int low, int high) {
  if (low > high) return -1;

  int mid = low + (high - low) / 2;

  if (target == nums[mid])
    return mid;
  else if (target < nums[mid])
    return binary_search_recursive(nums, target, low, mid - 1);
  else
    return binary_search_recursive(nums, target, mid + 1, high);
}

// Part 2
int search_insert(int nums[], int size, int target) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (target == nums[mid])
      return mid;
    else if (target < nums[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  return low;
}

// Part 3

void selection_sort(int nums[], int size) {
  
  for (int i = 0; i < size; ++i) {
    int smallest = i;
    for (int j = i + 1; j < size; ++j) {
      if (nums[j] < nums[smallest]) smallest = j;
    }
    int tmp = nums[i];
    
    nums[i] = nums[smallest];
    nums[smallest] = tmp;
  }
}

void bubble_sort(int nums[], int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        int tmp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = tmp;
      }
    }
  }
}

// The test zone
void test_binary() {
  int a[] = {2, 3, 5, 7};
  int b[] = {2};

  assert(binary_search(a, 4, 5) == 2);
  assert(binary_search(a, 4, 4) == -1);
  assert(binary_search(b, 1, 2) == 0);

  assert(binary_search_recursive(a, 5, 0, 4) == 2);
  assert(binary_search_recursive(a, 4, 0, 4) == -1);
  assert(binary_search_recursive(b, 2, 0, 1) == 0);
}

void test_insertion() {
  int a[] = {1, 3, 5, 6};

  assert(search_insert(a, 4, 5) == 2);
  assert(search_insert(a, 4, 2) == 1);
  assert(search_insert(a, 4, 7) == 4);
  assert(search_insert(a, 4, 0) == 0);
}

bool array_comparison(int a[], int b[], int n) {
  for (int i = 1; i < n; ++i) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

void test_sort() {
  int a[] = {4, 2, 9, 1};
  int b[] = {3, 1, 2};
  int c[] = {5};

  int x[] = {1, 2, 4, 9};
  int y[] = {1, 2, 3};
  int z[] = {5};

  selection_sort(a, 4);
  selection_sort(b, 3);
  selection_sort(c, 1);

  assert(array_comparison(a, x, 4));
  assert(array_comparison(b, y, 3));
  assert(array_comparison(c, z, 1));
}

int main(void) {
  // Binary Search
  test_binary();

  // Search Insert
  test_insertion();

  // Sorting
  test_sort();

  printf("All tests passed!\n");

  return 0;
}
