#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Unicorn
{
private:
    std::string name_;
    bool registered_ = false;

    inline static std::vector<std::string> takenNames_;

public:
    Unicorn(const std::string& name) : name_(name)
    {
        auto it = std::find(takenNames_.begin(), takenNames_.end(), name_);

        if (it != takenNames_.end())
        {
            std::cout << "Error: The name " << name_ << " is already taken!\n";
            return;
        }

        takenNames_.push_back(name_);
        registered_ = true;
    }

    ~Unicorn()
    {
        if (!registered_)
            return;

        // could just loop to find idx and then break

        auto it = std::find(takenNames_.begin(), takenNames_.end(), name_);

        if (it != takenNames_.end())
            takenNames_.erase(it);
    }

    Unicorn(const Unicorn&) = delete;
    Unicorn& operator=(const Unicorn&) = delete;
};

int main()
{
    {
        Unicorn first("Sparkles");
        Unicorn second("Sparkles"); //uncomment, and no duplicate name error
    }

    Unicorn third("Sparkles");
}