#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

template <typename T>
void PrintVector(const std::string& vectorName, const std::vector<T>& vector)
{
    std::cout << vectorName << ": ";

    for (const T& currentElement : vector)
    {
        std::cout << currentElement << ", ";
    }

    std::cout << std::endl;
}

void SortAlphabaticallyAndSplitAtPurple()
{
    std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };

    // Sort the vector in alphabetical order
    std::sort(colours.begin(), colours.end());

    // Find the split point
    auto splitPoint = std::find(colours.begin(), colours.end(), "purple");

    // Make new vectors
    std::vector<std::string> beforePurple, afterPurple;

    beforePurple.assign(colours.begin(), splitPoint);
    afterPurple.assign(splitPoint, colours.end());

    PrintVector("1: beforePurple", beforePurple);
    PrintVector("1: afterPurple", afterPurple);
}

void MakeUppercase()
{
    std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };

    std::for_each(colours.begin(), colours.end(), [](std::string& string)
        {
            std::transform(string.begin(), string.end(), string.begin(), std::toupper);
        });

    PrintVector("2: uppercase", colours);
}

void RemoveDubbles()
{
    std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };

    std::sort(colours.begin(), colours.end());
    auto uniqueEnd = std::unique(colours.begin(), colours.end());
    colours.erase(uniqueEnd, colours.end());

    PrintVector("3: withoutDoubles", colours);
}

void RemoveNegatives()
{
    std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

    auto IsNegative = [](int i)
        {
            return (i < 0);
        };

    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), IsNegative));

    PrintVector("4: withoutNegatives", numbers);
}

void EvenOrUneven()
{
    std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

    auto isEven = [](int num)
        {
            return num % 2 == 0;
        };

    std::vector<bool> evenOrUneven;

    for (const double& currentElement : numbers)
    {
        if (isEven(currentElement))
        {
            evenOrUneven.push_back(true);
        }
        else
        {
            evenOrUneven.push_back(false);
        }
    }

    PrintVector("5: evenOrUnevenValues", numbers);
    PrintVector("5: evenOrUnevenBools", evenOrUneven);
}

void CalcSumAverageAndProduct()
{
    std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

    double sum = 0;
    double average = 0;
    double product = 0;

    for (const double& currentElement : numbers)
    {
        sum += currentElement;

        if (product == 0)
        {
            product = currentElement;
        }
        else
        {
            product *= currentElement;
        }
    }

    average = sum / numbers.size();

    std::cout << "6: sum: " << sum << " - Average: " << average << " - Product: " << product << std::endl;
}

int main()
{
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)

    // 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
    SortAlphabaticallyAndSplitAtPurple();

    // 2) alle elementen UPPERCASE te maken.
    MakeUppercase();

    // 3) alle dubbele te verwijderen
    RemoveDubbles();

    // 4) alle negatieve elementen te verwijderen
    RemoveNegatives();

    // 5) voor alle elementen te bepalen of ze even of oneven zijn
    EvenOrUneven();

    // 6) de som, het gemiddelde, en het product van alle getallen te berekenen
    CalcSumAverageAndProduct();

    std::cin.get();
}