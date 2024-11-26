
#include "Table.hpp"
#include <iomanip>
#include <random>
#include <stdexcept>

// Constructor
Table::Table(size_t width, size_t height, int val)
    : width_(width), height_(height) {
  table_.resize(height_, row_t(width_, val));
}

// PrintTable: Prints the table in a nice format
 void Table::PrintTable(std::ostream& os) const {
  for (size_t row = 0; row < table_.size(); ++row) {
    for (size_t col = 0; col < table_[row].size(); ++col) {
      os << table_[row][col];
        os << ", ";
      
    }
    os << "\n"; // Add a newline after each row
  }
}


// FillRandom: Fills the table with random values
void Table::FillRandom(int low, int high, int seed) {
  std::mt19937 rng(seed); // Initialize random number generator with seed
  std::uniform_int_distribution<int> dist(low, high);

  for (auto& row : table_) {
    for (auto& val : row) {
      val = dist(rng);
    }
  }
}

// SetValue: Sets a value in the table if the indices are in range
bool Table::SetValue(size_t col, size_t row, int val) {
  if (row >= height_ || col >= width_) return false; // Out of range
  table_[row][col] = val;
  return true;
}

// GetValue: Gets a value from the table. Throws exception if out of range
int Table::GetValue(size_t col, size_t row) const {
  if (row >= height_ || col >= width_) {
    throw std::out_of_range("Index out of range");
  }
  return table_[row][col];
}
