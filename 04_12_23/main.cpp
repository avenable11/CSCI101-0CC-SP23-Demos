#include <iostream>
#include <climits>
#include <string>

const int ARRAY_SIZE = 100;
const int NUM_COLORS = 5;
enum colorType
{
    BLUE,
    RED,
    GREEN = 9,
    YELLOW,
    PURPLE
};

const colorType colors[NUM_COLORS] = {BLUE,
                                      RED,
                                      GREEN,
                                      YELLOW,
                                      PURPLE};
const std::string colorStr[NUM_COLORS] = {"Blue", "Red", "Green", "Yellow", "Purple"};

std::string colorToString(colorType);
colorType inputColor(std::string);
void resetStream();
void inputList(int[], int);
void initialize(int[], int); // fill in for lecture activity
void outputList(int[], int);
void findLargest(int[], int, int &);
void calculateSumAndAvg(int[], int, int &, double &);

int main()
{

    int list[ARRAY_SIZE]; // array must be created with a constant
    int sum = 0;
    int largestPos;
    int numItems = 10;
    double avg;
    /* for (int i = 0; i < ARRAY_SIZE; i++)
    {
        list[i] = 0; // array can be accessed with a constant or a variable
    } */
    // add function call to initialize the list of numItems
    inputList(list, numItems);
    outputList(list, numItems);
    calculateSumAndAvg(list, numItems, sum, avg);
    std::cout << "The average of the numbers is " << avg << std::endl;

    findLargest(list, numItems, largestPos);
    std::cout << "The largest item is " << list[largestPos] << " at index " << largestPos << std::endl;

    colorType mycolor = inputColor("Pick your favorite color: ");
    std::cout << colorToString(mycolor) << std::endl;

    return 0;
}

std::string colorToString(colorType theColor)
{
    for (int i = 0; i < NUM_COLORS; i++)
    {
        if (colors[i] == theColor)
            return colorStr[i];
    }

    return "Unknown";
}

colorType inputColor(std::string prompt)
{
    int colorInt;
    colorType theColor;
    std::cout << prompt << std::endl;
    for (int i = 0; i < NUM_COLORS; i++)
    {
        std::cout << i + 1 << ". " << colorStr[i] << std::endl;
    }
    std::cin >> colorInt;
    while (!std::cin || colorInt - 1 < 0 || colorInt - 1 > NUM_COLORS)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please choose a color from the list." << std::endl;
        std::cin >> colorInt;
    }
    theColor = colors[colorInt - 1];

    return theColor;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "You entered something that is not a number!" << std::endl;
}

void inputList(int list[], int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        std::cin >> list[i];
    }
}

void outputList(int l[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << l[i] << std::endl;
    }
}

void findLargest(int list[], int size, int &largestPos)
{
    largestPos = 0;
    for (int i = 1; i < size; i++)
    {
        if (list[i] > list[largestPos])
        {
            largestPos = i;
        }
    }
}

void calculateSumAndAvg(int list[], int size, int &sum, double &avg)
{
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += list[i]; // sum = sum + list[i];
    }
    avg = sum / static_cast<double>(size);
}
