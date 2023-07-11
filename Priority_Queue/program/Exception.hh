#include <string>

class Exception {
    private:

    std::string errorMessage;

    public:

    Exception(const std::string& msg) { errorMessage = msg; }

    ~Exception() {}

    std::string getErrorMessage() const { return errorMessage; }
};