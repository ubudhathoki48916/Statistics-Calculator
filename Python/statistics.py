
class StatisticsCalculator:
    def __init__(self, numbers):
        if not numbers:
            raise ValueError("The list cannot be empty.")
        self.numbers = list(numbers)

    def calculate_mean(self):
        return sum(self.numbers) / len(self.numbers)

    def calculate_median(self):
        sorted_numbers = sorted(self.numbers)
        n = len(sorted_numbers)
        middle = n // 2

        if n % 2 == 1:
            return sorted_numbers[middle]

        return (sorted_numbers[middle - 1] + sorted_numbers[middle]) / 2

    def calculate_mode(self):
        frequencies = {}
        for number in self.numbers:
            frequencies[number] = frequencies.get(number, 0) + 1

        highest_frequency = max(frequencies.values())
        return sorted(
            number for number, count in frequencies.items()
            if count == highest_frequency
        )


if __name__ == "__main__":
    numbers = [4, 2, 7, 2, 9, 4, 2, 6]
    calculator = StatisticsCalculator(numbers)

    print("Numbers:", numbers)
    print("Mean:", calculator.calculate_mean())
    print("Median:", calculator.calculate_median())
    print("Mode:", calculator.calculate_mode())
