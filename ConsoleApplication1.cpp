#include <iostream>
#include <vector>

void print(std::vector<int> arr) 
{
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;

}

//============================================================================

int main(int argc, const char** argv) 
{ 
    std::vector<int> nums = { 11, 6, 1, 1,2,3,4,5,6,7,8,9 };
    std::vector<int> help;
    help.push_back(nums.at(0));

    for (auto const& i : nums) {
        bool isDupe = false;
        for (auto it = help.begin(); it != help.end(); it++)
            if (i == *it)
                isDupe = true;

        if (!isDupe)
            help.push_back(i);
    }
    std::cout << help.size() << std::endl;
    print(help);
    print(nums);

    return 0;
}