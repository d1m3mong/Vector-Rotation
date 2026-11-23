#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

void rotate(std::vector<std::vector<int>> &matrix, int rotations = 1) {
  if (matrix.empty() || matrix[0].empty() || rotations < 0)
    return;

  rotations %= 4;

  std::vector<std::vector<int>> newVec;

  for (size_t i{}; i < rotations; i++) {

    size_t oldRow = matrix.size();
    size_t oldCol = matrix[0].size();

    newVec.resize(oldCol);
    for (size_t s{}; s <= newVec.size() - 1; s++) {
      newVec[s].resize(oldRow);
    }

    for (size_t x{}; x <= matrix.size() - 1; x++) {
      for (size_t y{}; y <= matrix[0].size() - 1; y++) {
        size_t newCol = matrix.size() - 1 - x;
        size_t newRow = y;

        newVec[newRow][newCol] = matrix[x][y];
      }
    }

    matrix = std::move(newVec);
  }

  newVec.clear();
}

int main(int argc, char **arcv) {
  std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}}; //}, {7, 8, 9}};

  rotate(matrix, *arcv[1]);

  for (size_t i{}; i <= matrix.size() - 1; i++) {
    for (const auto &n : matrix[i])
      std::cout << n << '\n';
  }

  return 0;
}
