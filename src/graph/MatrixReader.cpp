#include "MatrixReader.h"

#include <iostream>

#include "Constants.h"

int MatrixReader::readNextNumberOrThrow(
    std::string const &line, size_t *offset,
    std::string const &notFoundErrorMessage) const {
  // Проверяем, что в строке только числа
  if (!std::all_of(line.begin(), line.end(), [](char const &ch) {
        return ::isdigit(ch) || ::isspace(ch) || ch == '-';
      })) {
    throw std::invalid_argument("Adjecency matrix should contain only numbers");
  }

  // Получаем позицию следующего числа
  const std::string digits = Constants::getDigits();
  size_t numberPosition = line.find_first_of(digits, *offset);
  if (numberPosition == std::string::npos) {
    throw std::invalid_argument(notFoundErrorMessage);
  }

  // Получаем длину числа
  size_t positionAfterNumber = line.find_first_not_of(digits, numberPosition);
  int numberLength = positionAfterNumber == std::string::npos
                         ? line.size() - numberPosition
                         : positionAfterNumber - numberPosition;

  // Получаем строку, содержащую число
  std::string numberStr = line.substr(numberPosition, numberLength);

  int number;
  try {
    number = std::stoi(numberStr);
  } catch (const std::exception &e) {
    throw std::invalid_argument(numberStr +
                                " is more than maximum value of int number");
  }

  // двигаем смещение по строке на позицию после текущего числа
  *offset = numberPosition + numberLength + 1;
  return number;
}

int MatrixReader::readMatrixSize(std::ifstream &file) const {
  std::string line;
  int matrixSize;
  bool matrixSizeFound = false;

  while (getline(file, line)) {
    // Cчитываем строки, пока не появится текст.
    if (std::all_of(line.begin(), line.end(), ::isspace)) {
      continue;
    }

    // Получаем размер матрицы
    size_t offset = 0;
    matrixSize =
        readNextNumberOrThrow(line, &offset, "Matrix size is not found");

    if (matrixSize <= 0) {
      throw std::invalid_argument("Matrix size can't be less or equal to '0'");
    }

    // Бросаем исключение, если есть что-то после размера матрицы.
    if (line.find_first_not_of(' ', offset) != std::string::npos) {
      throw std::invalid_argument(
          "Invalid format of adjecency matrix: matrix size line is invalid");
    }

    matrixSizeFound = true;
    break;
  }

  if (!matrixSizeFound) {
    throw std::invalid_argument(
        "Invalid format of adjecency matrix: matrix size not found");
  }

  return matrixSize;
}

weight **MatrixReader::readAdjacencyMatrix(std::ifstream &file,
                                           int const matrixSize) const {
  weight **matrix = new weight *[matrixSize];
  for (int i = 0; i < matrixSize; i++) {
    matrix[i] = new weight[matrixSize];
  }

  for (int i = 0; i < matrixSize; i++) {
    bool hasAdjacency = false;

    size_t offset = 0;
    if (file.peek() == EOF) {
      throw std::invalid_argument(
          "invalid number of rows in the adjecency matrix");
    }

    std::string line;
    getline(file, line);
    for (int j = 0; j < matrixSize; j++) {
      weight number = readNextNumberOrThrow(
          line, &offset, "invalid number of columns in the adjecency matrix");
      if (number != 0) {
        hasAdjacency = true;
      }
      matrix[i][j] = number;
    }

    if (!hasAdjacency) {
      throw std::invalid_argument(
          "A vertex should have at least one adjacency");
    }
  }

  return matrix;
}

MatrixReader::~MatrixReader() {}
